#include <iostream>

using namespace std;

static char A[26][2];

void PreorderRecursive(int index)
{
	cout << (char)('A'+index);
	if (A[index][0] != '.')
	{
		PreorderRecursive(A[index][0] - 'A');
	}
	if (A[index][1] != '.')
	{
		PreorderRecursive(A[index][1] - 'A');
	}
}
void InorderRecursive(int index)
{
	if (A[index][0] != '.')
	{
		InorderRecursive(A[index][0] - 'A');
	}
	cout << (char)('A' + index);
	if (A[index][1] != '.')
	{
		InorderRecursive(A[index][1] - 'A');
	}
}
void PostorderRecursive(int index)
{
	if (A[index][0] != '.')
	{
		PostorderRecursive(A[index][0] - 'A');
	}
	if (A[index][1] != '.')
	{
		PostorderRecursive(A[index][1] - 'A');
	}
	cout << (char)('A' + index);
}

int main()
{
	// 0. 최적화
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// 1. 입력
	// 1-1. N 입력
	short N;
	cin >> N;
	// 1-2. 노드 입력
	size_t index;
	char c;
	for (size_t i = 0; i < N; i++)
	{
		cin >> c;
		index = c-'A';
		cin >> c;
		A[index][0] = c;
		cin >> c;
		A[index][1] = c;
	}

	// 2. 결과 출력
	PreorderRecursive(0);
	cout << '\n';
	InorderRecursive(0);
	cout << '\n';
	PostorderRecursive(0);
}