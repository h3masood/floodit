#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <sstream>


class TextDisplay {
	char **theDisplay; // display grid
	unsigned const int gridSize; 

  public:
	TextDisplay(int n);
	~TextDisplay();

	void notify(int r, int c, char ch); // update display at position theDisplay[r][c]
	bool filled();
	void print();
};


#endif
