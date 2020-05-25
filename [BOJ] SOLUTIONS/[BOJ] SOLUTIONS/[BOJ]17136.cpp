/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int INF = 987564321;
int map[10][10];
int left_pp[6] = { 0,5,5,5,5,5 };
int ret;
int cnt = 0;
void SLV(int x, int y)
{
	if (y == 10)
	{
		SLV(x + 1, 0);
		return;
	}
	if (x == 10)
	{
		ret = min(ret, cnt);
		return;
	}
	if (map[x][y] == 0)
	{
		SLV(x, y + 1);
		return;
	}
	for (int len = 5; len >= 1; len--)
	{
		if (left_pp[len] == 0 || x + len > 10 || y + len > 10)
			continue;

		bool check = true;
		for (int a = 0; a < len; a++)
		{
			for (int b = 0; b < len; b++)
			{
				if (map[x + a][y + b] == 0)
				{
					check = false;
					break;
				}
			}
			if (check == false)
				break;
		}
		if (check == false)
			continue;

		for (int a = 0; a < len; a++)
		{
			for (int b = 0; b < len; b++)
			{
				map[x + a][y + b] = 0;
			}
	
		}
		left_pp[len]--;
		cnt++;
		SLV(x, y + len);
		for (int a = 0; a < len; a++)
		{
			for (int b = 0; b < len; b++)
			{
				map[x + a][y + b] = 1;
			}

		}
		left_pp[len] ++;
		cnt--;
	}
}
int main()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			cin >> map[i][j];
	ret = INF;
	SLV(0, 0);
	if (ret == INF)
	{
		cout << -1;
	}
	else
		cout << ret;

	
}
*/