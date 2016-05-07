#include "textdisplay.h"
#include <cassert>
using namespace std;



TextDisplay::TextDisplay( int n ) : gridSize( n )
{
   // allocate display matrix on heap
   theDisplay = new char *[gridSize];  
   for ( unsigned int i = 0; i < gridSize; i++ ) {
      theDisplay[i] = new char[gridSize];
      for( unsigned int j = 0; j < gridSize; j++ ) {
         theDisplay[i][j] = 0; // default
      }
   }
}


TextDisplay::~TextDisplay()
{
   // deallocate display
   for ( unsigned int i = 0; i < gridSize; i++ ) {
      delete [] theDisplay[i];
   }
   delete [] theDisplay; 
}


void TextDisplay::notify( int r , int c, char ch )
{
   theDisplay[r][c] = ch; // update display to match the corresponding board configuration
}


bool TextDisplay::filled()
{
   bool isFilled = false; // are all the board elements identical ?
   char common = theDisplay[0][0]; 
   
   for ( unsigned int i = 0; i < gridSize; i++ ) {
      for (unsigned int j = 0; j < gridSize; j++ ) {
         
   if ( common != theDisplay[i][j] ) goto FAILURE;
         
      }
   }
   
   // game board filled
   isFilled = true;
   return isFilled;
    
   // game board not filled
   FAILURE: ;
   return isFilled;
   
}


void TextDisplay::print()
{
   for ( unsigned int i = 0; i< gridSize; i++ ) {
      for ( unsigned int j = 0; j < gridSize; j++ ) {
         cout << theDisplay[i][j]; // print board element
      }
      cout << '\n'; // put newline
   }
}
