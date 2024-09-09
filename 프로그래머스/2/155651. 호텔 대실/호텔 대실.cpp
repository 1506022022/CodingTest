#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>

using namespace std;

// 1. 입출력 확인
// vector<vector<string>> -> int

// 2. 제약조건
// 1 <= book_time.size <= 1000
// book_time[0] HH:MM
// book_time[1] HH:MM
// book_time[0] < book_time[1]
// 10분 딜레이

// 3. 문제 확인
// 최소 객실 수 구하기 문제

// 4. 슈도 코드
// 시작 시간 기준으로 정렬
// 점유 시간이 긴 순으로 정렬

// 시작 시간을 기준으로 정렬한다.
// 순회하며 다음 요소가 이전 요소 리스트에서 겹치는지 확인한다.
// 겹치면 새로운 요소를 생성하고 넣는다.
// 안 겹치면 안 겹치는 요소들 중 가장 차이가 적은 요소에 넣는다.
// 최종적으로 몇 개의 요소가 있는지를 리턴한다?


int ttoi(string t){
    string h = "";
    h+=t[0];
    h+=t[1];
    string m = "";
    m+=t[3];
    m+=t[4];
    return stoi(h)*60+stoi(m);
}


bool cmp(const vector<string>& a, const vector<string>& b){
    return a[0]<b[0];
}

int GetIndex(vector<vector<vector<string>>> room, vector<string> time)
{

    int index = -1;
    int min = ttoi("23:59") - ttoi("00:00");
    int rt = ttoi(time[0]);
       
    for(int i =0; i<room.size();i++)
    {
        auto r = room[i];
        auto last = r[r.size()-1];
        int lt = ttoi(last[1])+ttoi("00:10");
        
        if(rt < lt)
        {
            continue;
        }
        
        if(rt - lt < min)
        {
            min = rt - lt;
            index = i;
        }
    }
    return index;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    vector<vector<vector<string>>> rooms;
    sort(book_time.begin(), book_time.end(), cmp);
    int index = 0;

    for(auto t : book_time)
    {
        auto index = GetIndex(rooms, t);
        if(index == -1)
        {
            rooms.push_back(vector<vector<string>>());
            index = rooms.size()-1;
        }
        
        rooms[index].push_back(t);
    }
    
    return rooms.size();
}