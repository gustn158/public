/*
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int m, n;
int map[1001][1001];
int cache[1001][1001];

int main()
{
	cin >> m >> n;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> map[i][j];
		}
	}
	int maxlen = 0;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (map[i][j] == 0)
			{
				cache[i][j] = min(min(cache[i - 1][j], cache[i - 1][j - 1]), cache[i][j - 1]) + 1;
				maxlen = max(maxlen, cache[i][j]);
			}
		}
	}
	cout << maxlen;
}
*/