#include <iostream>
using namespace std;

int main() 
{
	int A[1000];
	int N;
	int a;
	cin >> N;
	for (int i = 0; i < 1000; i++) {
		A[i] = 0;
	}
	for (int i = 0; i < N; i++)
	{
		cin >> a;
		A[a]++;
	}
	int result = 0;
	int multi = 0;
	int jarisu = 0;
	int sum = 0;
	for (int i = 1; i < 999; i++)
	{
		if (A[i]>0)
		for (int j = i+1; j < 1000; j++)
		{
			if (A[j]==0) continue;
			
			multi = i * j;
			jarisu = 100000;
			sum = 0;
			while (jarisu > 0)
			{
				sum += multi / jarisu;
				multi -= (multi / jarisu) * jarisu;
				jarisu /= 10;
			}
			result = max(result, sum);
		}
	}
	for (int i = 1; i < 1000; i++)
	{
		if (A[i] > 1)
		{
			multi = i * i;
			jarisu = 100000;
			sum = 0;
			while (jarisu > 0)
			{
				sum += multi / jarisu;
				multi -= (multi / jarisu) * jarisu;
				jarisu /= 10;
			}
			result = max(result, sum);
		}
	}
	cout << result;
}