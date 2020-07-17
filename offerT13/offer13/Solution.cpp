#include <vector>
using namespace std;

class Solution {
public:
	struct Point {
		int x;
		int y;
		Point(int a, int b) {
			x = a;
			y = b;
		}
	};
	vector<Point> queue;
	bool visit[100][100] = { 0 };
	int movex[4] = { 1, -1, 0 ,0 };
	int movey[4] = { 0, 0, 1, -1 };


	bool judge(int x, int y, int m, int n, int k) {
		if (x < 0 || y < 0 || x >= m || y >= n) {
			return false;
		}
		int sumx = x / 10 + x % 10;
		int sumy = y / 10 + y % 10;
		if (sumx + sumy > k) {
			return false;
		}
		if (visit[x][y] == 1) {
			return false;
		}
		return true;
	}

	int movingCount(int m, int n, int k) {
		visit[0][0] = 1;
		queue.push_back(Point(0, 0));
		int head = 0;
		int tail = 0;
		while (head <= tail) {
			for (int i = head; i <= tail; i++) {
				int x = queue[i].x;
				int y = queue[i].y;
				for (int j = 0; j < 4; j++) {
					int newx = x + movex[j];
					int newy = y + movey[j];
					if (judge(newx, newy, m, n, k)) {
						visit[newx][newy] = 1;
						queue.push_back(Point(newx, newy));
					}
				}
			}
			head = tail + 1;
			tail = queue.size() - 1;
		}

		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 1) {
					ans++;
				}
			}
		}
		return ans;
	}
};