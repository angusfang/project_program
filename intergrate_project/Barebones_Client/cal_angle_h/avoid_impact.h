#pragma once

bool Big_angle_change(const double angle1[6], double angle2[6])
{
	for (int i = 0; i < 6; i++)
	{	
		if ((angle1[0] - angle2[0])*(angle1[0] - angle2[0]) >= (3.1415926 / 2.0)*(3.1415926 / 2.0))//if degree different over 90 degree
		{
			return true;
		}
	}
	return false; 
}

int avoid_impact(int best_set,double input[6][3],const double angle[64][6], double copy_bestangle[6], double T06[4][4])
{
	if (input[1][2] < -20000000)
	{
		best_set = -1;
		//std::cout << "avoid elbow impact to table" << std::endl;
	}
	if (input[2][2] < -10000000)
	{
		best_set = -1;
		//std::cout << "avoid hand impact to table" << std::endl;
	}
	/*if ((angle[best_set][0]>-110.0/180.0*3.14)&&( angle[best_set][0]<110.0/180.0*3.14))
	{
		best_set = -1;
		std::cout << "avoid strange pose" << std::endl;
	}*/
	if (Big_angle_change(angle[best_set], copy_bestangle))
	{
		//best_set = -1;
		//std::cout << "avoid big degree change" << std::endl;
	}

	

	return best_set;
}