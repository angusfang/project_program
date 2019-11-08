#pragma once

#include <cmath>

int solution(double T_06[4][4], double angle[64][6], double whattype[64][6])
{
	//number定義現在是第幾組解

		//共2^6組解，每次存6個角度
	int number = 0;
	double u = 0;
	double r11, r12, r13, x;
	double r21, r22, r23, y;
	double r31, r32, r33, z;
	double a1, a2, a3, a4, a5, a6;
	double t1, t2, t3, t4, t5, t6;
	r11 = T_06[0][0]; r12 = T_06[0][1]; r13 = T_06[0][2]; x = T_06[0][3];
	r21 = T_06[1][0]; r22 = T_06[1][1]; r23 = T_06[1][2]; y = T_06[1][3];
	r31 = T_06[2][0]; r32 = T_06[2][1]; r33 = T_06[2][2]; z = T_06[2][3];
	{

		//算a1
		for (int i1 = 0; i1 <= 1; i1++)
		{

			//a1公式
			if (i1 == 0)
			{
				t1 = 1;
				u = (y + pow((pow(x, 2) + pow(y, 2)), (0.5))) / x;
			}
			else if (i1 == 1)
			{
				t1 = 2;
				u = (y - pow((pow(x, 2) + pow(y, 2)), (0.5))) / x;
			}
			else
			{
				continue;
			}
			//存a1
			a1 = 2 * atan(u);


			//算a2
			for (int i2 = 0; i2 <= 1; i2++)
			{
				double s1, c1;
				s1 = sin(a1);
				c1 = cos(a1);
				if ((-1 * pow(L01, 4) + 4 * pow(L01, 3) * z - 2 * pow(L01, 2) * pow(L12, 2) + 4 * pow(L01, 2) * L12*c1*y - 4 * pow(L01, 2) * L12*s1*x + 2 * pow(L01, 2) * pow(L23, 2) + 2 * pow(L01, 2) * pow(L34a, 2) + 2 * pow(L01, 2) * pow(L34b, 2) - 2 * pow(L01, 2) * pow(c1, 2) * pow(y, 2) + 4 * pow(L01, 2) * c1*s1*x*y - 2 * pow(L01, 2) * pow(s1, 2) * pow(x, 2) - 6 * pow(L01, 2) * pow(z, 2) + 4 * L01*pow(L12, 2) * z - 8 * L01*L12*c1*y*z + 8 * L01*L12*s1*x*z - 4 * L01*pow(L23, 2) * z - 4 * L01*pow(L34a, 2) * z - 4 * L01*pow(L34b, 2) * z + 4 * L01*pow(c1, 2) * pow(y, 2) * z - 8 * L01*c1*s1*x*y*z + 4 * L01*pow(s1, 2) * pow(x, 2) * z + 4 * L01*pow(z, 3) - pow(L12, 4) + 4 * pow(L12, 3) * c1*y - 4 * pow(L12, 3) * s1*x + 2 * pow(L12, 2) * pow(L23, 2) + 2 * pow(L12, 2) * pow(L34a, 2) + 2 * pow(L12, 2) * pow(L34b, 2) - 6 * pow(L12, 2) * pow(c1, 2) * pow(y, 2) + 12 * pow(L12, 2) * c1*s1*x*y - 6 * pow(L12, 2) * pow(s1, 2) * pow(x, 2) - 2 * pow(L12, 2) * pow(z, 2) - 4 * L12*pow(L23, 2) * c1*y + 4 * L12*pow(L23, 2) * s1*x - 4 * L12*pow(L34a, 2) * c1*y + 4 * L12*pow(L34a, 2) * s1*x - 4 * L12*pow(L34b, 2) * c1*y + 4 * L12*pow(L34b, 2) * s1*x + 4 * L12*pow(c1, 3) * pow(y, 3) - 12 * L12*pow(c1, 2) * s1*x*pow(y, 2) + 12 * L12*c1*pow(s1, 2) * pow(x, 2) * y + 4 * L12*c1*y*pow(z, 2) - 4 * L12*pow(s1, 3) * pow(x, 3) - 4 * L12*s1*x*pow(z, 2) - pow(L23, 4) + 2 * pow(L23, 2) * pow(L34a, 2) + 2 * pow(L23, 2) * pow(L34b, 2) + 2 * pow(L23, 2) * pow(c1, 2) * pow(y, 2) - 4 * pow(L23, 2) * c1*s1*x*y + 2 * pow(L23, 2) * pow(s1, 2) * pow(x, 2) + 2 * pow(L23, 2) * pow(z, 2) - pow(L34a, 4) - 2 * pow(L34a, 2) * pow(L34b, 2) + 2 * pow(L34a, 2) * pow(c1, 2) * pow(y, 2) - 4 * pow(L34a, 2) * c1*s1*x*y + 2 * pow(L34a, 2) * pow(s1, 2) * pow(x, 2) + 2 * pow(L34a, 2) * pow(z, 2) - pow(L34b, 4) + 2 * pow(L34b, 2) * pow(c1, 2) * pow(y, 2) - 4 * pow(L34b, 2) * c1*s1*x*y + 2 * pow(L34b, 2) * pow(s1, 2) * pow(x, 2) + 2 * pow(L34b, 2) * pow(z, 2) - pow(c1, 4) * pow(y, 4) + 4 * pow(c1, 3) * s1*x*pow(y, 3) - 6 * pow(c1, 2) * pow(s1, 2) * pow(x, 2) * pow(y, 2) - 2 * pow(c1, 2) * pow(y, 2) * pow(z, 2) + 4 * c1*pow(s1, 3) * pow(x, 3) * y + 4 * c1*s1*x*y*pow(z, 2) - pow(s1, 4) * pow(x, 4) - 2 * pow(s1, 2) * pow(x, 2) * pow(z, 2) - pow(z, 4)) < 0)
				{
					//如果根號<0
					continue;
				}
				//a2公式
				if (i2 == 0)
				{
					t2 = 1;
					u = (pow((-1 * pow(L01, 4) + 4 * pow(L01, 3) * z - 2 * pow(L01, 2) * pow(L12, 2) + 4 * pow(L01, 2) * L12*c1*y - 4 * pow(L01, 2) * L12*s1*x + 2 * pow(L01, 2) * pow(L23, 2) + 2 * pow(L01, 2) * pow(L34a, 2) + 2 * pow(L01, 2) * pow(L34b, 2) - 2 * pow(L01, 2) * pow(c1, 2) * pow(y, 2) + 4 * pow(L01, 2) * c1*s1*x*y - 2 * pow(L01, 2) * pow(s1, 2) * pow(x, 2) - 6 * pow(L01, 2) * pow(z, 2) + 4 * L01*pow(L12, 2) * z - 8 * L01*L12*c1*y*z + 8 * L01*L12*s1*x*z - 4 * L01*pow(L23, 2) * z - 4 * L01*pow(L34a, 2) * z - 4 * L01*pow(L34b, 2) * z + 4 * L01*pow(c1, 2) * pow(y, 2) * z - 8 * L01*c1*s1*x*y*z + 4 * L01*pow(s1, 2) * pow(x, 2) * z + 4 * L01*pow(z, 3) - pow(L12, 4) + 4 * pow(L12, 3) * c1*y - 4 * pow(L12, 3) * s1*x + 2 * pow(L12, 2) * pow(L23, 2) + 2 * pow(L12, 2) * pow(L34a, 2) + 2 * pow(L12, 2) * pow(L34b, 2) - 6 * pow(L12, 2) * pow(c1, 2) * pow(y, 2) + 12 * pow(L12, 2) * c1*s1*x*y - 6 * pow(L12, 2) * pow(s1, 2) * pow(x, 2) - 2 * pow(L12, 2) * pow(z, 2) - 4 * L12*pow(L23, 2) * c1*y + 4 * L12*pow(L23, 2) * s1*x - 4 * L12*pow(L34a, 2) * c1*y + 4 * L12*pow(L34a, 2) * s1*x - 4 * L12*pow(L34b, 2) * c1*y + 4 * L12*pow(L34b, 2) * s1*x + 4 * L12*pow(c1, 3) * pow(y, 3) - 12 * L12*pow(c1, 2) * s1*x*pow(y, 2) + 12 * L12*c1*pow(s1, 2) * pow(x, 2) * y + 4 * L12*c1*y*pow(z, 2) - 4 * L12*pow(s1, 3) * pow(x, 3) - 4 * L12*s1*x*pow(z, 2) - pow(L23, 4) + 2 * pow(L23, 2) * pow(L34a, 2) + 2 * pow(L23, 2) * pow(L34b, 2) + 2 * pow(L23, 2) * pow(c1, 2) * pow(y, 2) - 4 * pow(L23, 2) * c1*s1*x*y + 2 * pow(L23, 2) * pow(s1, 2) * pow(x, 2) + 2 * pow(L23, 2) * pow(z, 2) - pow(L34a, 4) - 2 * pow(L34a, 2) * pow(L34b, 2) + 2 * pow(L34a, 2) * pow(c1, 2) * pow(y, 2) - 4 * pow(L34a, 2) * c1*s1*x*y + 2 * pow(L34a, 2) * pow(s1, 2) * pow(x, 2) + 2 * pow(L34a, 2) * pow(z, 2) - pow(L34b, 4) + 2 * pow(L34b, 2) * pow(c1, 2) * pow(y, 2) - 4 * pow(L34b, 2) * c1*s1*x*y + 2 * pow(L34b, 2) * pow(s1, 2) * pow(x, 2) + 2 * pow(L34b, 2) * pow(z, 2) - pow(c1, 4) * pow(y, 4) + 4 * pow(c1, 3) * s1*x*pow(y, 3) - 6 * pow(c1, 2) * pow(s1, 2) * pow(x, 2) * pow(y, 2) - 2 * pow(c1, 2) * pow(y, 2) * pow(z, 2) + 4 * c1*pow(s1, 3) * pow(x, 3) * y + 4 * c1*s1*x*y*pow(z, 2) - pow(s1, 4) * pow(x, 4) - 2 * pow(s1, 2) * pow(x, 2) * pow(z, 2) - pow(z, 4)), (0.5)) + 2 * L12*L23 - 2 * L23*c1*y + 2 * L23*s1*x) / (pow(L01, 2) - 2 * L01*L23 - 2 * L01*z + pow(L12, 2) - 2 * L12*c1*y + 2 * L12*s1*x + pow(L23, 2) + 2 * L23*z - pow(L34a, 2) - pow(L34b, 2) + pow(c1, 2) * pow(y, 2) - 2 * c1*s1*x*y + pow(s1, 2) * pow(x, 2) + pow(z, 2));
				}
				else if (i2 == 1)
				{
					t2 = 2;
					u = -(pow((-1 * pow(L01, 4) + 4 * pow(L01, 3) * z - 2 * pow(L01, 2) * pow(L12, 2) + 4 * pow(L01, 2) * L12*c1*y - 4 * pow(L01, 2) * L12*s1*x + 2 * pow(L01, 2) * pow(L23, 2) + 2 * pow(L01, 2) * pow(L34a, 2) + 2 * pow(L01, 2) * pow(L34b, 2) - 2 * pow(L01, 2) * pow(c1, 2) * pow(y, 2) + 4 * pow(L01, 2) * c1*s1*x*y - 2 * pow(L01, 2) * pow(s1, 2) * pow(x, 2) - 6 * pow(L01, 2) * pow(z, 2) + 4 * L01*pow(L12, 2) * z - 8 * L01*L12*c1*y*z + 8 * L01*L12*s1*x*z - 4 * L01*pow(L23, 2) * z - 4 * L01*pow(L34a, 2) * z - 4 * L01*pow(L34b, 2) * z + 4 * L01*pow(c1, 2) * pow(y, 2) * z - 8 * L01*c1*s1*x*y*z + 4 * L01*pow(s1, 2) * pow(x, 2) * z + 4 * L01*pow(z, 3) - pow(L12, 4) + 4 * pow(L12, 3) * c1*y - 4 * pow(L12, 3) * s1*x + 2 * pow(L12, 2) * pow(L23, 2) + 2 * pow(L12, 2) * pow(L34a, 2) + 2 * pow(L12, 2) * pow(L34b, 2) - 6 * pow(L12, 2) * pow(c1, 2) * pow(y, 2) + 12 * pow(L12, 2) * c1*s1*x*y - 6 * pow(L12, 2) * pow(s1, 2) * pow(x, 2) - 2 * pow(L12, 2) * pow(z, 2) - 4 * L12*pow(L23, 2) * c1*y + 4 * L12*pow(L23, 2) * s1*x - 4 * L12*pow(L34a, 2) * c1*y + 4 * L12*pow(L34a, 2) * s1*x - 4 * L12*pow(L34b, 2) * c1*y + 4 * L12*pow(L34b, 2) * s1*x + 4 * L12*pow(c1, 3) * pow(y, 3) - 12 * L12*pow(c1, 2) * s1*x*pow(y, 2) + 12 * L12*c1*pow(s1, 2) * pow(x, 2) * y + 4 * L12*c1*y*pow(z, 2) - 4 * L12*pow(s1, 3) * pow(x, 3) - 4 * L12*s1*x*pow(z, 2) - pow(L23, 4) + 2 * pow(L23, 2) * pow(L34a, 2) + 2 * pow(L23, 2) * pow(L34b, 2) + 2 * pow(L23, 2) * pow(c1, 2) * pow(y, 2) - 4 * pow(L23, 2) * c1*s1*x*y + 2 * pow(L23, 2) * pow(s1, 2) * pow(x, 2) + 2 * pow(L23, 2) * pow(z, 2) - pow(L34a, 4) - 2 * pow(L34a, 2) * pow(L34b, 2) + 2 * pow(L34a, 2) * pow(c1, 2) * pow(y, 2) - 4 * pow(L34a, 2) * c1*s1*x*y + 2 * pow(L34a, 2) * pow(s1, 2) * pow(x, 2) + 2 * pow(L34a, 2) * pow(z, 2) - pow(L34b, 4) + 2 * pow(L34b, 2) * pow(c1, 2) * pow(y, 2) - 4 * pow(L34b, 2) * c1*s1*x*y + 2 * pow(L34b, 2) * pow(s1, 2) * pow(x, 2) + 2 * pow(L34b, 2) * pow(z, 2) - pow(c1, 4) * pow(y, 4) + 4 * pow(c1, 3) * s1*x*pow(y, 3) - 6 * pow(c1, 2) * pow(s1, 2) * pow(x, 2) * pow(y, 2) - 2 * pow(c1, 2) * pow(y, 2) * pow(z, 2) + 4 * c1*pow(s1, 3) * pow(x, 3) * y + 4 * c1*s1*x*y*pow(z, 2) - pow(s1, 4) * pow(x, 4) - 2 * pow(s1, 2) * pow(x, 2) * pow(z, 2) - pow(z, 4)), (0.5)) - 2 * L12*L23 + 2 * L23*c1*y - 2 * L23*s1*x) / (pow(L01, 2) - 2 * L01*L23 - 2 * L01*z + pow(L12, 2) - 2 * L12*c1*y + 2 * L12*s1*x + pow(L23, 2) + 2 * L23*z - pow(L34a, 2) - pow(L34b, 2) + pow(c1, 2) * pow(y, 2) - 2 * c1*s1*x*y + pow(s1, 2) * pow(x, 2) + pow(z, 2));
				}
				else
				{
					continue;
				}
				//存a2

				a2 = 2 * atan(u);


				//算a3
				for (int i3 = 0; i3 <= 1; i3++)
				{
					double s2, c2;
					s2 = sin(a2);
					c2 = cos(a2);


					if ((-pow(L12, 2) + 2 * L12*L23*s2 + 2 * L12*c1*y - 2 * L12*s1*x - pow(L23, 2) * pow(s2, 2) - 2 * L23*c1*s2*y + 2 * L23*s1*s2*x + pow(L34a, 2) * pow(c2, 2) + pow(L34a, 2) * pow(s2, 2) + pow(L34b, 2) * pow(c2, 2) + pow(L34b, 2) * pow(s2, 2) - pow(c1, 2) * pow(y, 2) + 2 * c1*s1*x*y - pow(s1, 2) * pow(x, 2)) < 0)
					{
						//如果根號<0
						continue;
					}

					//a3公式	
					if (i3 == 0)
					{
						t3 = 1;
						u = (L34a*c2 + L34b * s2 + pow((-pow(L12, 2) + 2 * L12*L23*s2 + 2 * L12*c1*y - 2 * L12*s1*x - pow(L23, 2) * pow(s2, 2) - 2 * L23*c1*s2*y + 2 * L23*s1*s2*x + pow(L34a, 2) * pow(c2, 2) + pow(L34a, 2) * pow(s2, 2) + pow(L34b, 2) * pow(c2, 2) + pow(L34b, 2) * pow(s2, 2) - pow(c1, 2) * pow(y, 2) + 2 * c1*s1*x*y - pow(s1, 2) * pow(x, 2)), (0.5))) / (L12 - L34b * c2 - L23 * s2 + L34a * s2 - c1 * y + s1 * x);
					}
					else if (i3 == 1)
					{
						t3 = 2;
						u = (L34a*c2 + L34b * s2 - pow((-pow(L12, 2) + 2 * L12*L23*s2 + 2 * L12*c1*y - 2 * L12*s1*x - pow(L23, 2) * pow(s2, 2) - 2 * L23*c1*s2*y + 2 * L23*s1*s2*x + pow(L34a, 2) * pow(c2, 2) + pow(L34a, 2) * pow(s2, 2) + pow(L34b, 2) * pow(c2, 2) + pow(L34b, 2) * pow(s2, 2) - pow(c1, 2) * pow(y, 2) + 2 * c1*s1*x*y - pow(s1, 2) * pow(x, 2)), (0.5))) / (L12 - L34b * c2 - L23 * s2 + L34a * s2 - c1 * y + s1 * x);
					}
					else
					{
						continue;
					}
					//存a3
					a3 = 2 * atan(u);


					//算a5
					for (int i5 = 0; i5 <= 1; i5++)
					{
						double s3, c3;
						s3 = sin(a3);
						c3 = cos(a3);

						if ((-(c2*r33*s3 + c3 * r33*s2 - c2 * c3*r13*s1 - c1 * r23*s2*s3 + r13 * s1*s2*s3 + c1 * c2*c3*r23 - 1) / (c2*r33*s3 + c3 * r33*s2 - c2 * c3*r13*s1 - c1 * r23*s2*s3 + r13 * s1*s2*s3 + c1 * c2*c3*r23 + 1)) < 0)
						{
							//如果根號<0
							continue;
						}
						//a5公式
						if (i5 == 0)
						{
							t5 = 1;
							u = pow((-(c2*r33*s3 + c3 * r33*s2 - c2 * c3*r13*s1 - c1 * r23*s2*s3 + r13 * s1*s2*s3 + c1 * c2*c3*r23 - 1) / (c2*r33*s3 + c3 * r33*s2 - c2 * c3*r13*s1 - c1 * r23*s2*s3 + r13 * s1*s2*s3 + c1 * c2*c3*r23 + 1)), (0.5));
						}
						else if (i5 == 1)
						{
							t5 = 2;
							u = -pow((-(c2*r33*s3 + c3 * r33*s2 - c2 * c3*r13*s1 - c1 * r23*s2*s3 + r13 * s1*s2*s3 + c1 * c2*c3*r23 - 1) / (c2*r33*s3 + c3 * r33*s2 - c2 * c3*r13*s1 - c1 * r23*s2*s3 + r13 * s1*s2*s3 + c1 * c2*c3*r23 + 1)), (0.5));
						}
						else
						{
							continue;
						}
						//存a5
						a5 = 2 * atan(u);



						//算a4
						for (int i4 = 0; i4 <= 1; i4++)
						{
							double s5, c5;
							s5 = sin(a5);
							c5 = cos(a5);

							if ((-(s5 + c1 * r13 + r23 * s1)*(c1*r13 - s5 + r23 * s1)) < 0)
							{
								//如果根號<0
								continue;
							}

							//a4公式
							if (i4 == 0)
							{
								t4 = 1;
								u = (s5 + pow((-(s5 + c1 * r13 + r23 * s1)*(c1*r13 - s5 + r23 * s1)), (0.5))) / (c1*r13 + r23 * s1);
							}
							else if (i4 == 1)
							{
								t4 = 2;
								u = (s5 - pow((-(s5 + c1 * r13 + r23 * s1)*(c1*r13 - s5 + r23 * s1)), (0.5))) / (c1*r13 + r23 * s1);
							}
							else
							{
								continue;
							}
							//存a4
							a4 = 2 * atan(u);


							//算a6
							for (int i6 = 0; i6 <= 1; i6++)
							{
								double s4, c4;
								s4 = sin(a4);
								c4 = cos(a4);

								if ((-pow(c1, 2) * pow(c5, 2) * pow(r13, 2) + pow(c1, 2) * pow(r11, 2) * pow(s5, 2) + pow(c1, 2) * pow(r12, 2) * pow(s5, 2) - 2 * c1*pow(c5, 2) * r13*r23*s1 + 2 * c1*r11*r21*s1*pow(s5, 2) + 2 * c1*r12*r22*s1*pow(s5, 2) - pow(c5, 2) * pow(r23, 2) * pow(s1, 2) + pow(r21, 2) * pow(s1, 2) * pow(s5, 2) + pow(r22, 2) * pow(s1, 2) * pow(s5, 2)) < 0)
								{
									//如果根號<0
									continue;
								}
								//a6公式
								if (i6 == 0)
								{
									t6 = 1;
									u = -(pow((-pow(c1, 2) * pow(c5, 2) * pow(r13, 2) + pow(c1, 2) * pow(r11, 2) * pow(s5, 2) + pow(c1, 2) * pow(r12, 2) * pow(s5, 2) - 2 * c1*pow(c5, 2) * r13*r23*s1 + 2 * c1*r11*r21*s1*pow(s5, 2) + 2 * c1*r12*r22*s1*pow(s5, 2) - pow(c5, 2) * pow(r23, 2) * pow(s1, 2) + pow(r21, 2) * pow(s1, 2) * pow(s5, 2) + pow(r22, 2) * pow(s1, 2) * pow(s5, 2)), (0.5)) + c1 * r12*s5 + r22 * s1*s5) / (c1*c5*r13 + c1 * r11*s5 + c5 * r23*s1 + r21 * s1*s5);
								}
								else if (i6 == 1)
								{
									t6 = 2;
									u = -(c1*r12*s5 - pow((-pow(c1, 2) * pow(c5, 2) * pow(r13, 2) + pow(c1, 2) * pow(r11, 2) * pow(s5, 2) + pow(c1, 2) * pow(r12, 2) * pow(s5, 2) - 2 * c1*pow(c5, 2) * r13*r23*s1 + 2 * c1*r11*r21*s1*pow(s5, 2) + 2 * c1*r12*r22*s1*pow(s5, 2) - pow(c5, 2) * pow(r23, 2) * pow(s1, 2) + pow(r21, 2) * pow(s1, 2) * pow(s5, 2) + pow(r22, 2) * pow(s1, 2) * pow(s5, 2)), (0.5)) + r22 * s1*s5) / (c1*c5*r13 + c1 * r11*s5 + c5 * r23*s1 + r21 * s1*s5);
								}
								else
								{
									continue;
								}
								//存a6
								a6 = 2 * atan(u);

								if (a1 > 100)
									continue;
								if (a2 > 100)
									continue;
								if (a3 > 100)
									continue;
								if (a4 > 100)
									continue;
								if (a5 > 100)
									continue;
								if (a6 > 100)
									continue;

								angle[number][0] = a1;
								angle[number][1] = a2;
								angle[number][2] = a3;
								angle[number][3] = a4;
								angle[number][4] = a5;
								angle[number][5] = a6;
								whattype[number][0] = t1;
								whattype[number][1] = t2;
								whattype[number][2] = t3;
								whattype[number][3] = t4;
								whattype[number][4] = t5;
								whattype[number][5] = t6;

								number++;
							}
						}
					}
				}
			}
		}


	}
	return number;
}