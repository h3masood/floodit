#ifndef __GAME_H__
#define __GAME_H__
#include <iostream>
#include "cell.h"
#include "PRNG.h"
#include "textdisplay.h"


extern PRNG prng;
class Game {
	Cell** grid;  				 // The actual grid.
	const unsigned int gridSize;    // Size of the grid.
	unsigned int turns;  // Number of turns remaining
	TextDisplay* display;  // The text display.

  public:
	Game(int size, int numMoves);
	~Game();

	int getTurns(); // number of turns player
	bool isWon();
	void change(int state);  // Changes (0,0) and all appropriate neighbours to state
	void print(); // print grid's current state
};

#endif
