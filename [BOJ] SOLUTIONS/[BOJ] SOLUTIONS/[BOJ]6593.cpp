/*

당신은 상범 빌딩에 갇히고 말았다. 여기서 탈출하는 가장 빠른 길은 무엇일까? 상범 빌딩은 각 변의 길이가 1인 정육면체(단위 정육면체)로 이루어져있다. 각 정육면체는 금으로 이루어져 있어 지나갈 수 없거나, 비어있어서 지나갈 수 있게 되어있다. 당신은 각 칸에서 인접한 6개의 칸(동,서,남,북,상,하)으로 1분의 시간을 들여 이동할 수 있다. 즉, 대각선으로 이동하는 것은 불가능하다. 그리고 상범 빌딩의 바깥면도 모두 금으로 막혀있어 출구를 통해서만 탈출할 수 있다.

당신은 상범 빌딩을 탈출할 수 있을까? 만약 그렇다면 얼마나 걸릴까?

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <tuple>
#include <cstring>
using namespace std;
int L, R, C;
char map[32][32][32];
bool check[32][32][32];
int dx[6] = { -1,1,0,0,0,0 };
int dy[6] = { 0,0,-1,1,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
int sz, sx, sy;
int ez, ex, ey;
int SEC=999999999;
queue <tuple<int, int, int, int>> q;
bool BFS()
{
	bool find = false;
	check[sz][sx][sy] = true;
	q.push({ sz,sx,sy,0 });

	while (!q.empty())
	{
		tuple <int, int, int, int> cp = q.front();
		q.pop();
		if (map[get<0>(cp)][get<1>(cp)][get<2>(cp)] == 'E')
		{
			SEC = min(SEC,get<3>(cp));
			return true;
		}
		for (int i = 0; i < 6; i++)
		{
			int new_z = get<0>(cp) + dz[i];
			int new_x = get<1>(cp) + dx[i];
			int new_y = get<2>(cp) + dy[i];

			if (new_z < 0 || new_x < 0 || new_y < 0 || new_z >= L || new_x >= R || new_y >= C)
				continue;
			if (map[new_z][new_x][new_y] == '#')
				continue;
			if (!check[new_z][new_x][new_y] && (map[new_z][new_x][new_y] == '.' || map[new_z][new_x][new_y] == 'E'))
			{
				check[new_z][new_x][new_y] = true;
				q.push({ new_z,new_x,new_y,get<3>(cp) + 1 });
			}
		}
	}
	return false;
}
int main()
{

	while (true)
	{
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0)
			break;
		for (int z = 0; z < L; z++)
		{
			for (int i = 0; i < R; i++)
			{
				string str;
				cin >> str;
				for (int j = 0; j < str.length(); j++)
				{
					map[z][i][j] = str[j];
					if (map[z][i][j] == 'S')
						sz = z, sx = i, sy = j;
					else if (map[z][i][j] == 'E')
						ez = z, ex = i, ey = j;
				}
			}
		}
		if (BFS())
		{
			cout << "Escaped in " << SEC << " minute(s)." << endl;
		}
		else
			cout << "Trapped!"<<endl;
		for (int z = 0; z < L; z++)
		{
			for (int i = 0; i < R; i++)
			{
				for (int j = 0; j < C; j++)
				{
					map[z][i][j] = 0;
					check[z][i][j] = false;
				}
			}
		}
		while (!q.empty())
			q.pop();
		SEC = 999999999;
	}
	return 0;
}
*/