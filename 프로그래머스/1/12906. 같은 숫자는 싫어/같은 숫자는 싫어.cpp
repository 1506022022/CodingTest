#include <vector>
#include <iostream>
#include <queue>
using namespace std;

vector<int> solution(vector<int> arr)
{
    vector<int> answer;
    queue<int> q;
    for (auto i : arr)
    {
        if (!q.empty() && q.back() == i)
        {
            continue;
        }
        q.push(i);
    }
    while (!q.empty())
    {
        answer.push_back(q.front());
        q.pop();
    }
    return answer;
}
