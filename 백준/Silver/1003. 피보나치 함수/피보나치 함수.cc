#include <iostream>

using namespace std;

static int A[41][2];

void fibonacci(int n)
{
	if (n > 1)
	{
		A[n][0] = A[n - 1][0] + A[n - 2][0];
		A[n][1] = A[n - 1][1] + A[n - 2][1];
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int T;
	cin >> T;

	for (int i = 0; i < 41; i++)
	{
		A[i][0] = 0;
		A[i][1] = 0;
	}

	A[0][0] = 1;
	A[0][1] = 0;
	A[1][0] = 0;
	A[1][1] = 1;

	for (size_t i = 2; i < 41; i++)
	{
		fibonacci(i);
	}

	for (int i = 0; i < T; i++)
	{
		int N;
		cin >> N;
		cout << A[N][0] << " " << A[N][1] << '\n';
	}
}
