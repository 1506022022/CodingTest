#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

// 오름차순 정렬 -> 0 1,2 ... 이진 트리 root, rooot +1을 합친다... 바뀐 root가 K를 넘을 때까지.
int solution(vector<int> scoville, int K) {
	int answer = 0;
	std::priority_queue<int, std::vector<int>, std::greater<int>> h(scoville.begin(), scoville.end());
	while (1 < h.size() && h.top() < K)
	{
		auto first = h.top();
		h.pop();
		auto second = h.top();
		h.pop();

		h.push(second*2+first);
		answer++;
	}
    if(h.size()==1 && h.top() < K)
    {
        answer = -1;
    }
	return answer;
}