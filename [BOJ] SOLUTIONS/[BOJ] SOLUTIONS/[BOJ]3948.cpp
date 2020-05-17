/*
두 변의 길이가 모두 양의 정수인 직사각형 모양의 종이가 주어져 있다. 이 종이를 칼로 여러 번 잘라서 모든 조각이 한 변의 길이가 양의 정수인 정사각형이 되도록 하고자 한다.

칼로 종이를 자르는 규칙은 다음과 같다.

	자르는 방향은 수직 또는 수평만 허용된다. 즉, 사선으로는 자를 수 없다.
	자르는 도중 칼의 방향을 바꿀 수 없다.
	자르는 도중에 칼을 멈출 수 없다. 즉, 일단 어떤 조각을 자르기 시작하면 그 조각이 반드시 둘로 분리될 때 까지 자른다.
	잘려진 조각의 각 변의 길이는 양의 정수이어야 한다.

위의 규칙에 따라 주어진 직사각형 모양의 종이를 잘라 각 조각이 정사각형이 되도록 하되, 잘려진 조각 개수가 최소가 되도록 하고자 한다.

예를 들어, 아래 왼쪽 그림에서 보인 것과 같이 두 변의 길이가 5와 6인 종이가 주어질 때, 최소 개수의 정사각형 조각을 얻도록 자른 결과를 아래 오른쪽 그림에서 보였다.
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
int cache[10001][101];
const int MAX = 987654321;
int SLV(int s,int g)
{
	if (s == g)
		return cache[s][g] = 1;
	if (s<  0 || g < 0) return MAX;

	int& ret = cache[s][g];
	if (ret != -1)
		return ret;
	ret = s*g;
	if (s >= 3 * g) ret = min(ret, SLV(s - g, g) + 1);
	else {
		for (int k = 1; k <= (g + 1) / 2; k++)
		{
			ret = min(ret, SLV(s, k) + SLV(s, g - k));
		}
		for (int k = 1; k <= (s + 1) / 2; k++)
		{
			ret = min(ret, SLV(k, g) + SLV(s - k, g));
		}
	}
	return ret;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	memset(cache, -1, sizeof(cache));
	cout << SLV(n,m);
}

*/