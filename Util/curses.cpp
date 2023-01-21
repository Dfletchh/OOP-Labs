#include <ncurses.h>

#define UP_ARROW	3
#define DOWN_ARROW	2
#define LEFT_ARROW	4
#define RIGHT_ARROW	5

int main()
{
	initscr();		// init ncurses library
	raw();			// pass all input to getch() (including Ctrl-Z/C)
	keypad(stdscr, TRUE);	// enable handling of special keys (arrows!)
	noecho();		// don't echo user input
	clear();		// clear screen
	curs_set(0);	// hide cursor

	int x = 5, y = 5;
	char c;

	mvaddch(x, y, 'O');		// print 'O' at the x,y coord

	c = getch();
	while (c != 26)		// loop until Ctrl-Z
	{
		switch (c)
		{
			case UP_ARROW: y--; break;
			case DOWN_ARROW: y++; break;
			case RIGHT_ARROW: x++; break;
			case LEFT_ARROW: x--; break;
		}

		if (x < 0)
			x = 0;
		else if (x > 79)
			x = 79;
		if (y < 0)
			y = 0;
		else if (y > 24)
			y = 24;

		clear();
		mvaddch(y, x, 'O');
		refresh();

		c = getch();
	}
	
	curs_set(1);
	endwin();

	return 0;
}

