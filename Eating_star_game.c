#include <stdio.h>
#include <curses.h>
#include <signal.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

#define GROUND 20
#define WALL 50
#define print_score "SCORE = "
#define WARNING "Out of Range!!!"

int x_pos = 10;
int y_pos = 0;
int item_x_pos = 0;
int item_y_pos = 0;
int past_y = 0;
int past_x = 0;
int score = 0;

char blank[] = " ";

void main(){

	srand(time(NULL));

	initscr();
	keypad(stdscr, TRUE);
	clear();
	
	gamestart();
	make_ground();

	game();

	endwin();

	return 0;
}

void gamestart()
{
	move(10,15);

	addstr("Game start!");
	move(12,15);
	addstr("Press any key to start");
	refresh();


	if(getch() != 0)
		clear();
	
	refresh();

}

void game()
{
	void on_input();

	int i = 0;
	item();

	while(1)
	{

		make_ground();
		
		if(item_y_pos == y_pos && item_x_pos== x_pos)
		{
			score++;

			make_ground();

			move(item_y_pos,item_x_pos);
			addstr(blank);
			item();

			y_pos = 0;
			x_pos = 0;
		}


		move(y_pos,x_pos);		
		addstr("@");
		
		refresh();

		past_y = y_pos;
		past_x = x_pos;
		
		refresh();

		on_input();

		move(past_y,past_x);
		addstr(blank);
	
		if(y_pos >= GROUND|| x_pos >= WALL || y_pos<0 || x_pos <0)
		{	
			move(10,10);
			addstr(WARNING);
			refresh();
			sleep(2);
			break;
		}
		
	}
}

void on_input()
{
	int num = rand()%3 +1;
	
	int ch = getch();

   	if(ch ==  KEY_UP)
		{
			 y_pos = y_pos-num;
		} 
		else if(ch == KEY_DOWN)
		{		
			y_pos = y_pos+num;
		}
		else if(ch == KEY_LEFT)
		{
			x_pos = x_pos-num;
		}
		else if (ch == KEY_RIGHT)	
		{
			x_pos = x_pos+num;
		}

		move(23,10);
		printw("The random number is %d",num);
		
}



void make_ground()
{
	int i = 0;

	for(i=0; i<WALL;i++)
	{	move(GROUND,i);
		addstr("-");
	}
	for(i=0;i<GROUND;i++)
	{
		move(i,WALL);
		addstr("|");
	}

	move(GROUND+2,20);
	addstr(print_score);
	printw("%d",score);

	refresh();
}

void item()
{

	item_x_pos = rand()%(WALL-2) +1;
	item_y_pos = rand()%(GROUND-2) +1;

	move(item_y_pos, item_x_pos);

	addstr("*");

}
