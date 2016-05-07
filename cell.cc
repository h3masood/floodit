#include "cell.h"
#include "textdisplay.h"
#include <cassert>
using namespace std;

TextDisplay *Cell::display;

Cell::Cell()
{
   inProgress  = true; // game started
   state  = 0; // default
   prevState = NO_PREVIOUS;
   numNeighbours = 0;
   row = -1; // initialize with sentinel
   col = -1; // initialize with sentinel
}



void Cell::notifyNeighbours()
{
   for ( unsigned int i = 0; i < numNeighbours; i++ ) {
      if ( neighbours[i]->getState() == prevState ) neighbours[i]->notify( state ); // change neigbour's state if different from my current state
   }
}


void Cell::notifyDisplay()
{
   char ch  = '0' + state;
   display->notify( row, col, ch ); // tell display of my new state
}



int Cell::getState()
{
   return state;
}


void Cell::setState( int change )
{
   prevState = state;
   state = change;
   notifyDisplay(); // update display of my new state
}


void Cell::setCoords( int r, int c )
{
   row = r;
   col = c;
}


void Cell::addNeighbour( Cell *neighbour )
{
   neighbours[numNeighbours] = neighbour;
   numNeighbours += 1;
}


void Cell::addDisplay( TextDisplay *dspl )
{
   display = dspl; // connect to display
}


// check again
void Cell::notify( int current, int previous )
{
	if ( state == current ) return;  // is the current state same as the new ?
	 setState( current ); // update cell to new state
   	  // inform others (concerned) of my new state
   	  notifyNeighbours();
}


