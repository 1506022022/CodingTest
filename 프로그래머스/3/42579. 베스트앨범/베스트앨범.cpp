#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

static unordered_map<string, int> GenresTotal;
static vector<int> Plays;

bool CompareGenres(const string a, const string b)
{
	return GenresTotal[a] > GenresTotal[b];
}
bool ComparePlays(const int a, const int b)
{
	return Plays[a] > Plays[b];
}

vector<int> solution(vector<string> genres, vector<int> plays) {
	// 1. 선호 장르
	// 2. 재생수
	// 3. ID
	vector<int> answer;
	unordered_map<string, vector<int>> indices;
	Plays = plays;
	for (int i = 0; i < plays.size(); i++)
	{
		// 장르별 총 재생 횟수
		if (GenresTotal.find(genres[i]) == GenresTotal.end())
		{
			GenresTotal.insert(make_pair(genres[i], plays[i]));
		}
		else
		{
			GenresTotal[genres[i]] += plays[i];
		}

		// 곡별 재생 횟수
		if (indices.find(genres[i]) == indices.end())
		{
			indices.insert(make_pair(genres[i], vector<int>()));
		}

		indices[genres[i]].push_back(i);
	}

	unordered_set<string> s(genres.begin(), genres.end());
	vector<string> v(s.begin(), s.end());
	sort(v.begin(), v.end(), CompareGenres);
	for (auto genre : v)
	{
		sort(indices[genre].begin(), indices[genre].end(), ComparePlays);
		answer.push_back(indices[genre][0]);
		if (indices[genre].size() > 1)
		{
			answer.push_back(indices[genre][1]);
		}

	}
	return answer;
}