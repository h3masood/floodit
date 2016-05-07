#include <iostream>
#include <cstdlib> // atoi
#include <sstream>
#include <unistd.h>
#include "game.h"
using namespace std;


int usage()
{
   cerr << "Usage: floodit [ -size N (width and height of game ) >= 2) ]"
        << " | [ -moves M (number of moves until game is over) >= 1) ]"
	<< " | [ -seed S (seed for random-number generator (1..INT_MAX)) ] " << endl;
   
   return( EXIT_FAILURE );
}

PRNG prng( getpid() ); // use process ID to initialize cells

int main( int argc, const char *argv[] )
{
   // default list
   unsigned int boardSize = 10; // number of cell(s) on board
   unsigned int totalMoves = 20; // number of total moves
   // list end
   
   // handling command-line args
   if ( argc != 1 ) { // any command-line args to handle?
      for ( int i = 1; i < argc; i += 2 ) {
         if ( i == argc - 1 ) return usage(); // is number of args valid ?
         // reset default values
         string usrInput = argv[i];
         if ( usrInput == "-seed" ) {
            int seedVal = atoi( argv[i+1] );
	    if ( seedVal < 1 ) return usage(); // Bad input, terminate
	    prng.seed( seedVal ); // reset seed
         }
         if ( usrInput == "-moves" ) {
            int val = atoi( argv[i+1] );
            if ( val < 1 )  return usage(); // Bad input, terminate
            totalMoves = val; // reset totalMoves
         }
         if ( usrInput == "-size" ) {
            int val = atoi( argv[i+1] );
            if ( val < 2 ) return usage(); // Bad input, terminate
            boardSize = val; // reset number of cells on board
         }
      } // for
   }
   // handling complete
   
   // Begin Game
   Game playGame( boardSize, totalMoves ); // set-up the game for play
   string usrResponse; // user input
   
   while ( true ) {
      if ( ( cin >> usrResponse ) == 0 ) break; // end of input ?
      int newState; 
      stringstream ss( usrResponse );
  
      // process usrInput
      ss >> dec >> newState; // read in integer from stringstream
      if ( ss.fail() || ! ( newState >= 0 && newState <= 4 )  ) { // is the user input a valid integer ?
        cerr << "Invalid move" << endl;
        continue; // skip to next iteration
      }
      // process complete
 	      
      playGame.change( newState ); // change cell(s) state
      playGame.print(); // print board after recent cell(s) state changes
	
      if ( playGame.isWon() ) {
         cout << "Won" << endl;
         return( EXIT_SUCCESS );
      }

      if ( playGame.getTurns() == 0 ) { // how many turns left?
         // Game Over
         cout << "Lost" << endl;
         return( EXIT_FAILURE );
      }
   } // while
}
