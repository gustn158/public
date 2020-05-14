/*


수아는 x축 위에 앉아있다. "나는 x축이 너무 좋아!!" 라고 수아가 말했다. 수평선에는 n개의 사탕바구니가 있고, 각 사탕 바구니에는 m개의 사탕이 있다. 각 사탕 바구니는 x1, x2, ..., xn 에 있고, 수아는 0에 있다.

오늘은 날씨가 덥다. 따라서, 시간이 1만큼 지날 때 마다, 모든 사탕바구니에서 사탕은 1만큼 줄어든다. 수아는 매우 배가고프기 때문에, 사탕바구니에 있는 사탕을 0만에 모두 먹을 수 있다. 수아가 1만큼 움직일 때, 시간은 1만큼 지나간다.

수아가 먹을 수 있는 사탕의 최대 개수를 구하는 프로그램을 작성하시오.



#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n, m;
int cache[303][303][2]; // i~j번째 사탕 먹을때 위치
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