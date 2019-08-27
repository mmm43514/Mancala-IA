#include "Bot.h"

#ifndef MANUPCBOT_H_
#define MANUPCBOT_H_

class BotM:Bot {
public:
	Move actions[6] = {M1, M2, M3, M4, M5, M6};

	const double MAX_V = 999999999;
	const double MIN_V = -999999999;
	double right_most_heuristic = 0;
	int ind_next_move;
	const int DEPTH = 11;
	Player jugador, jugador_oponente;

	BotM();
	~BotM();

	void initialize();
	string getName();
	Move nextMove(const vector<Move> &adversary, const GameState &state);
	double alpha_beta_minimax(GameState state, int depth, double alpha, double beta, Player p);
	int MyPoints(const GameState &state);
	int OpponentPoints(const GameState &state);
};

#endif /* MANUPCBOT_H_ */
