/*


���ƴ� x�� ���� �ɾ��ִ�. "���� x���� �ʹ� ����!!" ��� ���ư� ���ߴ�. ���򼱿��� n���� �����ٱ��ϰ� �ְ�, �� ���� �ٱ��Ͽ��� m���� ������ �ִ�. �� ���� �ٱ��ϴ� x1, x2, ..., xn �� �ְ�, ���ƴ� 0�� �ִ�.

������ ������ ����. ����, �ð��� 1��ŭ ���� �� ����, ��� �����ٱ��Ͽ��� ������ 1��ŭ �پ���. ���ƴ� �ſ� �谡������ ������, �����ٱ��Ͽ� �ִ� ������ 0���� ��� ���� �� �ִ�. ���ư� 1��ŭ ������ ��, �ð��� 1��ŭ ��������.

���ư� ���� �� �ִ� ������ �ִ� ������ ���ϴ� ���α׷��� �ۼ��Ͻÿ�.



#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int cache[303][303][2]; // i~j��° ���� ������ ��ġ
vector <int> v,sum;
int SLV(int left, int right, int flag,int candy)
{
	if (!candy)
		return 0;
	if (left > right)
		return 1e9;
	int& ret = cache[left][right][flag];
	if (ret != -1)
		return ret;
	ret = 1e9;
	int cur = flag ? right : left;
	if (flag)
	{
		if (right != n )
			ret = min(ret, SLV(left, right + 1, 0, candy - 1) + candy * (v[right + 1] - v[left]));
		if (left >= 1)
		{
			ret = min(ret, SLV(left - 1, right, 1, candy - 1) + candy * (v[left] - v[left - 1]));
		}
	}
	else
	{
		if (right != n )
			ret = min(ret, SLV(left, right + 1, 0, candy - 1) + candy * (v[right + 1] - v[right]));
		if (left >= 1)
			ret = min(ret, SLV(left - 1, right, 1, candy - 1) + candy * (v[right] - v[left - 1]));
	}

	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	
	for (int i = 0; i < n; i++)
	{
		int num;
		cin >> num;
		v.push_back(num);
	}
	v.push_back(0);
	sort(v.begin() , v.end());
	int cur_idx = 0;
	for (int i = 0; i <= n; i++)
	{
		if (v[i] == 0)
		{
			cur_idx = i;
			break;
		}
	}
	int ans = 0;
	memset(cache, -1, sizeof(cache));
	for (int i = 0; i <= n; i++)
	{
		memset(cache, -1, sizeof(cache));
		ans = max(ans, i * m - SLV(cur_idx, cur_idx, 0, i));
	}
	cout << ans;
}
*/