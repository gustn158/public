/*
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
int map[6][10];
bool check[13];
vector <pair<int, int>> v;
int x_cnt;
void Print()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			if (map[i][j] == -1)
				cout << '.';
			else
			{
				cout << (char)('A' + map[i][j] - 1);
			}
		}
		cout << "\n";
	}
}
bool CAL()
{
	if ((map[1][5] + map[2][4] + map[3][3] + map[4][2]) != 26) return false;
	if ((map[2][2] + map[2][4] + map[2][6] + map[2][8]) != 26) return false;
	if ((map[1][5] + map[2][6] + map[3][7] + map[4][8]) != 26)return false;
	if ((map[4][2] + map[4][4] + map[4][6] + map[4][8]) != 26) return false;
	if ((map[2][2] + map[3][3] + map[4][4] + map[5][5]) != 26)return false;
	if ((map[5][5] + map[4][6] + map[3][7] + map[2][8]) != 26) return false;

	return true;
}
void Dfs(int idx , int cnt)
{
	if (cnt == x_cnt)
	{
		if (CAL())
		{
			Print();
			exit(0);
		}
			return;
	}
	for (int i = 1; i <= 12; i++)
	{
		if (check[i])
			continue;
		check[i] = true;
		map[v[idx].first][v[idx].second] = (i);
		Dfs(idx + 1, cnt + 1);
		check[i] = false;
		map[v[idx].first][v[idx].second] = 0;
	}
}
int main()

{
	
	for (int i = 1; i <= 5; i++)
	{
		string s;
		cin >> s;
		for (int j = 1; j <= 9; j++)
		{
			if ('A' <= s[j - 1] && s[j - 1] <= 'L')
			{
				map[i][j] = (int)s[j - 1] - 65 + 1;
				check[map[i][j]] = true;
			}
			if (s[j - 1] == 'x')
			{
				map[i][j] = 0;
				v.push_back({ i,j });
				x_cnt++;
			}
			if (s[j - 1] == '.')
				map[i][j] = -1;
		}
	}
	Dfs(0, 0);

	return 0;

}
*/