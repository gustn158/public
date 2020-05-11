/*
강호는 코딩 교육을 하는 스타트업 스타트링크에 지원했다.오늘은 강호의 면접날이다.하지만, 늦잠을 잔 강호는 스타트링크가 있는 건물에 늦게 도착하고 말았다.

스타트링크는 총 F층으로 이루어진 고층 건물에 사무실이 있고, 스타트링크가 있는 곳의 위치는 G층이다.강호가 지금 있는 곳은 S층이고, 이제 엘리베이터를 타고 G층으로 이동하려고 한다.

보통 엘리베이터에는 어떤 층으로 이동할 수 있는 버튼이 있지만, 강호가 탄 엘리베이터는 버튼이 2개밖에 없다.U버튼은 위로 U층을 가는 버튼, D버튼은 아래로 D층을 가는 버튼이다. (만약, U층 위, 또는 D층 아래에 해당하는 층이 없을 때는, 엘리베이터는 움직이지 않는다)

강호가 G층에 도착하려면, 버튼을 적어도 몇 번 눌러야 하는지 구하는 프로그램을 작성하시오.만약, 엘리베이터를 이용해서 G층에 갈 수 없다면, "use the stairs"를 출력한다.
*/

#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int F, S, G, U, D;
bool check[1000001];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);


	cin >> F >> S >> G >> U >> D;
	
	queue <pair<int, int>> q; 
	check[S] = true;
	q.push({ S,0 });
	bool can = false;
	int ans = 0;
	while (!q.empty())
	{
		int cur_flr = q.front().first;
		int bcnt = q.front().second;
		q.pop();
		if (cur_flr == G)
		{
			ans = bcnt;
			can = true;
			break;
		}
		int new_up = cur_flr + U;
		if (new_up > F || new_up < 0)
			continue;
		if (!check[new_up])
		{
			check[new_up] = true;
			q.push({ new_up,bcnt + 1 });
		}
		int new_down = cur_flr - D;
		if (new_down > F || new_down < 0)
			continue;
		if (!check[new_down])
		{
			check[new_down] = true;
			q.push({ new_down,bcnt + 1 });
		}
	}

	if (can)
		cout << ans;
	else
		cout << "use the stairs";

	return 0;
}