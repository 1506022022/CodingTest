#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
	// 1. 입력
	long long answer = 0;

	// 2. 1사분면만 탐색
	long long r1Pow = (long long)r1 * (long long)r1;
	long long r2Pow = (long long)r2 * (long long)r2;
	long long yPow;
	int outCircleVertices;
	int inCircleVertices;

	for (int y = 1; y <= r2; y++)
	{

		// 2-1. 바깥 원에 포함된 버텍스를 구한다.
		yPow = (long long)y * (long long)y;
		outCircleVertices = floor(sqrt(r2Pow - yPow)) + 1;

		// 2-2. 안쪽 원에 포함된 버텍스를 구한다.
		if (y < r1)
		{
			double x = sqrt(r1Pow - yPow);
			if (0.00000001 < fmod(x, 1.0))
			{
				x += 1;
			}
			inCircleVertices = floor(x);
		}
		else
		{
			inCircleVertices = 0;
		}
		// 2-3. 두 원의 버텍스의 교집합을 구한다.
		answer += outCircleVertices - inCircleVertices;
	}

	// 3. 4개의 사분면 취합한다.
	answer *= 4;

	// 4. 결과를 출력한다.
	return answer;
}