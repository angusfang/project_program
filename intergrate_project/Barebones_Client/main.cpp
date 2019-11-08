#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#include <Kinect.h>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <windows.h>
#include <cal_angle.h>
#include <thread>

int SerialPort_main();
int finger_move_integration_main(double wrist[3], double hand[3], double thumb[3], double indexfinger[3],int finger_command);

using namespace std;

//my--return robot arm angle command
string main_calculate_angle(double* p1, double *p2, double *p3, double*p4, double*p5, double*p6, int *count, string str_command,int finger_command)
{
	//my--input is all human coordinate
	//my--output is robot arm angle
	static double input[6][3] = { 0 };
	static double output[6] = { 0 };

	for (int i = 0; i < 3; i++)
	{
		input[0][i] = p1[i];
		input[1][i] = p2[i];
		input[2][i] = p3[i];
		input[3][i] = p4[i];
		input[4][i] = p5[i];
		input[5][i] = p6[i];
	}

	cal_angle(input, output);

	str_command = "{\"dsID\":\"HCRemoteMonitor\", \"cmdType\" : \"command\", \"cmdData\" : [\"rewriteDataList\", \"800\", \"6\", \"0\" ";
	for(int i=0;i<6;i++)
		str_command = str_command + ", \"" + to_string(int(output[i]* 1000)) + "\"";
	str_command = str_command + "]}";

	finger_move_integration_main(p3, p4, p5, p6, finger_command);
	
	return str_command;

}


// output operator for CameraSpacePoint
//輸出rPos物件時，直接顯示其XYZ
ostream& operator<<(ostream& rOS, const CameraSpacePoint& rPos)
{
	rOS << "X" << rPos.X << "Y" << rPos.Y << "Z" << rPos.Z << "P";
	return rOS;
}

// output operator for Vector4
//輸出rVec物件時，直接顯示其XYZW
ostream& operator<<(ostream& rOS, const Vector4& rVec)
{
	rOS << "(" << rVec.x << "/" << rVec.y << "/" << rVec.z << "/" << rVec.w << ")";
	return rOS;
}



