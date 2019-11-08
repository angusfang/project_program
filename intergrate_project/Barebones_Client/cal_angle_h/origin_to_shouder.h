#pragma once
void origin_to_shouder(double input[6][3])
{
	for (int i = 1; i < 6; i++)
		for (int j = 0; j < 3; j++)
			input[i][j] = input[i][j] - input[0][j];
	for (int i = 0; i < 3; i++)
		input[0][i] = 0;
}