#pragma once
#include<iostream>;
const double PI = 3.1415926;
const double very_big = 1e20;
const double no_solution = -1;

//無解return -1 有解return 最佳解在第幾組 
int best_solution(int number, double angle[64][6], double copy_bestangle[6],double T_06[4][4], double input[6][3])
{
	double square_dif = 0;
	

	//紀錄最小距離解是哪組
	double min_square_dif = very_big;
	int min_number = no_solution;



	//全部number組分別計算
	for (int i = 0; i < number; i++)
	{
		//角度再+-180度之間
		for (int j = 0; j <= 5; j++)
		{

			while (angle[i][j] > 1 * PI)
			{
				angle[i][j] = angle[i][j] - 2 * PI;
			}
			while (angle[i][j] < -1 * PI)
			{
				angle[i][j] = angle[i][j] + 2 * PI;
			}
		}

		//角度1在-180~+180以外的直接刪去
		if ((angle[i][0] < -180.0*(PI / 180.0)) || (angle[i][0] > 180.0*(PI / 180.0)))
		{
			continue;
		}
		
		//角度2在-100~90以外的直接刪去
		if ((angle[i][1] < -100.0*(PI / 180.0)) || (angle[i][1] > 90.0*(PI / 180.0)))
		{
			continue;
		}
		//角度3在-80~+95以外的刪去
		if ((angle[i][2] < -80.0*(PI / 180.0)) || (angle[i][2] > 95.0*(PI / 180.0)))
		{
			continue;
		}
		//角度4在-180~+180以外的刪去
		if ((angle[i][3] < -180.0*(PI / 180.0)) || (angle[i][3] > 180.0*(PI / 180.0)))
		{
			continue;
		}
		//角度5在-120~+120以外的刪去
		if ((angle[i][4] < -120.0*(PI / 180.0)) || (angle[i][4] > 120.0*(PI / 180.0)))
		{
			continue;
		}

		//建構T01
		//angle[i][0] 角度1
		double s1 = sin(angle[i][0]);
		double c1 = cos(angle[i][0]);
		double T01[4][4] = { { -s1,-c1,0,0 },
		{ c1,-s1,0,0 },
		{ 0,0,1,L01 },
		{ 0,0,0,1 } };


		//建構T12
		double s2 = sin(angle[i][1]);
		double c2 = cos(angle[i][1]);
		double T12[4][4] = { { -s2,-c2,0,L12 },
		{ 0,0,-1,0 },
		{ c2,-s2,0,0 },
		{ 0,0,0,1 } };
		//建構T23
		double s3 = sin(angle[i][2]);
		double c3 = cos(angle[i][2]);
		double T23[4][4] = { { c3,-s3,0,L23 },
		{ s3,c3,0,0 },
		{ 0,0,1,0 },
		{ 0,0,0,1 } };

		//建構T34
		double s4 = sin(angle[i][3]);
		double c4 = cos(angle[i][3]);
		double T34[4][4] = { { c4,-s4,0,L34a },
		{ 0,0,-1,-L34b },
		{ s4,c4,0,0 },
		{ 0,0,0,1 } };

		//建構T45
		double s5 = sin(angle[i][4]);
		double c5 = cos(angle[i][4]);
		double T45[4][4] = { { c5,-s5,0,0 },
		{ 0,0,1,0 },
		{ -s5,-c5,0,0 },
		{ 0,0,0,1 } };

		//建構T56
		double s6 = sin(angle[i][5]);
		double c6 = cos(angle[i][5]);
		double T56[4][4] = { { c6,-s6,0,0 },
		{ 0,0,-1,0 },
		{ s6,c6,0,0 },
		{ 0,0,0,1 } };
		
		//建構T06m
		double T06m[4][4] = { 0 };
		double T05m[4][4] = { 0 };
		double T04m[4][4] = { 0 };
		double T03m[4][4] = { 0 };
		double T02m[4][4] = { 0 };
		
		mul_matrix(&T02m[0][0], &T01[0][0], &T12[0][0], 4, 4, 4);
		mul_matrix(&T03m[0][0], &T02m[0][0], &T23[0][0], 4, 4, 4);
		mul_matrix(&T04m[0][0], &T03m[0][0], &T34[0][0], 4, 4, 4);
		mul_matrix(&T05m[0][0], &T04m[0][0], &T45[0][0], 4, 4, 4);
		mul_matrix(&T06m[0][0], &T05m[0][0], &T56[0][0], 4, 4, 4);
			   
		//t06已知，t06m使用計算
		double check0 = 0;
		double check1 = 0;
		double check2 = 0;
		double check3 = 0;
		//以角度算to6矩陣
		double to6mR1[3] = { T06m[0][0],T06m[1][0],T06m[2][0] };
		double to6R1[3] = { T_06[0][0],T_06[1][0],T_06[2][0] };

		double to6mR2[3] = { T06m[0][1],T06m[1][1],T06m[2][1] };
		double to6R2[3] = { T_06[0][1],T_06[1][1],T_06[2][1] };

		double to6mR3[3] = { T06m[0][2],T06m[1][2],T06m[2][2] };
		double to6R3[3] = { T_06[0][2],T_06[1][2],T_06[2][2] };

		double to6mxyz[3] = { T06m[0][3],T06m[1][3],T06m[2][3] };
		double to6xyz[3] = { T_06[0][3],T_06[1][3],T_06[2][3] };

		check0 = count_length(to6mR1, to6R1);
		check1 = count_length(to6mR2, to6R2);
		check2 = count_length(to6mR3, to6R3);
		check3 = count_length(to6mxyz, to6xyz);
		//如果手腕比肩膀手肘延長線低
		if (T04m[2][3] < (T03m[2][3]-0.0)/L23*(L23+L34b))
		{
			std::cout << "elbow can not higher than wrist" << std::endl;
			return -1;
		}
		//如果誤差<0.01
		if ((check0 + check1 + check2 + check3) < 0.01)
		{
			//找到最小的角度
			double P_human_normal[3] = { 0 };
			double P_robot_normal[3] = { 0 };
			
			double P_now_robot_elbow_normal[3] = { 0 };
			double diff_h_r[3] = { 0 };
			

			//人的手肘
			P_human_normal[0] = input[1][0];
			P_human_normal[1] = input[1][1];
			P_human_normal[2] = input[1][2];

			//機器手肘
			P_robot_normal[0] = T03m[0][3];
			P_robot_normal[1] = T03m[1][3];
			P_robot_normal[2] = T03m[2][3];
			
			//計算上次跟這次的角度差
			double square_last_dif = 0.0;
			for (int j = 0; j < 6; j++)
			{
				square_last_dif += (angle[i][j] - copy_bestangle[j])*(angle[i][j] - copy_bestangle[j]);
			}

			//得到兩向量相減
			minus_vector(diff_h_r, P_human_normal, P_robot_normal);

			//計算人手肘跟機器手肘的差
			square_dif = (diff_h_r[0] * diff_h_r[0] + diff_h_r[1] * diff_h_r[1] + diff_h_r[2] * diff_h_r[2]);
			
			//加上跟上一個手肘動作的差
			if (square_dif + square_last_dif * 1e3 <= min_square_dif)
			{
				min_square_dif = square_dif;
				min_number = i;
				return i;
			}

		}
	}
	return -1;
}