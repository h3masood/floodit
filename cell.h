#ifndef __CELL_H__
#define __CELL_H__
#include <iostream>
#include "textdisplay.h"

static const int MAX_NEIGHBOURS = 4;
static const int NO_PREVIOUS = -1;


class Cell {
	static TextDisplay *display; // reference to display
	bool inProgress; // is game in play state?
	int state; // current value in cell
	int prevState; // previous value in cell
	unsigned int numNeighbours; 
   Cell *neighbours[MAX_NEIGHBOURS]; 
	int row, col; // cell coords
	void notifyNeighbours();   // Tell all of my neighbours that I have been
	// switched.
	void notifyDisplay(); // update display to reflect new state

  public:
	Cell();  // Default constructor

	int getState();
	void setState(int change);         // Changes state
	void setCoords(int r, int c);

	void addNeighbour(Cell* neighbour);
	static void addDisplay(TextDisplay* dspl); // connect to a display
	void notify(int current, int previous = NO_PREVIOUS); // update all dependencies
};
#endif
