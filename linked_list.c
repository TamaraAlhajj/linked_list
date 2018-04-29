/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/

/*
Purpose: insert a new node into the list as the first element
input
id - id of person
firstName - first name of person
familyName - family name of person

input/output
head - head of linked list

return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, char *firstName, char *familyName)
{
	//allocate mem.
	PersonalInfo* newNode = calloc(1, sizeof(PersonalInfo));
	
	//create new node
	newNode->id = id;
    strcpy(newNode->firstName,firstName);
    strcpy(newNode->familyName,familyName);
	
	//set head pointer
	newNode->next = *head;
    *head = newNode;
	
	return newNode;
}


/************************************************************************/
/*
Purpose: insert a new node into the list after the given node  

Input
node - the node after which the new node must be added to the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful

*/

PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, char *firstName, char *familyName)
{
	//allocate mem
	PersonalInfo* newNode = calloc(1, sizeof(PersonalInfo));  
	
	//create new node
	newNode->id = id;
	strcpy(newNode->firstName,firstName);
    strcpy(newNode->familyName,familyName);
	
	//set pointers to next node
    newNode->next = node->next;
	node->next = newNode;
	
	return newNode;
}

/************************************************************************/
/*
Purpose: create a new node and insert it into the end of the list
Input
head - the head of the list
id - id of person
firstName - first name of person
familyName - family name of person


return
A pointer to the node that was allocated.  

NULL - if the operation was not successful
*/

PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, char *firstName, char *familyName)
{
	//allocate mem
	PersonalInfo* newNode = (PersonalInfo*) calloc(1, sizeof(PersonalInfo));
	PersonalInfo* tail = *head;
	
	//if list is empty
	if(tail == NULL){
	
		//create new node
		newNode->id = id;
		strcpy(newNode->firstName,firstName);
		strcpy(newNode->familyName,familyName);
	
		//set head pointer
		newNode->next = *head;
		*head = newNode;
		return newNode;
	}  
	
	//create new node
	newNode->id = id;
    strcpy(newNode->firstName,firstName);
    strcpy(newNode->familyName,familyName);
	while(tail->next != NULL) tail = tail->next;
	
	//set pointers to next node
	tail->next = newNode;
	newNode->next = NULL;
	
	return newNode;
}


/************************************************************************/
/*
Purpose: search for the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

return
a pointer to the node that was found.
NULL - if no node was found or list empty

*/


PersonalInfo *searchByName(PersonalInfo *head, char *firstName)
{
	//empty list
	if(head == NULL) return NULL;
	
	//create temp node
	PersonalInfo* currentNode = head;
	
	//run through list
	while(currentNode != NULL){
		//if name is found return this node
		if(strcmp(currentNode->firstName,firstName) == 0) return currentNode;
		//otherwise move on
		currentNode = currentNode->next;
	}
    //if exit loop: not found
	return NULL;
}

/************************************************************************/
/*
Purpose: search for the first node with the matching id
Input
head - the head of the list
id - id of person person

return
a pointer to the node that was allocated.  

NULL - if no node was found or list empty 

*/


PersonalInfo *searchById(PersonalInfo *head, unsigned int id)
{
	//empty list
	if(head == NULL) return NULL;
	
	//create temp node
	PersonalInfo* currentNode = head;
	
	//run through list
	while(currentNode != NULL){
		//if id is found return this node
		if(currentNode->id == id) return currentNode;
		//otherwise move on
		currentNode = currentNode->next;
	}
    //if exit loop: not found
	return NULL;
}

/***************************************************************/

/*
Purpose: delete the first node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of deleted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted
1 if node was not deleted or list is empty

*/


int deleteFromList(PersonalInfo **head, unsigned int *id, char *firstName, char *familyName)
{
	if(*head == NULL) return 1;			//empty list
	PersonalInfo* currentNode = *head;  //save head
	*head = currentNode->next;			//set next node as the new head
	printNode(currentNode);				//output
	currentNode = NULL;	
	free(currentNode);					//free original head				
	return 0;
}

/***************************************************************/

/*
Purpose: delete the last node from the list
Input
head - the head of the list

output
head - the head of the list
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return

0 if node was deleted  
1 if node was not deleted or list is empty 

*/


int deleteLast(PersonalInfo **head, unsigned int *id, char *firstName, char *familyName)
{
	if(*head == NULL) return 1;			//empty list

	if((*head)->next == NULL){
		printNode(*head);			//output
		free(*head);				//free original head
		*head = NULL;					
		return 0;	
	}
	
	PersonalInfo* current = *head;  		//save current, as head	
	PersonalInfo* prevNode = current;		//save next node

	while(current->next != NULL){ 
		//if tail not found, move through
		prevNode = current;			
		current = current->next;
	}
	
	printNode(current);
	free(current);
	current = NULL;	
	prevNode->next = NULL;	//set before tail next to NULL
	return 0;
}

