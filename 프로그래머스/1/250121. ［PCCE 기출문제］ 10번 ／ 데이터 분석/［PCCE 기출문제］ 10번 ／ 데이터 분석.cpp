#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct CustomComparator {
	int mExt;

	CustomComparator(int etx) : mExt(etx) {}

	bool operator()(vector<int> a, vector<int> b) const
	{
		return a[mExt] < b[mExt];
	}
};

vector<vector<int>> solution(vector<vector<int>> data, string ext, int val_ext, string sort_by) {
	// 1. 입력
	vector<vector<int>> answer;
	unordered_map<string, size_t> table;
	table.insert(make_pair("code", 0));
	table.insert(make_pair("date", 1));
	table.insert(make_pair("maximum", 2));
	table.insert(make_pair("remain", 3));

	// 2. 필터
	for (auto item : data)
	{
		if (item[table[ext]] <= val_ext)
		{
			answer.push_back(item);
		}
	}

	// 3. 정렬
	sort(answer.begin(), answer.end(), CustomComparator(table[sort_by]));
    
	// 4. 결과 출력
	return answer;
}