/*
여러 섬으로 이루어진 나라가 있다.이 나라의 대통령은 섬을 잇는 다리를 만들겠다는 공약으로 인기몰이를 해 당선될 수 있었다.하지만 막상 대통령에 취임하자, 다리를 놓는다는 것이 아깝다는 생각을 하게 되었다.그래서 그는, 생색내는 식으로 한 섬과 다른 섬을 잇는 다리 하나만을 만들기로 하였고, 그 또한 다리를 가장 짧게 하여 돈을 아끼려 하였다.

이 나라는 N×N크기의 이차원 평면상에 존재한다.이 나라는 여러 섬으로 이루어져 있으며, 섬이란 동서남북으로 육지가 붙어있는 덩어리를 말한다.다음은 세 개의 섬으로 이루어진 나라의 지도이다.

위의 그림에서 색이 있는 부분이 육지이고, 색이 없는 부분이 바다이다.이 바다에 가장 짧은 다리를 놓아 두 대륙을 연결하고자 한다.가장 짧은 다리란, 다리가 격자에서 차지하는 칸의 수가 가장 작은 다리를 말한다.다음 그림에서 두 대륙을 연결하는 다리를 볼 수 있다.

물론 위의 방법 외에도 다리를 놓는 방법이 여러 가지 있으나, 위의 경우가 놓는 다리의 길이가 3으로 가장 짧다(물론 길이가 3인 다른 다리를 놓을 수 있는 방법도 몇 가지 있다).

지도가 주어질 때, 가장 짧은 다리 하나를 놓아 두 대륙을 연결하는 방법을 찾으시오.
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
using namespace std;
int n;
int map[101][101];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
bool check[101][101];
void Bfs(int x, int y, int cnt)
{
	check[x][y] = true;
	queue <pair<int, int>> q;
	q.push({ x,y });
	map[x][y] = cnt;
	while (!q.empty())
	{
		pair <int, int> cp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y = cp.second + dy[i];
			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)
				continue;
			if (!check[new_x][new_y] && map[new_x][new_y] == 1)
			{
				check[new_x][new_y] = true;
				q.push({ new_x,new_y });
				map[new_x][new_y] = cnt;
			}
		}
	}
}
int far(int x, int y)
{
	queue <pair<pair<int, int>, int>> q;
	check[x][y] = true;
	q.push({ {x,y} ,0 });
	int color = map[x][y];

	while (!q.empty())
	{
		pair <int, int> cp = q.front().first;
		int level = q.front().second;
		q.pop();
		if (map[cp.first][cp.second] != color)
		{
			if (map[cp.first][cp.second] != 0)
				return level;
		}
		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y = cp.second + dy[i];

			if (new_x < 0 || new_x >= n || new_y < 0 || new_y >= n)
				continue;
			if (!check[new_x][new_y] && (map[new_x][new_y] != color))
			{
				check[new_x][new_y] = true;
				q.push({ { new_x,new_y },level + 1 });

			}
		}

	}
	return 999999999;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	int cnt = 2;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (map[i][j] == 1 && !check[i][j])
			{
				Bfs(i, j, cnt);
				cnt++;
			}
	int mindist = 999999999;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			memset(check, false, sizeof(check));
			if (map[i][j] != 0)
				mindist = min(mindist, far(i, j));
		}
	}
	cout << mindist - 1;

	return 0;
}