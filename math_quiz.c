#include<stdio.h>
#include<stdlib.h>
#include<curses.h>
#define title "\tmath quiz\n\n\n\n\n\n\n\n\n\n\tinput +,-,x\tq: quit"
#define answer "answer = "
#define clear1 "perfect!"
#define c "congraturation"
#define f "failed"
#define g "Your grade is "
char q[10];
int n=1;
void clear2()
{
	clear();
	move(10,15);
	addstr(c);
	move(13,15);
	addstr(g); addstr("A+");
	refresh();
	getch();
	endwin();
}
void fail()
{
	beep();
	clear();
	move(10,20);
	addstr(f);
	move(13,15);
	addstr(g);
	
	if(n==1)
		addstr("F");
	else if(n>1&&n<6)
		addstr("C");
	else if(n>5&&n<9)
		addstr("B");
	else
		addstr("A");
	refresh();
	getch();
	endwin();
}

void plus()
{
	q[2]='+';
	int a,b,d,s;
	char s1[10];
	clear();
	refresh();
	
	srandom(time(0));
	a=rand()%10;
	b=rand()%10;
	q[0]=a+48;
	q[4]=b+48;
	d=a+b;

	if(n>1)
	{
		move(15,20);
		addstr(clear1);
		refresh();
	}

	move(10,20);
	addstr(q);
	

	refresh();
	move(13,18);
	addstr(answer);
	refresh();
	
	getstr(s1);
	s=atoi(s1);

	if(s==d)
	{
	
		if(n<10)
		{
			n++;
			plus();
		}
		else 
			clear2();
	}
	else
		fail();
}
void minus()
{
	q[2]='-';
	int a,b,d,s;
	char s1[10];
	clear();
	refresh();
	
	srandom(time(0));
	a=rand()%10;
	b=rand()%10;
	q[0]=a+48;
	q[4]=b+48;
	d=a-b;

	if(n>1)
	{
		move(15,20);
		addstr(clear1);
		refresh();
	}

	move(10,20);
	addstr(q);
	

	refresh();
	move(13,18);
	addstr(answer);
	refresh();
	
	getstr(s1);
	s=atoi(s1);

	if(s==d)
	{
	
		if(n<10)
		{
			n++;
			minus();
		}
		else 
			clear2();
	}
	else
		fail();
}
void mult()
{
	q[2]='x';
	int a,b,d,s;
	char s1[10];
	clear();
	refresh();
	
	srandom(time(0));
	a=rand()%10;
	b=rand()%10;
	q[0]=a+48;
	q[4]=b+48;
	d=a*b;

	if(n>1)
	{
		move(15,20);
		addstr(clear1);
		refresh();
	}

	move(10,20);
	addstr(q);
	

	refresh();
	move(13,18);
	addstr(answer);
	refresh();
	
	getstr(s1);
	s=atoi(s1);

	if(s==d)
	{
	
		if(n<10)
		{
			n++;
			mult();
		}
		else 
			clear2();
	}
	else
		fail();
}
void math_main()
{
	q[1]=q[3]=q[5]=q[7]=' ';
	q[8]='?';
	q[9]='\0';
	q[6]='=';

	initscr();
	clear();

	move(10,10);
	addstr(title);
	refresh();
	int ch=getch();
	//int ch;
	//scanf("%c",&ch);
	
	echo();
	switch(ch)
	{
		case 43: 
			plus();  break;
		case 45:
			minus(); break;
		case 120:
			mult(); break;
		case 113:
			endwin();

	}
}

