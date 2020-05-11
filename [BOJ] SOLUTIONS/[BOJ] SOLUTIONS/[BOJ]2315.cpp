/*
�����ҿ��� ���� ��Ʈ�� ĸ�� ������ ��¡�� Z��(���� ��¡��)�� �ϼ��ߴ�.������ ������ �̹� �±� V�� ���� ��ȭ�ο� ���¸� �����ϰ� �ֱ� ������ ��¡���� ���׿��� ���ε��� ���� ���� ��Ű��� �ߴ�.

������ �߽ɿ��� �ſ� �� ���ΰ� �ִµ�, �� ���� ������ ���ε��� ������ �ִ�.��¡���� �� ���ε��� ���� ���� 5�ÿ� ���� �����ؾ� �Ѵ�.���� 5�� ������ ��¡���� ��Ȯ�� ���� ���ε� �߿��� ��� �� ���ε� �ٷ� �ؿ� ��ġ�ϰ� �ִٰ� ���� �����Ѵ�.�׷���, ���ε�� �������� ������ �Һ��ϴ� ������ �޷��ְ�, �츮�� ���ڵ��� ��¡���� ���������� �ſ� ��ö�ϱ� ������ �������� ������ �����ϱ� ��ġ �ʴ´�.

�׷��� �Һ������� �ּ�ȭ�� �� �ֵ��� ���ε��� ���� ������ �˾Ƴ��� �;� �Ѵ�.��¡���� �����ϰ� 1m / sec �� �ӵ��� �����̸�, ���ε��� �� ������ �ð��� �����ص� �ȴ�.�ֳ��ϸ� ��¡���� �ʹ� ���ر� ������ �������鼭 ���İ��� ���ε��� �� �� �ֱ� �����̴�.

�׷��ٸ�, ������������ �ʶ� ������ �츮�� ���ڵ��� ��¡���� ������ �� �ִ� ���α׷��� �ۼ��Ͻÿ�.

���ε��� ��ġ�� �� ���ε��� �Һ��ϴ� ������ ���� �־��� ���� ��, 5�� �������Ŀ� ����� �� �ִ� ������ �ּڰ��� ���ϸ� �ȴ�.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
int n, m;
const ll MAX = 9999999999999;
ll cache[1111][1111][2];
vector <ll> loc, val, sum;
ll SLV(int left, int right, int flag)
{
	if (left == 1 && right == n)
		return 0;
	ll& ret = cache[left][right][flag];
	if (ret != -1)
		return ret;
	int cur = flag ? right : left;
	ll valsum = sum[n] - sum[right] + sum[left - 1];
	if (left - 1 >= 1)
	{
		ll tmp = SLV(left - 1, right, 0) + (loc[cur] - loc[left - 1]) * valsum;
		if (ret == -1 || ret > tmp) ret = tmp;
	}
	if (right + 1 <= n)
	{
		ll tmp = SLV(left, right + 1, 1) + (loc[right + 1] - loc[cur]) * valsum;
		if (ret == -1 || ret > tmp) ret = tmp;
	}

	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n >> m;
	loc.resize(n + 1);
	val.resize(n + 1);
	sum.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> loc[i] >> val[i];
		sum[i] = sum[i - 1] + val[i];
	}
	memset(cache, -1, sizeof(cache));
	cout << SLV(m, m, 0);
}
*/