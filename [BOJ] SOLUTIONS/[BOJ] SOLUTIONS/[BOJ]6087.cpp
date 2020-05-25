/*
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;
int w, h;
char map[101][101];
vector <pair<int, int>> v;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int minturn = 999999999;
int cache[101][101];
int ex, ey;
void BFS()
{
	int sx = v[0].first;
	int sy = v[0].second;
	ex = v[1].first;
	ey = v[1].second;
	queue <tuple<int, int, int,int>> q;
	q.push({ sx,sy,0, -1});
	cache[sx][sy] = 0;
	while (!q.empty())
	{
		pair<int, int> cp = { get<0>(q.front()),get<1>(q.front())};
		int cnt = get<2>(q.front());
		int rotate = get<3>(q.front());
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y = cp.second + dy[i];
			if (new_x < 1 || new_y < 1 || new_x > h || new_y > w)
				continue;
			if (((map[new_x][new_y] == '.')) || (new_x == ex && new_y == ey))
			{
				if (rotate == -1)
				{
					cache[new_x][new_y] = 0;
					q.push({ new_x,new_y,cnt,i });
				}
				else{
					int new_cnt = (rotate == i) ? cnt : cnt + 1;
					if (cache[new_x][new_y] >= new_cnt)
					{
						cache[new_x][new_y] = new_cnt;
						q.push({ new_x,new_y,new_cnt,i });
					}

				}

			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> w >> h;
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'C')
			{
				v.push_back({ i,j });
			}
		}
	}
	for (int i = 0; i <= 100; i++)
	{
		fill(cache[i], cache[i] + 101, 10001);
	}
	BFS();
	cout << cache[ex][ey];
}
*/