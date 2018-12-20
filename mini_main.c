#include <stdio.h>
#include <curses.h>

int main()
{

	initscr();
	clear();

	print();

	int ch = getch();

	if(ch == 49)
	{
		guess_main();
	}
	else if(ch == 50)
	{
		catch_main();
	}
	else if(ch == 51)
	{
		math_main();
	}
	else if(ch == 'Q'|| ch == 'q')
	{
		endwin();

	}


}

void print()
{
	move(5,10);
	printw("---------------------------------\n");
	move(6,10);
	printw("  00  00     ii     00   00     ii  \n");
	move(7,10);
	printw(" 00 00 00    ii     000  00     ii  \n");
	move(8, 10);
	printw("00  00  00   ii     0  0 00     ii  \n");
	move(9,10);
	printw("00  00  00   ii     0  0000     ii  \n");

	move(11,20);
	printw("game  festival\n");

	move(12,10);
	printw("---------------------------------\n");
	
	move(14,20);
	printw("Press the number");
	move(15,20);
	printw("(1) Guess number");
	move(16,20);
	printw("(2) Catch the star");
	move(17,20);
	printw("(3) Math quiz");
	move(18,20);
	printw("(Q) quit");

	refresh();
}
