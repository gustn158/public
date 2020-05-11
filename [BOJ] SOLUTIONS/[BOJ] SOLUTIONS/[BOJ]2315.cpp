/*
연구소에서 “초 울트라 캡쑝 으라차 마징가 Z”(이하 마징가)를 완성했다.하지만 지구는 이미 태권 V로 인해 평화로운 상태를 유지하고 있기 때문에 마징가는 동네에서 가로등을 끄는 일을 시키기로 했다.

마을의 중심에는 매우 긴 도로가 있는데, 이 도로 변에는 가로등이 세워져 있다.마징가는 이 가로등을 매일 새벽 5시에 끄기 시작해야 한다.새벽 5시 정각에 마징가는 정확히 여러 가로등 중에서 어느 한 가로등 바로 밑에 위치하고 있다가 일을 시작한다.그런데, 가로등에는 일정량의 전력을 소비하는 전구가 달려있고, 우리의 날쌘돌이 마징가는 절약정신이 매우 투철하기 때문에 쓸데없이 전력을 낭비하길 원치 않는다.

그래서 소비전력을 최소화할 수 있도록 가로등을 끄는 순서를 알아내고 싶어 한다.마징가는 일정하게 1m / sec 의 속도로 움직이며, 가로등을 끈 동안의 시간은 무시해도 된다.왜냐하면 마징가는 너무 날쌔기 때문에 지나가면서 순식간에 가로등을 끌 수 있기 때문이다.

그렇다면, 절약정신으로 똘똘 뭉쳐진 우리의 날쌘돌이 마징가를 도와줄 수 있는 프로그램을 작성하시오.

가로등의 위치와 그 가로등이 소비하는 전력의 양이 주어져 있을 때, 5시 정각이후에 낭비될 수 있는 전력의 최솟값을 구하면 된다.

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