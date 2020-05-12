/*
뿌요뿌요의 룰은 다음과 같다.

필드에 여러 가지 색깔의 뿌요를 놓는다. 뿌요는 중력의 영향을 받아 아래에 바닥이나 다른 뿌요가 나올 때까지 아래로 떨어진다.

뿌요를 놓고 난 후, 같은 색 뿌요가 4개 이상 상하좌우로 연결되어 있으면 연결된 같은 색 뿌요들이 한꺼번에 없어진다.

뿌요들이 없어지고 나서 위에 다른 뿌요들이 있다면, 역시 중력의 영향을 받아 차례대로 아래로 떨어지게 된다.

아래로 떨어지고 나서 다시 같은 색의 뿌요들이 4개 이상 모이게 되면 또 터지게 되는데, 터진 후 뿌요들이 내려오고 다시 터짐을 반복할 때마다 1연쇄씩 늘어난다.

터질 수 있는 뿌요가 여러 그룹이 있다면 동시에 터져야 하고 여러 그룹이 터지더라도 한번의 연쇄가 추가된다.

남규는 최근 뿌요뿌요 게임에 푹 빠졌다. 이 게임은 1:1로 붙는 대전게임이라 잘 쌓는 것도 중요하지만, 상대방이 터뜨린다면 연쇄가 몇 번이 될지 바로 파악할 수 있는 능력도 필요하다. 하지만 아직 실력이 부족하여 남규는 자기 필드에만 신경 쓰기 바쁘다. 상대방의 필드가 주어졌을 때, 연쇄가 몇 번 연속으로 일어날지 계산하여 남규를 도와주자!


#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
char map[12][6];
bool check[12][6];
bool Bfs(int x, int y)
{
	vector <pair<int, int>> v;
	check[x][y] = true;
	queue <pair<int, int>> q;
	q.push({ x,y } );
	char color = map[x][y];
	v.push_back({ x,y });
	int cnt = 0;
	while (!q.empty())
	{
		pair <int, int> cp = q.front();

		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int new_x = cp.first + dx[i];
			int new_y = cp.second + dy[i];

			if (new_x < 0 || new_x >= 12 || new_y < 0 || new_y >= 6)
				continue;
			if (!check[new_x][new_y] && map[new_x][new_y] == color)
			{
				check[new_x][new_y] = true;
				q.push({ new_x,new_y });
				v.push_back({ new_x,new_y });
				cnt++;
			}
		}
	}
	if (cnt >= 3)
	{
		for (int i = 0; i < v.size(); i++)
		{
			map[v[i].first][v[i].second] = '.';
		}
		return true;
	}
	else
		return false;
}
void fill()
{
	for (int i = 5; i >=0; i--)
	{
		for (int j = 11; j >= 0; j--)
		{
			if (map[j][i] == '.')
			{
				int len = 0;
				for (int k = j; map[k][i] == '.' && k >= 0; k--)
				{
					len++;
				}
				if (len <= j) {
					map[j][i] = map[j - len][i];
					map[j - len][i] = '.';
				}
			}
	}
	}

	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << map[i][j];
		}
		cout << "\n";
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	for (int i = 0; i < 12; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < str.length(); j++)
		{
			map[i][j] = str[j];
		}
	}

	memset(check, false, sizeof(check));
	int sido = 9;
	int ans = 0;
	while (sido > 0) {
		sido = 0;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 6; j++)
			{

				if (!check[i][j] && map[i][j] != '.')
				{
					memset(check, false, sizeof(check));
					if (Bfs(i, j))
					{
						sido++;
					}
				}
			}
		}
		fill();
		if(sido>0)
			ans++;
	}
	cout << ans;
}

*/