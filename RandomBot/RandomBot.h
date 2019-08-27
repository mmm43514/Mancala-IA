#include "Bot.h"

#ifndef MANUPCBOT_H_
#define MANUPCBOT_H_

class RandomBot:Bot {
public:
	RandomBot();
	~RandomBot();


	void initialize();
	string getName();
	Move nextMove(const vector<Move> &adversary, const GameState &state);
};

#endif /* MANUPCBOT_H_ */
