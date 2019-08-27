
#include "Bot.h"

#ifndef MANUPCBOT_H_
#define MANUPCBOT_H_

class GreedyBot:Bot {
public:
	GreedyBot();
	~GreedyBot();


	void initialize();
	string getName();
	Move nextMove(const vector<Move> &adversary, const GameState &state);
};

#endif 
