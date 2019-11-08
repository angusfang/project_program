#pragma once
#ifndef cal_angle_h
#define cal_angle_h

#include "robot_argument.h"
#include "matrix_function.h"

#include "origin_to_shouder.h"
#include "to_robot_size.h"
#include "make_T06.h"
#include "solution.h"
#include "best_solution.h"
#include "set_output.h"
#include "avoid_impact.h"
void correct_angle(double angle[6])//弧度
{
	for (int i = 0; i < 6; i++)
	{
		while (angle[i] < (-180 / 180.0*3.14))
		{
			angle[i] += (360 / 180.0*3.14);
			std::cout << "in big collect loop (cal_angle_function)"<<std::endl;
		}
		while (angle[i] > (180 / 180.0*3.14))
		{
			angle[i] -= (360 / 180.0*3.14);
			std::cout << "in small collect loop(cal_angle_function)" << std::endl;
		}
	}

}
// 輸入
//input:kinect的xyz
//output:要輸出的六個角度(非弧度)
//copy_bestangle:上一次的角度
void cal_angle(double input[6][3], double output[6])
{
	static double copy_bestangle[6] = { 0 };
	origin_to_shouder(input);
	to_robot_size(input);
	double T06[4][4];
	//T06直接以人手座標看出
	make_T06(input, T06);
	//max have 64 solution
	double angle[64][6], whattype[64][6];//angle為弧度
	int number = 0;//計算有幾組解

	number=solution(T06,angle,whattype);
	int best_set=0;
	////手肘不能超過手腕寫在best_set
	//尋找最相近的解
	best_set=best_solution(number,angle, copy_bestangle,T06,input);
	for (int i = 0; i < number; i++)
		correct_angle(angle[i]);
	best_set = avoid_impact(best_set,input, angle, copy_bestangle, T06);
	set_output(angle, best_set,output,copy_bestangle);
}

#endif // !cal_angle_h

