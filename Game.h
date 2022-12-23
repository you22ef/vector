#pragma once
#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
class Game
{
protected:
	vector<vector<string>>board = {{"0"}};
	int size;
public:
	void display_board(Game&b,int s);
	void set_board(Game& b, int s);
	bool play(Game& b, string sympol, int rocket);
	void set_size(int s);
	virtual void run(int a);
	bool winner(Game& b, string sympol);
};

