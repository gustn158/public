/*


진영 택배 회사는 물품을 빠르고 정확하게 배송하기로 유명하다. 본점으로 수집된 물품은 각각 지정된 지점으로 배송되는데, 본점은 고속도로가 시작하는 곳에 있고, 지점들은 1번부터 10,000번까지 번호 순서대로 고속도로를 따라 일정한 간격으로 놓여 있다.

진영 택배 회사에서 물품을 옮기는 데는 트럭과 헬리콥터를 이용하는 두 가지 방법이 있다. 트럭은 본점에서 지점으로 또는 지점에서 다른 지점으로 물품을 옮기는 데 사용되고, 헬리콥터는 본점에서 지점으로 물품을 옮기는 데 사용된다. 트럭이 한 물품을 운반하는 비용은 그 물품의 운송 거리에 비례하고, 헬리콥터는 물품의 개수와 운송 거리와는 상관없이 비용이 일정하다. 트럭으로는 한 번에 하나의 물품을 운송할 수 있으나, 헬리콥터가 운송할 수 있는 물품의 개수는 제한이 없다. 풍족한 진영 택배 회사에는 항상 충분한 수의 트럭과 헬리콥터가 준비되어 있다고 가정한다.

예를 들어, 본점에 10번, 40번, 30번, 50번, 10번 지점으로 옮겨야 하는 5개의 물품이 접수되었는데, 물품 하나를 트럭으로 한 지점 간격 옮기는 데는 10만큼의 비용이 들고, 헬리콥터를 한 번 이용하는 데는 물품의 개수나 거리에 상관없이 200만큼의 비용이 든다고 하자. 5개의 물품을 모두 트럭을 이용해서 옮기면 1400만큼의 비용이 든다. 하지만 10번 지점으로 가야하는 두 물품은 트럭으로 옮기고, 나머지 세 물품은 한꺼번에 40번 지점으로 헬리콥터를 이용해 옮기면 40번 지점으로 갈 물품은 목적 지점에 도착되었고, 이어 30번 지점과 50번 지점으로 갈 물품을 40번 지점에서 각각 트럭을 이용하여 옮기면, 총 600만큼의 비용이 든다.

배송할 물품의 총 개수와, 각 물품의 목적 지점, 트럭과 헬리콥터 사용 비용이 주어졌을 때, 모든 물품을 목적 지점으로 옮기는 데 드는 총 비용의 최솟값을 구하는 프로그램을 작성하시오.

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
int n;
vector <int> v,sum; // 위치 저장
int TVAL, HVAL;
typedef long long int ll;
ll cache[3001];
const ll MAX = 9999999999;
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	v.resize(n + 1);
	sum.resize(n + 1);
	for (int i = 1; i <= n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin()+1, v.end());
	for (int i = 1; i <= n; i++)
	{
		sum[i] = sum[i - 1] + v[i];
	}
	cin >> TVAL >> HVAL;
	for (int i = 1; i <= n; i++)
	{
		cache[i] = cache[i - 1] + v[i] * TVAL;
		for (int j = i; j >= 1; j--)
		{
			int mid = (i + j) / 2;
			int left = (v[mid] * (mid - j + 1) - (sum[mid] - sum[j - 1])) * TVAL;
			int right = ((sum[i] - sum[mid - 1]) - (v[mid] * (i - mid + 1))) * TVAL;

			int cost = left + right + HVAL;
			cache[i] = min(cache[i], cache[j - 1] + cost);
		}
	}
	cout << cache[n];
}
*/