/*
오민식은 오늘이 크리스마스라고 생각해서, 크리스마스 트리를 만들려고 한다.트리는 N개의 레벨로 이루어져 있다.위에서부터 레벨1, ... 레벨 N이다.또, 민식이는 빨강, 파랑, 초록색의 장난감을 가지고 있다.그리고 민식이는 이 장난감을 일정한 규칙에 의해서 장식하려고 한다.

레벨 K에는 딱 K개의 장난감이 있어야 한다.또, 각 레벨에 놓으려고 선택한 색이 있으면, 그 색의 장난감의 수는 서로 같아야 한다.예를 들어, 레벨 3에 장난감을 놓으려고 할 때, 빨강 2, 파랑 1과 같이 놓으면, 빨강과 파랑의 수가 다르기 때문에 안 된다.하지만, 레벨 4에 빨강 2, 파랑 2와 같이 놓으면, 가능하다.

N과, 장난감의 수가 주어질 때, 트리를 장식하는 경우의 수를 출력하는 프로그램을 작성하시오.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long int ll;
int n;
ll cache[11][101][101][101];
ll COMB[11][11];
ll SLV(int level, int R, int G, int B)
{
	if (level >= n + 1)
		return 1;
	ll& ret = cache[level][R][G][B];
	if (ret != -1)
		return ret;
	ret = 0;
	if (R >= level) ret += SLV(level + 1, R - level, G, B);
	if (G >= level) ret += SLV(level + 1, R , G-level, B);
	if (B >= level) ret += SLV(level + 1, R , G, B-level);

	if (level % 2 == 0)
	{
		if (R >= level / 2 && G >= level / 2)
			ret += SLV(level + 1, R - level / 2, G - level / 2, B) * COMB[level][level/2];
		if (R >= level / 2 && B >= level / 2)
			ret += SLV(level + 1, R - level / 2, G , B - level/2) * COMB[level][level / 2];
		if (G >= level / 2 && B >= level / 2)
			ret += SLV(level + 1, R, G - level / 2, B-level/2) * COMB[level][level / 2];
	} 
	if (level % 3 == 0)
	{
		if (R >= level / 3 && G >= level / 3 && B >= level / 3)
			ret += SLV(level + 1, R - level / 3, G - level / 3, B - level / 3)*COMB[level][level/3] * COMB[level - level/3][level/3];
	}

	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	COMB[2][1] = 2;
	COMB[3][1] = 3;
	COMB[4][2] = 6;
	COMB[6][2] = 15;
	COMB[6][3] = 20;
	COMB[8][4] = 70;
	COMB[9][3] = 84;
	COMB[10][5] = 252;
	int R, G, B;
	cin >> n >> R >> G >> B;
	memset(cache, -1, sizeof(cache));
	cout << SLV(1, R, G, B);
}
*/