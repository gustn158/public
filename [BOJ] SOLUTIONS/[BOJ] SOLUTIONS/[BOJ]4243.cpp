/*
���� ���� ��ü�� �����̰�, �������� �ִ� ���� ���� ���� ������ �����ϴ� ������ �ð� �ִ�.

�������� �������� ��Ÿ�� �� �ְ�, ����� ȸ��� ������ ���ʺ��� ������� ���� ���� �� pi�� ��Ÿ�� �� �ִ�. ȸ��� pa�� �ְ�, s�� ��Ÿ����. ���� s���� ������ �����ؼ�, ��� ���� pi�� ��� �� �� �湮�ؾ� �Ѵ�. ������ i�� ���ؼ�, pi�� pi+1���̸� �����µ� �ɸ��� �ð��� t[pi,pi+1]�̴�. pi�� ��� �ð� ��i�� s�� ����ؼ� pi�� ó�� �����ϱ� ���� �ɸ� �ð��̴�. ������ s = pa�� ��� �ð� ��a�� 0�̴�. ���� ��� ������ ��� �ð��� ���� �ּҰ� �ǰ� �ϱ� ���� ������ �ؾ� �Ѵ�.

�Ʒ� �׸����� �� 6���� ���� p1���� p6������ �ְ�, ������ s�� p3�̴�. ��, t[p1,p2] = 7, t[p2,p3] = 4, t[p3,p4] = 1, t[p4,p5] = 2, t[p5,p6] = 9�̴�. ��찡 s���� ���������� �ȱ� �����Ѵٸ�, ��� �ð� ��4�� ��5�� 1�� 3�� �ȴ�. �Ʒ� �׸��� �����ִ� ������� ������ �Ѵٸ�, ��� �ð��� ���� 71�� �ȴ�. 71���� ��� �ð��� ���� ���̴� ����� ����.

���� �� N��, pi�� pi+1 ���̸� �����µ� �ɸ��� �ð� t[pi,pi+1] (t = 1,...,N-1)�� �־����� ��, ��� �ð��� �ּҷ� �ϴ� ���α׷��� �ۼ��Ͻÿ�
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const ll MAX = 99999999999;
ll cache[101][101][2];
vector <ll> sum;
int n;
ll SLV(int left, int right, int flag)
{
	if (left == 1 && right == n)
		return 0;
	ll& ret = cache[left][right][flag];
	if (ret != -1)
		return ret;
	int cur = flag ? right : left;
	ll total = n - right + left - 1;
	if (right + 1 <= n)
	{
		ll tmp = SLV(left, right + 1, 1) + total * (sum[right + 1] - sum[cur]);
		if (ret == -1 || tmp < ret)ret = tmp;
	}
	if (left - 1 >= 1)
	{
		ll tmp = SLV(left - 1, right, 0) + total * (sum[cur] - sum[left - 1]);
		if (ret == -1 || tmp < ret) ret = tmp;
	}
	
	return ret;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while (T--)
	{
		cin >> n;
		int cur_idx;
		cin >> cur_idx;
		sum.resize(n + 1);
		sum[0] = 0;
		sum[1] = 0;
		for (int i = 2; i <= n; i++)
		{
			int dist;
			cin >> dist;
			sum[i] = dist + sum[i - 1];
		}
		memset(cache, -1, sizeof(cache));
		
		cout << SLV(cur_idx, cur_idx, 0) << "\n";
		sum.clear();
	}
}
*/