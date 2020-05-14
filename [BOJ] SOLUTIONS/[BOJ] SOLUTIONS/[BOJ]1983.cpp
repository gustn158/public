/*
그림과 같이 숫자 박스는 위와 아래의 두 행과 N개의 열로 나누어져 있다. 따라서 숫자 박스는 전체 2N개의 칸으로 이루어져 있고, 각 칸에는 0이 아닌 -10 이상 10 이하의 정수가 적힌 숫자판이 들어갈 수 있다. 아래 그림은 N=7 인 경우 어떤 숫자 박스의 상태를 보여주고 있다. 빈칸은 숫자판이 들어있지 않은 칸을 나타내며, 위와 아래의 행에 들어있는 숫자판의 개수는 같지 않을 수도 있다.

숫자 박스의 "값"은 각 열의 위와 아래에 있는 두 숫자들의 곱을 모두 더한 값으로 정의된다. 빈칸은 0으로 계산한다. 예를 들면, 위 그림의 숫자 박스의 값은 (-3)×0 + (-1)×(-3) + (-2)×2 + 0×4 + 5×0 + (-1)×5 + 0×(-2) = -6 이다. 각 행에 주어진 숫자판들에 대해 그 순서를 유지하면서 좌우로 움직이면 다른 숫자 박스의 “값”을 얻을 수 있다. 위의 예에서 윗 행에 있는 5와 -1을 오른쪽으로 각각 한 칸씩 옮기고, 아래 행의 -3을 왼쪽으로 한 칸, 2와 4를 오른쪽으로 각각 한 칸씩 옮기면 그 결과 숫자 박스는 다음과 같다.

이 숫자 박스의 “값”은 9 + 25 + 2 = 36이 된다. 주어진 숫자 박스의 위와 아래의 행에 놓인 숫자판들을 그 순서는 유지하면서 위의 조건을 만족하도록 움직여서 얻을 수 있는 숫자 박스의 최댓값을 구하는 프로그램을 작성하시오. 숫자판들은 좌우 빈칸으로만 움직일 수 있으며, 건너뛰는 형태로 다른 숫자판과 그 위치가 교환될 수는 없다. 다시 말하면, 빈칸을 제외하면 각 행의 숫자판들의 순서는 항상 그대로 유지되어야 한다

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MIN = -999999999;
int n;
int map[2][401];
vector <int> up;
vector <int> down;
int cache[401][401][401];
int SLV(int idx, int upidx,int downidx,int uplast, int downlast)
{
	if (idx >= n)
		return 0;
	int& ret = cache[idx][upidx][downidx];
	if (ret != MIN)
		return ret;
	ret = MIN;
	if (uplast > 0 && downlast > 0) ret = max(ret, SLV(idx + 1, upidx, downidx, uplast - 1, downlast - 1));
	if (upidx < up.size() && downidx < down.size()) ret = max(ret, SLV(idx + 1, upidx + 1, downidx + 1, uplast, downlast) + (up[upidx] * down[downidx]));
	if (upidx < up.size() && downlast > 0) ret = max(ret, SLV(idx + 1, upidx + 1, downidx, uplast, downlast - 1));
	if (downidx < down.size() && uplast > 0) ret = max(ret, SLV(idx + 1, upidx, downidx + 1, uplast - 1, downlast));

	return ret;
}	
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int  num;
		cin >> num;
		if (num != 0)
			up.push_back(num);
	}
	for (int i = 0; i < n; i++)
	{
		int  num;
		cin >> num;
		if (num != 0)
			down.push_back(num);
	}
	for (int i = 0; i <= 400; i++)
	{
		for (int j = 0; j <= 400; j++)
		{
			fill(cache[i][j], cache[i][j] + 401, MIN);
		}
	}
	cout << SLV(0,0,0, n - up.size(), n - down.size());


}
*/