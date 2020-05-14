/*


N×N크기의 땅이 있고, 땅은 1×1개의 칸으로 나누어져 있다. 각각의 땅에는 나라가 하나씩 존재하며, r행 c열에 있는 나라에는 A[r][c]명이 살고 있다. 인접한 나라 사이에는 국경선이 존재한다. 모든 나라는 1×1 크기이기 때문에, 모든 국경선은 정사각형 형태이다.

오늘부터 인구 이동이 시작되는 날이다.

인구 이동은 다음과 같이 진행되고, 더 이상 아래 방법에 의해 인구 이동이 없을 때까지 지속된다.

	국경선을 공유하는 두 나라의 인구 차이가 L명 이상, R명 이하라면, 두 나라가 공유하는 국경선을 오늘 하루동안 연다.
	위의 조건에 의해 열어야하는 국경선이 모두 열렸다면, 인구 이동을 시작한다.
	국경선이 열려있어 인접한 칸만을 이용해 이동할 수 있으면, 그 나라를 오늘 하루 동안은 연합이라고 한다.
	연합을 이루고 있는 각 칸의 인구수는 (연합의 인구수) / (연합을 이루고 있는 칸의 개수)가 된다. 편의상 소수점은 버린다.
	연합을 해체하고, 모든 국경선을 닫는다.

각 나라의 인구수가 주어졌을 때, 인구 이동이 몇 번 발생하는지 구하는 프로그램을 작성하시오.


#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int n;
int L, R;
int map[51][51];
int tmp[51][51];
bool pos[51][51];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int sum = 0;
bool Bfs(int i, int j)
{
	sum = 0;
	vector <pair<int, int>> v;
	queue <pair<int, int>> q;
	pos[i][j] = true;
	q.push({ i,j });
	v.push_back({ i,j });
	bool check = false;
	while (!q.empty())
	{
		pair <int, int> cp = q.front();
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y =cp.second + dy[i];
			if (new_x < 1 || new_y < 1 || new_x > n || new_y > n)
				continue;
			int gap = abs(map[cp.first][cp.second] - map[new_x][new_y]);
			if (!pos[new_x][new_y] && (gap >= L && gap <= R))
			{
				pos[new_x][new_y] = true;
				q.push({ new_x,new_y });
				v.push_back({ new_x,new_y });
				check = true;
			}
		}
	}
	for (int i = 0;i< v.size(); i++)
	{
		sum += map[v[i].first][v[i].second];
	}
	sum /= v.size();
	for (int i = 0; i<v.size(); i++)
	{
		tmp[v[i].first][v[i].second] = sum;
	}
	return check;
}
int main()
{
	cin >> n >> L >> R;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	int ans = 0;
	int cnt = 1;
	while (cnt > 0)
	{
		memcpy(tmp, map, sizeof(map));
		cnt = 0;
		sum = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (!pos[i][j])
				{
					if (Bfs(i, j))
					{
						cnt++;
					}
					else
					{
						memset(pos, 0, sizeof(pos));
					}
				}
			}
		}
		memcpy(map, tmp, sizeof(tmp));
		memset(pos, 0, sizeof(pos));
		if (cnt != 0)
			ans++;
	}
	cout << ans;
}*/