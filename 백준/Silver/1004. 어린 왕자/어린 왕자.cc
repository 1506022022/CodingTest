#include <iostream>
#include <cmath>
using namespace std;


int main()
{
    // 0. 최적화
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    // 1. 입력
    // 1-1. 테스트 케이스 입력 
	int t;
	cin >> t;
    
	for (int i = 0; i < t; i++)
	{
        // 1-2. 출발, 도착 입력
		int start[2];
		int end[2];
		cin >> start[0] >> start[1];
		cin >> end[0] >> end[1];
        // 1-3. 행성 입력
		int n;
		cin >> n;
		int x;
		int y;
		int r;
		int count = 0;
        
        // 2. 탐색
		for (int j = 0; j < n; j++)
		{
			cin >> x >> y >> r;
			float dis1 = sqrt(pow(x - start[0], 2) + pow(y - start[1], 2));
			float dis2 = sqrt(pow(x - end[0], 2) + pow(y - end[1], 2));

            // 하나의 점만 행성계에 포함되면 진입, 이탈이 발생한다.
			if ((dis1 <= r)^(dis2 <= r))
			{
				count++;
			}
		}
        
        // 3. 결과 출력
		cout << count << endl;
	}
}