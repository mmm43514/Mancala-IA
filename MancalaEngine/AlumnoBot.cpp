#include "AlumnoBot.hpp"

#include <string>
#include <cstdlib>
#include <iostream>
#include <limits>

using namespace std;

BotM::BotM() {
	// Inicializar las variables necesarias para ejecutar la partida
}

BotM::~BotM() {
	// Liberar los recursos reservados (memoria, ficheros, etc.)
}

void BotM::initialize() {
	// Inicializar el bot antes de jugar una partida
}

string BotM::getName() {
	return "BotM"; // Sustituir por el nombre del bot
}

// Lista de movimientos realizadas por adversario y estado del juego
Move BotM::nextMove(const vector<Move> &adversary, const GameState &state) {

	Player turno = this->getPlayer();
	long timeout = this->getTimeOut();

	Move movimiento = M_NONE;

	// Implementar aquí la selección de la acción a realizar

	// OJO: Recordatorio. NO USAR cin NI cout.
	// Para salidas por consola (debug) utilizar cerr. Ejemplo:
	// cerr<< "Lo que quiero mostrar"<<endl;


	// OJO: Recordatorio. El nombre del bot y de la clase deben coincidir.
	// En caso contrario, el bot no podrá participar en la competición.
	// Se deberá sustituir el nombre BotM como nombre de la clase por otro
	// seleccionado por el alumno. Se deberá actualizar también el nombre
	// devuelto por el método getName() acordemente.
	jugador = turno;
	jugador_oponente = (Player) ((jugador + 1) % 2);
	
	alpha_beta_minimax(state, DEPTH, MIN_V, MAX_V, turno);
	
	movimiento = actions[ind_next_move];

	return movimiento;
}

double BotM::alpha_beta_minimax(GameState state, int depth, double alpha, double beta, Player p){
	if (depth == 0 || state.isFinalState()){
		double h = MyPoints(state) - 0.5 * OpponentPoints(state) + right_most_heuristic;
		right_most_heuristic = 0;

		return h;
	}
	
	double p_v, v;
	int m;
	bool right_most_considered = false;

	GameState next_state;
	if (jugador == state.getCurrentPlayer()){ // Max 
		v = MIN_V;

		for (int i = 0; i < 6; i++){
			next_state = state.simulateMove(actions[i]);
			if (!right_most_considered && !next_state.isFinalState()){
				right_most_considered = true;
				right_most_heuristic = 0.4;
			}
				
			p_v = alpha_beta_minimax(next_state, depth - 1, alpha, beta, next_state.getCurrentPlayer());

			if (p_v > v){
				v = p_v;
				m = i;
			}

			alpha = max(alpha, v);
			
			if (beta <= alpha)
				break;
		}

		if (depth == DEPTH)
			ind_next_move = m;

		return v;
	}
	else{// Min - opponent playing
		v = MAX_V;

		for (int i = 0; i < 6; i++){
			next_state = state.simulateMove(actions[i]);

			if (!right_most_considered && !next_state.isFinalState()){
				right_most_considered = true;
				right_most_heuristic = 0.4;
			}

			p_v = alpha_beta_minimax(next_state, depth - 1, alpha, beta, next_state.getCurrentPlayer());

			if (p_v < v)	
				v = p_v;
				
			beta = min(beta, v);

			if (beta <= alpha)
				break;
		}

		return v;
	}
}

int BotM::MyPoints(const GameState &state){
	return state.getSeedsAt(jugador, GRANERO);
}

int BotM::OpponentPoints(const GameState &state){
	return state.getSeedsAt((Player)jugador_oponente, GRANERO);
}




