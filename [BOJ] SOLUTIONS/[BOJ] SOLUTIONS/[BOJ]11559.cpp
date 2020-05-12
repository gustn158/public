/*
�ѿ�ѿ��� ���� ������ ����.

�ʵ忡 ���� ���� ������ �ѿ並 ���´�. �ѿ�� �߷��� ������ �޾� �Ʒ��� �ٴ��̳� �ٸ� �ѿ䰡 ���� ������ �Ʒ��� ��������.

�ѿ並 ���� �� ��, ���� �� �ѿ䰡 4�� �̻� �����¿�� ����Ǿ� ������ ����� ���� �� �ѿ���� �Ѳ����� ��������.

�ѿ���� �������� ���� ���� �ٸ� �ѿ���� �ִٸ�, ���� �߷��� ������ �޾� ���ʴ�� �Ʒ��� �������� �ȴ�.

�Ʒ��� �������� ���� �ٽ� ���� ���� �ѿ���� 4�� �̻� ���̰� �Ǹ� �� ������ �Ǵµ�, ���� �� �ѿ���� �������� �ٽ� ������ �ݺ��� ������ 1���⾿ �þ��.

���� �� �ִ� �ѿ䰡 ���� �׷��� �ִٸ� ���ÿ� ������ �ϰ� ���� �׷��� �������� �ѹ��� ���Ⱑ �߰��ȴ�.

���Դ� �ֱ� �ѿ�ѿ� ���ӿ� ǫ ������. �� ������ 1:1�� �ٴ� ���������̶� �� �״� �͵� �߿�������, ������ �Ͷ߸��ٸ� ���Ⱑ �� ���� ���� �ٷ� �ľ��� �� �ִ� �ɷµ� �ʿ��ϴ�. ������ ���� �Ƿ��� �����Ͽ� ���Դ� �ڱ� �ʵ忡�� �Ű� ���� �ٻڴ�. ������ �ʵ尡 �־����� ��, ���Ⱑ �� �� �������� �Ͼ�� ����Ͽ� ���Ը� ��������!


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