int main()
{
	//create another thread
	std::thread mthread1(SerialPort_main);
	int count = 0;
	double p1[3] = { 0,0,0 };
	double p2[3] = { 0,0,0 };
	double p3[3] = { 0,0,0 };
	double p4[3] = { 0,0,0 };
	double p5[3] = { 0,0,0 };
	double p6[3] = { 0,0,0 };

	//to control robot arm
	string str_command;

	// 1a. Get default Sensor
	//cout << "Try to get default sensor" << endl;
	IKinectSensor* pSensor = nullptr;
	if (GetDefaultKinectSensor(&pSensor) != S_OK)
	{
		cerr << "Get Sensor failed" << endl;
		return -1;
	}

	// 1b. Open sensor
	//cout << "Try to open sensor" << endl;
	if (pSensor->Open() != S_OK)
	{
		cerr << "Can't open sensor" << endl;
		return -1;
	}

	// 2a. Get frame source
	//cout << "Try to get body source" << endl;
	IBodyFrameSource* pFrameSource = nullptr;
	if (pSensor->get_BodyFrameSource(&pFrameSource) != S_OK)
	{
		cerr << "Can't get body frame source" << endl;
		return -1;
	}

	// 2b. Get the number of body
	INT32 iBodyCount = 0;
	if (pFrameSource->get_BodyCount(&iBodyCount) != S_OK)
	{
		cerr << "Can't get body count" << endl;
		return -1;
	}
	//cout << " > Can trace " << iBodyCount << " bodies" << endl;
	IBody** aBody = new IBody*[iBodyCount];
	for (int i = 0; i < iBodyCount; ++i)
		aBody[i] = nullptr;

	// 3a. get frame reader
	//cout << "Try to get body frame reader" << endl;
	IBodyFrameReader* pFrameReader = nullptr;
	if (pFrameSource->OpenReader(&pFrameReader) != S_OK)
	{
		cerr << "Can't get body frame reader" << endl;
		return -1;
	}

	// 2b. release Frame source
	//cout << "Release frame source" << endl;
	pFrameSource->Release();
	pFrameSource = nullptr;

	// Enter main loop
	int iStep = 0;
	while (iStep < 10000000)
	{
		
		// 4a. Get last frame
		IBodyFrame* pFrame = nullptr;
		if (pFrameReader->AcquireLatestFrame(&pFrame) == S_OK)
		{
			++iStep;

			// 4b. get Body data
			if (pFrame->GetAndRefreshBodyData(iBodyCount, aBody) == S_OK)
			{
				int iTrackedBodyCount = 0;

				// 4c. for each body
				for (int i = 0; i < iBodyCount; ++i)
				{
					IBody* pBody = aBody[i];

					// check if is tracked
					BOOLEAN bTracked = false;
					if ((pBody->get_IsTracked(&bTracked) == S_OK) && bTracked)
					{
						//my--get left hand state
						HandState leftHandState = HandState_Unknown;
						pBody->get_HandLeftState(&leftHandState);

						++iTrackedBodyCount;
	
						// get joint position
						Joint aJoints[JointType::JointType_Count];
						if (pBody->GetJoints(JointType::JointType_Count, aJoints) != S_OK)
						{
							cerr << "Get joints fail" << endl;
						}

						// get joint orientation
						JointOrientation aOrientations[JointType::JointType_Count];
						if (pBody->GetJointOrientations(JointType::JointType_Count, aOrientations) != S_OK)
						{
							cerr << "Get joints fail" << endl;
						}

						//my--get right shoulder
						{
							JointType eJointType1 = JointType::JointType_ShoulderRight;
							const Joint& rJointPos1 = aJoints[eJointType1];
							const JointOrientation& rJointOri1 = aOrientations[eJointType1];

							//cout << " > right shoulder is ";
							if (rJointPos1.TrackingState == TrackingState_NotTracked)
							{
								//cout << "not tracked" << endl;
							}
							else
							{
								if (rJointPos1.TrackingState == TrackingState_Inferred)
								{
									//cout << "inferred ";
								}
								else if (rJointPos1.TrackingState == TrackingState_Tracked)
								{
									//cout << "tracked ";
								}
								//my--get coordinate								
								p1[0] = rJointPos1.Position.X;
								p1[2] = rJointPos1.Position.Y;
								p1[1] = -rJointPos1.Position.Z;
							}
						}

						//my--get right elobow
						{
							JointType eJointType2 = JointType::JointType_ElbowRight;
							const Joint& rJointPos2 = aJoints[eJointType2];
							const JointOrientation& rJointOri2 = aOrientations[eJointType2];

							//cout << " > right elobow is ";
							if (rJointPos2.TrackingState == TrackingState_NotTracked)
							{
								//cout << "not tracked" << endl;
							}
							else
							{
								if (rJointPos2.TrackingState == TrackingState_Inferred)
								{
									//cout << "inferred ";
								}
								else if (rJointPos2.TrackingState == TrackingState_Tracked)
								{
									//cout << "tracked ";
								}
								//my--get coordinate
								p2[0] = rJointPos2.Position.X;
								p2[2] = rJointPos2.Position.Y;
								p2[1] = -rJointPos2.Position.Z;
							}
						}

						//my--get right wrist
						{
							JointType eJointType3 = JointType::JointType_WristRight;
							const Joint& rJointPos3 = aJoints[eJointType3];
							const JointOrientation& rJointOri3 = aOrientations[eJointType3];

							//cout << " > right wrist is ";
							if (rJointPos3.TrackingState == TrackingState_NotTracked)
							{
								//cout << "not tracked" << endl;
							}
							else
							{
								if (rJointPos3.TrackingState == TrackingState_Inferred)
								{
									//cout << "inferred ";
								}
								else if (rJointPos3.TrackingState == TrackingState_Tracked)
								{
									//cout << "tracked ";
								}
								//my--get coordinate							
								p3[0] = rJointPos3.Position.X;
								p3[2] = rJointPos3.Position.Y;
								p3[1] = -rJointPos3.Position.Z;
							}
						}

						//my--get right hand
						{
							JointType eJointType4 = JointType::JointType_HandRight;
							const Joint& rJointPos4 = aJoints[eJointType4];
							const JointOrientation& rJointOri4 = aOrientations[eJointType4];

							//cout << " > right hand is ";
							if (rJointPos4.TrackingState == TrackingState_NotTracked)
							{
								//cout << "not tracked" << endl;
							}
							else
							{
								if (rJointPos4.TrackingState == TrackingState_Inferred)
								{
									//cout << "inferred ";
								}
								else if (rJointPos4.TrackingState == TrackingState_Tracked)
								{
									//cout << "tracked ";
								}
								//my--get coordinate
								p4[0] = rJointPos4.Position.X;
								p4[2] = rJointPos4.Position.Y;
								p4[1] = -rJointPos4.Position.Z;
							}
						}

						//my--get right hand tip
						{
							JointType eJointType5 = JointType::JointType_HandTipRight;
							const Joint& rJointPos5 = aJoints[eJointType5];
							const JointOrientation& rJointOri5 = aOrientations[eJointType5];

							//cout << " > right hand tip is ";
							if (rJointPos5.TrackingState == TrackingState_NotTracked)
							{
								//cout << "not tracked" << endl;
							}
							else
							{
								if (rJointPos5.TrackingState == TrackingState_Inferred)
								{
									//cout << "inferred ";
								}
								else if (rJointPos5.TrackingState == TrackingState_Tracked)
								{
									//cout << "tracked ";
								}
								//my--get coordinate
								p5[0] = rJointPos5.Position.X;
								p5[2] = rJointPos5.Position.Y;
								p5[1] = -rJointPos5.Position.Z;
							}
						}

						//my--get right thumb
						{
							JointType eJointType6 = JointType::JointType_ThumbRight;
							const Joint& rJointPos6 = aJoints[eJointType6];
							const JointOrientation& rJointOri6 = aOrientations[eJointType6];

							//cout << " > right thumb is ";
							if (rJointPos6.TrackingState == TrackingState_NotTracked)
							{
								//cout << "not tracked" << endl;
							}
							else
							{
								if (rJointPos6.TrackingState == TrackingState_Inferred)
								{
									//cout << "inferred ";
								}
								else if (rJointPos6.TrackingState == TrackingState_Tracked)
								{
									//cout << "tracked ";
								}
								//my--get coordinate
								p6[0] = rJointPos6.Position.X;
								p6[2] = rJointPos6.Position.Y;
								p6[1] = -rJointPos6.Position.Z;
							}
						}

						//my--use function get command
						str_command=main_calculate_angle(p1, p2, p3, p4, p5, p6, &count, str_command, leftHandState);

						//my--this wii allow another thread to run
						std::this_thread::sleep_for(0.001s);

						//my--avoid collision command will get new kinect coordinate
						if (str_command == "AvoidCollision")
						{
							continue;
						}
					}
				}

				if (iTrackedBodyCount > 0) {}
					//cout << "Total " << iTrackedBodyCount << " bodies in this time\n" << endl;
			}
			else
			{
				cerr << "Can't read body data" << endl;
			}

			// 4e. release frame
			pFrame->Release();
		}
		else
		{
			//cout << "pFrameReader not ready"<<endl;
		}
		string ipAddress = "192.168.10.201";			// IP Address of the server
		int port = 9760;						// Listening port # on the server

		// Initialize WinSock
		WSAData data;
		WORD ver = MAKEWORD(2, 2);
		int wsResult = WSAStartup(ver, &data);
		if (wsResult != 0)
		{
			cerr << "Can't start Winsock, Err #" << wsResult << endl;
			return 0;
		}

		// Create socket
		SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
		if (sock == INVALID_SOCKET)
		{
			cerr << "Can't create socket, Err #" << WSAGetLastError() << endl;
			WSACleanup();
			return 0;
		}

		// Fill in a hint structure
		sockaddr_in hint;
		hint.sin_family = AF_INET;
		hint.sin_port = htons(port);
		inet_pton(AF_INET, ipAddress.c_str(), &hint.sin_addr);

		// Connect to server
		int connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
		if (connResult == SOCKET_ERROR)
		{
			cerr << "Can't connect to server, Err #" << WSAGetLastError() << endl;
			closesocket(sock);
			WSACleanup();
			return 0;
		}

		// Do-while loop to send and receive data
		char buf[4096];
		string userInput;

		
			// Prompt the user for some text
			cout << "> ";
			cout << str_command<<endl;
			
			userInput= str_command;
			Sleep(1000);
			

			if (userInput.size() > 0)		// Make sure the user has typed in something
			{
				// Send the text
				int sendResult = send(sock, userInput.c_str(), userInput.size() + 1, 0);
				if (sendResult != SOCKET_ERROR)
				{
					// Wait for response
					ZeroMemory(buf, 4096);
					//int bytesReceived = recv(sock, buf, 4096, 0);
					//if (bytesReceived > 0)
					//{
					//	// Echo response to console
					//	cout << "SERVER> " << string(buf, 0, bytesReceived) << endl;
					//}
				}
			}

		

		// Gracefully close down everything
		closesocket(sock);
		WSACleanup();
		
	}

	// delete body data array
	delete[] aBody;

	// 3b. release frame reader
	//cout << "Release frame reader" << endl;
	pFrameReader->Release();
	pFrameReader = nullptr;

	// 1c. Close Sensor
	//cout << "close sensor" << endl;
	pSensor->Close();

	// 1d. Release Sensor
	//cout << "Release sensor" << endl;
	pSensor->Release();
	pSensor = nullptr;
	return 0;
}
