#include <cmath>
#include <iostream>

using namespace std;

int main()
{
	// 0. 최적화
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 1. 입력	
	long n;
	cin >> n;
    long result = n;
    
	// 2. 오일러 피
	for (int i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			result = result - result / i;
			while (n % i == 0)
			{
				n = n / i;
			}
		}
	}
	if (n > 1)
	{
		result = result - result /n;
	}
	// 3. 결과 출력
	cout << result;
}