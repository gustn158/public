/*
���ν��� ������ ũ����������� �����ؼ�, ũ�������� Ʈ���� ������� �Ѵ�.Ʈ���� N���� ������ �̷���� �ִ�.���������� ����1, ... ���� N�̴�.��, �ν��̴� ����, �Ķ�, �ʷϻ��� �峭���� ������ �ִ�.�׸��� �ν��̴� �� �峭���� ������ ��Ģ�� ���ؼ� ����Ϸ��� �Ѵ�.

���� K���� �� K���� �峭���� �־�� �Ѵ�.��, �� ������ �������� ������ ���� ������, �� ���� �峭���� ���� ���� ���ƾ� �Ѵ�.���� ���, ���� 3�� �峭���� �������� �� ��, ���� 2, �Ķ� 1�� ���� ������, ������ �Ķ��� ���� �ٸ��� ������ �� �ȴ�.������, ���� 4�� ���� 2, �Ķ� 2�� ���� ������, �����ϴ�.

N��, �峭���� ���� �־��� ��, Ʈ���� ����ϴ� ����� ���� ����ϴ� ���α׷��� �ۼ��Ͻÿ�.

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