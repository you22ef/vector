#pragma once
#include "Game.h"
class AiGame :public Game
{
private:
	string sympol;
public:
	void run(int s);
	int minimax(AiGame& board, int depth, int alpha, int beta, bool ismaximizing, bool firstime, int s);
	void get_sympol(string s);
	bool playai(AiGame& b, string sympol, int rocket);
	int checkWinner(AiGame& b);
	bool reset_board(AiGame& b, string sympol, int rocket);
	bool good(AiGame& b);
};