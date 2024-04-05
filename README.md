# 최근에 푼 문제

```C++
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

struct Move
{
	int DX;
	int DY;
	int Distance;

	Move(int dx, int dy, int distance)
	{
		DX = dx;
		DY = dy;
		Distance = distance;
	}
};

vector<int> solution(vector<string> park, vector<string> routes)
{
	const unordered_map<string, Move> Directions =
	{
		{ "E", Move(1, 0,1)  },
		{ "W", Move(-1, 0,1) },
		{ "S", Move(0, 1,1)  },
		{ "N", Move(0, -1,1) }
	};
	vector<int> answer(2);

	// 1-1. 공원 크기 구하기
	int parkHeight = park.size();
	int parkWidth = park[0].size();

	// 1-2. 시작 지점 찾기
	for (int y = 0; y < parkHeight; y++)
	{
		for (int x = 0; x < parkWidth; x++)
		{
			if (park[y][x] == 'S')
			{
				answer[0] = y;
				answer[1] = x;
			}
		}
	}

	// 1-3. 명령 읽어들이기
	vector<Move> moves;
	for (string route : routes)
	{
		string direction = route.substr(0, 1);
		Move move = Directions.at(direction);

		string distance = route.substr(2, route.size() - 2);
		move.Distance = stoi(distance);

		moves.push_back(move);
	}

	// 2. 명령 수행하기
	for (auto move : moves)
	{
		// 2-1. 공원을 벗어난다.
		int x;
		int y;
		y = answer[0] + move.DY * move.Distance;
		x = answer[1] + move.DX *move.Distance;
		if (x < 0 || parkWidth <= x ||
			y < 0 || parkHeight <= y)
		{
			continue;
		}

		// 2-2. 장애물이 있다.
		int dx = 0;
		int dy = 0;
        bool bObstruction = false;
		for (int d = 1; d <= move.Distance; d++)
		{
			dy = move.DY * d;
			dx = move.DX * d;
			if (park[answer[0] + dy][answer[1] + dx] == 'X')
			{
                bObstruction=true;
			}
		}
        if(bObstruction)
        {
            continue;
        }
        
	// 2-3. 여기까지 왔다면 명령을 수행한다.
	answer[0] += move.DY * move.Distance;
	answer[1] += move.DX * move.Distance;
	}

	// 3. 결과 출력.
	return answer;
}

```
