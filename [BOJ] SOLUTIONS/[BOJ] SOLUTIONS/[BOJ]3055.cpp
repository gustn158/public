/*
����� ������ ���� �̹����� ���� ���� ������ �տ� �־���, �� �ɷ��� �����غ��� ���� ��ó�� Ƽ������ ȫ���� ����Ű���� �Ѵ�. �� ������ ����ġ�� �� ���� ��� �ִ�. ����ġ�� ���� ģ�� ģ���� ����� ���� ������ ���� ������ ȫ���� ���Ϸ��� �Ѵ�.

Ƽ������ ������ R�� C���� �̷���� �ִ�. ����ִ� ���� '.'�� ǥ�õǾ� �ְ�, ���� ���ִ� ������ '*', ���� 'X'�� ǥ�õǾ� �ִ�. ����� ���� 'D'��, ����ġ�� ��ġ�� 'S'�� ��Ÿ������ �ִ�.

�� �и��� ����ġ�� ���� �ִ� ĭ�� ������ �� ĭ �� �ϳ��� �̵��� �� �ִ�. (��, �Ʒ�, ������, ����) ���� �� �и��� ����ִ� ĭ���� Ȯ���Ѵ�. ���� �ִ� ĭ�� �������ִ� ����ִ� ĭ(��� �� ���� ����)�� ���� ���� �ȴ�. ���� ����ġ�� ���� ����� �� ����. ��, ����ġ�� ���� ���ִ� �������� �̵��� �� ����, ���� ����� �ұ��� �̵��� �� ����.

Ƽ������ ������ �־����� ��, ����ġ�� �����ϰ� ����� ���� �̵��ϱ� ���� �ʿ��� �ּ� �ð��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

����ġ�� ���� �� ������ ĭ���� �̵��� �� ����. ��, ���� �ð��� ���� �� ������ ĭ���� ����ġ�� �̵��� �� ����. �̵��� �� ������ ����ġ�� ���� ������ �����̴�.

*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int r, c;
char map[51][51];
bool dcheck[51][51];
bool check[51][51];
int gx, gy;
int wx, wy;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
vector <pair<int, int>> v;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	int ax, ay;
	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == 'S')
				gx = i, gy = j;
			if (map[i][j] == '*')
			{
				v.push_back({ i,j });
			}
			if (map[i][j] == 'D')
				ax = i, ay = j;
			if (map[i][j] == 'X')
				check[i][j] = true;
		}
	queue <pair<pair<int, int>, int>> dq;
	queue <pair<pair<int, int>, int>> wq;
	dq.push({ {gx,gy},0 });
	for (int i = 0; i < v.size(); i++)
	{
		check[v[i].first][v[i].second] = true;
		wq.push({ { v[i].first,v[i].second }, 0
			});
	}
	int cnt = 0;
	while (!dq.empty())
	{

		while (!wq.empty() && wq.front().second == cnt) {
			pair <int, int> wc = wq.front().first;
			int wlevel = wq.front().second;
			wq.pop();
			for (int i = 0; i < 4; i++)
			{
				int wnew_x = wc.first + dx[i];
				int wnew_y = wc.second + dy[i];

				if (wnew_x < 0 || wnew_y < 0 || wnew_x >= r || wnew_y >= c)
					continue;

				if (!check[wnew_x][wnew_y] && map[wnew_x][wnew_y] == '.')
				{
					check[wnew_x][wnew_y] = true;
					map[wnew_x][wnew_y] = '*';
					wq.push({ {wnew_x,wnew_y},wlevel + 1 });
				}
			}
		}
		while (!dq.empty() && dq.front().second == cnt) {
			pair<int, int> gs = dq.front().first;
			int glevel = dq.front().second;
			dq.pop();
			map[gs.first][gs.second] = '.';
			if (gs.first == ax && gs.second == ay)
			{
				cout << glevel;
				exit(0);
			}
			for (int i = 0; i < 4; i++)
			{
				int gnew_x = gs.first + dx[i];
				int gnew_y = gs.second + dy[i];

				if (gnew_x < 0 || gnew_y < 0 || gnew_x >= r || gnew_y >= c)
					continue;
				if (!check[gnew_x][gnew_y] && (map[gnew_x][gnew_y] == '.' || map[gnew_x][gnew_y] == 'D'))
				{
					map[gnew_x][gnew_y] = 'S';
					dq.push({ {gnew_x,gnew_y},glevel + 1 });
				}

			}
		}
		cnt++;
		/*for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cout << map[i][j];
			}
			cout << "\n";
		}*/
		if (cnt >= r * c)
			break;
	}
	cout << "KAKTUS";
}
