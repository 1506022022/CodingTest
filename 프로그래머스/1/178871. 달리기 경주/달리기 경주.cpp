#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    // 1. 입력
    vector<string> answer;
    for (size_t i = 0; i < players.size(); i++)
    {
        answer.push_back(players[i]);
    }
    unordered_map<string, int> ranking;
    for (int i = 0; i < players.size(); i++)
    {
        ranking.insert(make_pair(answer[i], i));
    }

    // 2. 호명
    for (auto name : callings)
    {
        size_t index = ranking[name];
        string swap = answer[index-1];
        answer[index - 1] = name;
        ranking[name] = index - 1;
        answer[index] = swap;
        ranking[swap] = index;
    }

    // 3. 출력
    return answer;
}