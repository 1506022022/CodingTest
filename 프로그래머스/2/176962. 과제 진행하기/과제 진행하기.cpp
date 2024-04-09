#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;
static stack<vector<string>> waiting;

int ttoi(string time)
{
	return  stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
}
string itot(int time)
{
	string t = time / 60 < 10 ? "0" + to_string(time / 60) : to_string(time / 60);
	string m = time % 60 < 10 ? "0" + to_string(time % 60) : to_string(time % 60);
	return  t + ":" + m;
}

bool cmp(vector<string> a, vector<string> b)
{
	return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> plans) {
	vector<string> answer;
	vector<string> work;
	vector<string> nextWork;

	// 1. 시작시간 오름차순 정렬
	sort(plans.begin(), plans.end(), cmp);

	// 2. 작업
	int time = ttoi(plans[0][1]);
	for (int i = 0; i < plans.size(); i++)
	{
		// 2-1. 진행중인 작업
		work = plans[i];

		// 2-2. 웨이팅 호출
		if (time < ttoi(work[1]) &&
			!waiting.empty())
		{
			work = waiting.top();
			waiting.pop();
			work[1] = itot(time);
			i--;
		}

		// 2-3. 새로 들어온 작업
		if (i + 1 < plans.size())
		{
			nextWork = plans[i + 1];
		}
		else
		{
			answer.push_back(work[0]);
			break;
		}

		// 2-4. 작업 교착
		int as = ttoi(work[1]);
		int ae = as + stoi(work[2]);
		int bs = ttoi(nextWork[1]);
		int be = bs + stoi(nextWork[2]);
		if (ae > bs)
		{
			work[2] = to_string(ae - bs);
			time = ttoi(nextWork[1]);
			waiting.push(work);
		}
		// 2-5. 작업 종료
		else
		{
			time = ttoi(work[1]) + stoi(work[2]);
			answer.push_back(work[0]);
		}
	}
	// 3. 웨이팅 전부 호출
	while (!waiting.empty())
	{
		work = waiting.top();
		waiting.pop();
		answer.push_back(work[0]);
	}

	// 4. 결과 반환
	return answer;
}
