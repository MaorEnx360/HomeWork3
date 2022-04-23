#include <stdio.h>
#include "Queue.h"

void list_delete(intNode * head);
intNode *addToHead(intNode *head, intNode *toAdd);
void removeItem(intNode **head);

/***************** Queue ADT Implementation *****************/

void initQueue(Queue* q)
{
	// add your code here
	q->head = NULL;
	q->tail = NULL;

}

void destroyQueue(Queue* q)
{
	list_delete(q->head);

	// add your code here
}

void enqueue(Queue* q, unsigned int data)
{
	// add your code here
	intNode* new = (intNode*)malloc(sizeof(intNode));
	new->data = data;
	new->next = NULL;
	//IF THE QUEUE IS EMPTY, HEAD AND TAIL POINTERS OF THE SAME ADREES(NODE). 
	if (!isEmptyQueue(q)) q->tail->next = new;
	else q->head = new;
		q->tail = new;
}

unsigned int dequeue(Queue* q)
{
	if (isEmptyQueue(q))
	{
		return 0;
	}
	else {
		// add your code here
		unsigned int tmp = q->head->data;
		intNode* old = q->head;
		q->head = q->head->next;
		if (q->head == NULL) q->tail = NULL;
		free(old);
		return tmp;
	}
}
int isEmptyQueue(const Queue* q)
{
	// add your code here
	return q->tail == NULL && q->head == NULL;
}

/***************** Functions using Queues - Implementation/definition **************************/

void rotateQueue(Queue* q)
{
	if (q == NULL) {
		printf("Invaild Queue data \n");
	}
	else {
		Queue* tmp = (Queue*)malloc(sizeof(Queue));
		initQueue(tmp); //create temprory queue תור עזר 
		while (q->head != q->tail) { //מעביר את כל האיברים חוץ מהאיבר האחרון לתור העזר 
			enqueue(tmp, dequeue(q));
		}
	
		while (!isEmptyQueue(tmp)) { //לאחר שבתור הנתון נשארנו רק עם האיבר האחרון נרצה להוסיף את האיברים שהזזנו לתור העזר בחזרה לתור הנתון
			enqueue(q, dequeue(tmp));
		}
	}
	// add your code here
}


void cutAndReplace(Queue* q)
{
	// add your code here
	unsigned int count = 0, num = 0, sum = 0;
	Queue* tmp1 = (Queue*)malloc(sizeof(Queue));
	Queue* tmp2 = (Queue*)malloc(sizeof(Queue));
	initQueue(tmp1);
	initQueue(tmp2);
	while (!isEmptyQueue(q)) {
		num = dequeue(q);
		sum += num;
		enqueue(tmp1, num);
		count++;
	}
	if (count % 2 != 0) {
		int avrg = sum / count;
		enqueue(tmp1, avrg);
		count++;
	}
	for(int i = 0; i<count/2;i++){
		enqueue(tmp2, dequeue(tmp1));
	}
	while (!isEmptyQueue(tmp1)) {
		rotateQueue(tmp1);
		enqueue(q, dequeue(tmp1));
	}
	while (!isEmptyQueue(tmp2)) {
		enqueue(q, dequeue(tmp2));
	}
	
}

void sortKidsFirst(Queue* q)
{
	// add your code here

	Queue* tmp = (Queue*)malloc(sizeof(Queue));
	initQueue(tmp);

	while (!isEmptyQueue(q)) {
		if (q->tail->data == q->head->data) {
			dequeue(q);
		}
		else if(q->tail->data > q->head->data){
			while (q->tail->data > q->head->data) {
				rotateQueue(q);
			}
		}
		enqueue(tmp, dequeue(q));
	}
	while (!isEmptyQueue(tmp)) {
		enqueue(q, dequeue(tmp));
	}
}


/***************** LinkedList Functions *****************/

void list_delete(intNode * head)
{
	intNode* tmp = NULL;
	while (head != NULL) {
		tmp = head;
		free(tmp);
		head = head->next;
	}
}
intNode *addToHead(intNode *head, intNode *toAdd) {
	toAdd->next = head;
	head = toAdd;
	return head;
}
void removeItem(intNode **head) {
	if (*head == NULL) return; //if stack empty
	intNode * tmp = *head;
	*head = (*head)->next;
	free(tmp);
}
