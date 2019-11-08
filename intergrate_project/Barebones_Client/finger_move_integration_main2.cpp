#include <cmath>
#include <iostream>
#include <thread>
#include <cstdint>
#include "every_command.h"

double clamp(double val, double high, double low)
{
	if (val > high)
		return high;
	if (val < low)
		return low;
	return val;
}

class My_vector
{
private:
	double m_x;
	double m_y;
	double m_z;
public:
	My_vector(const double vector[3])
		:m_x(vector[0]), m_y(vector[1]), m_z(vector[2])
	{}
	My_vector(const double a, const double b, const double c)
		:m_x(a), m_y(b), m_z(c)
	{}

	My_vector add(const My_vector& other)const
	{
		return My_vector(m_x + other.m_x, m_y + other.m_y, m_z + other.m_z);
	}

	My_vector operator+(const My_vector& other)const
	{
		return add(other);
	}

	My_vector minus(const My_vector& other)const
	{
		return My_vector(m_x - other.m_x, m_y - other.m_y, m_z - other.m_z);
	}

	My_vector operator-(const My_vector& other)const
	{
		return minus(other);
	}

	My_vector multiply(const My_vector& other)const
	{
		return My_vector(m_x * other.m_x, m_y * other.m_y, m_z * other.m_z);
	}

	My_vector operator*(const My_vector& other)const
	{
		return multiply(other);
	}

	double dot(const My_vector& other)const
	{
		double ans1 = 0;
		double ans2 = 0;
		double ans3 = 0;
		ans1 = m_x * other.m_x;
		ans2 = m_y * other.m_y;
		ans3 = m_z * other.m_z;

		return (ans1+ans2+ans3);
	}

	double vector_length()const
	{
		double square = (m_x*m_x) + (m_y * m_y) + (m_z * m_z);
		double ans1 = sqrt(square);
		return(ans1);
	}

	double angle_cal(const My_vector& other)const
	{
		double ans1 = ((*this).dot(other));
		double ans2 = ((*this).vector_length())*(other.vector_length());
		double ans3 = ans1/ans2;
		return (acos(ans3));
	}
	
};

