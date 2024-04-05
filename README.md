# 최근에 푼 문제

<details>
<summary><b>문제 내용 보기</b></summary>

 
# [level 1] 공원 산책 - 172928 

[문제 링크](https://school.programmers.co.kr/learn/courses/30/lessons/172928?language=cpp) 

### 성능 요약

메모리: 3.61 MB, 시간: 0.02 ms

### 구분

코딩테스트 연습 > 연습문제

### 채점결과

정확성: 100.0<br/>합계: 100.0 / 100.0

### 제출 일자

2024년 04월 05일 21:14:40

### 문제 설명

<p>지나다니는 길을 'O', 장애물을 'X'로 나타낸 직사각형 격자 모양의 공원에서 로봇 강아지가 산책을 하려합니다. 산책은 로봇 강아지에 미리 입력된 명령에 따라 진행하며, 명령은 다음과 같은 형식으로 주어집니다.</p>

<ul>
<li>["방향 거리", "방향 거리" … ]</li>
</ul>

<p>예를 들어 "E 5"는 로봇 강아지가 현재 위치에서 동쪽으로 5칸 이동했다는 의미입니다. 로봇 강아지는 명령을 수행하기 전에 다음 두 가지를 먼저 확인합니다.</p>

<ul>
<li>주어진 방향으로 이동할 때 공원을 벗어나는지 확인합니다.</li>
<li>주어진 방향으로 이동 중 장애물을 만나는지 확인합니다.</li>
</ul>

<p>위 두 가지중 어느 하나라도 해당된다면, 로봇 강아지는 해당 명령을 무시하고 다음 명령을 수행합니다.<br>
공원의 가로 길이가 W, 세로 길이가 H라고 할 때, 공원의 좌측 상단의 좌표는 (0, 0), 우측 하단의 좌표는 (H - 1, W - 1) 입니다.</p>

<p><img src="https://user-images.githubusercontent.com/62426665/217702316-1bd5d3ba-c1d7-4133-bfb5-36bdc85a08ba.png" title="" alt="image"></p>

<p>공원을 나타내는 문자열 배열 <code>park</code>, 로봇 강아지가 수행할 명령이 담긴 문자열 배열 <code>routes</code>가 매개변수로 주어질 때, 로봇 강아지가 모든 명령을 수행 후 놓인 위치를 [세로 방향 좌표, 가로 방향 좌표] 순으로 배열에 담아 return 하도록 solution 함수를 완성해주세요.</p>

<hr>

<h5>제한사항</h5>

<ul>
<li>3 ≤ <code>park</code>의 길이 ≤ 50

<ul>
<li>3 ≤ <code>park[i]</code>의 길이 ≤ 50

<ul>
<li><code>park[i]</code>는 다음 문자들로 이루어져 있으며 시작지점은 하나만 주어집니다.

<ul>
<li>S : 시작 지점</li>
<li>O : 이동 가능한 통로</li>
<li>X : 장애물</li>
</ul></li>
</ul></li>
<li><code>park</code>는 직사각형 모양입니다.</li>
</ul></li>
<li>1 ≤ <code>routes</code>의 길이 ≤ 50

<ul>
<li><code>routes</code>의 각 원소는 로봇 강아지가 수행할 명령어를 나타냅니다.</li>
<li>로봇 강아지는 <code>routes</code>의 첫 번째 원소부터 순서대로 명령을 수행합니다.</li>
<li><code>routes</code>의 원소는 "op n"과 같은 구조로 이루어져 있으며, op는 이동할 방향, n은 이동할 칸의 수를 의미합니다.

<ul>
<li>op는 다음 네 가지중 하나로 이루어져 있습니다.

<ul>
<li>N : 북쪽으로 주어진 칸만큼 이동합니다.</li>
<li>S : 남쪽으로 주어진 칸만큼 이동합니다.</li>
<li>W : 서쪽으로 주어진 칸만큼 이동합니다.</li>
<li>E : 동쪽으로 주어진 칸만큼 이동합니다.</li>
</ul></li>
<li>1 ≤ n ≤ 9</li>
</ul></li>
</ul></li>
</ul>

<hr>

<h5>입출력 예</h5>
<table class="table">
        <thead><tr>
<th>park</th>
<th>routes</th>
<th>result</th>
</tr>
</thead>
        <tbody><tr>
<td>["SOO","OOO","OOO"]</td>
<td>["E 2","S 2","W 1"]</td>
<td>[2,1]</td>
</tr>
<tr>
<td>["SOO","OXX","OOO"]</td>
<td>["E 2","S 2","W 1"]</td>
<td>[0,1]</td>
</tr>
<tr>
<td>["OSO","OOO","OXO","OOO"]</td>
<td>["E 2","S 3","W 1"]</td>
<td>[0,0]</td>
</tr>
</tbody>
      </table>
<hr>

<h5>입출력 예 설명</h5>

<p>입출력 예 #1</p>

<p>입력된 명령대로 동쪽으로 2칸, 남쪽으로 2칸, 서쪽으로 1칸 이동하면 [0,0] -&gt; [0,2] -&gt; [2,2] -&gt; [2,1]이 됩니다.</p>

<p>입출력 예 #2</p>

<p>입력된 명령대로라면 동쪽으로 2칸, 남쪽으로 2칸, 서쪽으로 1칸 이동해야하지만 남쪽으로 2칸 이동할 때 장애물이 있는 칸을 지나기 때문에 해당 명령을 제외한 명령들만 따릅니다. 결과적으로는 [0,0] -&gt; [0,2] -&gt; [0,1]이 됩니다.</p>

<p>입출력 예 #3</p>

<p>처음 입력된 명령은 공원을 나가게 되고 두 번째로 입력된 명령 또한 장애물을 지나가게 되므로 두 입력은 제외한 세 번째 명령만 따르므로 결과는 다음과 같습니다. [0,1] -&gt; [0,0]</p>


> 출처: 프로그래머스 코딩 테스트 연습, https://school.programmers.co.kr/learn/challenges
</details>

**[코드 짜면서 고민했던 내용]**
- 이동 방향과 거리가 문자열 배열로 주어졌는데 이 데이터를 가독성 좋으면서도 최대한 짧게 작성하기 위해서 고민했습니다.
- 코딩 테스트에서는 그럴 리 없지만, 만약 나중에 기능이 수정된다면 이라는 가정을 하고 작성해 봤습니다. 그래서 기능을 제거하거나 추출하기 쉽도록 기능별로 번호를 매겼습니다. 또한 2-2번 파트는 일부러 bool 변수를 둬서 다른 파트와 연관되지 않도록 했습니다.

**[코드]**
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
