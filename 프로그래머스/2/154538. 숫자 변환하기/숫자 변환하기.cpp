#include <string>
#include <vector>
#include <queue>

using namespace std;

// int,int,int -> int
// 1<=x,y,<=1,000,000
// 1<=n<=y
// 최소 변환 횟수 구하기, 변환 가능한지 구하기
// 

// 4. 슈도
// x * 2 약수 x 리턴
// x * 3 약수 x 리턴
// x + n > y 리턴
// () == y 최소값 갱신

int solution(int x, int y, int n) {
    queue<pair<int,int>> bfs;
    bfs.push(make_pair(x,0));
    bool visit[1000001] ={false};
    while(!bfs.empty())
    {
        auto pair = bfs.front();
        auto num = pair.first;
        bfs.pop();
        if(visit[num]) continue;;
        visit[num] = true;
        if(num == y) return pair.second;
        if(num * 2 == y || num * 3 == y || num + n == y) return pair.second+1;
        if(num + n < y) bfs.push(make_pair(num+n,pair.second+1));
        if(num * 3 < y) bfs.push(make_pair(num*3,pair.second+1));
        if(num * 2 < y) bfs.push(make_pair(num*2,pair.second+1));
    }
    
    return -1;
}