#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include<curses.h>
#define g "I am thinking of a number between 1 and 100"
#define MAX_NUMBER 100
#define MAX_GUESSES 7
int j=1;
int out=0;
// Print a line onto the Terminal.
void print_line(int len)
{
    move(10+j+1,1);
    for(int i=0;i<len;i++)
       addstr("-");
    refresh();
}

// Perform the steps for the guess. Reads the value entered by the user,
// outputs a message, and then returns true if the got it otherwise it returns
// false.
bool perform_guess(int num_guess, int target,int out)
{
    int guess;
    char gu[4];
    
     
    move(5+j,6);
    j++;
    addstr("Guess : ");
    refresh();
    
    getstr(gu);
    guess=atoi(gu);
    refresh();
    
    move(5+j,5);
    j++;
    
    if (target < guess) 
    {
	
       addstr("The number is less than ");
       addstr(gu);
       refresh();
      
    }
    else if (target > guess) 
    {
	
       addstr("The number is larger than ");
       addstr(gu);

    }
    else 
    {
      addstr("Well done... the number was ");
      addstr(gu);
    }
    
    return target == guess;
}

// Implements a simple guessing game. The program generates
// a random number, and the player tries to guess it.
void play_game()
{
    int my_number, num_guess;
    bool got_it;
    
    my_number = random() % MAX_NUMBER + 1;
    num_guess = 0; //Keep track of the number of guesses
 
    move(5,5);
    addstr(g);
    refresh();
    
    
    do
    {
        num_guess++;
        got_it = perform_guess(num_guess, my_number,out);
    }
    while( num_guess < MAX_GUESSES && !got_it);
    
    if ( !got_it )
    {
	printw("\n");
        printw("You ran out of guesses... the number was %d\n", my_number);
    }
}

// Loops the guessing game until the user decided to quite.
int main()
{
    int i=0;
    initscr();
    clear();
    //refresh();
   
 
    char again;
    
    
    srandom(time(0));
    refresh();
    do
    {
	j = 1;
        play_game();
      
        print_line(50);
	printw("\n");
        addstr("Do you want to play again [y/N]? ");
	refresh();
        scanf(" %c", &again);
	refresh();
	clear();
	

    } while (again == 'y' || again == 'Y');
    
    addstr("\nBye\n");
    refresh();
    endwin();
    return 0;
}
