/*
사악한 암흑의 군주 이민혁은 드디어 마법 구슬을 손에 넣었고, 그 능력을 실험해보기 위해 근처의 티떱숲에 홍수를 일으키려고 한다. 이 숲에는 고슴도치가 한 마리 살고 있다. 고슴도치는 제일 친한 친구인 비버의 굴로 가능한 빨리 도망가 홍수를 피하려고 한다.

티떱숲의 지도는 R행 C열로 이루어져 있다. 비어있는 곳은 '.'로 표시되어 있고, 물이 차있는 지역은 '*', 돌은 'X'로 표시되어 있다. 비버의 굴은 'D'로, 고슴도치의 위치는 'S'로 나타내어져 있다.

매 분마다 고슴도치는 현재 있는 칸과 인접한 네 칸 중 하나로 이동할 수 있다. (위, 아래, 오른쪽, 왼쪽) 물도 매 분마다 비어있는 칸으로 확장한다. 물이 있는 칸과 인접해있는 비어있는 칸(적어도 한 변을 공유)은 물이 차게 된다. 물과 고슴도치는 돌을 통과할 수 없다. 또, 고슴도치는 물로 차있는 구역으로 이동할 수 없고, 물도 비버의 소굴로 이동할 수 없다.

티떱숲의 지도가 주어졌을 때, 고슴도치가 안전하게 비버의 굴로 이동하기 위해 필요한 최소 시간을 구하는 프로그램을 작성하시오.

고슴도치는 물이 찰 예정인 칸으로 이동할 수 없다. 즉, 다음 시간에 물이 찰 예정인 칸으로 고슴도치는 이동할 수 없다. 이동할 수 있으면 고슴도치가 물에 빠지기 때문이다.

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
