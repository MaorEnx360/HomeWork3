#include <stdio.h>
#include "Stack.h"
#include "Queue.h"

void main()
{
	// add your code here
	//Stack dummy;
	//initStack(&dummy);
	//flipBetweenHashes("Remem#reb# thi#crap s#tice");	
	//flipBetweenHashes("#meR#embe#siht r# practice");
	//push(&dummy,'S');
	//push(&dummy, 'I');
	//push(&dummy, 'H');
	//push(&dummy, 'P');
	//	push(&dummy, 'M');
	//push(&dummy, 'E');
	//push(&dummy, 'M');

	//rotateStack(&dummy, -5);
	//destroyStack(&dummy);

		Queue dummy;
	initQueue(&dummy);
	enqueue(&dummy, 6);
	enqueue(&dummy, 1);
	enqueue(&dummy, 5);
	enqueue(&dummy, 2);
	enqueue(&dummy, 3);
	enqueue(&dummy, 1);
	enqueue(&dummy, 9);

	//rotateQueue(&dummy);
	//cutAndReplace(&dummy);
	sortKidsFirst(&dummy);
	
}