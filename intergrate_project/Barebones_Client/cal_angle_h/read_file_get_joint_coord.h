#pragma once

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool read_file_get_joint_coord(ifstream &in, double* p1, double* p2, double* p3, double* p4, double* p5, double* p6)
{
	//讀取座標檔案

	string inputStr;
	string Str2Double;
	double pt1[3], pt2[3], pt3[3], pt4[3], pt5[3], pt6[3];

	//a,b,c,d為關鍵字的位置
	int a, b, c, d;
	double x, y, z;

	//處理字串為座標
	//檔案第一行無用
	getline(in, inputStr);
	if (inputStr == "")
		return false;
	cout << inputStr<<endl;
	//肩膀
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//確定關鍵字位置
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//藉由關鍵字取出數值
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}

		//肩膀座標
		pt1[0] = x; pt1[1] = y; pt1[2] = z;
	}
	//手肘
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//確定關鍵字位置
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//藉由關鍵字取出數值
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}
		//手肘座標
		pt2[0] = x; pt2[1] = y; pt2[2] = z;
	}
	//手腕
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//確定關鍵字位置
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//藉由關鍵字取出數值
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}
		//手腕座標
		pt3[0] = x; pt3[1] = y; pt3[2] = z;
	}
	//手掌
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//確定關鍵字位置
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//藉由關鍵字取出數值
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}
		//手腕座標
		pt4[0] = x; pt4[1] = y; pt4[2] = z;
	}
	//食指
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//確定關鍵字位置
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//藉由關鍵字取出數值
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}
		//手腕座標
		pt5[0] = x; pt5[1] = y; pt5[2] = z;
	}
	//拇指
	{
		getline(in, inputStr);
		if (inputStr != "")
		{
			//確定關鍵字位置
			a = inputStr.find("X", 0);
			b = inputStr.find("Y", 0);
			c = inputStr.find("Z", 0);
			d = inputStr.find("P", 0);
			//藉由關鍵字取出數值
			x = stod(Str2Double.assign(inputStr, a + 1, b - a - 1));
			y = stod(Str2Double.assign(inputStr, b + 1, c - b - 1));
			z = stod(Str2Double.assign(inputStr, c + 1, d - c - 1));
		}
		else
		{
			return false;
		}
		//手腕座標
		pt6[0] = x; pt6[1] = y; pt6[2] = z;
	}

	//如果前面都沒有失敗才會傳回主程式
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