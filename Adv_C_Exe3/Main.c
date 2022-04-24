#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	// add your code here
	//Stack dummy;
	Stack dummy2;

	//initStack(&dummy);
	initStack(&dummy2);

	//flipBetweenHashes("Remem#reb# thi#crap s#tice");	
	//flipBetweenHashes("#meR#embe#siht r# practice");
	//push(&dummy,'S');
//	push(&dummy, 'I');
//	push(&dummy, 'H');
	//push(&dummy, 'P');
//	push(&dummy, 'M');
	//push(&dummy, 'E');
	//push(&dummy, 'M');
	//rotateStack(&dummy, 2);
	//destroyStack(&dummy);

//	push(&dummy, 'S');
	//push(&dummy, 'I');
	//push(&dummy, 'H');
//	push(&dummy, 'P');
//	push(&dummy, 'M');
//	push(&dummy, 'E');
//	push(&dummy, 'M');

//push(&dummy2, 'M');
//push(&dummy2, 'A');
//push(&dummy2, 'D');
//push(&dummy2, 'A');
//push(&dummy2, 'M');
//isPalindrome(&dummy2);


	Queue Dummy;
	initQueue(&Dummy);
	enqueue(&Dummy, 6);
	enqueue(&Dummy, 1);
	enqueue(&Dummy, 5);
	enqueue(&Dummy, 2);
	enqueue(&Dummy, 3);
	enqueue(&Dummy, 1);
	enqueue(&Dummy, 9);

	rotateQueue(&Dummy);
	cutAndReplace(&Dummy);
	sortKidsFirst(&Dummy);
	
}