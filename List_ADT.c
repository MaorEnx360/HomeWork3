/*****************************************************************//**
 * \file   List_ADT.c
 * \brief  
 * 
 * \author Erez Yaakov Eines
 * \date   April 2022
 *********************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define LIST_END NULL
#define EMPTY_LIST NULL

#define LIST_POINTER_ERROR "Error - NULL pointer.\n"
#define BAD_ALLOC "Error - allocation error.\n"

/**
 * Node implements a singly linked list (sll) node
 */
typedef struct Node
{
	int data; /**< The value stored in the node */
	struct Node* next; /**< Points to the next list element. can be NULL*/
}Node;

/**
 * Struct List is the managing structure for the ADT List.\n
 */
typedef struct List
{
	Node* head; //!< pointer to an sll Node. this is the list's head
	Node* tail; //!< pointer to an sll Node. this is the list's tail
} List;

/*AUXILARY FUNCTIONS*/
/**
 * \brief checks if the pointer "object" points to the NULL address.\n
 * object can be any pointer (int*, float*, List*, int**...).\n
 * any pointer type is implicitly cast into void*
 * \param object the object pointer to check for NULLity
 * \param message the error message to print to log file and std-err.
 * set message to NULL for empty message
 * \warning If this function recieves a NULL pointer as object parameter,\n
 *  it exits the running process that called it.
 * \private \memberof List
 */
void checkNullLogExit(const void* object, const char* message);

/**
 * \brief takes a newly created list and initializes it for use.\n
 *
 * \param list Pointer to the list being initialized.
 * \warning Users must call init on a newly created List object before using any of the public interface\n
 *		methods. calling any other method from the interface before init, results in undefined behaviour.
 * \public \memberof List
 * Ref checkNullLogExit()
 */
void initList(List* list);

/**
 * \brief adds an element to the head of the list.
 *
 * \param list Pointer to the list being initialized.
 * \param data The value to add as element at the head of the list.
 * \attention Assumes list has been properly initialized.
 * \public \memberof List
 */
void addToHead(List* list, int data);

/**
 * \brief removes the first element from a list and returns it's data value
 *
 * \param list The list to remove an element from.
 * \returns the first element in the list
 * \attention Assumes list has been properly initialized.
 * \warning Calling this method on an empty list results in process termination.
 * \public \memberof List
 * Ref checkNullLogExit()
 */
int removeFromHead(List* list);

/**
 * \brief adds a new element with value data to the end of a list.
 *
 * \param list The list to append an element to.
 * \param data The value to add as element at the tail of the list.
 * \attention Assumes list has been properly initialized.
 * \public \memberof List
 * Ref checkNullLogExit()
 */
void addToTail(List* list, int data);

/**
 * \brief finds the last element of the list, removes it and returns it's value.\n
 *
 * \param list The list to remove an element from.
 * \returns the last element in the list
 * \attention Assumes list has been properly initialized.
 * \warning Calling this method on an empty list results in process termination.
 * \public \memberof List
 * Ref checkNullLogExit()
 */
int removeFromTail(List* list);

/**
 * \brief outputs the list elements, from head through tail into the standard output.\n
 * this method does not change the list.
 * \param list The list to print.
 * \attention Assumes list has been properly initialized.
 * \public \memberof List
 */
void printList(const List* list);

/**
 * \brief checks if a list is empty.\n
 * this method does not change the list.
 * \param list The list to check for emptiness.
 * \returns 1 (true) if the list is empty, 0 (false) otherwise
 * \attention Assumes list has been properly initialized.
 * \attention Calling isEmpty on a destroyed list returns true but should be regarded as undefined behavior.
 * \public \memberof List
 * Ref checkNullLogExit()
 */
int isEmptyList(const List* list);

/**
 * \brief frees/deallocates all resources used by struct list\n
 *	- destroying an already destroyed list has no effect.\n
 *  - destroying a NULL pointer has no effect.
 * \param list - The list to destroy
 * \attention Assumes list has been properly initialized.
 * \warning destroying a list that has never been initialized results in undefined behavior
 * \warning once a list has been destroyed, do not re-use it by calling init.
 * \public \memberof List
 */
void destroyList(List* list);

void initList(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	list->head = list->tail = EMPTY_LIST;
}

void checkNullLogExit(const void* object, const char* message)
{
	if (object == NULL)
	{
		FILE* logErrors = NULL;
		fopen_s(&logErrors, "logErrors.txt", "w");
		if (logErrors != NULL && message != NULL)
		{
			fprintf(logErrors, "%s", message);
			fprintf(stderr, "%s", message);
		}
		exit(EXIT_FAILURE);
	}
}

int removeFromHead(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	checkNullLogExit(list->head, LIST_POINTER_ERROR);

	int toReturn = list->head->data; //save return value
	Node* temp = list->head->next; //save new list head
	free(list->head);
	list->head = temp;//update list
	//check if list has become empty after removal
	if (list->head == EMPTY_LIST)
	{
		list->tail = EMPTY_LIST;//update list
	}
	return toReturn;
}

void printList(const List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);

	if (list->head == EMPTY_LIST)
	{
		return;
	}

	Node* temp = list->head;
	while (temp != LIST_END)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}

	printf("NULL\n");
}

void addToTail(List* list, int data)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//create new list node
	Node* newTail = (Node*)calloc(1, sizeof(Node));
	checkNullLogExit(newTail, BAD_ALLOC);
	newTail->data = data;
	//case this is very first list element added to empty list
	if (list->tail == EMPTY_LIST)
	{
		list->head = list->tail = newTail;//update list
		return;
	}
	else //list has at least one element
	{
		list->tail->next = newTail;
		list->tail = newTail;//update list
	}
}

int isEmptyList(const List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//double check for testing purposes
	return (list->head == EMPTY_LIST && list->tail == EMPTY_LIST);
}

void destroyList(List* list)
{
	if (list == NULL)
	{
		return;
	}

	Node* toDestroy = list->head;
	Node* next;
	while (toDestroy != LIST_END)
	{
		next = toDestroy->next;
		free(toDestroy);
		toDestroy = next;
	}

	list->head = list->tail = EMPTY_LIST;//update list
}

void addToHead(List* list, int data)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	//create new list node
	Node* newHead = (Node*)calloc(1, sizeof(Node));
	checkNullLogExit(newHead, BAD_ALLOC);
	newHead->data = data;
	//case this is very first list element added to empty list
	if (list->head == EMPTY_LIST)
	{
		list->head = list->tail = newHead;//update list
	}
	else //list has at least one element
	{
		newHead->next = list->head;
		list->head = newHead;//update list
	}
}

int removeFromTail(List* list)
{
	checkNullLogExit(list, LIST_POINTER_ERROR);
	checkNullLogExit(list->head, LIST_POINTER_ERROR);
	//temp nodes to iterate over list and find the element previous to tail
	Node* current = list->head;
	Node* previous = NULL;
	while (current->next != LIST_END)
	{
		previous = current;
		current = current->next;
	}
	
	int toReturn = current->data;//save return value
	free(current);
	list->tail = previous;//update list
	//check if list has become empty after removal
	if (list->tail == EMPTY_LIST)
	{
		list->head = EMPTY_LIST;//update list
	}
	else
	{
		list->tail->next = LIST_END;//update tail to point to null (was previously pointing to freed element)
	}

	return toReturn;
}