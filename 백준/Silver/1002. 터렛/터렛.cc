#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	// 1. 입력
	int x1;
	int y1;
	int r1;
	int x2;
	int y2;
	int r2;
	int N;
	double distance;
	cin >> N;
	for (size_t i = 0; i < N; i++)
	{
		cin >> x1 >> y1 >> r1;
		cin >> x2 >> y2 >> r2;

		distance = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
		// 1. 두 원이 겹쳤다.
		if (distance == 0 && r1==r2)
		{
			cout << -1 << '\n';
		}
		// 2. 두 원이 한 점에서 만난다.
		else if (distance == r1 + r2  || distance == abs(r1-r2) )
		{
			cout << 1 << '\n';
		}
		// 3. 두 원이 두 점에서 만난다.
		else if(distance < r1 + r2 && min(r1,r2)+distance > max(r1,r2))
		{
			cout << 2 << '\n';
		}
		else
		{
		// 여기까지 왔다면 두 원은 만나지 않는다.
		cout << 0 << '\n';

		}


		
	}
}