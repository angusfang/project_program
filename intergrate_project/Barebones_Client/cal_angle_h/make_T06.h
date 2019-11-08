#pragma once
#include "matrix_function.h"

void make_T06(double input[6][3], double T_06[4][4])
{
	//x_54_0為 (手指扣掉手掌)以0座標系當參考
	double x_54_0[3] = { 0 };
	double y_54_0[3] = { 0 };
	double z_54_0[3] = { 0 };
	double ans[3] = { 0 };

	//為了方便舊版寫法做轉換
	double p1_0[4][1];
	double p2_0[4][1];
	double p3_0[4][1];
	double p4_0[4][1];
	double p5_0[4][1];
	double p6_0[4][1];

	p1_0[3][0] = 1;
	p2_0[3][0] = 1;
	p3_0[3][0] = 1;
	p4_0[3][0] = 1;
	p5_0[3][0] = 1;
	p6_0[3][0] = 1;


	for (int i = 0; i < 3; i++)
	{
		p1_0[i][0] = input[0][i];
		p2_0[i][0] = input[1][i];
		p3_0[i][0] = input[2][i];
		p4_0[i][0] = input[3][i];
		p5_0[i][0] = input[4][i];
		p6_0[i][0] = input[5][i];

	}

	{
		//z_54_0=p5_0-p4_0
		minus_vector(z_54_0, &p5_0[0][0], &p4_0[0][0]);
		unit_vector(z_54_0);

		//ans=p6_0-p4_0
		//x_54_0= z_54_0 (cross) ans
		minus_vector(ans, &p6_0[0][0], &p4_0[0][0]);
		unit_vector(ans);
		cross_product(x_54_0, z_54_0, ans);
		unit_vector(x_54_0);

		//y_54_0= z_54_0 (cross) y_54_0
		cross_product(y_54_0, z_54_0, x_54_0);
		unit_vector(y_54_0);
	}

	double R_0_54[3][3] = { { x_54_0[0], y_54_0[0],z_54_0[0] },
	{ x_54_0[1], y_54_0[1],z_54_0[1] },
	{ x_54_0[2], y_54_0[2],z_54_0[2] } };
	/*double ans1[3][3] = { 0 };*/
	/*mul_matrix(&ans1[0][0], &Ry[0][0], &Rz[0][0], 3, 3, 3);
	mul_matrix(&R_0_54[0][0], &ans1[0][0], &Rx[0][0], 3, 3, 3);*/

	//Transfunction {6}相對於{0}
	//建構T_06
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			T_06[i][j] = R_0_54[i][j];
		}
	}
	for (int i = 0; i < 3; i++)
	{
		T_06[i][3] = p3_0[i][0];
	}
	for (int j = 0; j < 3; j++)
	{
		T_06[3][j] = 0;
	}
	T_06[3][3] = 1;
}