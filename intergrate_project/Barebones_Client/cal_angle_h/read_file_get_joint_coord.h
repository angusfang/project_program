#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool read_file_get_joint_coord(ifstream &in, double* p1, double* p2, double* p3, double* p4, double* p5, double* p6)
{
	//Ū���y���ɮ�

	string inputStr;
	string Str2Double;
	double pt1[3], pt2[3], pt3[3], pt4[3], pt5[3], pt6[3];

	//a,b,c,d������r����m
	int a, b, c, d;
	double x, y, z;

	//�B�z�r�ꬰ�y��
	//�ɮײĤ@��L��
	getline(in, inputStr);
	if (inputStr == "")
		return false;
	cout << inputStr<<endl;
	//�ӻH
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//�T�w����r��m
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//�ǥ�����r���X�ƭ�
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}

		//�ӻH�y��
		pt1[0] = x; pt1[1] = y; pt1[2] = z;
	}
	//��y
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//�T�w����r��m
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//�ǥ�����r���X�ƭ�
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}
		//��y�y��
		pt2[0] = x; pt2[1] = y; pt2[2] = z;
	}
	//���
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//�T�w����r��m
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//�ǥ�����r���X�ƭ�
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}
		//��îy��
		pt3[0] = x; pt3[1] = y; pt3[2] = z;
	}
	//��x
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//�T�w����r��m
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//�ǥ�����r���X�ƭ�
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}
		//��îy��
		pt4[0] = x; pt4[1] = y; pt4[2] = z;
	}
	//����
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//�T�w����r��m
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//�ǥ�����r���X�ƭ�
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}
		//��îy��
		pt5[0] = x; pt5[1] = y; pt5[2] = z;
	}
	//���
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//�T�w����r��m
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//�ǥ�����r���X�ƭ�
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}
		//��îy��
		pt6[0] = x; pt6[1] = y; pt6[2] = z;
	}

	//�p�G�e�����S�����Ѥ~�|�Ǧ^�D�{��
	for (int i = 0; i < 3; i++)
	{
		p1[i] = pt1[i];
		p2[i] = pt2[i];
		p3[i] = pt3[i];
		p4[i] = pt4[i];
		p5[i] = pt5[i];
		p6[i] = pt6[i];
	}

	return true;
}