
/*
#include <iostream>
#include <algorithm>
using namespace std;
int queen[100000];
int N;
bool finish = false;
int N_Q(int x)
{
	if (finish)
		return 0;
	if (x == N + 1)
	{
		for (int i = 1; i <= N; i++)
			cout << queen[i] << "\n";
		finish = true;
		return 0;
	}
	for (int i = 1; i <= N; i++)
	{
		int flag = false;
		for (int j = 1; j <= x - 1; j++)
		{
			if (queen[x - j] == i - j || i == queen[x - j] || i + j == queen[x - j])
			{
				flag = true;
				break;
			}
		}
		if (!flag)
		{
			queen[x] = i;
			N_Q(x + 1);
		}
	}
}
int main()
{
	cin >> N;
	
	N_Q(1);
}
*/