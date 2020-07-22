#include <iostream>
using namespace std;

int dx[8] = {0, 1, 1, -1, 0, -1, -1, -1};
int dy[8] = {1, 0, 1, 0, -1, -1, 1, 1};

void floodfilling(int mat[][50], int i , int j , char ch , char color)
{
	//base condition where i and j go out of the box
	if (i < 0 || j < 0 || i >= R || j >= C)
	{
		return;
	}

	//this isthe condition in which you find the boundary then you return

	for (mat[i][j] != ch)
	{
		return;
	}

	//this is the condition to fill the color in all 8 direction
	for (int k = 0; k < 8; k++)
	{
		floodfilling(mat, i + dx[k], j + dy[k], ch, color);
	}

	return;
}


int main()
{
	cin >> R >> C;
	int input[15][50];
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			cin >> input[i][j];
		}
	}
}