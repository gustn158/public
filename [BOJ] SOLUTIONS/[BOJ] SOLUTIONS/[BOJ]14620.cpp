/*
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int map[11][11];
int cache[11][11];
int dx[5] = { 0,-1,1,0,0 };
int dy[5] = { 0,0,0,-1,1 };
int minans = 987564321;
bool check[11][11];
bool pos(int x, int y)
{
	bool ret = true;
	for (int i = 0; i < 5; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		if (check[new_x][new_y])
			return false;
	}
	return true;
}
int hap(int x, int y)
{
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		sum += map[new_x][new_y];
	}
	return sum;
}
void make_check(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		check[new_x][new_y]= true;
	}
}
void del_check(int x, int y)
{
	for (int i = 0; i < 5; i++)
	{
		int new_x = x + dx[i];
		int new_y = y + dy[i];
		check[new_x][new_y] = false;
	}
}
void SLV(int cnt,int sum)
{
	if (cnt == 3)
	{
		minans = min(minans, sum);
		return;
	}
	for (int i = 2; i <= n - 1; i++)
	{
		for (int j = 2; j <= n - 1; j++)
		{
			if (pos(i, j))
			{
				make_check(i, j);
				int plus = hap(i, j);
				SLV(cnt + 1, sum +plus );	
				del_check(i, j);
			}
		}
	}
	return;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	SLV(0,0);
	cout << minans;
}
*/