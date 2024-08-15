#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct CompareVector
{
    bool operator()(const vector<int>& a, const vector<int>& b)
    {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    // 작업을 시작 시간 기준으로 정렬
    sort(jobs.begin(), jobs.end());
    
    priority_queue<vector<int>, vector<vector<int>>, CompareVector> pq;
    int currentTime = 0;  // 현재 시간
    int index = 0;        // jobs 배열의 인덱스
    int completedJobs = 0;
    int totalWaitTime = 0;
    
    while (completedJobs < jobs.size()) {
        // 현재 시간까지 도착한 모든 작업을 큐에 넣음
        while (index < jobs.size() && jobs[index][0] <= currentTime) {
            pq.push(jobs[index]);
            index++;
        }
        
        // 큐에서 작업을 하나 꺼내어 처리
        if (!pq.empty()) {
            auto job = pq.top();
            pq.pop();
            currentTime += job[1];
            totalWaitTime += currentTime - job[0];
            completedJobs++;
        } else {
            // 처리할 작업이 없다면 시간을 한 칸 앞으로
            currentTime = jobs[index][0];
        }
    }
    
    return totalWaitTime / jobs.size();
}