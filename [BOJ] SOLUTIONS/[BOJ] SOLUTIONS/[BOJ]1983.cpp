/*
�׸��� ���� ���� �ڽ��� ���� �Ʒ��� �� ��� N���� ���� �������� �ִ�. ���� ���� �ڽ��� ��ü 2N���� ĭ���� �̷���� �ְ�, �� ĭ���� 0�� �ƴ� -10 �̻� 10 ������ ������ ���� �������� �� �� �ִ�. �Ʒ� �׸��� N=7 �� ��� � ���� �ڽ��� ���¸� �����ְ� �ִ�. ��ĭ�� �������� ������� ���� ĭ�� ��Ÿ����, ���� �Ʒ��� �࿡ ����ִ� �������� ������ ���� ���� ���� �ִ�.

���� �ڽ��� "��"�� �� ���� ���� �Ʒ��� �ִ� �� ���ڵ��� ���� ��� ���� ������ ���ǵȴ�. ��ĭ�� 0���� ����Ѵ�. ���� ���, �� �׸��� ���� �ڽ��� ���� (-3)��0 + (-1)��(-3) + (-2)��2 + 0��4 + 5��0 + (-1)��5 + 0��(-2) = -6 �̴�. �� �࿡ �־��� �����ǵ鿡 ���� �� ������ �����ϸ鼭 �¿�� �����̸� �ٸ� ���� �ڽ��� �������� ���� �� �ִ�. ���� ������ �� �࿡ �ִ� 5�� -1�� ���������� ���� �� ĭ�� �ű��, �Ʒ� ���� -3�� �������� �� ĭ, 2�� 4�� ���������� ���� �� ĭ�� �ű�� �� ��� ���� �ڽ��� ������ ����.

�� ���� �ڽ��� �������� 9 + 25 + 2 = 36�� �ȴ�. �־��� ���� �ڽ��� ���� �Ʒ��� �࿡ ���� �����ǵ��� �� ������ �����ϸ鼭 ���� ������ �����ϵ��� �������� ���� �� �ִ� ���� �ڽ��� �ִ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�. �����ǵ��� �¿� ��ĭ���θ� ������ �� ������, �ǳʶٴ� ���·� �ٸ� �����ǰ� �� ��ġ�� ��ȯ�� ���� ����. �ٽ� ���ϸ�, ��ĭ�� �����ϸ� �� ���� �����ǵ��� ������ �׻� �״�� �����Ǿ�� �Ѵ�

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