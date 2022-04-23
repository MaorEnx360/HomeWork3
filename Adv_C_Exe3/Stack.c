#include "Stack.h"
#include <stdio.h>

void list_delete2(charNode * head);
charNode *addToHead(charNode *head, charNode *toAdd);
void removeItem(charNode **head);

/***************** Stack ADT Implementation *****************/

void initStack(Stack* s)
{
	s->head = NULL;
	// add your code here
}

void destroyStack(Stack* s)
{
	list_delete(s->head);
	// add your code here
}

void push(Stack* s, char data)
{
	charNode* new = (charNode*)malloc(sizeof(charNode));
	new->data = data;
	s->head = addToHead(s->head, new);

	// add your code here
}

char pop(Stack* s)
{
	int res;
	if (isEmptyStack(s)) {
		printf("Stack is empty \n"); return 0;
	}
	res = s->head->data;
	removeItem(&s->head);
	return res;
	// add your code here
}


int isEmptyStack(const Stack* s)
{
	return s->head == 0;
	// add your code here
}




/*************** Functions using stacks - Implementation/definition **************************/

void flipBetweenHashes(const char* sentence)
{
	// add your code here
	unsigned int i = 0;
	Stack tmp;
	tmp.head = NULL;
	while (sentence[i] != '\0') {
		if (sentence[i] == '#') {
			while (sentence[i + 1] != '#') {
				push(&tmp, sentence[i + 1]);
				i++;
			}
			while (!isEmptyStack(&tmp)) {
				printf("%c", pop(&tmp));
			}
			i += 2;
		}
		else {
			printf("%c", sentence[i]);
			i++;
		}
	}
	printf("\t");

}

int isPalindrome(Stack* s)
{
	// add your code here

	char str[20];
	int count = 0;
	char tmp = 0;
	while (!isEmptyStack(s)) {
		str[count] = pop(s);
		count++;
	}
	count--;
	for (int i = 0; i < count; i++) {
		if (str[i] != str[count - i]) {
			tmp = 0;
			break;
		}
		tmp = 1;
	}
	return tmp;

}




void rotateStack(Stack* s, int n)
{
	if (n <= 0)
		return;
	unsigned int size = 0;
	Stack tmp, tmp2, tmp3;
	initStack(&tmp);
	initStack(&tmp2);
	initStack(&tmp3);
	while (!isEmptyStack(s)) {
		push(&tmp, pop(s));
		size++;
	}
	if (n <= size) {
		for (int i = 0; i < n; i++) {
			push(&tmp2, pop(&tmp));
		}
		while (!isEmptyStack(&tmp2)) {
			push(&tmp3, pop(&tmp2));
		}
	}
	while (!isEmptyStack(&tmp)) {
		push(s, pop(&tmp));
	}
	while (!isEmptyStack(&tmp3)) {
		push(s, pop(&tmp3));
	}



	// add your code here
}



/***************** LinkedList Functions *****************/

void list_delete(charNode * head)
{
	charNode* tmp = NULL;
	while (head != NULL) {
		tmp = head;
		free(tmp);
		head = head->next;
	}
}
charNode *addToHead(charNode *head, charNode *toAdd) {
	toAdd->next = head;
	head = toAdd;
	return head;
}
void removeItem(charNode **head) {
	if (*head == NULL) return; //if stack empty
	charNode * tmp = *head;
	*head = (*head)->next;
	free(tmp);
}