#include <iostream>
#include <cmath>
#include <set>
using namespace std;

int main() 
{
	// 0. 입출력 최적화
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	// 1. 입력
	long A;
	long B;
	cin >> A >> B;
	int a = sqrt(A);
	int b = sqrt(B);
	bool Arr[10000001];
	for (int i = 2; i < 10000001; i++)
	{
		Arr[i] = true;
	}
	// 2. 채 알고리즘으로 소수 구하기
	int count = 0;
	for (int i = 2; i <= b; i ++)
	{
		if (Arr[i])
		{
			for (int j = i + i; j <= b; j+=i)
			{
				Arr[j] = false;
			}
		}
	}
	// 3. 거의 소수 탐색
	for (int i = 2; i <= b; i++)
	{
		if (Arr[i])
		for (int j = 2; pow(i, j) <= B; j++)
		{
			if(A<=pow(i,j))
			count++;
		}
	}
	// 4. 결과 출력
	cout << count;
}