int finger_move_integration_main(double wrist[3], double hand[3], double thumb[3], double indexfinger[3],int finger_command)
{
	std::cout << "---inside-------inside---------inside--inside----inside--inside---inside----inside----finger_command"<<finger_command << std::endl;
	My_vector C_wrist(wrist);
	My_vector C_hand(hand);
	My_vector C_thumb(thumb);
	My_vector C_indexfinger(indexfinger);
	My_vector C_hand_to_wrist( C_wrist- C_hand );
	My_vector C_hand_to_thumb(C_thumb-C_hand);
	My_vector C_hand_to_indexfinger(C_indexfinger-C_hand);

	//date:20190902
	float length_hand_to_thumb = C_hand_to_thumb.vector_length()*10000;
	float length_hand_to_index = C_hand_to_indexfinger.vector_length()*10000;

	std::cout << std::endl;
	std::cout << length_hand_to_thumb<<"TTT" << std::endl;
	std::cout << length_hand_to_index << "III"<<std::endl;
	std::cout << std::endl;


	double deg_of_hand_to_wrist_and_hand_to_indexfinger = 0;
	double deg_of_hand_to_indexfinger_and_hand_to_thumb = 0;
	deg_of_hand_to_wrist_and_hand_to_indexfinger = C_hand_to_wrist.angle_cal(C_hand_to_indexfinger);
	deg_of_hand_to_indexfinger_and_hand_to_thumb = C_hand_to_indexfinger.angle_cal(C_hand_to_thumb);
	//angle correcttion
	deg_of_hand_to_wrist_and_hand_to_indexfinger *= 180.0 / 3.14;//arc to deg
	deg_of_hand_to_indexfinger_and_hand_to_thumb *= 180.0 / 3.14;//

	//angle correcttion deg_of_hand_to_wrist_and_hand_to_indexfinger
	deg_of_hand_to_wrist_and_hand_to_indexfinger = -1 * deg_of_hand_to_wrist_and_hand_to_indexfinger + 180;
	deg_of_hand_to_wrist_and_hand_to_indexfinger = (clamp(deg_of_hand_to_wrist_and_hand_to_indexfinger, 90, 70) - 70)*9 ;
	deg_of_hand_to_wrist_and_hand_to_indexfinger = clamp(deg_of_hand_to_wrist_and_hand_to_indexfinger, 170, 10);

	deg_of_hand_to_indexfinger_and_hand_to_thumb = (clamp(deg_of_hand_to_indexfinger_and_hand_to_thumb, 100, 90) - 90) * 15 ;
	deg_of_hand_to_indexfinger_and_hand_to_thumb = clamp(deg_of_hand_to_indexfinger_and_hand_to_thumb, 170, 10);

	/*deg_of_hand_to_wrist_and_hand_to_indexfinger= clamp(deg_of_hand_to_wrist_and_hand_to_indexfinger, 170, 40);
	deg_of_hand_to_indexfinger_and_hand_to_thumb = clamp(deg_of_hand_to_indexfinger_and_hand_to_thumb, 170, 40);*/

	

	int command = 0;


	//如果平均量減少就閉合
	static double indexFinger[5] = { 0 };
	static double thumbFinger[5] = { 0 };

	static int this_finger_state = 0;
	
	
	static int count = 0;

	indexFinger[count] = length_hand_to_index;
	thumbFinger[count] = length_hand_to_thumb;


	static double avelast[2] = { 0 };
	static double avenow[2] = { 0 };

	count++;

	//5次做一次平均

	if (count == 5)
	{
		
		static bool first = true;
		if (first)
		{
			first = false;
		}
		else
		{
			avelast[0] = avenow[0];
			avelast[1] = avenow[1];
		}

		double sum = 0.0;
		for (int i = 0; i < 5; i++)
		{
			std::cout <<"食指"<<i<<":"<<indexFinger[i] << std::endl;
			std::cout << std::endl;
			sum = sum + indexFinger[i];
		}
		//拇指平均
		avenow[1] = sum / 5.0;

		sum = 0.0;
		for (int i = 0; i < 5; i++)
		{
			std::cout << "拇指" << i << ":" << thumbFinger[i] << std::endl;
			sum = sum + thumbFinger[i];
		}
		//食指平均
		avenow[0] = sum / 5.0;
		sum = 0;
		count = 0;

		static int leg_In = 0;
		static int leg_th = 0;



		//這次平均扣掉上次平均，比較大就全開
		////食指
		std::cout << "上次食指平均:" << avelast[1]<<std::endl;
		std::cout << "這次食指平均:" << avenow[1]<<std::endl;
		//if (avenow[1] - avelast[1]>15.0)
		//{
		//	leg_In = 150;
		//}
		//else if (avenow[1] - avelast[1] < -15.0)
		//{
		//	leg_In = 30;
		//}
		//////拇指
		//if (avenow[0] - avelast[0] > 15.0)
		//{
		//	leg_th = 120;
		//}
		//else if (avenow[0] - avelast[0] < -15.0)
		//{
		//	leg_th = 60;
		//}
		//sellect what command shoud sent
		/*std::cout << "食指跟手掌:" << leg_In << std::endl;
		std::cout << "拇指跟食指:" << leg_th << std::endl;*/
		//角度輸出
		//command = leg_th * 10000 + leg_In * 10 + 1;
		//output to robot hand

		//finger_command 2綠色,3,4紅色藍色
		//this_finger_state = 1 開
		//this_finger_state = 2 關
		if (finger_command == 2)
		{
			this_finger_state = 1;
		}
		if (finger_command == 3)
		{
			this_finger_state = 2;
		}
		if (finger_command == 4)
		{
			this_finger_state = 2;
		}

		if (this_finger_state == 1)
		{
			leg_In = 120;
			leg_th = 120;

		}
		if (this_finger_state == 2)
		{
			leg_In = 40;
			leg_th = 60;
		}

		command = leg_th * 10000 + leg_In * 10 + 1;

		every_command::serial_command = command;
	}

	
	return 0;
}