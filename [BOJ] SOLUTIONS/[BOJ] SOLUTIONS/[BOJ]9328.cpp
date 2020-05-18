/*
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
int T;
int h, w;
char map[105][105];
bool check[26];
bool visited[105][105];
int ans = 0;
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void Bfs()
{
    queue <pair<int, int>> q;
    q.push({ 0,0 });

    while (!q.empty())
    {
        pair <int, int> cp = q.front();
        q.pop();

        if (cp.first < 0 || cp.second < 0 || cp.first > h + 1 || cp.second > w + 1)
            continue;
        if (visited[cp.first][cp.second] || map[cp.first][cp.second] == '*' || ('A' <= map[cp.first][cp.second] && map[cp.first][cp.second] <= 'Z'))
            continue;

        visited[cp.first][cp.second] = true;

        if (map[cp.first][cp.second] == '$')
        {
            ans++;
            map[cp.first][cp.second] = '.';
        }

        if ('a' <= map[cp.first][cp.second] && map[cp.first][cp.second] <= 'z')
        {
            char Door = (char)toupper(map[cp.first][cp.second]);
            map[cp.first][cp.second] = '.';

            if (!check[(int)Door - 65])
            {
                check[(int)Door - 65] = true;

                for (int i = 1; i <= h; i++)
                {
                    for (int j = 1; j <= w; j++)
                    {
                        if (map[i][j] == Door)
                        {
                            map[i][j] = '.';
                        }
                    }
                }

                memset(visited, false, sizeof(visited));
                while (!q.empty())
                {
                    q.pop();
                }
                q.push({ cp.first,cp.second });
                continue;
            }
        }

        for (int i = 0; i < 4; i++)
        {
            int new_x = cp.first + dx[i];
            int new_y = cp.second + dy[i];

            q.push({ new_x,new_y });
        }
    }
}

int main()
{
    cin >> T;
    while (T--)
    {
        cin >> h >> w;
        memset(check, false, sizeof(check));
        memset(visited, false, sizeof(visited));
        for (int i = 0; i <= h + 1; i++)
        {
            map[i][w + 1] = map[i][0] = '.';
        }
        for (int j = 0; j <= w + 1; j++)
        {
            map[0][j] = map[h + 1][j] = '.';
        }
        for (int i = 1; i <= h; i++)
        {
            string s;
            cin >> s;
            for (int j = 1; j <= w; j++)
            {
                map[i][j] = s[j - 1];
            }
        }

        string key;
        cin >> key;
        for (int k = 0; key[k] != '0' && k < key.length(); k++)
        {
            check[(int)key[k] - 97] = true;

            for (int i = 1; i <= h; i++)
            {
                for (int j = 1; j <= w; j++)
                {
                    if (map[i][j] == (char)toupper(key[k]))
                        map[i][j] = '.';
                }
            }
        }
        ans = 0;
        Bfs();
        cout << ans << "\n";

    }
}

*/