/************************************************************************/

/*
Purpose: delete the record after the given node 
Input
node - a node in the list

output
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0 if node was deleted 
1 if node was not deleted (either input node is NULL or input node was the lastnode in the list)

*/
int deleteAfter(PersonalInfo *node, unsigned int *id, char *firstName, char *familyName)
{

	if((node == NULL)||(node->next == NULL)) return 1;	
	PersonalInfo* after = node->next;  	//save next node
	node->next = after->next;			//point to node after current	
	printNode(after);
	free(after);						//delete the node after given 
	after = NULL;
	return 0;
	
}

/************************************************************************/

/*
Purpose: delete the first node with the matching firstName
Input
head - the head of the list
firstName - first name of person

output
head - the head of the list
firstName - first name of deleted record
familyName - family name of deleted recrod
id - id of deleted record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonalInfo **head, char *firstName, char *familyName, unsigned int *id)
{

	//empty list
	if(*head == NULL) return 1;
	//Find the node

    PersonalInfo* name = searchByName(*head,firstName);
	printNode(name);	

	if(name == NULL) return 1;
	if(name == *head)
	{
		PersonalInfo* nextNode = (*head)->next;
		free(*head);
		*head = nextNode;
		return 0;
	}
	//run through, find node
	PersonalInfo* currentNode = *head;
	while(currentNode->next != name) currentNode = currentNode->next;

	currentNode->next = name->next;
	name->next = NULL;
	free(name);
	name = NULL;
	return 0;
	
}
/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list
*/

void deleteList(PersonalInfo **head)
{
	//empty list
	if(*head == NULL) return;
	
	PersonalInfo* current = *head;
	
	//create temp node
	while(current != NULL){
		current = (*head)->next;
		free(*head);
		*head = current;
	}
	*head = NULL;		
}

/************************************************************************/
/*
Purpose: prints the fields of a node
input:
node - a pointer to a given node

*/

void printNode(PersonalInfo *node)
{
	printf("%-20s %-20s %7d \n",node->firstName, node->familyName, node->id);
}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head)
{
	//empty list
	if(head == NULL) return;
	PersonalInfo* currentNode = head;
	while(currentNode != NULL)
	{
		//print every element
		printNode(currentNode);
		currentNode = currentNode->next;
	}
}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list
input
head - the head of the list

return 
the number of nodes in the list

*/


int listSize(PersonalInfo *head)
{
	int count = 0;
	PersonalInfo* currentNode = head;
	while(currentNode != NULL)
	{
		//count every element
		count++;
		currentNode = currentNode->next;
	}
	return count;
}

/************************************************************************/
/*
Purpose: counts the number of nodes in the list with a matching firstName
input
head - the head of the list

return 
the number of nodes in the list that match the firstName


*/

int countRecords(PersonalInfo *head, char *firstName)
{
	int count = 0;
	if(head == NULL) return count;
	
	PersonalInfo* currentNode = head;
	
	while(currentNode != NULL)
	{
		//run through and count every instance
		if(strcmp(currentNode->firstName, firstName) == 0) count++;
		currentNode = currentNode->next;
	}
	return count;
}

/************************************************************************/
/*

Purpose: removes all duplicates records from the list.  Duplicate records are determined by their first name. 
You can assume that the listed is sorted by first name.

input
head - the head of the  list

*/

void removeDuplicates(PersonalInfo *head)
{
	if((head == NULL)||(head->next == NULL)) return;
	PersonalInfo* current = head;
    PersonalInfo* nextNode = current->next;

    //While the two nodes have the same name delete it
    while(nextNode!=NULL)
	{
		while(nextNode != NULL && strcmp(current->firstName, nextNode->firstName) == 0)
		{
			//delete
		    current->next = nextNode->next;
		    nextNode->next = NULL;
		    free(nextNode);
		    nextNode = current->next;
		}
		//Increment
		if(nextNode != NULL)
		{
			current = nextNode;
        	nextNode = nextNode->next;
		}    
	} 
}

/*

Purpose: merges two given linked lists 

input
head1 - the head of the  list 1
head2 - the head of the  list 2
outHead - the head of the out list

*/
void mergeLists(PersonalInfo **head1, PersonalInfo **head2, PersonalInfo **outHead)
{
	if((*head1 == NULL)||(*head2 == NULL)) return;	
	PersonalInfo* newHead = *head1;	
	PersonalInfo* tail = *head1;
	PersonalInfo* middle = *head2;	
	
	while(tail->next != NULL) tail = tail->next;
	
	tail->next = middle;
	*outHead = newHead;
}
