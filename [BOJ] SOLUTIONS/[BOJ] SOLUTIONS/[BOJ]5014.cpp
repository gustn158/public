/*
��ȣ�� �ڵ� ������ �ϴ� ��ŸƮ�� ��ŸƮ��ũ�� �����ߴ�.������ ��ȣ�� �������̴�.������, ������ �� ��ȣ�� ��ŸƮ��ũ�� �ִ� �ǹ��� �ʰ� �����ϰ� ���Ҵ�.

��ŸƮ��ũ�� �� F������ �̷���� ���� �ǹ��� �繫���� �ְ�, ��ŸƮ��ũ�� �ִ� ���� ��ġ�� G���̴�.��ȣ�� ���� �ִ� ���� S���̰�, ���� ���������͸� Ÿ�� G������ �̵��Ϸ��� �Ѵ�.

���� ���������Ϳ��� � ������ �̵��� �� �ִ� ��ư�� ������, ��ȣ�� ź ���������ʹ� ��ư�� 2���ۿ� ����.U��ư�� ���� U���� ���� ��ư, D��ư�� �Ʒ��� D���� ���� ��ư�̴�. (����, U�� ��, �Ǵ� D�� �Ʒ��� �ش��ϴ� ���� ���� ����, ���������ʹ� �������� �ʴ´�)

��ȣ�� G���� �����Ϸ���, ��ư�� ��� �� �� ������ �ϴ��� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.����, ���������͸� �̿��ؼ� G���� �� �� ���ٸ�, "use the stairs"�� ����Ѵ�.
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