Project author: Humble Masood
Date created: March 15, 2016

-> About the game

An instance of floodit consists of an n x n-grid of cells, each of which can be in one
of five states: 0, 1, 2, 3, 4. Before the game begins, an initial configuration of cell
states will be generated. Once the cells are configured, the player repeatedly changes the
state of the top left (0, 0) cell. In response, all neighbouring cells(to the north, east,
south, west) change state if they were in the same state as the neighbouring cell which 
changed state. This action is referred to as a floofing.

-> Objective: have all the cells, in the grid in the same state before the player runs out of moves

-> Running the game
 1. Create the game executable using the provided Makefile
 2. Run the executable using command-line with the following options
	floodit [ -size n ] [ -moves m ] [ -seed value ]
 
n: the size of grid; it is an integer grater than 2
m: number of moves until the game is over and must be atleast 1
s: the size of the grid 
note: all command-line options are optional, if any or all of them are not provided then the game will run
with default values:

-> Playing the game

Input the new state of the top left (0, 0) cell by entering the state value and then pressing return(enter);
repeat the above until either the state of all the cells in the grid are in the same state or you have run out of moves


  
