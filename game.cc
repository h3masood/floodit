#include "game.h"
#include "cell.h"
#include <cstdlib>
#include <unistd.h>
#include "textdisplay.h"
#include "PRNG.h"

   

Game::Game( int size, int numMoves ) : gridSize( size )
{
   // Game initialization
   turns = numMoves;
   
   display = new TextDisplay( gridSize ); // the board used to display game board
   grid[0][0].addDisplay( display ); // connect cells with display
   
   
   // Game board Construction
   grid = new Cell *[gridSize];
   for ( unsigned int i = 0 ; i < gridSize; i++ ) {
      grid[i] = new Cell[gridSize];
      for ( unsigned int j = 0; j < gridSize; j++ ) {
         grid[i][j].setCoords( i, j );
         grid[i][j].setState( prng( 4 ) ); // intialize Cell with random values in [0,4]
	}
   }
   // Construction complete

   // adding neighbours
   for ( unsigned int i = 0; i < gridSize; i++ ) {
      for ( unsigned int j = 0; j < gridSize; j++ ) {
         
         if ( i == 0 ) { // first row ?
            grid[i][j].addNeighbour( &grid[i+1][j] ); // SOUTH
            
            if ( j == 0 ) { // first col ?
               grid[i][j].addNeighbour( &grid[i][j+1] ); // WEST
            }
            else if ( j == gridSize - 1 ) { // last col ?
               grid[i][j].addNeighbour( &grid[i][j-1] ); // EAST
            }
            else {
               grid[i][j].addNeighbour( &grid[i][j-1] ); // EAST
               grid[i][j].addNeighbour( &grid[i][j+1] ); // WEST
            }
            
         }
         else if ( i == gridSize - 1 ) { // last row ?
            grid[i][j].addNeighbour( &grid[i-1][j] ); // NORTH
            
            if ( j == 0 ) { // first col ?
               grid[i][j].addNeighbour( &grid[i][j+1] ); // EAST
            }
            else if ( j == gridSize - 1 ) { // last col ?
               grid[i][j].addNeighbour( &grid[i][j-1] ); // WEST
            }
            else {
               grid[i][j].addNeighbour( &grid[i][j-1] ); // WEST
               grid[i][j].addNeighbour( &grid[i][j+1] ); // EAST
            }
            
         }
         else { // middle rows
            grid[i][j].addNeighbour( &grid[i-1][j] ); // NORTH
            grid[i][j].addNeighbour( &grid[i+1][j] ); // SOUTH
            
            if ( j == 0 ) { // first col ?
               grid[i][j].addNeighbour( &grid[i][j+1] ); // EAST
            }
            else if ( j == gridSize - 1 ) { // last col ?
               grid[i][j].addNeighbour( &grid[i][j-1] ); // WEST
            }
            else {
               grid[i][j].addNeighbour( &grid[i][j+1] ); // EAST
               grid[i][j].addNeighbour( &grid[i][j-1] ); // WEST
            }
            
         }
      } // for
   } // for
   // adding neighbours complete
   // intitialization complete
   print(); // print board's initial configuration   
}


Game::~Game()
{ 
   for ( unsigned int i = 0; i < gridSize; i++ ) {
      delete [] grid[i];
   }
   delete [] grid;
   delete display;
  
}


int Game::getTurns()
{
   return turns;
}


bool Game::isWon()
{
   if ( turns == 0 ) return false;
   return display->filled();
}


void Game::change( int state )
{
   turns -= 1;
   grid[0][0].notify( state ); // inform (0,0) of the new state
}


void Game::print()
{
   display->print(); // print board to screen
   if ( getTurns() == 1 ) {
     cout << "1 move left" << endl;
     return;
   }
   cout << getTurns() <<  " moves left" << endl;
}
