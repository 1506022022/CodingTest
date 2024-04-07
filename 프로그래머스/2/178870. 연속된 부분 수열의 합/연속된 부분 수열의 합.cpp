#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
	// 1. 입력
	vector<int> answer;
	int end = 0;
	int sum = 0;
	int start = 0;

	// 2. 슬라이딩 윈도우 생성
	// 2-1. 종료 지점
	end = sequence.size() - 1;
	while (k < sequence[end])
	{
		end--;
	}
	// 2-2 시작 지점
	start = end + 1;
	while (sum < k)
	{
        start--;
		sum += sequence[start];
	}

	// 3. 구간 조정
	while (sum != k)
	{
		// 3-1. 값이 부족하다.
		if (sum < k)
		{
			start--;
			sum += sequence[start];
		}
		// 3-2. 값이 넘친다.
		else
		{
			sum -= sequence[end];
			end--;
		}
	}

    
	// 4. 왼쪽으로 슬라이딩
    if(0<start)
	while (sequence[start-1] == sequence[end])
	{
		start--;
		end--;
		if (start == 0)
		{
			break;
		}
	}
    
	answer = { start,end };

	// 5. 결과 반환
	return answer;
}