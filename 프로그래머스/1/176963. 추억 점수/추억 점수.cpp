#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer(photo.size(), 0);
    unordered_map<string, int> M;
    for (int i = 0; i < name.size(); i++)
    {
        M .insert(make_pair(name[i], yearning[i]));
    }
    for (int i = 0; i < photo.size(); i++)
    {
        for (string n : photo[i])
        {
            answer[i] += M[n];
        }
    }
    return answer;
}