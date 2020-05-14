/*


A����� B���� ���漱�� ���� �� ��° �ο�� �ִ�. ���� ������ ũ��� ���簢���̰�, R��C ���� ĭ���� �������� �ִ�. ��� ĭ���� ��� ���� �Ǵ� �ٳ��� ������ �ɾ��� �ִ�.

���, �⳪�� ���� ������ ������ ���� �߸������� ���� ������ �����ߴ�. ����̴� �ҵ����� �̿��� �Ϻ� ĭ�� �ִ� ������ ��� �����ϰ�, �׷��� ĭ�� ���漱���� �̿��Ϸ��� �Ѵ�. �ҵ����� ���� ���� ��ĭ���� ����ϸ�, �� ĭ �Ʒ�, ������, ������ �Ʒ� �밢������ �̵��� �� �ִ�. �ҵ����� ������ �Ʒ�ĭ�� ������ ������ �̵��Ѵ�.

A�� �ҵ����� ������ ���� �Ʒ����� ������ �ǰ�, B�� ������ ������ �ȴ�. ����, ���� �ϳ��� ���� ���ϴ� ��찡 ���� ���� �ִ�.

������ A�� ��� ������� ����� �����ϰ�, B�� ��� ������� �ٳ����� �����Ѵٴ� ����� �˰� �ִ�. ����, �ҵ����� ������ ���� �Ʒ��ʿ� �ִ� ��� ������ ������ ���ʿ� �ִ� �ٳ��� ���� ������ ���� ũ�� ������� �Ѵ�.

������ �� �� ���� ū ���� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.


#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int r, c;
int A[1503][1503];
int B[1503][1503];
int cache[1503][1503][3];
int dx[3] = { 1,0,1 };
int dy[3] = { 0,1,1 };

int SLV(int x, int y, int direc)
{
	if (x == r && y == c )
		return 0;
	int& ret = cache[x][y][direc];
	if (ret != -1)
		return ret;
	ret = 0;
	//������ �Ʒ�
	if (x < r  && y < c )
	{
		ret = max(ret, SLV(x + 1, y + 1, 2) + A[r][y] - A[x][y] + B[x][y + 1]);
	}
	//�Ʒ�
	if (x < r )
	{
		ret = max(ret, SLV(x + 1, y, 0));
	}
	//������
	if (y < c )
	{
		ret = max(ret, SLV(x, y + 1, 1) + A[r][y] - A[x][y] + B[x-1][y+1]);
	}

	return ret;

}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> r >> c;
	for (int i = 1; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			string s;
			cin >> s;
			if (s[0] == 'A')
			{
				A[i][j] = stoi(s.substr(1));
			}
			else
			{
				B[i][j] = stoi(s.substr(1));
			}
		}
	}
	for (int i = 2; i <= r; i++)
	{
		for (int j = 1; j <= c; j++)
		{
			A[i][j] += A[i - 1][j];
			B[i][j] += B[i - 1][j];
		}
	}
	memset(cache, -1, sizeof(cache));
	cout << SLV(1, 1, 0);
	
}
*/