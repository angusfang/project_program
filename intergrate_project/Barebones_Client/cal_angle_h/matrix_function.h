#pragma once
#ifndef matrix_function_h
#define matrix_function_h

#include <iostream>

//表示矩陣C=A*B a:A的row b:A的column,B的row c:b的column
//example:mul_matrix(&Minus_P_RK_ORG[0][0], &R_KR_T[0][0], &P_KR_ORG[0][0], 3, 3, 1);
void mul_matrix(double* C, double* A, double* B, int a, int b, int c)
{
	//歸零
	for (int i = 1; i <= a; i++)
	{
		for (int k = 1; k <= c; k++)
		{
			//C[i][k]=A[i][0]*B[0][k]+A[i][1]*B[2][k]+...A[i][j]*B[j][k]+...A[i][b]*B[b][k]
			*(C + (i - 1)*c + k - 1) = 0;
		}

	}
	//矩陣乘法
	for (int i = 1; i <= a; i++)
	{
		for (int k = 1; k <= c; k++)
		{
			for (int j = 1; j <= b; j++)
			{
				//C[i][k]=A[i][0]*B[0][k]+A[i][1]*B[2][k]+...A[i][j]*B[j][k]+...A[i][b]*B[b][k]
				*(C + (i - 1)*c + k - 1) += (*(A + (i - 1)*b + j - 1))*(*(B + (j - 1)*c + k - 1));
			}
		}

	}
}

//顯示座標
void display_coord(double* p)
{
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		std::cout << p[i] << " ";
	}
	std::cout << std::endl;
}

//顯示6座標
void display_6_coord(double p[6][3])
{
	for (int i = 0; i < 6; i++)
	{	
		for (int j = 0; j < 3; j++)
		{
			std::cout << p[i][j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

//計算距離 a,b皆為長度3向量
double count_length(double* a, double* b)
{
	return sqrt((a[0] - b[0])*(a[0] - b[0]) + (a[1] - b[1])*(a[1] - b[1]) + (a[2] - b[2])*(a[2] - b[2]));

}

//正常化座標
void normal_coord(double* p, double L)
{
	p[0] = p[0] / L;
	p[1] = p[1] / L;
	p[2] = p[2] / L;
}

//向量單位化
void unit_vector(double* p)
{
	double l = 0;
	l = sqrt(p[0] * p[0] + p[1] * p[1] + p[2] * p[2]);
	p[0] = p[0] / l;
	p[1] = p[1] / l;
	p[2] = p[2] / l;
}

//兩向量相減 A=B-C
void minus_vector(double* A, double* B, double* C)
{
	for (int i = 0; i < 3; i++)
	{
		A[i] = B[i] - C[i];
	}
}

//兩向量外積 A=B X C
void cross_product(double* A, double* B, double* C)
{
	A[0] = B[1] * C[2] - B[2] * C[1];
	A[1] = -1 * (B[0] * C[2] - B[2] * C[0]);
	A[2] = B[0] * C[1] - B[1] * C[0];
}

//把矩陣A[3]轉成B[4][1]
void matrix_S_3_41(double* A, double* B)
{
	*B = *A;
	*(B + 1) = *(A + 1);
	*(B + 2) = *(A + 2);
	*(B + 3) = 1;
}

//沿著z旋轉a角度
void rotation_z(double* Rz, double a)
{
	Rz[0] = cos(a); Rz[1] = -1 * sin(a); Rz[2] = 0;
	Rz[3] = sin(a); Rz[4] = cos(a); Rz[5] = 0;
	Rz[6] = 0; Rz[7] = 0; Rz[8] = 1;
}

//沿著y旋轉a角度
void rotation_y(double* Ry, double a)
{
	Ry[0] = cos(a); Ry[1] = 0; Ry[2] = sin(a);
	Ry[3] = 0; Ry[4] = 1; Ry[5] = 0;
	Ry[6] = -1 * sin(a); Ry[7] = 0; Ry[8] = cos(a);
}

//沿著x旋轉a角度
void rotation_x(double* Rx, double a)
{
	Rx[0] = 1; Rx[1] = 0; Rx[2] = 0;
	Rx[3] = 0; Rx[4] = cos(a); Rx[5] = -1 * sin(a);
	Rx[6] = 0; Rx[7] = sin(a); Rx[8] = cos(a);
}



#endif matrix_function_h

