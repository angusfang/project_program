#pragma once
#include "matrix_function.h"
#include "robot_argument.h"

void to_robot_size(double input[6][3])
{
	//��è��y
	double h2 = 0;
	//��y��ӻH
	double h1 = 0;

	h2 = count_length(input[2], input[1]);
	h1 = count_length(input[1], input[0]);
	//�������`�Ʀ�1������

	//������è��y
	double R_h2 = 0;
	//������y��ӻH
	double R_h1 = 0;

	R_h2 = pow(L34b*L34b + L34a * L34a, 0.5);
	R_h1 = L23;
	//�x�s���ӭn�������V�q
	double vertex[3] = { 0 };
	double store_p[3] = { 0 };
	//��j�⪺�j�p�������@��
	for (int i = 0; i < 3; i++)
	{
		//��ӻH���y�ܦ���������u�@��
		store_p[i] = input[1][i];
		input[1][i] = input[1][i] * (R_h1 / h1);
		vertex[i] = input[1][i] - store_p[i];
		input[2][i] = input[2][i] + vertex[i];
		input[3][i] = input[3][i] + vertex[i];
		input[4][i] = input[4][i] + vertex[i];
		input[5][i] = input[5][i] + vertex[i];

		//���y�����ܦ���������u�@��
		store_p[i] = input[2][i];
		input[2][i] = (input[2][i] - input[1][i]) * (R_h2 / h2) + input[1][i];
		vertex[i] = input[2][i] - store_p[i];
		input[3][i] = input[3][i] + vertex[i];
		input[4][i] = input[4][i] + vertex[i];
		input[5][i] = input[5][i] + vertex[i];

	}

}
