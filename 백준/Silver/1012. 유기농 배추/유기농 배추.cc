#include <iostream>
#include <queue>

using namespace std;

static const int DX[4] = { 1,-1,0,0 };
static const int DY[4] = { 0,0,1,-1 };

int main()
{
	// 0. 최적화
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	// 1. 입력
	int A[50][50];
	int T;
	cin >> T;
	int height;
	int width;
	int K;
	

	// 2. 탐색 시작
	while (T-- > 0)
	{
		cin >> width >> height;
		cin >> K;

		// 2-1. 밭 생성
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				A[y][x] = 0;
			}
		}

		// 2-2. 배추 심기
		int y;
		int x;
		for (int i = 0; i < K; i++)
		{
			cin >> x >> y;
			A[y][x] = 1;
		}

		// 2-3. BFS 탐색
		int group = 2;
		queue<vector<int>> bfs;
		for (int y = 0; y < height; y++)
		{
			for (int x = 0; x < width; x++)
			{
				// 2-3-1. 그룹이 지어졌거나, 배추가 없는 땅
				if (A[y][x] != 1)
				{
					continue;
				}
				// 2-3-2. 배추흰지렁이가 필요한 땅
				else
				{
					// BFS 시작
					bfs.push({ x, y });
					while (!bfs.empty())
					{
						auto pos = bfs.front();
						bfs.pop();

						// 배추가 있다.
						if (A[pos[1]][pos[0]] == 1)
						{
							A[pos[1]][pos[0]] = group;

							// 사방을 살핀다.
							for (int i = 0; i < 4; i++)
							{
								int nx = pos[0] + DX[i];
								int ny = pos[1] + DY[i];

								if (0 <= nx && nx < width &&
									0 <= ny && ny < height)
								{
									bfs.push({ nx, ny });
								}
							}
						}
					}

					// 새로운 그룹을 형성한다.
					group++;
				}
			}
		}

		// 3. 결과 출력
		cout << group - 2 << '\n';
	}
}