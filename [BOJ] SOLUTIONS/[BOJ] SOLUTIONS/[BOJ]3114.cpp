/*


A나라와 B나라가 국경선을 놓고 몇 년째 싸우고 있다. 분쟁 지역의 크기는 직사각형이고, R×C 개의 칸으로 나누어져 있다. 모든 칸에는 사과 나무 또는 바나나 나무가 심어져 있다.

방금, 기나긴 영토 분쟁을 끝내기 위해 중립국에서 협상가 김상근이 도착했다. 상근이는 불도저를 이용해 일부 칸에 있는 나무를 모두 제거하고, 그러한 칸을 국경선으로 이용하려고 한다. 불도저는 가장 왼쪽 윗칸에서 출발하며, 한 칸 아래, 오른쪽, 오른쪽 아래 대각선으로 이동할 수 있다. 불도저는 오른쪽 아랫칸에 도착할 때까지 이동한다.

A는 불도저가 지나간 길의 아래쪽을 가지게 되고, B는 위쪽을 가지게 된다. 따라서, 땅을 하나도 받지 못하는 경우가 생길 수도 있다.

김상근은 A에 사는 사람들은 사과를 좋아하고, B에 사는 사람들은 바나나를 좋아한다는 사실을 알고 있다. 따라서, 불도저가 지나간 길의 아래쪽에 있는 사과 나무의 개수와 위쪽에 있는 바나나 나무 개수의 합을 크게 만들려고 한다.

가능한 합 중 가장 큰 합을 구하는 프로그램을 작성하시오.


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int r, c;
int A[1503][1503];
int B[1503][1503];
int cache[1503][1503][3];
int dx[3] = { 1,0,1 };
int dy[3] = { 0,1,1 };

int SLV(int x, int y, int direc)
{
	if (x == r && y == c )
		return 0;
	int& ret = cache[x][y][direc];
	if (ret != -1)
		return ret;
	ret = 0;
	//오른쪽 아래
	if (x < r  && y < c )
	{
		ret = max(ret, SLV(x + 1, y + 1, 2) + A[r][y] - A[x][y] + B[x][y + 1]);
	}
	//아래
	if (x < r )
	{
		ret = max(ret, SLV(x + 1, y, 0));
	}
	//오른쪽
	if (y < c )
	{
		ret = max(ret, SLV(x, y + 1, 1) + A[r][y] - A[x][y] + B[x-1][y+1]);
	}

	return ret;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			string s;
			cin >> s;
			if (s[0] == 'A')
			{
				A[i][j] = stoi(s.substr(1));
			}
			else
			{
				B[i][j] = stoi(s.substr(1));
			}
		}
	}
	for (int i = 2; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			A[i][j] += A[i - 1][j];
			B[i][j] += B[i - 1][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	cout << SLV(1, 1, 0);
	
}
*/