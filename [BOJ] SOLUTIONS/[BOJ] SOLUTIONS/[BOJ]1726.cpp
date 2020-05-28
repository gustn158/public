/*
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <tuple>
using namespace std;
int n, m;
int map[101][101];
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,1,-1,0,0 };
int sx, sy, sd;
int ex, ey, ed;
bool check[101][101][5];
int Cal_d[5][5];
int Bfs()
{
	queue <tuple<int,int,int,int>> q;
	check[sx][sy][sd] = true;
	q.push({ sx,sy,sd,0 }); //x,y,direc,order,walk
	while (!q.empty())
	{
		tuple <int, int, int, int> cp = q.front();
		q.pop();
		if (get<0>(cp) == ex && get<1>(cp) == ey && get<2>(cp) == ed)
		{
			return  get<3>(cp);
		
		}
		
		for (int i = 1; i <= 3; i++)
		{
			int new_x = get<0>(cp) + i*dx[get<2>(cp)];
			int new_y = get<1>(cp) + i*dy[get<2>(cp)];

			if (check[new_x][new_y][get<2>(cp)])
				continue;
			if (new_x >= 1 && new_y >= 1 && new_x <= n && new_y <= m && map[new_x][new_y] == 0)
			{
				check[new_x][new_y][get<2>(cp)] = true;
				q.push({ new_x,new_y,get<2>(cp),get<3>(cp) + 1 });
			}
			else
				break;
		}
		for (int i = 1; i <= 4; i++)
		{
			if (get<2>(cp) != i && !check[get<0>(cp)][get<1>(cp)][i])
			{
				check[get<0>(cp)][get<1>(cp)][i] = true;
				if ((get<2>(cp) == 1 && i == 2) || (get<2>(cp) == 2 && i == 1) || (get<2>(cp) == 3 && i == 4) || (get<2>(cp) == 4 && i == 3))
				{
					q.push({ get<0>(cp),get<1>(cp),i,get<3>(cp) + 2 });
				}
				else
				{
					q.push({ get<0>(cp),get<1>(cp),i,get<3>(cp) + 1 });
				}
			}
		}
			


		
	}
	return -1;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			cin >> map[i][j];
		}
	}
	cin >>  sx>> sy>> sd;
	cin >> ex>> ey>> ed;
	cout << Bfs();
}
*/