#include "Game.h"
void Game::display_board(Game&b,int s) {

	cout << endl;
	for (size_t i = 0; i < s; i++)
	{
		cout << "|" << " ";
		for (size_t j = 0; j < s; j++)
		{
			cout <<b.board[i][j] <<" " << "|"<<" ";
		}
		cout << endl;
	}
	this->board = b.board;
	
}
bool Game::winner(Game& b, string sympol) {
	int counter = 0;
	for (size_t i = 0; i < size; i++)
	{
		if (sympol == "x") {
			if (b.board[i][size - 1] == sympol + to_string(i)) {
				counter++;
			}
		}
		else {
			if (b.board[size - 1][i] == sympol + to_string(i)) {
				counter++;
			}
		}
		if (counter == size - 2) {
			return true;
		}
	}
	return false;
}
void Game::set_board(Game&b,int s) {
	vector<string>v(s);
	vector<vector<string>>boarde(s, v);
	b.board = boarde;
	for (size_t i = 0; i < s; i++)
	{
		for (size_t j = 0; j < s; j++)
		{
			b.board[i][j]="p0";
		}
	}
	for (size_t i = 1; i <= s-2; i++)
	{
		b.board[i][0] = "x" + to_string(i);
	}
	for (size_t i = 1; i <= s - 2; i++)
	{
		b.board[0][i] = "y" + to_string(i);;
	}
	this->board = b.board;
}
void Game::set_size(int s) {
	size = s;
}


bool Game::play(Game &b,string sympol, int rocket) {
	bool check = false;
	for (int i = 0; i < size; i++) {
		for (size_t j = 0;  j < size;  j++)
		{
			if (sympol == "y") {
				if (b.board[i][j] == sympol + to_string(rocket)) {
					if (i >= size - 1) {
						cout << "Out Of Range !!" << endl;
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
						cout << "out of range" << endl;
						return true;
					}
					if (b.board[i][j+1] != "p0" && b.board[i][j+2] != "p0") {
						check = true;
						return true;
					}
					else {
						if (b.board[i][j+1] != "p0") {
							b.board[i][j] = "p0";
							b.board[i][j+2] = sympol + to_string(rocket);
						}
						else {
							b.board[i][j] = "p0";
							b.board[i][j+1] = sympol + to_string(rocket);
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
	cout << endl;
	display_board(b, size);
	return false;
}
void Game::run(int a) {
	Game board;
	int r;
	bool turn = true;
	set_size(a);
	set_board(board,a);
	display_board(board,a);
	while (true) {
		if (turn == true) {
			cout << "Please Player(x) Choose The Rocket Number To Move : ";
			cin >> r;
			if (r <= size - 2) {
				if(!play(board,"x", r)){
					turn = false;
				}
				else {
					turn = true;
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
			cout << "Please Player(y) Choose The Rocket Number To Move : ";
			cin >> r;
			if (r <= size - 2) {
				if (!play(board, "y", r)) {
					turn = true;
				}
				else {
					turn = false;
				}
				if (winner(board, "y")) {
					cout << "Player(y) Is Winner !!" << endl;
					exit(0);
				}
				
			}
			else {
				exit(0);
			}
		}
		
	}
}