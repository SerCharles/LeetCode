#include<vector>
using namespace std;

class Solution {

public:
	bool visit[200][200] = { 0 };
	int movex[4] = { 1, -1, 0, 0 };
	int movey[4] = { 0, 0, 1, -1 };
	bool success = false;
	void DFS(int steps, int placex, int placey, vector<vector<char>>& board, string& word) {
		//找前后左右符合word[steps] = board[i][j]的，而且visit = 0
		if (success == true) {
			return;
		}
		if (steps == word.size()) {
			success = true;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int newx = movex[i] + placex;
			int newy = movey[i] + placey;
			if (newx < 0 || newy < 0 || newx >= board.size() || newy >= board[newx].size()) {
				continue;
			}
			if (visit[newx][newy] == 1) {
				continue;
			}
			if (board[newx][newy] == word[steps]) {
				visit[newx][newy] = 1;
				DFS(steps + 1, newx, newy, board, word);
				visit[newx][newy] = 0;
			}
		}
	}

	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == word[0]) {
					visit[i][j] = 1;
					DFS(1, i, j, board, word);
					visit[i][j] = 0;
				}
			}
		}
		return success;
	}
};

int main()
{
	vector<char> board0;
	board0.push_back('a');
	board0.push_back('b');
	vector<char> board1;
	board1.push_back('c');
	board1.push_back('d');
	vector<vector<char>> board;
	board.push_back(board0);
	board.push_back(board1);
	string word = "abcd";
	Solution a;
	a.exist(board, word);
	return 0;
}