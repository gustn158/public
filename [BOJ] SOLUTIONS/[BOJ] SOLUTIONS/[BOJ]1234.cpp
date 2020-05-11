/*

KOI 두부 공장에서 만들어내는 크기가 N × N (N ≤ 11)인 두부모판이 있다. 이 모판을 1×1 크기의 단위두부가 2개 붙어있는 형태의 포장단위(즉, 1×2 혹은 2×1 크기)로 잘라서 판매한다. 그런데 두부제조 공정상 모판에 있는 각 단위두부의 품질은 A, B, C, F급으로 분류되고, 잘려진 포장단위의 두부 가격은 이 포장단위에 있는 두 개의 단위두부의 품질에 따라서 그림 1과 같이 정해진다
등급 	A 	B 	C 	F
A 	100 	70 	40 	0
B 	70 	50 	30 	0
C 	40 	30 	20 	0
F 	0 	0 	0 	0

그림 1. 포장단위의 가격표

포장단위에 있는 두 단위두부가 [A,A]급이면 100원을 받고, [A,B]급이면 70원을, [A,C]급이면 40원을, [B,B]급이면 50원을, [B,C]급이면 30원을, [C,C]급이면 20원을 받는다. 포장단위에 있는 두 개의 단위두부 중 하나라도 F급이 있으면 이 포장단위는 한푼도 받을 수 없다.

N×N 두부 모판의 품질이 주어질 때, 가장 높은 가격을 받도록 두부 모판을 1×2 혹은 2×1 크기의 포장단위들로 자르고자 한다. 예를 들어 그림 2와 같은 3×3 두부 모판이 주어져 있다고 하자.

그림 2. 두부 모판의 예

이 경우, 그림 3과 같이 자르면 4개의 포장단위가 만들어진다.

그림 3. 잘려진 두부모판

이때, 이들 포장단위의 가격은 [A,A]=100, [F,C]=0, [A,C]=40, 그리고 [A,B]=70 이다. 여기서 오른쪽 위 [C]와 같이 단위두부 하나는 포장단위가 아니므로 판매할 수 없다. 따라서 총 가격은 210원이 된다. 이 가격은 그림 2와 같은 3×3 두부모판에서 받을 수 있는 가장 높은 가격이다.

두부모판의 크기와 단위두부의 등급이 주어질 때, 이를 포장단위로 잘라 받을 수 있는 총 가격의 최댓값을 구하는 프로그램을 작성하시오.


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n;
int MAX = 11;
int val[4][4];
int map[15][15];
int cache[15][15][1<<12];
int dx[2] = { 0,1 };
int dy[2] = { 1,0 };
bool check[15][15];
int CUR, DOWN, NEXT,MOD;
int SLV(int x, int y, int bit)
{
	int& ret = cache[x][y][bit];
	if (ret != -1)
		return ret;
	if (x == n) return ret = 0;
	if (y == n)return ret = SLV(x + 1, 0, bit);
	if (!(bit & CUR))
	{
		if (y < n - 1 && !(bit & NEXT))
		{
			int tmp = SLV(x, y + 2, (bit << 2) % MOD) + val[map[x][y]][map[x][y + 1]];
			ret = max(ret, tmp);
		}
		if (x < n - 1 && !(bit & DOWN))
		{
			int tmp = SLV(x, y + 1, ((bit | DOWN) << 1) % MOD) + val[map[x][y]][map[x + 1][y]];
			ret = max(tmp, ret);
		}
	}
	int tmp = SLV(x, y + 1, (bit << 1) % MOD);
	ret = max(ret, tmp);
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < n; j++)
		{
			if (str[j] == 'A')
				map[i][j] = 0;
			if (str[j] == 'B')
				map[i][j] = 1;
			if (str[j] == 'C')
				map[i][j] = 2;
			if (str[j] == 'F')
				map[i][j] = 3;
		}
	}
	val[0][0] = 100; val[0][1] = 70; val[0][2] = 40; val[0][3] = 0;
	val[1][0] = 70; val[1][1] = 50; val[1][2] = 30; val[1][3] = 0;
	val[2][0] = 40; val[2][1] = 30; val[2][2] = 20; val[2][3] = 0;
	val[3][0] = 0; val[3][1] = 0; val[3][2] = 0; val[3][3] = 0;
	
	CUR = (1 << n); DOWN = 1; NEXT = (1 << (n - 1)); MOD = (1 << (n + 1));
	memset(cache, -1, sizeof(cache));
	cout << SLV(0, 0, 0);
}
*/