#pragma once
void correct_angle(double& angle)
{
	
		while (angle < (-180 / 180.0*3.14))
		{
			angle += (360 / 180.0*3.14);
		}
		while (angle > (180 / 180.0*3.14))
		{
			angle -= (360 / 180.0*3.14);
		}

}

void correct_negative_plus_360(double& angle)
{

	angle = angle -(10.0/180.0)*3.1415926  ;
	if (angle < 0)
	{
		angle = angle + 2 * 3.1415926;
	}

	if (angle > (110 + 90)*3.14 / 180.0)
	{
		angle = (110 + 90)*3.14 / 180.0;
	}

	if (angle < (110 - 45)*3.14 / 180.0)
	{
		angle = (110 - 45)*3.14 / 180.0;
	}
	
}

void set_output(double angle[64][6],int best_set, double output[6],double copyangle[6])
{


	
	if (angle[best_set][0] < (91.0 / 180.0*3.14) && angle[best_set][0] > (-141.0 / 180.0*3.14))
	{
		best_set = -1;
	}



	if (best_set == -1)
	{
		for (int i = 0; i < 6; i++)
			
			output[i] = copyangle[i]*(180.0)/3.1415926;
	}
	else
	{
		for (int i = 0; i < 6; i++)
		{
			//correct angle
			angle[best_set][0] = angle[best_set][0] + 180 / 180.0*3.14;
			
			angle[best_set][3] = angle[best_set][3] + 100 / 180.0*3.14;
			
			correct_angle(angle[best_set][0]);
			correct_angle(angle[best_set][3]);
			correct_negative_plus_360(angle[best_set][5]);
			output[i] = angle[best_set][i] * (180.0) / 3.1415926;//to angle
		}
	}
	
	if (best_set == -1)
	{
		for (int i = 0; i < 6; i++)
			output[i] = copyangle[i] * (180.0) / 3.1415926;
	}

	
	for (int i = 0; i < 6;i++) 
	{
		copyangle[i] = output[i]*3.1415926/180.0;
	}
	
}