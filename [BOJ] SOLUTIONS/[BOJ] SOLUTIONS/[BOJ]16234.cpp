/*


N��Nũ���� ���� �ְ�, ���� 1��1���� ĭ���� �������� �ִ�. ������ ������ ���� �ϳ��� �����ϸ�, r�� c���� �ִ� ���󿡴� A[r][c]���� ��� �ִ�. ������ ���� ���̿��� ���漱�� �����Ѵ�. ��� ����� 1��1 ũ���̱� ������, ��� ���漱�� ���簢�� �����̴�.

���ú��� �α� �̵��� ���۵Ǵ� ���̴�.

�α� �̵��� ������ ���� ����ǰ�, �� �̻� �Ʒ� ����� ���� �α� �̵��� ���� ������ ���ӵȴ�.

	���漱�� �����ϴ� �� ������ �α� ���̰� L�� �̻�, R�� ���϶��, �� ���� �����ϴ� ���漱�� ���� �Ϸ絿�� ����.
	���� ���ǿ� ���� ������ϴ� ���漱�� ��� ���ȴٸ�, �α� �̵��� �����Ѵ�.
	���漱�� �����־� ������ ĭ���� �̿��� �̵��� �� ������, �� ���� ���� �Ϸ� ������ �����̶�� �Ѵ�.
	������ �̷�� �ִ� �� ĭ�� �α����� (������ �α���) / (������ �̷�� �ִ� ĭ�� ����)�� �ȴ�. ���ǻ� �Ҽ����� ������.
	������ ��ü�ϰ�, ��� ���漱�� �ݴ´�.

�� ������ �α����� �־����� ��, �α� �̵��� �� �� �߻��ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


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