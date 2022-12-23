#include "AiGame.h"
#include "Game.h"


bool AiGame::reset_board(AiGame& b, string sympol, int rocket) {
	bool check = false;
	for (int i = size - 1; i >= 0; i--) {
		for (int j = size - 1; j >= 0; j--)
		{
			if (sympol == "y") {
				if (b.board[i][j] == sympol + to_string(rocket)) {
					if (i <= 0) {
						return true;
					}
					if (b.board[i - 1][j] != "p0" && b.board[i - 2][j] != "p0") {
						check = true;
						return true;
					}
					else {
						if (b.board[i - 1][j] != "p0") {
							b.board[i][j] = "p0";
							b.board[i - 2][j] = sympol + to_string(rocket);
						}
						else {
							b.board[i][j] = "p0";
							b.board[i - 1][j] = sympol + to_string(rocket);
						}
						check = true;
						break;
					}
				}
			}
			else {
				if (b.board[i][j] == sympol + to_string(rocket)) {
					if (j <= 0) {
						return true;
					}
					if (b.board[i][j - 1] != "p0" && b.board[i][j - 2] != "p0") {
						check = true;
						return true;
					}
					else {
						if (b.board[i][j - 1] != "p0") {
							b.board[i][j] = "p0";
							b.board[i][j - 2] = sympol + to_string(rocket);
						}
						else {
							b.board[i][j] = "p0";
							b.board[i][j - 1] = sympol + to_string(rocket);
						}
						check = true;
						break;
					}
				}
			}

		}
		if (check) {
			break;
		}
	}
	return false;
}


int AiGame::checkWinner(AiGame& b) {
	int countery = 0;
	int counterx = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (b.board[i][size - 1] == "x" + to_string(i)) {
			counterx++;
		}
		if (b.board[size - 1][i] == "y" + to_string(i)) {
			countery++;
		}
		if (countery == size - 2) {
			return 2;
		}
		if (counterx == size - 2) {
			return -2;
		}
	}
	return 1;
}


bool AiGame::playai(AiGame& b, string sympol, int rocket) {
	bool check = false;
	for (int i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++)
		{
			if (sympol == "y") {
				if (b.board[i][j] == sympol + to_string(rocket)) {
					if (i >= size - 1) {
						return true;
					}
					if (b.board[i + 1][j] != "p0" && b.board[i + 2][j] != "p0") {
						check = true;
						return true;
					}
					else {
						if (b.board[i + 1][j] != "p0") {
							b.board[i][j] = "p0";
							b.board[i + 2][j] = sympol + to_string(rocket);
						}
						else {
							b.board[i][j] = "p0";
							b.board[i + 1][j] = sympol + to_string(rocket);
						}
						check = true;
						break;
					}
				}
			}
			else {
				if (b.board[i][j] == sympol + to_string(rocket)) {
					if (j >= size - 1) {
						return true;
					}
					if (b.board[i][j + 1] != "p0" && b.board[i][j + 2] != "p0") {
						check = true;
						return true;
					}
					else {
						if (b.board[i][j + 1] != "p0") {
							b.board[i][j] = "p0";
							b.board[i][j + 2] = sympol + to_string(rocket);
						}
						else {
							b.board[i][j] = "p0";
							b.board[i][j + 1] = sympol + to_string(rocket);
						}
						check = true;
						break;
					}
				}
			}

		}
		if (check) {
			break;
		}
	}
	return false;
}
bool AiGame::good(AiGame& b) {
	int check = 0;
	for (size_t i = 1; i < size; i++)
	{
		if (b.board[i][size - 1] == "x" + to_string(i)) {
			check++;
		}
	}
	bool check2 = false;
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size; j++)
		{
			if (b.board[i][j] == "x" + to_string(j) && j != size - 1) {
				if (b.board[i][j + 1] != "p0" && b.board[i][j + 2] != "p0") {
					check2 = true;
				}
			}
		}
	}
	if (check == size-3&&check2==true) {
		return 1;
	}
	else {
		return 0;
	}
}

int AiGame::minimax(AiGame& boardc, int depth, int alpha, int beta, bool isMaximizing, bool firstTime, int s) {


	int result = checkWinner(boardc);

	if (depth == 0 || result != 1) {

		return result;
	}

	if (isMaximizing) {

		int finalScore = -10;
		int finalI = 0;
		//bool check = false;
		for (int i = 1; i < s - 1; i++) {
			if (!playai(boardc, "y", i)||good(boardc) != 0) {
				int score = minimax(boardc, depth - 1, alpha, beta, false, false, s);
				alpha = max(score, alpha);
				reset_board(boardc, "y", i);
				if (score > finalScore) {
					finalScore = score;
					finalI = i;
				}
				if (beta <= alpha) {
					break;
				}
				if (firstTime) {

					cout << "max  " << "score : " << score << "final score : " << finalScore << endl;
				}
			}
			else {
				/*static int counter = 0;
				counter++;
				if (counter == 6) {
					display_board(boardc, s);
					exit(0);
				}*/

				//reset_board(boardc, "y", i);
				continue;
			}

		}
		if (firstTime) {

			play(boardc, "y", finalI);
		}

		return finalScore;
	}
	else {
		int finalScore = 10;
		int finalI = 0;
		for (int i = 1; i < s - 1; i++) {
			if (!playai(boardc, "x", i) || good(boardc) != 0) {
				int score = minimax(boardc, depth - 1, alpha, beta, true, false, s);
				beta = min(score, beta);
				reset_board(boardc, "x", i);
				if (score < finalScore) {
					finalScore = score;
					finalI = i;
				}
				if (beta <= alpha) {
					break;
				}
			}
			else {
				//reset_board(boardc, "x", i);
				continue;
			}
		}
		if (firstTime) {

			play(boardc, "y", finalI);
		}
		return finalScore;
	}
}

void AiGame::get_sympol(string g) {
	sympol = g;
}

void AiGame::run(int a) {
	AiGame board;
	int r;
	bool turn = true;
	set_size(a);
	set_board(board, a);
	display_board(board, a);
	while (true) {
		if (turn == false) {
			cout << "Please Player(x) Choose The Rocket Number To Move : ";
			cin >> r;
			if (r <= size - 2) {
				if (!play(board, "x", r)) {
					turn = true;
					get_sympol("x");
				}
				else {
					turn = false;
				}
				if (winner(board, "x")) {
					cout << "Player(x) Is Winner !!" << endl;
					exit(0);
				}

			}
			else {
				exit(0);
			}
		}
		else {
			get_sympol("y");
			minimax(board, 100, -1000, 1000, true, true, a);
			if (winner(board, "y")) {
				cout << "Computer Is Winner !!" << endl;
				exit(0);
			}
			turn = false;
		}
	}
}