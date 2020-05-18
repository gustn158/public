/*
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
char map[31][31];
char cmp[31][31];
int SUM_OF_ES;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
int cntans = 1000001;
bool check[31][31];
void make_check(int x, int y, int direc, int len)
{
	for (int i = 0; i < len; i++)
	{
		int new_x = x + i * dx[direc];
		int new_y = y + i * dy[direc];
		check[new_x][new_y] = true;
	}
}
void del_check(int x, int y, int direc, int len)
{
	for (int i = 0; i < len; i++)
	{
		int new_x = x + i * dx[direc];
		int new_y = y + i * dy[direc];
		check[new_x][new_y] = false;
	}
}
void SLV(int x, int y, int rotate,int sumnt)
{
	if (sumnt == 0)
	{
		cntans = min(cntans, rotate);
		return;
	}
	for (int i = 0; i < 4; i++)
	{
		int new_x = x; int new_y = y;
		int len = 0;
		while (!check[new_x][new_y] && map[new_x][new_y] == '.'&&(new_x>= 1 && new_x <= n && new_y>=1 && new_y<=m))
		{
			len++;
			new_x = x + len*dx[i];
			new_y = y + len * dy[i];
		}
		if (len == 1)
			continue;

		make_check(x, y, i, len - 1);
		SLV(new_x - dx[i], new_y - dy[i], rotate + 1, sumnt - len +1);
		del_check(x, y, i, len - 1);
	}
}
int main()
{
	int cnt = 1;
	int i, j;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	while (cin >> n >> m)
	{
		memset(check, false, sizeof(check));
		memcpy(map, cmp, sizeof(cmp));
		SUM_OF_ES = 0;
		for (int i = 1; i <= n; i++)
		{
			string s;
			cin >> s;
			for (int j = 1; j <= m; j++)
			{
				map[i][j] = s[j - 1];
				if (map[i][j] == '.')
					SUM_OF_ES++;
			}
		}
		int ans = 1000001;
		
			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					cntans = 1000001;
					if (map[i][j] == '.')
					{
						memset(check, false, sizeof(check));
						SLV(i, j, 0, SUM_OF_ES - 1);
					}
					ans = min(ans, cntans);
				}
			}
		
		if (ans >= 1000001)
			ans = -1;
		cout << "Case " << cnt << ": " << ans << "\n";

		cnt++;
	}
	return 0;
}
*/