/*
* 미로탐색
* https://www.acmicpc.net/problem/2178
*
* @ddunny
*/
#include <iostream>
#include <queue>

using namespace std;

#define MAX_SIZE 101

struct position {
	int y, x;
};
queue<position> path;

int N, M;
int miro[MAX_SIZE][MAX_SIZE];
int dir[4][2] = { {0, 1}, {1, 0}, {0, -1}, {-1, 0} };

int BFS() {
	position now;
	int nexty, nextx;
	path.push({ 0, 0 }); //무조건 0,0 부터 시작

	while (!path.empty()) {
		now = { path.front().y, path.front().x };
		path.pop();

		for (int i = 0; i < 4; i++) {
			nexty = now.y + dir[i][0];
			nextx = now.x + dir[i][1];

			if (0 <= nexty && nexty < N && 0 <= nextx && nextx < M && miro[nexty][nextx] == 1) { /*이동가능하다면*/
				miro[nexty][nextx] = miro[now.y][now.x] + 1;
				path.push({ nexty, nextx });
			}
		}
	}

	return miro[N-1][M-1];
}

int main(void) {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%1d", &miro[i][j]);
		}
	}
	
	int result = BFS();
	cout << result << endl;

	return 0;
}