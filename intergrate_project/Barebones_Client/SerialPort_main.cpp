/* Zain Ul Mustafa 2017 */

//Rules:
/*
1. Check if connection with Arduino is made
2. If Arduino is connected then take input from user in a String
3. Make a char array of the size of string + 1
4. Copy the whole string into the char array
5. Add escape sequence \n because this represents the end of a line in Serial Comm port
6. Write the whole char array into the buffer (a buffer takes the info forward to the Serial Comm Port)
7. Read from the Arduino if data is received successfully or if the action is taken as per needed
*/

//Connect with me:
/*	Twitter: http://www.twitter.com/ZainsOfficial/
	Facebook: http://www.facebook.com/ZainsOfficial/
	Github: http://github.com/ZainUlMustafa/
*/

/* This software is allowed for any user to copy, modify, merge, and distribute in any of his/her project.
Complete repository for this project is available on github. If you find this project anywhere except github, it
is to be noted that it is not made by me and not distributed by me. 
Please follow this link to get to the original repository of github for this project
Github shortened link (no spam and no ads): http://bit.ly/2vGkinQ
*/

/* PC 2 Arduino */

#include<iostream>
using namespace std;
#include<string>
#include<stdlib.h>


#include <thread>
#include"SerialPort.h"
#include"every_command.h"

char output[MAX_DATA_LENGTH];
char incomingData[MAX_DATA_LENGTH];

// change the name of the port with the port name of your computer
// must remember that the backslashes are essential so do not remove them
char *port = (char*)"\\\\.\\COM3";

int SerialPort_main(){
	cout << "Serial_main start running" << endl;
	SerialPort arduino(port);
	if(arduino.isConnected()){
		cout<<"Connection made"<<endl<<endl;
	}
	else{
		cout<<"Error in port name"<<endl<<endl;
	}
	while (arduino.isConnected()) {

		cout << "Enter your command: " << endl;
		string data;

		data = std::to_string(every_command::serial_command);
		if (every_command::serial_command < 1000000)
		{
			data = std::string("0") + std::to_string(every_command::serial_command);
		}

		char *charArray = new char[data.size() + 1];
		copy(data.begin(), data.end(), charArray);
		charArray[data.size()] = '\n';

		arduino.writeSerialPort(charArray, MAX_DATA_LENGTH);	
		arduino.readSerialPort(output, MAX_DATA_LENGTH);


		/*cout << std::endl;
		cout << ">> " << every_command::serial_command << endl;
		cout << ">> " << output << endl;
		cout << ">> " << charArray << endl;
		cout << ">> " << charArray << endl;
		cout << std::endl;*/

		do{
		std::this_thread::sleep_for(0.8s);
		} while (!every_command::if_serial_command_change());
		
		

		delete [] charArray;
	}
	return 0;
}
