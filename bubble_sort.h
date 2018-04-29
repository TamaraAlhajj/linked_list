bubble_sort.o                                                                                       0000664 0001751 0001751 00000002364 13056546014 012517  0                                                                                                    ustar   admin                           admin                                                                                                                                                                                                                  ELF                            4     (  	 U���x�E�E�e�   �E�1��E�    �E�    �E�    �E�    �}� ��   �E�� ��P��������E��}���   �E�� �E��r�E��E��E�   �X�E�� �E��E�� �E��E��P�E�����j RP���������~!�E���E���E��U���E��U���E�    �E�� �E��E�� � ��u��}� t��U��E�������E�e3   t������� GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609         zR |�            �    A�B��                             ��                                                                                           �                   #              +               bubble_sort.c bubbleSort listSize strncmp __stack_chk_fail G   	  �   
  �            .symtab .strtab .shstrtab .rel.text .data .bss .comment .note.GNU-stack .rel.eh_frame                                                       4   �                     	   @       �     
            %             2                     +             2                     0      0       2  5                 9              g                     M             h  8                  I   	   @       �     
                          �  W                                �  �               	              `  <                                                                                                                                                                                                                                                                                              linked_list.c                                                                                       0000664 0001751 0001751 00000031232 13064050061 012465  0                                                                                                    ustar   admin                           admin                                                                                                                                                                                                                  
/* 
File name is linked_list.c

*/

/******************************************************************/
// INCLUDE 

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "linked_list.h"


/************************************************************************/
// Define 



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

PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName)
{       
        PersonalInfo *p = (PersonalInfo *) malloc(sizeof(PersonalInfo)); //allocate required space and typecast 
        p->next = *head;
        p->id = id;
        int x = 0;
        int y = 0;
        
        *(firstName + 31) = '\0'; 
        *(familyName + 31) = '\0';   
        strncpy(p->firstName, &(*(firstName + 0)), 32); //destination, source, number of characters;
        strncpy(p->familyName, &(*(familyName + 0)), 32); //destination, source, number of characters;
        
        *head = p;
        
        return *head;

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
	if (node == NULL) return NULL;
        
        PersonalInfo *p = (PersonalInfo *) malloc(sizeof(PersonalInfo));
        
     
        p->id = id;
        *(firstName + 31) = '\0'; 
        *(familyName + 31) = '\0';   
        
        strncpy(p->firstName, &(*(firstName + 0)), 32); //destination, source, number of characters;
        strncpy(p->familyName, &familyName[0], 32); //destination, source, number of characters;
        
        p->next = node->next;
        node->next = p;
        
        return p;
        
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
	if (*head == NULL) return insertToList(head,id,firstName,familyName);
        
        PersonalInfo *temp = *head;
        while(temp->next != NULL){
         temp = temp->next;       
        }
        
        insertAfter(temp, id, firstName, familyName); 
        
     /*   PersonalInfo *last = (PersonalInfo *) malloc(sizeof(PersonalInfo));
       
        last->id = id;
        *(firstName + 31) = '\0';
        *(familyName + 31) = '0';
        strncpy(last->firstName, &(*(firstName + 0)), 32); //destination, source, number of characters;
        strncpy(last->familyName, &familyName[0], 32); //destination, source, number of characters;
        
        temp->next = last;
        last->next = NULL;
        
        return last; */
        
        
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
	if (head == NULL) return NULL;
        int i = 0;//In C, any value that is not zero is true, and zero is false
	PersonalInfo *p = head;
        while(p->next != NULL && strncmp(firstName, p->firstName, 32) != 0){
         p = p->next;       
        }
        
       //printf("Fail test 1\n");
        
        
       if(strncmp(firstName, p->firstName, 32) == 0) i = 1;
        
       //printf("Fail test 2\n");
        
        
       if(i){
        return p;       
       }else{
        //printf("Fail test 3\n");
        return NULL;       
       }

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
	if (head == NULL) return NULL;
        PersonalInfo *p;
        int i = 0;
        for(p = head; p->next != NULL && p->id != id; p = p->next);
  
        if(p->id == id) i = 1;

        
        if(i){
         return p;       
        }else{
         return NULL;       
        }
    
}

/***************************************************************/

/*
Purpose: delete the first node from the list
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


int deleteFromList(PersonalInfo **head, unsigned int *id,
	char *firstName, char *familyName)

{       
        if(*head == NULL) return 1;
        printf("This is the deleted node: ");
        printNode(*head);
        
        PersonalInfo *next = (*head)->next;
        free(*head);
        *head = next;
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


int deleteLast(PersonalInfo **head, unsigned int *id,
                char *firstName, char *familyName)

{
    if(*head == NULL) return 1; 
     
    if((*head)->next == NULL){
	printf("This is the deleted node: ");
        printNode(*head);
	free(*head);
	*head = NULL;
	return 0;
    }
    PersonalInfo *p = *head;
    PersonalInfo *prev = p;    
    while(p->next != NULL){
            prev = p;
            p = p->next;
    }
    printf("This is the deleted node: ");
    printNode(p);
    free(p);
    p = NULL;
    prev->next = NULL;    
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



int deleteAfter(PersonalInfo *node, unsigned int *id,
                char *firstName, char *familyName)

{
    if(node == NULL || node->next == NULL) return 1;
    printf("This is the node that was deleted: ");    
    printNode(node->next);
    PersonalInfo *s = node->next;    
    node->next = s->next;   
    s->next = NULL;
    free(s);    
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
firstName - first name of delted record
familyName - family name of deleted recrod
id - id of deleted record


return
0  if node was deleted
1 if node was not found (e.g., list is empty, no such node exists)

*/


int deleteNodeByName(PersonalInfo **head, char *firstName,
	char *familyName, unsigned int *id)
{
	PersonalInfo *p = searchByName(*head, firstName);
        if(p == NULL) return 1;
        printf("This is the deleted node: ");
        printNode(p);
        
        if(p == *head){
                PersonalInfo *next = (*head)->next;
                free(*head);
                *head = next;
                return 0;   
        }else{
                PersonalInfo *temp = *head;
                while(temp->next != p) temp = temp->next;
                temp->next = p->next;
                p->next = NULL;
                free(p);
                p = NULL;
                return 0;
              }
}
/************************************************************************/
/*
Purpose: deletes all nodes from the list
input/output
head - the head of the list


*/


void deleteList(PersonalInfo **head)
{
	// add code...must free here to ensure no memory leaks!
        PersonalInfo *next  = *head;
        
        while(*head != NULL){
                next = (*head)->next;       
                free(*head);
                *head = next;
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
        //if(node != NULL){
                printf("%-20s %-20s %7d \n",node->firstName, node->familyName, node->id);
        //}else{
          //      printf("NULL \n");//Changed just for my personal testing, will comment out changed code when submitting
        //}

}


/************************************************************************/
/*
Purpose: prints all the records in the list

input
head - the head of the list
*/


void printList(PersonalInfo *head)
{
      if(head == NULL) printf("Empty List \n");  
      while(head != NULL){
       printNode(head);       
       head = head->next;       
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
	if(head == NULL) return 0;
        int counter = 1;
        while(head->next != NULL){
                counter++;
                head = head->next;
        }
        return counter;


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
	if(head == NULL) return 0;
        int counter = 0;
        while(head != NULL){
                if(strncmp(firstName, head->firstName, 32) == 0) counter++;
                head = head->next;
        }
        
        return counter; 


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
	if(head == NULL || head->next == NULL) return;
        
        PersonalInfo *curr = head;
        PersonalInfo *next = head->next;
        
        while(next != NULL){
                while(next != NULL && strncmp(curr->firstName, next->firstName,32) == 0){
                        curr->next = next->next;
                        next->next = NULL;
                        free(next);
                        next = curr->next;
                }
                if(next != NULL){
                        curr = next;
                        next = next->next;
                        
                }
        }


}


/************************************************************************/
/*

//Bonus...no specs on desired implementation... going with my best guess */
void mergeLists(PersonalInfo **head1, PersonalInfo **head2, PersonalInfo **outHead)
{
        if(*head1 == NULL || *head2 == NULL) return; 
        
        PersonalInfo *p = *head1;
        PersonalInfo *q = *head2;
        *outHead = p;       
        PersonalInfo *r = *outHead;
         
        //p = p->next;
        while(p != NULL){
              r = p;
              r->next = p->next;  
              p = p->next;
        }
        //printf("Error check 2 \n");
        
        if(q != NULL){ 
                r->next = q;
                r = r->next;
        }
        while(q != NULL){
              r = q;
              r->next = q->next;
              q = q->next;   
        }
        //printf("Error check 3 \n"); 
                
}

                                                                                                                                                                                                                                                                                                                                                                      linked_list.h                                                                                       0000664 0001751 0001751 00000003242 13064066772 012512  0                                                                                                    ustar   admin                           admin                                                                                                                                                                                                                  /* 
File name is linked_list.h

*/


#ifndef LINKED_LIST_2401
#define LINKED_LIST_2401 1

#define NAME_LENGTH 32

typedef struct personalInfo {
	struct personalInfo *next;
	unsigned int id;		
	char firstName[NAME_LENGTH];
	char familyName[NAME_LENGTH];
} PersonalInfo;

// Part 
// Insert Functions 
PersonalInfo *insertToList(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName);

PersonalInfo *insertAfter(PersonalInfo *node, unsigned int id, 
        char *firstName, char *familyName);

PersonalInfo *insertLast(PersonalInfo **head, unsigned int id, 
        char *firstName, char *familyName);


// Search Functions

PersonalInfo *searchByName(PersonalInfo *head, char *firstName);

PersonalInfo *searchById(PersonalInfo *head, unsigned int id);


// Delete Functions
int deleteFromList(PersonalInfo **head, unsigned int *id, 
        char *firstName, char *familyName);

int deleteLast(PersonalInfo **head, unsigned int *id,
	char *firstName, char *familyName);

int deleteAfter(PersonalInfo *node, unsigned int *id,
        char *firstName, char *familyName);

int deleteNodeByName(PersonalInfo **head, char *firstName,
	char *lastName, unsigned int *id);

void deleteList(PersonalInfo **head);


// Print Functions
void printNode(PersonalInfo *node);

void printList(PersonalInfo *head);

// Counting Functions
int listSize(PersonalInfo *head);

int countRecords(PersonalInfo *head, char *firstName);

// Miscellaneous Functions

void removeDuplicates(PersonalInfo *head);

// Bonus

void mergeLists(PersonalInfo **head1, PersonalInfo **head2, 
        PersonalInfo **outHead);


#endif
                                                                                                                                                                                                                                                                                                                                                              linked_list.o                                                                                       0000664 0001751 0001751 00000021064 13064050116 012504  0                                                                                                    ustar   admin                           admin                                                                                                                                                                                                                  ELF                      �      4     (   U�����jH��������E�E��E��E�U�P�E�    �E�    �E���  �E���  �E����j �uP��������E��(��j �uP��������E�U��E� ��U����} u�    �n��jH��������E�E�U�P�E���  �E���  �E����j �uP��������E��(��j �uP��������E��E��E�U��E���U����E� ��u�u�u�u�u��������/�E� �E���E� �E�E� ��u��u�u�u�u����������U����} u�    �m�E�    �E�E���E� �E�E� ��t�E����j P�u���������uԋE����j P�u���������u�E�   �}� t�E���    ��U����} u�    �M�E�    �E�E���E�� �E��E�� ��t�E��@;Eu�E��@;Eu�E�   �}� t�E���    ��U����E� ��u�   �I��h    ��������E� ��P��������E� � �E�E� ��P��������E�U��    ��U����E� ��u
�   �   �E� � ��uB��h    ��������E� ��P��������E� ��P��������E�     �    �h�E� �E��E��E���E��E�E�� �E��E�� ��u��h    ����������u�����������u���������E�    �E��     �    ��U����} t	�E� ��u�   �O��h   ��������E� ��P��������E� �E�E��E��E��     ���u���������    ��U����E� ���uP��������E��}� u
�   �   ��h    ����������u���������E� ;E�u*�E� � �E�E� ��P��������E�U��    �I�E� �E���E� �E�E� ;E�u�E���E��E��     ���u���������E�    �    ��U����E� �E��#�E� � �E�E� ��P��������E�U��E� ��uԋE�     ���U����E�@�U�J(�U��PQRh@   ����������U����} u(��hR   �����������u��������E� �E�} u���U����} u�    �!�E�   ��E��E� �E�E� ��u�E���U����} u�    �9�E�    �'�E����j P�u���������u�E��E� �E�} uӋE���U����} ��   �E� ��tz�E�E��E� �E��b�E��E���E��     ���u���������E�� �E�}� t�E�P�E�����j RP���������t��}� t�E�E��E� �E�}� u�����U����E� ����   �E� ��tx�E� �E�E� �E��E�U��E� �E���E�E��E��E���E� �E�}� u�}� t*�E��U���E�� �E���E��E��E���E���E�� �E��}� u�����This is the deleted node:   This is the node that was deleted:  %-20s %-20s %7d 
 Empty List  1       I   E              8  �   �   �   
    int �  S    �  x   �  x   �   k    %   H�      �    	id %   �     �     ( �   
j  �     (Q      �   �Q  )  (W  � id (%   ��  )r   ��  )r   �p +Q  �dx .O   �hy /O   �l �   Q  �  PQ  �   �   ��      PQ  � id P%   ��  Pr   ��  Pr   �p TQ  �l �   wQ  	  V   �  )  wW  � id w%   ��  wr   ��  wr   ��   {Q  �l     �Q  _  �   �g  )  �Q  � �  �r   �i �O   �hp �Q  �l 2   �Q  �  b   ��  )  �Q  � id �%   �p �Q  �pi �O   �t �   �O   C  a   �  )  �W  � id �  ��  �r   ��  �r   �   �Q  �l %   �  O   �  �   ��  )  W  � id   ��  r   ��  r   �p %Q  �h,  &Q  �l =   KO   t  m   ��      KQ  � id K  ��  Lr   ��  Lr   �s RQ  �l w  pO   �  �   ��  )  pW  � �  pr   ��  qr   �id q  �p sQ  �h6  *   m     yQ  �l `  I   �   ~Q  �d  �  ��  H   ��  )  �W  �    �Q  �l .  ��  +   ��      �Q  �  �  �  =   �  )  �Q  �     �O   [  6   �A  )  �Q  � �   �O   �t �   �O   �  N   ��  )  �Q  � �  �r   ��   �O   �l �  �  �   ��  )  Q  �    Q  �h   Q  �l �  -u  �   �  -W  �   -W  ��   -W  �p 1Q  �lq 2Q  �pr 4Q  �t  %  $ >  $ >   I  I  ! I/  :;   :;I8  	 :;I8  
 :;I  .?:;'I@�B   :;I   :;I  4 :;I  4 :;I  .?:;'I@�B  .?:;'I@�B   :;I   :;I  4 :;I  4 :;I      .?:;'@�B  .?:;'I@�B  .?:;'@�B                              �   5   �       linked_list.c    linked_list.h          )g�uv��gh�Z.g fv����gh��>.g �Z�/��<.g fuug/� �� �yg[[.g fvu � � �� �wgZ[.g �u���Z.g �����v�g/g�����u�Z.g f �u�����Z.gg f��؟��v� . �����uZ.h�/���<h"<g f �/׀j<g fuu/K��?.g fuu/ �K�k?.g ��g�0���~ f�ggw�} 6g ������/g�mg��/g�m�  searchByName next curr listSize node personalInfo searchById deleteAfter GNU C11 5.4.0 20160609 -mtune=generic -march=i686 -g -fstack-protector-strong counter unsigned char insertLast long unsigned int temp short unsigned int deleteFromList countRecords outHead insertToList head1 head2 short int head printNode unsigned int linked_list.c long long unsigned int PersonalInfo deleteNodeByName deleteList insertAfter familyName sizetype long long int char removeDuplicates mergeLists firstName printList deleteLast long int signed char /home/admin/Downloads prev  GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609         zR |�            �    A�B��    <   �   �    A�B�    \   	  V    A�BR�    |   _  �    A�B~�    �   �  b    A�B^�    �   C  a    A�B]�    �   �  �    A�B��    �   t  m    A�Bi�      �  �    A�B��    <  �  H    A�BD�    \  �  +    A�Bg�     |    =    A�By�     �  [  6    A�Br�     �  �  N    A�BJ�    �  �  �    A�B��    �  u  �    A�B��                             ��                                                                                                 	                                                                              �                   #              +   �   �     7   	  V     B   _  �     O              W   �  b     b   C  a     q              x   �  +     �              �   �  �     �   t  m     �   �  �     �   �  H     �     =     �              �   [  6     �   �  N     �   �  �     �   u  �      linked_list.c insertToList malloc strncpy insertAfter insertLast searchByName strncmp searchById deleteFromList printf printNode free deleteLast deleteAfter deleteNodeByName deleteList printList puts listSize countRecords removeDuplicates mergeLists       Y     p     �     �     �     %    V    �    �    ]    b    s    �    �    �    �    �    5    :    H    V    �    �    �    �    �            %    J    �    �            .    3    C    �    "    K            
     
     
       !   	  (   
  /   
  6   
  =   
  D   
  K   
  Y   
  `   
  g   
  n   
  {   
  �   
  �   
  �   
  �   
  �   
  �   
  �     �   
    
    
  ^  
  h    w  
  �  
  �  
  �  
  �    �  
  �  
  �  
    
    
  $    3  
  A  
  h  
  r    �  
  �  
  �    �  
  �  
  �  
    
    
  %    4  
  Q  
  `  
  |  
  �  
  �    �  
  �  
  �  
  �  
  �    	  
    
  '  
  Q    ^  
  n    w  
  �  
  �    �  
  �  
  �  
  �    �  
  �  
  �    �  
  	  
      #  
  2  
  B  
  M    \  
  k  
  z  
  �  
  �    �  
  �  
  �  
  �  
  �    �  
  �  
  �  
            B           @     `     �     �     �     �               @    `    �    �    �    �          .symtab .strtab .shstrtab .rel.text .data .bss .rodata .rel.debug_info .debug_abbrev .rel.debug_aranges .rel.debug_line .debug_str .comment .note.GNU-stack .rel.eh_frame                                                       4                       	   @       @  H              %             @                     +             @                     0             @  ^                  <              �  5                 8   	   @       �                 H              �  �                 Z              �                     V   	   @       �        	         m              �  �                 i   	   @       �                 y      0       �  1                �      0       �  5                 �              �                     �             �                   �   	   @       �  �                             @  �                                  @              	              D  �                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              main.c                                                                                              0000664 0001751 0001751 00000005175 13056546411 011131  0                                                                                                    ustar   admin                           admin                                                                                                                                                                                                                  
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "linked_list.h"
#include "bubble_sort.h"

#define CONTINUE {printf("hit <cr> to continue \n"); getchar();}

void populatePerson(char *firstName, char *familyName, int *id);


int main(int argc, char* argv[])
{
	char firstName[NAME_LENGTH];
	char familyName[NAME_LENGTH];
	int id;
	struct personalInfo *empHead = NULL;
	struct personalInfo *p = NULL, *q = NULL;
	int i;
    int rc = 0;
	
	for (i = 0; i < 20; i++) {
	// add code for testing
		populatePerson(firstName, familyName, &id);
		insertToList(&empHead, id, firstName, familyName);
	}

	printList(empHead);

    printf("test SearchById \n");
	q = p = searchById(empHead, 111);
    if(p == NULL) { 
        printf("search by id failed \n");
    } else {
        printNode(p);
    }
    CONTINUE;
	if (p != NULL) {
	    for (i = 0; i < 4; i++) {
		    populatePerson(firstName, familyName, &id);
		    p = insertAfter(p, id, firstName, familyName);
	    }
    }
	printList(empHead);

    // test delete after
    
	rc = deleteAfter(q, &id, firstName, familyName);
    printf("deleteAfter rc = %d \n",rc);
	printList(empHead);
    CONTINUE;


	p = searchById(empHead, 111);
	if (p != NULL) {
		printf("\n found name to delete \n");
		printNode(p);
		strncpy(firstName, p->firstName, NAME_LENGTH);
		deleteNodeByName(&empHead, firstName, familyName, &id);
	}

	

	bubbleSort(&empHead);

	printf("\n\n sorted list \n\n");
	printList(empHead);

//	getchar();

	printf("\n\n remove duplicates \n\n");
	removeDuplicates(empHead);
	printList(empHead);
    deleteList(&empHead);
//	getchar();

	return 0;
}


	

/***************************************************************************/
/* purpose: the function populate the personal info

input/output
struct personalInfo *p - allocated memory to the struct pointer which the function assigns values.




*/

void populatePerson(char *firstName, char *familyName, int *id)
{
	static int initRand = 0;
	int j;
	char *first[5] = { "John", "Don", "Edna", "Bev", "Miya" };
	char *family[5] = { "Broker", "Smith", "Tower", "Little", "Bronson" };

	if (!initRand) {
		srand(1557);
		initRand ++;
	}
	// populate the first  name using a random i ndex to the first name array 
	j = rand() % 5;
	// copy the first name to the structure pointed by p using strcpy
	strncpy(firstName, first[j], NAME_LENGTH);

	// populate the first  name using a random i ndex to the first name array 
	j = rand() % 5;
	// copy the family name to the structure pointed by p using strcpy
	strncpy(familyName, family[j], NAME_LENGTH);

	// populate the student id using the random numnber in the range of 0-4096  
	*id = rand() % 150;

}






                                                                                                                                                                                                                                                                                                                                                                                                   main_test.o                                                                                         0000664 0001751 0001751 00000147440 13063102420 012170  0                                                                                                    ustar   admin                           admin                                                                                                                                                                                                                  ELF                      ��      4     (   �L$����q�U��Q��T�ȋ@�E�e�   �E�1��E�    �E�    �E�    �E�    �E�   �E�    h    �E�Pj�u���������E���Ph    ���������h2   ������������h    �E�Pj�u���������E���PhH   ���������h2   ������������h    �E�Pj�u���������E���Phx   ���������h2   ������������h    �E�Pj�u���������E���Ph�   ���������h2   ������������h    �E�Pj�u���������E���Ph�   ���������h2   ������������h    �E�Pj�u���������E���Ph  ���������h2   ������������h    �E�Pj
�u���������E���Ph<  ���������h2   ������������h    �E�Pj�u���������E���Php  ���������h2   ������������h    �E�Pj�u���������E���Ph�  ���������h2   ������������h    �E�Pj�u���������E���Ph�  ���������h2   ������������h    �E�Pj�u���������E���Ph  ���������h2   ������������h    �E�Pj�u���������E���Ph8  ���������h2   �������������E���Php  ��������    �U�e3   t������M�ɍa��U���8�E�EԋE�E�e�   �E�1��E�    �E�    �E�    ��h�  �������������E��}� u���u�E��Ѓ��E���u�������E؃�P��������E�E؉E܋E܃�������~���u�h�  ��������E؉E��E�����uT�E؉E�E�% �  ���E�E��t��t#�2��h�  ��������Eԋ�EEԉ���h�  ����������h�  ��������    �M�e3   t�������U���8�E�EԋE�E�e�   �E�1��E�    �E�    �E�    ��h  �������������E��}� u���u�E��Ѓ��E���u�������E؃�P��������E�E؉E܋E܃�������~���u�h�  ��������E؉E��E�����uT�E؉E�E�% �  ���E�E��t��t#�2��h3  ��������Eԋ�EEԉ���hF  ����������h[  ��������    �M�e3   t�������U���8�E�EԋE�E�e�   �E�1��E�    �E�    �E�    ��hy  �������������E��}� u���u�E��Ѓ��E���u�������E؃�P��������E�E؉E܋E܃�������~���u�h�  ��������E؉E��E�����uT�E؉E�E�% �  ���E�E��t��t#�2��h�  ��������Eԋ�EEԉ���h�  ����������h�  ��������    �M�e3   t�������U���X�E�EċE�E�e�   �E�1��E�    �E�    ���]��E�    ��h�  �������������E��}� u��j �E��Ѓ��E���u�������Eȃ�P��������E�EȉE̋Ẽ�������~#���u�h�  ���������h�  ��������EȉEЋEЃ���ub�EȉEԋE�% �  ���E�E��u%��h7  ��������E��E�8  �����]��!��hU  ���������hp  ��������������E��}� u��j�E��Ѓ��E���u�������Eȃ�P��������E�EȉE؋E؃�������~���u�h�  ��������EȉE܋E܃���uX�EȉE��E�% �  ���E�E��t��t'�6��h�  ��������E��E�8  �����]����hU  ����������h�  ��������Eċ �E��E��E��}��E��f�E��m��]��m��U��Eĉ�    �M�e3   t�������U���h�E�E��E�E�e�   �E�1��E�    �E�    ���]��E�    �E�� ��Ph�  �������������E��}� u��j �E��Ѓ��E���u�������E���P��������E�E��E��E���������~���u�h�  ��������E��EċEă�����   �E��EȋE�% �  ���E���u��u�h   ��������E��u?��h  ��������E��E�@  �����]��E���d$��$h5  ��������!��hM  ���������hl  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E̋Ẽ�������~#���u�h�  ���������h�  ��������E��EЋEЃ���u{�E��EԋE�% �  ���E�E��u?��h�  ��������E��E�@  �����]��E���d$��$h�  ��������!��h  ���������h   ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E؋E؃�������~#���u�h�  ���������hl  ��������E��E܋E܃���uk�E��E��E�% �  ���E�E��u?��h�  ��������E��E�@  �����]��E���d$��$h�  ����������h�  ����������h�  ��������E�� �E��E��E��}��E��f�E��m��]��m��U��E���    �M�e3   t�������U���h�E�E��E�E�e�   �E�1��E�    �E�    ���]��E�    �E�� ��Ph  �������������E��}� u��j �E��Ѓ��E���u�������E���P��������E�E��E��E���������~���u�h�  ��������E��EċEă�����   �E��EȋE�% �  ���E���u��u�h   ��������E��u?��h  ��������E��E�@  �����]��E���d$��$h5  ��������!��hM  ���������hl  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E̋Ẽ�������~#���u�h�  ���������h�  ��������E��EЋEЃ���u{�E��EԋE�% �  ���E�E��u?��h�  ��������E��E�@  �����]��E���d$��$h�  ��������!��h  ���������h   ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E؋E؃�������~#���u�h�  ���������hl  ��������E��E܋E܃���uk�E��E��E�% �  ���E�E��u?��h�  ��������E��E�@  �����]��E���d$��$h�  ����������h�  ����������h�  ��������E�� �E��E��E��}��E��f�E��m��]��m��U��E���    �M�e3   t�������U���h�E�E��E�E�e�   �E�1��E�    �E�    ���]��E�    �E�� ��Ph,  �������������E��}� u��j �E��Ѓ��E���u�������E���P��������E�E��E��E���������~���u�h�  ��������E��EċEă�����   �E��EȋE�% �  ���E���u��u�h   ��������E��u?��h\  ��������E��E�@  �����]��E���d$��$h5  ��������!��h|  ���������hl  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E̋Ẽ�������~#���u�h�  ���������h�  ��������E��EЋEЃ���u{�E��EԋE�% �  ���E�E��u?��h�  ��������E��E�@  �����]��E���d$��$h�  ��������!��h�  ���������h   ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E؋E؃�������~#���u�h�  ���������h  ��������E��E܋E܃���uk�E��E��E�% �  ���E�E��u?��h<  ��������E��E�@  �����]��E���d$��$h�  ����������h\  ����������h�  ��������E�� �E��E��E��}��E��f�E��m��]��m��U��E���    �M�e3   t�������U���h�E�E��E�E�e�   �E�1��E�    �E�    ���]��E�    �E�� ��Ph�  �������������E��}� u��j �E��Ѓ��E���u�������E���P��������E�E��E��E���������~���u�h�  ��������E��EċEă�����   �E��EȋE�% �  ���E���u��u�h   ��������E��u?��h�  ��������E��E�@  �����]��E���d$��$h5  ����������h�  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E̋Ẽ�������~#���u�h�  ���������h	  ��������E��EЋEЃ���uk�E��EԋE�% �  ���E�E��u?��h/	  ��������E��E�@  �����]��E���d$��$h�  ����������hK	  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E؋E؃�������~#���u�h�  ���������hl	  ��������E��E܋E܃���uk�E��E��E�% �  ���E�E��u?��h�	  ��������E��E�@  �����]��E���d$��$h�  ����������h�	  ����������h�	  ��������E�� �E��E��E��}��E��f�E��m��]��m��U��E���    �M�e3   t�������U���h�E�E��E�E�e�   �E�1��E�    �E�    ���]��E�    �E�� ��Ph�	  �������������E��}� u��j �E��Ѓ��E���u�������E���P��������E�E��E��E���������~���u�h�  ��������E��EċEă�����   �E��EȋE�% �  ���E���u��u�h   ��������E��u?��h
  ��������E��E�@  �����]��E���d$��$h5  ��������!��h1
  ���������hP
  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E̋Ẽ�������~#���u�h�  ���������h�
  ��������E��EЋEЃ���uk�E��EԋE�% �  ���E�E��u?��h�
  ��������E��E�@  �����]��E���d$��$h�  ����������hK	  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E؋E؃�������~#���u�h�  ���������h�
  ��������E��E܋E܃���uk�E��E��E�% �  ���E�E��u?��h�
  ��������E��E�@  �����]��E���d$��$h�  ����������h  ����������h'  ��������E�� �E��E��E��}��E��f�E��m��]��m��U��E���    �M�e3   t�������U���h�E�E��E�E�e�   �E�1��E�    �E�    ���]��E�    �E�� ��PhH  �������������E��}� u��j �E��Ѓ��E���u�������E���P��������E�E��E��E���������~���u�h�  ��������E��EċEă�����   �E��EȋE�% �  ���E���u��u�h   ��������E��u?��hm  ��������E��E�@  �����]��E���d$��$h5  ����������h�  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E̋Ẽ�������~#���u�h�  ���������h�  ��������E��EЋEЃ���uk�E��EԋE�% �  ���E�E��u?��h�
  ��������E��E�@  �����]��E���d$��$h�  ����������h�  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E؋E؃�������~#���u�h�  ���������h�  ��������E��E܋E܃���uk�E��E��E�% �  ���E�E��u?��h  ��������E��E�@  �����]��E���d$��$h�  ����������h  ����������h5  ��������E�� �E��E��E��}��E��f�E��m��]��m��U��E���    �M�e3   t�������U���h�E�E��E�E�e�   �E�1��E�    �E�    ���]��E�    �E�� ��PhT  �������������E��}� u��j �E��Ѓ��E���u�������E���P��������E�E��E��E���������~���u�h�  ��������E��EċEă�����   �E��EȋE�% �  ���E���u��u�h   ��������E��u?��h~  ��������E��E�@  �����]��E���d$��$h5  ����������h�  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E̋Ẽ�������~#���u�h�  ���������h�  ��������E��EЋEЃ���uk�E��EԋE�% �  ���E�E��u?��h�  ��������E��E�@  �����]��E���d$��$h�  ����������h  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E؋E؃�������~#���u�h�  ���������h$  ��������E��E܋E܃���uk�E��E��E�% �  ���E�E��u?��hL  ��������E��E�@  �����]��E���d$��$h�  ����������hl  ����������h�  ��������E�� �E��E��E��}��E��f�E��m��]��m��U��E���    �M�e3   t�������U���h�E�E��E�E�e�   �E�1��E�    �E�    ���]��E�    �E�� ��Ph�  �������������E��}� u��j �E��Ѓ��E���u�������E���P��������E�E��E��E���������~���u�h�  ��������E��EċEă�����   �E��EȋE�% �  ���E���u��u�h   ��������E��u?��h�  ��������E��E�@  �����]��E���d$��$h5  ����������h   ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E̋Ẽ�������~#���u�h�  ���������h$  ��������E��EЋEЃ���uk�E��EԋE�% �  ���E�E��u?��hP  ��������E��E�@  �����]��E���d$��$h�  ����������hp  ��������������E��}� u��j�E��Ѓ��E���u�������E���P��������E�E��E؋E؃�������~#���u�h�  ���������h�  ��������E��E܋E܃���uk�E��E��E�% �  ���E�E��u?��h�  ��������E��E�@  �����]��E���d$��$h�  ����������h�  ����������h  ��������E�� �E��E��E��}��E��f�E��m��]��m��U��E���    �M�e3   t�������U���he�   �E�1��E�    �E�    �E�    �E�    �E�    �@h�<  �E�P�E�P�E�P��������E����E��E��E�P�E�PR�E�P��������E��E�;E|��E�    �E��E��?�E��P�E�� �@��9�t�E��@��Ph(  ��������   �Q�E�� �E��E��E�� ��u��E��;E�t���u�u�hT  ��������   ����E�P��������    �M�e3   t�������U���he�   �E�1��E�    �E�    �E�    �E�    �E�    �@h�<  �E�P�E�P�E�P��������E����E��E��E�P�E�PR�E�P��������E��E�;E|��E�    �E��E��B�E��P�E�� �@��9�t!�E��@��Ph�  ��������   �  �E�� �E��E��E�� ��u��E��;E�t ���u�u�h�  ��������   �S  ���E�P��������E�    �@h�<  �E�P�E�P�E�P��������E����E��E��E�P�E�PR�E�P��������E��E��;E���E����E��E��E�P�E�PR�E�P��������E�    �E��E��B�E��P�E�� �@��9�t!�E��@��Ph�  ��������   �   �E�� �E��E��E�� ��u��E��;E�t���u�u�h�  ��������   �K�E���P��������E��E�;Et���u�u�h�  ��������   ����E�P��������    �M�e3   t�������U���he�   �E�1��E�    �E�    �E�    �E�    �E�    �Kh�<  �E�P�E�P�E�P��������E����E��E���t�E��E�P�E�PR�E�P����������E��E�;E|��E���jP��������E��}� t"�E�   �E��E�P�E�PR�u�����������h:  ��������E�    �E��E��?�E��P�E�� �@��9�t�E��@��PhL  ��������   �Q�E�� �E��E��E�� ��u��E��;E�t���u�u�hx  ��������   ����E�P��������    �M�e3   t�������U���xe�   �E�1��E�    �E�    �E�    �E�    �E�    �E�    ��h�  ��������E�   �E�    �@h�<  �E�P�E�P�E�P��������E����E��E��E�P�E�PR�E�P��������E��E�;E|��E�P�E�P�E�P�E�P��������E��} ty�E��@��t��h�  ��������   �Z�E�    �E��E��?�E��P�E�� �@��9�t�E��@��Ph�  ��������   ��E�� �E��E��E�� ��u��E��M�e3   t�������U���he�   �E�1��E�    �E�    �E�    �E�    �E�    ��h  ��������} u*�E��U�R�U�R�U�RP��������E��}������]  �E�   �E�    �@h�<  �E�P�E�P�E�P��������E����E��E��E�P�E�PR�E�P��������E��E�;E|��}u*�E��U�R�U�R�U�RP��������E��}�������   �E��E��E�P�E�P�E�P�u���������E��}� t��h0  ��������E��   �}��   �E��@��t$�E�� �@��t��hh  ��������   �^�E�    �E�� �E��?�E��P�E�� �@��9�t�E��@��Ph�  ��������   ��E�� �E��E��E�� ��u��    �M�e3   t�������U���he�   �E�1��E�    �E�    �E�    �E�    �E�    ��h�  ��������} u@�E�P�E�P�E�P�E�P��������E��}�t��h�  ��������}������v  �E�   �E�    �@h�<  �E�P�E�P�E�P��������E����E��E��E�P�E�PR�E�P��������E��E�;E|��E�P�E�P�E�P�E�P��������E��}u8�E���t)��h�  ����������E�P��������   ��   �E���   �}��   �E�    �E��E��N�E��P�E�� �@��9�t-�E��@��Ph�  ����������E�P��������   �j�E�� �E��E��E�� ��u��E��;E�t&��h   ����������E�P��������   �$��h?  ����������E�P��������    �M�e3   t�������U���   e�   �E�1��E�    �E�    �E�DN35�E�5779�E�    �E�    �E�    �E�    �E�    �E�    ǅ|���    �E�    �E�    ��hB  ��������} u0��x���P�E�P�E�P��|���P��������E��}�������  �}��  ǅx���   h�<  ��x���P�E�P�E�P����������E�P�E�P���������x����E�P�E�PR��|���P����������E�P�E�P���������x���P�E�P�E�P��|���P��������E��}� t�}� �����  ��|�����u���E�P�E�P���������t��hX  ��������   ��  ǅx���   h�<  ��x���P�E�P�E�P���������x����E�P�E�PR��|���P����������E�P�E�P���������x���P�E�P�E�P��|���P��������E��}�t�}������S  ��|�����P���������t��hX  ��������   �"  ����|���P��������    �  ǅx���   �E�    �eh�<  ��x���P�E�P�E�P��������}�u���E�P�E�P��������E�����x�����x����E�P�E�PR��|���P��������E��E�;E|����E�P�E�P���������x���P�E�P�E�P��|���P��������E���|������U�RP��������E��}� u�}� t���u��u�h�  ��������E��  �E�    ��|���� �E��N�E��P�E�� �@��9�t-�E��@��t!�E��@��Ph   ��������   �  ��E�� �E��E��E�� ��u���|�����P��������E��9�t��hP  ��������   �l  ����|���P�������ǅx���   �E�    �Lh�<  ��x���P�E�P�E�P��������E�����x�����x����E�P�E�PR��|���P��������E��E�;E|����E�P�E�P���������x���P�E�P�E�P��|���P��������E��}� u��h|  ��������E��   �E�    ��|���� �E��?�E��P�E�� �@��9�t�E��@��Ph�  ��������   �Z�E�� �E��E��E�� ��u���|�����P�������;Et��h�  ��������   �����|���P��������    �M�e3   t�������U���   e�   �E�1��E�    �E�    �E�DN35�E�5779�E�    �E�    �E�    �E�    �E�    �E�    ǅ|���    �E�    �E�    ��h  ��������} u>��|������U�RP��������E��}� t��h$  ��������}� �����#  �}�c  ǅx���   h�<  ��x���P�E�P�E�P����������E�P�E�P���������x����E�P�E�PR��|���P���������|������U�RP��������E��}� u,��hX  �����������|���P��������   �u  ����|���P�������ǅx���   h�<  ��x���P�E�P�E�P���������x����E�P�E�PR��|���P���������|������U�RP��������E��}� t,��h�  �����������|���P��������   ��  ����|���P��������    �  ǅx���   �E�    �eh�<  ��x���P�E�P�E�P��������}�u���E�P�E�P��������E�����x�����x����E�P�E�PR��|���P��������E��E�;E|����E�P�E�P���������|������U�RP��������E��}� u,��hX  �����������|���P��������   ��   ����|���P�������ǅx���   �E�    �Lh�<  ��x���P�E�P�E�P��������E�����x�����x����E�P�E�PR��|���P��������E��E�;E|���|������U�RP��������E��}� t)��h�  �����������|���P��������   �����|���P��������    �M�e3   t�������U���   e�   �E�1��E�    �E�    �E�DN35�E�5779�E�    �E�    �E�    �E�    �E�    �E�    ǅ|���    �E�    �E�    ��h�  ��������} u<��|�����jP��������E��}� t��h�  ��������}� �����  �}�p  ǅx���   h�<  ��x���P�E�P�E�P����������E�P�E�P���������x����E�P�E�PR��|���P���������x�����|�����RP��������E��}� u,��h  �����������|���P��������   �f  ����|���P�������ǅx���   h�<  ��x���P�E�P�E�P���������x����E�P�E�PR��|���P���������x�������|�����RP��������E��}� t,��h�  �����������|���P��������   �  ����|���P��������    �  ǅx���   �E�    �eh�<  ��x���P�E�P�E�P��������}�u���E�P�E�P��������E�����x�����x����E�P�E�PR��|���P��������E��E�;E|���|�����jP��������E��}� u,��h0  �����������|���P��������   ��   ����|���P�������ǅx���   �E�    �Lh�<  ��x���P�E�P�E�P��������E�����x�����x����E�P�E�PR��|���P��������E��E�;E|���|�����jaP��������E��}� t)��h�  �����������|���P��������   �����|���P��������    �M�e3   t�������U���   e�   �E�1��E�    �E�    �E�DN35�E�5779�E�    �E�    �E�    �E�    �E�    �E�    ǅ|���    �E�    �E�    ��h[  ��������} u:��|�����P��������E��}� t��hl  ��������}� ������   ǅx���   �E�    �Lh�<  ��x���P�E�P�E�P��������E�����x�����x����E�P�E�PR��|���P��������E��E�;E|���|�����P��������E��E�;Et)��h�  �����������|���P��������   �����|���P��������    �M�e3   t�������U���   e�   �E�1��E�    �E�    �E�DN35�E�5779�E�    �E�    �E�    �E�    �E�    �E�    ǅ|���    �E�    �E�    ��h�  ��������} u>��|������U�RP��������E��}� t��h�  ��������}� �����"  �}�c  ǅx���   h�<  ��x���P�E�P�E�P����������E�P�E�P���������x����E�P�E�PR��|���P���������|������U�RP��������E��}�t,��h  �����������|���P��������   �t  ����|���P�������ǅx���   h�<  ��x���P�E�P�E�P���������x����E�P�E�PR��|���P���������|������U�RP��������E��}� t,��hD  �����������|���P��������   ��  ����|���P��������    �  ǅx���   �E�    �wh�<  ��x���P�E�P�E�P��������}�t�}�	t�}�t�}�u���E�P�E�P��������E�����x�����x����E�P�E�PR��|���P��������E��E�;E|���|������U�RP��������E��}�t,��hp  �����������|���P��������   ��   ����|���P�������ǅx���   �E�    �Lh�<  ��x���P�E�P�E�P��������E�����x�����x����E�P�E�PR��|���P��������E��E�;E|���|������U�RP��������E��}� t)��hD  �����������|���P��������   �����|���P��������    �M�e3   t�������U���   e�   �E�1��E�    �E�    �E�DN35�E�5779�E�    �E�    �E�    �E�    �E�    �E�    ǅ|���    �E�    �E�    ��h�  ��������} u7��|�����P��������}� t��h�  ��������}� ������  �}��   ǅx���   h�<  ��x���P�E�P�E�P����������E�P�E�P���������x����E�P�E�PR��|���P���������|�����P�����������|���P��������    �h  ǅx���   �E�    �wh�<  ��x���P�E�P�E�P��������}�t�}�	t�}�t�}�u���E�P�E�P��������E�����x�����x����E�P�E�PR��|���P��������E��E�;E|�����|���P���������h�  ���������|�����P���������|�����P���������|�����P��������E���h�  ���������|�����P����������u�h�  ��������}�t)��hp  �����������|���P��������   �����|���P��������    �M�e3   t�������U���H�E�EċE�E��E�E�e�   �E�1��E��  �E��  �E��  �E��  �E��  �E��  �E�  �E�
  �E�  �E�  �    ��u�E��P��������E�    ��������gfff����������)ЉEȋUȉ����)��ȉEȋEȋD�̃�j P�u����������������gfff����������)ЉEȋUȉ����)��ȉEȋEȋD����j P�u������������������N����������)�i��   )��ȋU����E�e3   t�������U����E�    ��jHj��������E�}� u�    �L�E����j�uP��������E��(��j�uP��������E�U�P�E��E��E�U��E���U����E�u�u�uP���������U����E�    �E� ��u�u�u�u�u��������0�E� �E���E� �E�E� ��u�E��u�u�uP���������U����E�    �E�    �E�E��(�E�����j �uP��������E�}� t�E�� �E��}� u����E���U����E�    �E�E���E��@;Et�E�� �E��}� u����E���U����E�    �E� ��u�   �^�E� �E�E��E��E�P�E��E����j P�u��������E��(��j P�u����������u���������    ��U����E�    �E� ��u�   �Y�E� �E�E� ��u�u�u�u�u��������2�E� �E���E� �E�E� � ��u�E��u�u�uP���������U����} u�   ��E�u�u�uP���������U����E�    �E�    �E� ���uP��������E�}� u�   �P�E� ;E�u�u�u�u�u��������0�E� �E���E�� �E��E�� ;E�u��u�u�u�u����������U���h�E�E�e�   �E�1���E�P�E�P�E�P�u���������E�� ��u���E�e3   t�������U����E�@�U�J(�U��PQRh  ����������U����E�    �E�E�����u���������E� �E�}� u���U����E�    �E�    �E�E���E��E�� �E��}� u�E���U����E�    �E�    �E�E��'�E�����j �uP���������u�E��E�� �E��}� uӋE���U���h�E�E�e�   �E�1��E�    �E�    �E��E��G�E�� �P�E�����j RP��������E��}� u�E�P�E�P�E�P�u����������E�� �E��}� t	�E�� ��u���E�e3   t�������U��]�U���x�E�E�e�   �E�1��E�    �E�    �E�    �E�    �}� ��   �E�� ��P��������E��}���   �E�� �E��r�E��E��E�   �X�E�� �E��E�� �E��E��P�E�����j RP���������~!�E���E���E��U���E��U���E�    �E�� �E��E�� � ��u��}� t��U��E�������E�e3   t�������  
 After Testing insert to list totalPoints = %d 
 hit <cr> to continue  
 After Testing insert last totalPoints = %d 
  
 After Testing insert after totalPoints = %d 
 
 After Testing delete from list totalPoints = %d 
 
 After Testing delete after totalPoints = %d 
 
 After Testing delete last totalPoints = %d 
  
 After Testing delete by name totalPoints = %d 
   
 After Testing search by name totalPoints = %d 
   
 After Testing search by id totalPoints = %d 
 
 After Testing list size totalPoints = %d 
    
 After Testing count records totalPoints = %d 
    
 After Testing remove duplicates id totalPoints = %d 
 

 total assignment points = %d 
 
Testing insert to list   Child  %d was signaled to stop !!!
 Passed insertToList  Error in insertToList  Completed testing insertToList  
 Testing insert last  Passed insertLast  Error in insertLast  Completed testing insertLast  
Testing insert After  Passed insertAfter  Error in insertAfter    Completed testing insertAfter  
 Testing delete from list   Problem cuased because attempting to delete from an empty list Passed test 1 DeleteFromList  Error in DeleteFromList    Wrong return code when list is empty  Passed test 2 DeleteFromList  Completed testing deleteFromList    
 Testing delete After totalPints = %d
 returned cpid = %d rc=%d
 Passed DeleteAfter test 1  1 local points = %3.1f
 Error in DeleteAfter test 1    Wrong return code when deleting from a list with no nodes   deleteAfter segmentation error test 2 Passed DeleteAfter test 2  2 local points = %3.1f
 Error in DeleteAfter test 2    Wrong return code when trying to delete after a node that has no successor  deleteAfter segmentation error test 3 Passed DeleteAfter test 3  3 local points = %3.1f
 Error in DeleteAfter test 3    Completed testing deleteAfter   
 Testing delete Last totalPints = %d
  
 Testing delete Node By Name totalPints = %d
  Passed DeleteNodeByName test 1  Error in DeleteNodeByName test 1    deleteNodeByName segmentation error test 2  Passed DeleteNodeByName test 2  Error in DeleteNodeByName test 2    deleteNodeByName segmentation error test 3  Passed DeleteNodeByName test 3  Error in DeleteNodeByName test 3    Completed testing deleteNodeByName  
 Testing search By Name totalPints = %d
 Passed SearchByName test 1  Error in SearchByName test 1  SearchByName segmentation error test 2 Passed SearchByName test 2  Error in SearchByName test 2     SearchByName segmentation error test 3 Passed SearchByName test 3  Error in SearchByName test 3     Completed testing SearchByName  
 Testing SearchById totalPoints = %d
 Passed SearchById test 1  Error in SearchById test 1     Wrong return code when searching from a list with no nodes  SearchById segmentation error test 2 Passed SearchById test 2   SearchById segmentation error test 3 Passed SearchById test 3  Error in SearchById test 3  Completed testing SearchById     
 Testing ListSize totalPoints = %d
 Passed ListSize test 1  Error in ListSize test 1   ListSize segmentation error test 2 Error in ListSize test 2     ListSize segmentation error test 3 Passed ListSize test 3  Error in ListSize test 3  Completed testing ListSize     
 Testing Count Records totalPoints = %d
 Passed Count Records test 1   Error in Count Records test 1   Count Records segmentation error test 2 Passed Count Records test 2     Error in Count Records test 2   Count Records segmentation error test 3 Passed Count Records test 3     Error in Count Records test 3   Completed testing Count Records     
 Testing removeDuplicates  totalPoints = %d
   Passed removeDuplicates test 1  Error in removeDuplicates test 1    removeDuplicates segmentation error test 2  Passed removeDuplicates test 2  Error in removeDuplicates test 2    removeDuplicates segmentation error test 3  Passed removeDuplicates test 3  Error in removeDuplicates test 3    Completed testing removeDuplicates  Error in insert to list (order) p->id=%d 
  error in insert to list (num records) i =%d numrecords = %d
    Error in insert last (order) p->id=%d 
 error in insert last (num records) i =%d numrecords = %d
   error in insert last (counting records) size =%d numrecords = %d
 ERROR IN TEST     Error in insert after (order) p->id=%d 
    error in insert after (num records) i =%d numrecords = %d
 
 testdeleteFromList     Did not delete the first record!!   Error in delete from list (order) p->id=%d 
 
 testdeleteAfter  deleteAfter test: functions returns wrong return code   Did not delete the node after!! 
 testDeleteLast    deleteLast: error in return code when deleting from an empty list    Did not properly deleted last node from a list with one node   did not delete the last record 11 
 test deleteBy Name  deleteNode byName: error when deleting from a a list with one matched record    deleteNodeByName matched test: function returns wrong return code or function did not find matched node rc=%d p = %p
   Error in deleteNodeByName (order) p->id=%d 
    delete node by name: node was not deleted   deleteNodeByName unmatched test: function returns wrong return code delete node by name: a node was deleted when no node should have been deleted 
 test search by name searchByName: errro found a node in an empty loist  searchByName: did not find an existing name     searchByName: error found a non existing record  
 test search By Id    searchById: errro found a node in an empty list     searchById: did not find an existing id     searchByName: did not find an existing id  
 test list size listSize: wrong list size when list is empty    listSize: returned the wrong list size  
 test count records    countRecords: error counting records when list is empty countRecords: did not count existing records    countRecords: counted non existing records  countRecords: did not count all existing records 
 test remove duplicates   list before removing duplicates  rc = %d
 John Don Edna Bev Miya Broker Smith Tower Little Bronson %-20s %-20s %7d 
               @      @5       f  �  �      �L      �  8    �  �  �   int I  �  s  {   x   3  O   x   �   k    Z  H�   �  �    	id %   �  �     �   ( �   
f   �   �   ,O       t  ��  r  ,O   � �  ,�  u��  .�   uT  /�   uTid 0O   s   1�   u@p 2�   uDq 2�   uHi 3O   rc 4O   uL�  5O   uP-  6O   u� r   �   |O   t  2  �J  �  |O   � �   |O   �-  |   �L�   |Y  �Hi O   j O   �d�  �O   �h  �O   �Prc �O   �`�  (     d   *  T     O   Y  O    J     �O   �  2  �  �  �O   � �   �O   �-  �   �L�   �Y  �Hi �O   j �O   �d�  �O   �h  �O   �Prc �O   �`$  (   L  d   \  T     V  �O   �  2  ��  �  �O   � �   �O   �-  �   �L�   �Y  �Hi �O   j �O   �d�  �O   �h  �O   �Prc �O   �`V  (   ~  d   �  T     �  O   
  K  ��  �  O   � �   O   �-     ���   Y  ��i O   j O   �d�  O   �h  O   �@rc O   �`<   �  �\�  8   �  r   �  �  b    q  (   �  h   �  X       F  YO   U	  �  ��  �  YO   � �   YO   �-  Y   ���   YY  ��i \O   j \O   �d�  ]O   �h  ^O   ��rc _O   �`<   `�  �\�	  (   
  �   p  
  �    �
  8     �   �  -  {    �  8     {   +  k        �O   �  �  ��  �  �O   � �   �O   �-  �   ���   �Y  ��i �O   j �O   �d�  �O   �h  �O   ��rc �O   �`<   ��  �\r  (   �  �   x  �  �    z  8   �  �   �  �  {    x  8   �  {   �  k     �   8O     �  ��  �  8O   � �   8O   �-  8   ���   8Y  ��i ;O   j ;O   �d�  <O   �h  =O   ��rc >O   �`<   ?�  �\  (   /  �   �  C  �      8   G  �   �  W  {      8   E  {   U  k     �  �O     u  ��  �  �O   � �   �O   �-  �   ���   �Y  ��i �O   j �O   �d�  �O   �h  �O   ��rc �O   �`<   ��  �\�  (   �  �   �  �  �    �  8   �  {   �  �  k    �  8   �  {   �  k     �  O   �  �  ��	  �  O   � �   O   �-     ���   Y  ��i O   j O   �d�  O   �h  O   ��rc  O   �`<   !�  �\  (   9  �   �	  M  �      8   Q  {   �	  a  k      8   ?  {   O  k     �  �O     u  ��
  �  �O   � �   �O   �-  �   ���   �Y  ��i �O   j �O   �d�  �O   �h  �O   ��rc �O   �`<   ��  �\�  (   �  �   �
  �  �    �  8   �  {   �
  �  k    |  8   �  {   �  k     I  �O   �  u  ��  �  �O   � �   �O   �-  �   ���   �Y  ��i O   j O   �d�  O   �h  O   ��rc O   �`<   �  �\  (   3  �   �  G  �       8   ;   {   �  K   k    �   8   )!  {   9!  k     �   sO   �!  u  ��  �  sO   � �   sO   �-  s   ���   sY  ��i vO   j vO   �d�  wO   �h  xO   ��rc yO   �`<   z�  �\�"  (   �"  �   �  �"  �    x#  8   �#  {   �  �#  k    f$  8   �$  {   �$  k     	  O   m%  $  �|  �  O   � �  �   ��  �   �Lid O   ��s   �   ��p �   ��q �   ��i O   ��rc O   �� c  7O   �&  i  �  �  7O   � �  9�   ��  :�   �Lid ;O   ��s   <�   ��p =�   ��q =�   ��i >O   ��rc ?O   �� �  �O   �(  {  ��  �  �O   � �  ��   ��  ��   �Lid �O   ��s   ��   ��p ��   ��q ��   ��i �O   ��rc �O   �� 9  �O   u*  S  �h  �  �O   � i �O   ��j �O   �  �O   ��  �O   ��rc �O   ���  ��   ��  ��   �Lid �O   ��s   ��   ��p ��   ��q ��   �� W  �O   �+  �  �"  �  �O   � i �O   ��j �O   �  �O     �O   ��rc �O   ���  �   ��  �   �Lid �O   ��s   ��   ��p ��   ��q ��   �� �  O   �-    ��  �  O   � i "O   ��j "O   �  #O     $O   ��rc %O   ���  &�   ��  '�   �Lid (O   ��s   )�   ��p *�   ��q *�   �� 4  cO   �/  �  ��  �  cO   � i fO   ��~j fO   �  gO     hO   ��rc iO   ���   j�   ���  k�   ��  l�   �Lid mO   ��~s   n�   ��~p o�   ��~q o�   �� +   �O   S5  �  ��  �  �O   � i �O   ��~j �O   �  �O     �O   ��~rc �O   ���   ��   ���  ��   ��  ��   �Lid �O   ��~s   ��   ��~p ��   ��q ��   ��   ^O   O9  �  �n  �  ^O   � i aO   ��~j aO   �  bO     cO   ��~rc dO   ���   e�   ���  f�   ��  g�   �Lid hO   ��~s   i�   ��~p j�   ��q j�   �� H   �O   ?=  �  �E  �  �O   � i �O   ��~j �O   �  �O     �O   ��~rc �O   ���   ��   ���  ��   ��  ��   �Lid �O   ��~s   ��   ��~p ��   ��q ��   �� 8  O   �>  �  �  �  O   � i O   ��~j O   �  O     	O   ��~rc 
O   ���   �   ���  �   ��  �   �Lid O   ��~s   �   ��~p �   ��q �   �� #  qO   �B  �  ��  �  qO   � i tO   ��~j tO   �  uO     vO   ��~rc wO   ���   x�   ���  y�   ��  z�   �Lid {O   ��~s   |�   ��~p }�   ��q }�   �� �   ��E  V  ��  �  �r   ��  �r   ��id �   ��L  �O   �r  �O       j �O   �@�  ��  �D�  ��  �X r   �  k    �  )�  �F  z   ��  �   )�  � id )%   ��  *r   �  *r   �p .�  �l �   �  �  S�  nG     �O  �  S�  � id S%   ��  Sr   �  Sr   � �  m�  �G  ^   ��  �   m�  � id m%   ��  mr   �  mr   �p p�  �l �  ��  �G  R   ��  �   ��  � �  �r   �rc �O   �lp ��  �h     ��  ;H  6   �<  �   ��  � id �%   �p ��  �t �  �O   qH  }   ��  �   ��  � id ͙  ��  �r   �  �r   �p ��  �l %   {  �O   �H  x   ��  �   ��  � id ��  ��  �r   �  �r   �p ��  �l %  O   fI  *   �R  �  �  � id �  ��   r   �   r   � |  ?O   �I  �   ��  �   ?�  � �  ?r   �  @r   �id @�  �p D�  �lq E�  �h �  _J  M   �  �   _�  ��id c%   ���  d�   ��  e�   �L U   ygJ  +   �=  �  y�  �  (  ��J  4   �p  �   ��  � p ��  �l  �   �O   �J  3   ��  �   ��  � p ��  �p�  �O   �t w  �O   �J  N   �  �   ��  � �  �r   �p ��  �h�  �O   �l �  �GK  �   �}  �   ��  ��p ��  ��rc �O   ��id �%   ���  ��   ��   ��   �L !V  �K     ��  g  �  � m  �  �%  �  � "  !�K  �   ��   !�  ��p1 #�  ��p2 #�  ��p #�  ��a   $�   ���  %O   ��g  &O   ��  %  $ >  $ >   I  I  ! I/  :;   :;I8  	 :;I8  
 :;I  .?:;'I@�B   :;I  4 :;I  4 :;I  4 :;I       'I   I  .?:;'I@�B   :;I  4 :;I  4 :;I  4 :;I    4 :;I  4 :;I  .?:;'@�B   :;I   :;I  .?:;'I@�B   .?:;'I@�B  !.?:;'@�B  ".?:;'@�B                    �L          +   n   �       main_test.c    test_functions.c    nuss_linked_list.c    bubble_sort.c    linked_list.h          ,��u�uuxY=MY=MY=MY=MY=MY=MY=MY=MY=MY=MY?LY=L=Y� �uvv�h�!K0�=	�y.��0�%�Z4 �uvv�h�!K0�=	�y.��0�%�Z4 �uvv�h�!K0�=	�y.��0�%�Z5 �uuZv�h�!K/��=��/0��&�h�!K0�=	�y.�/0�%�,Z4 �uuZvZ�h�!K0>=Yv�/�0��&�h�!K/��=v�/�0��'�h�!K/��=v�/�0�#�,Z3 �uuZvZ�h�!K0>=Yv�/�0��&�h�!K/��=v�/�0��'�h�!K/��=v�/�0�#�,Z4 �uuZvZ�h�!K0>=Yv�/�0��&�h�!K/��=v�/�0��'�h�!K/��=v�/�0�#�,Z5 �uuZvZ�h�!K0>=Yv�/�0�&�h�!K/��=v�/�0�'�h�!K/��=v�/�0�#�,Z	. �uuZvZ�h�!K0>=Yv�/�0��&�h�!K/��=v�/�0�'�h�!K/��=v�/�0�#�,Z
. �uuZvZ�h�!K0>=Yv�/�0�&�h�!K/��=v�/�0�'�h�!K/��=v�/�0�#�,Z
. �uuZvZ�h�!K0>=Yv�/�0�&�h�!K/��=v�/�0�'�h�!K/��=v�/�0�#�,Z. �uuZvZ�h�!K0>=Yv�/�0�&�h�!K/��=v�/�0�'�h�!K/��=v�/�0�#�,Z�v.f�u�x � � � � J��Kg q ���Yx� Z�yf�u�x � � � � J��Kg � ���Y�� � � � � J����Kg � ���Yx"�Yx� Z�yf�u�x�����  J	�=gu���Kg q ���Yx� Z�zf�uxu�v�u � � � � J��g��v�Kg q �� >�zf�uxu��h��u � � � � J�h��g�g� ���vKg q �� Z�yf�uxu��h�g��u � � � � J��gu�堅��Kg� p �����w�� Z�{��uu8���h�蟠�/�/� f� �g���/� f�g�!����h 0 � x� J�/�� fgY�=K�g�  ����$� � � � � J�/�g�=Kg q ��g�w$ Z�t��uu8���h�g�蟠�/��g�!�#����g�!�!����h 0 � x� J�/�g�!�%� � � � � J��g�!v! Z�	t��uu8���hgg�蟠�/��g�!�#����g�!�!����h 0 � x� J�gg�!�%� � � � � J�gg�!v! Z�	t��uu8���hKg�� � � � � J�K��!v# \�z��uu8���h�g�蟠�/��g�!�#����g�!�!���� f f fh 0 � x� J��g�!�%� � � � � J��g�!w! \�x��uu8���h!g�蟠�/�!"���� f f fh 0 � x� J�!�!!K�!/g�!v" _�%tt�##��/w/w+�x<iw! fwgg���=.hM.hz�\ � ��L.iuu�� d ��"=.iv� � ��"=.gv �w���gh�Y.gv �v� �[ � ��K.g fuM.iuvi fu �[ � ��=.��0d�<g"<iv � Xi<huv � �h?.iuv� � I �j?.��uy�� f�  f�<@�|<��Mw�=��/gu0��۟��vr��fc�A  dnSearchById forkDeleteLast forkInsertLast testSearchByName localPoints testListSize dnPrintNode temp PersonalInfo empHead sizetype populatePerson forkDeleteNodeByName dnListSize main short int testFun head testName forkInsertToList maxPoints forkRemoveDuplicates familyName float testSearchById dnPrintList testDeleteNodeByName long long int testDeleteAfter head1 head2 long int dnDeleteNodeByName forkDeleteFromList dnInsertLast node dnDeleteFromList dnSearchByName /home/c2401/Dropbox/COMP2401/2017_winter/assignments/assignment_3/test_program testRemoveDuplicates unsigned char forkDeleteAfter dnMergeLists testInsertLast argc dnCountRecords dnRemoveDuplicates signed char long long unsigned int testInsertAfter family unsigned int argv firstName forkSearchByName secondName short unsigned int status dnDeleteAfter char testCountRecords forkCountRecords personalInfo listSorted initRand dnDeleteLast dnInsertToList long unsigned int dnDeleteList cpid size testDeleteLast count numRecords dnInsertAfter forkSearchById main_test.c testInsertToList bubbleSort outHead totalPoints testDeleteFromList initRand1 forkInsertAfter GNU C11 5.4.0 20160609 -mtune=generic -march=i686 -g -fstack-protector-strong first next forkListSize  GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.4) 5.4.0 20160609         zR |�  ,          t   D Gu Cu|a A�C      L   t  2   A�B.�   l   �  2   A�B.�   �   �  2   A�B.�   �   
  K   A�BG�   �   U	  �   A�B��   �   �  �   A�B��       �   A�B��   ,    u   A�Bq�   L  �  �   A�B��   l    u   A�Bq�   �  �  u   A�Bq�   �  �!  u   A�Bq�   �  m%  $   A�B �   �  �&  i   A�Be�     �(  {   A�Bw�   ,  u*  S   A�BO�   L  �+  �   A�B��   l  �-     A�B�   �  �/  �   A�B��   �  S5  �   A�B��   �  O9  �   A�B��   �  ?=  �   A�B��     �>  �   A�B��   ,  �B  �   A�B��   L  �E  V   A�BR�   l  �F  z    A�Bv�    �  nG      A�BY�     �  �G  ^    A�BZ�    �  �G  R    A�BN�    �  ;H  6    A�Br�       qH  }    A�By�    ,  �H  x    A�Bt�    L  fI  *    A�Bf�     l  �I  �    A�B��    �  J  M    A�BI�    �  gJ  +    A�Bg�     �  �J  4    A�Bp�     �  �J  3    A�Bo�       �J  N    A�BJ�    ,  GK  �    A�B��    L  �K      A�BB�     l  �K  �    A�B��                             ��                                                                                                             	                                                                              t        m%  $    1   t  2    B              I              N              V   �&  i    e   �  2    t   �(  {    �   �  2    �   u*  S    �   
  K    �   �+  �    �   U	  �    �   �-      �   �  �    �   �/  �        �    "  S5  �    3    u    D  O9  �    S  �  �    b  ?=  �    o    u    |  �>  �    �  �  u    �  �B  �    �  �!  u    �             �             �             �             �  �E  V    �               J  M                    �G  ^     )  �J  3     4  ;H  6     A             M             \             h             s             ~             �             �             �  �G  R     �             �             �             �             �             �  �K  �     �  �J  4                                              �F  z                  &  nG       4             <  qH  }     M             R  �H  x     _  fI  *     m  �I  �     �  gJ  +     �  �J  N     �  GK  �     �  �K        main_test.c initRand.4678 main testInsertToList forkInsertToList printf puts getchar testInsertLast forkInsertLast testInsertAfter forkInsertAfter testDeleteFromList forkDeleteFromList testDeleteAfter forkDeleteAfter testDeleteLast forkDeleteLast testDeleteNodeByName forkDeleteNodeByName testSearchByName forkSearchByName testSearchById forkSearchById testListSize forkListSize testCountRecords forkCountRecords testRemoveDuplicates forkRemoveDuplicates __stack_chk_fail fork exit wait populatePerson insertToList dnDeleteList insertLast dnInsertLast dnListSize dnSearchById insertAfter deleteFromList deleteAfter deleteLast deleteList deleteNodeByName strcpy strcmp dnSearchByName searchByName searchById listSize countRecords removeDuplicates bubbleSort dnPrintList srand strncpy dnInsertToList calloc dnInsertAfter strncmp dnDeleteFromList free dnDeleteLast dnDeleteAfter dnDeleteNodeByName dnPrintNode dnCountRecords dnRemoveDuplicates dnMergeLists  O     ]     l     q     |     �     �     �     �     �     �     �     �     �     �     �     �     �     �     �                 )    .    9    >    F    K    Y    h    m    x    }    �    �    �    �    �    �    �    �    �    �     �    �    �    �          !    "  %    *    5    :    B    G  #  U  $  d    i    t    y    �    �  %  �  &  �    �    �    �    �    �  '  �  (  �    �    �    �    �      )    *  !    &    1    6    >    J    O    h  +  �    �    �  ,  �  -  �  .          P    U    q    v    �    �    �  +  �    �    �  ,    -    .  @    E    �    �    �    �    �    �    �  +            ,  @  -  L  .  r    w    �    �    �    �    �    �      +  E    J    R  ,  v  -  �  .  �    �    �    �    �    �                )    .    7  ,  [  -  g  .  �    �    �    �    �    �    �    	    
	    O	  +  �	    �	    �	  ,  �	  -  �	  .  �	    �	    7
    <
    N
    S
    b
    {
    �
    �
    �
    �
    �
    �
  ,  �
  -  �
  .                  L    Q    `    y    ~    �    �    �    �    �  ,  �  -  �  .  �                J    O    ^    w    |    �    �    �    �    �  +  +    0    8  ,  \  -  h  .  �    �    �    �    �    �    �            "    '    2    7    @  ,  d  -  p  .  �    �    �    �    �    �    �                 %    0    5    >  ,  b  -  n  .  �    �    �    �    �    �    �                #    /    4    y  +  �    �    �  ,  �  -  �  .  #    (    a    f    x    }    �    �    �    �    �    �    �    �  ,  �  -    .  +    0    ;    @    v    {    �    �    �    �    �    �    �    �  ,  �  -    .  )    .    9    >    t    y    �    �    �    �    �    �    �      +  U    Z    b  ,  �  -  �  .  �    �    �    �            !    :    ?    L    Q    Z  ,  ~  -  �  .  �    �    �    �    �             (    -    :    ?    H  ,  l  -  x  .  �    �    �    �    �    �    �            (    -    9    >    �  +  �    �    �  ,  �  -    .  -    2    k    p    �    �    �    �    �    �    �    �    �    �  ,    -    .  5    :    E    J    �    �    �    �    �    �    �    �  ,  �  -  �  .  #    (    3    8    n    s    �    �    �    �    �    �    �      +  O    T    \  ,  �  -  �  .  �    �    �    �                4    9    F    K    T  ,  x  -  �  .  �    �    �    �    �    �    	    "    '    4    9    B  ,  f  -  r  .  �    �    �    �    �    �    �            "    '    3    8    }  +  �    �    �  ,  �  -    .  '    ,    e    j    |    �    �    �    �    �    �    �  ,  �  -  �  .       $     /     4     j     o     ~     �     �     �     �     �   ,  �   -  �   .  !    !    !    "!    X!    ]!    l!    �!    �!    �!    �!    �!    �!    �!  +  9"    >"    F"  ,  j"  -  v"  .  �"    �"    �"    �"    �"    �"    #    #    ##    0#    5#    >#  ,  b#  -  n#  .  �#    �#    �#    �#    �#    �#    �#    $    $    $    #$    ,$  ,  P$  -  \$  .  �$    �$    �$    �$    �$    �$    �$    �$    �$    %    %    %    "%    g%  +  �%  /  �%  0  &    &    W&    \&    r&  1  �&  +  �&  /  �&  2  >'    C'    ~'    �'    �'  1  �'  /  �'  3  (  2  I(    N(    �(    �(    �(  4  �(    �(    �(  1  �(  +  B)  /  m)  3  �)  5  �)  6  �)    �)    �)    *    ;*    @*    V*  1  o*  +  �*    �*    �*  /  +  3  )+  7  H+    M+    �+    �+    �+  +   ,    ,    #,  8  ^,  /  �,  3  �,  8  �,  8  �,    �,    (-    --    l-    q-    �-  +  �-    �-    .  9  .     .    X.  /  {.  3  �.  9  �.    �.    �.  :   /    %/    4/  :  f/    k/    z/  :  �/    �/    �/  :  �/  +  50    :0    ^0  ;  �0  /  �0  <  �0  3  �0  <  1  ;  91  =  H1    M1    }1  /  �1  3  �1  <  �1  ;  �1  4  2    2    )2  1  b2  /  {2  <  �2  3  �2  <  �2  ;  �2  >  3    "3    p3    u3    �3  4  �3    �3    �3  1  4  /  :4  3  Y4  <  w4  ;  �4    �4    �4    �4    5  4  5    5    45  1  M5  +  �5    �5    �5  ?  �5    6    B6  /  U6  <  u6  3  �6  ?  �6    �6    �6  1  �6  1  �6  /  7  3  .7  ?  B7    G7    Y7  1  u7  1  �7  /  �7  <  �7  3  8  <  (8  ?  <8    A8    S8  1  o8  1  �8  /  �8  3  �8  ?   9    9    9  1  09  1  I9  +  �9    �9    �9  @  �9    �9    <:  /  O:  <  o:  3  �:  @  �:    �:    �:  1  �:  1  �:  /  ;  3  5;  @  I;    N;    `;  1  |;  1  �;  /  �;  <  �;  3  <  @  .<    3<    E<  1  a<  1  �<  /  �<  3  �<  @  �<    �<    =  1   =  1  9=  +  �=    �=    �=  A  �=    �=    )>  /  U>  3  s>  A  �>    �>    �>  1  �>  1  �>  +  N?    S?    o?  B  �?    �?    �?  /  �?  <  �?  3  @  B  $@    )@    ;@  1  W@  1  }@  /  �@  3  �@  B  �@    �@    �@  1  �@  1  3A  /  ^A  <  �A  3  �A  B  �A    �A    �A  1  �A  1  "B  /  NB  3  pB  B  �B    �B    �B  1  �B  1  �B  +  IC    NC    fC  C  wC    |C    �C  /  �C  <  �C  3   D  C  D  1  KD  /  vD  <  �D  3  �D  D  �D    �D    �D  E  �D  C  E  4  E    E    +E  E  9E    >E    OE    TE    fE  1  E  1  �E  +  �E    �E    �E    �E    �E    �E    �E    �E    �E    F    F    F  F  #F    (F  G  gF  H  oF  G  �F  H  �F  G  �F  +  	G  J  0G  H  GG  H  �G  I  �G  I  �G  I  H  L  �H  H  �H  H  �H  N  )I  M  ]I  M  �I  M  �I  >  �I  M  J  P  CJ  M  aJ  +  �J    �J    �J  R  %K  L  �K  L  �K  P  �K  +  +L  A  |L  L  �L  +                           !   
  (     /     6     =     D     K     Y     `     g     n     {     �     �     �     �     �     �     �     �     
        '    ?    {    �    �    �    �    �    �    �            .    7    @    `    j    y    �    �    �    �    �    �    �                %    3    A    O    r    �    �    �    �    �    �    �    �    �         '    6    S    b    k    x    �    �    �    �    �    �    �    �    �    �        $    B    Q    Z    g    q    z    �    �    �    �    �    �    �    �    �    �        ,    J    Y    b    o    y    �    �    �    �    �    �    �    �    �    �    �    %    4    R    a    j    w    �    �    �    �    �    �    �    �    �    �    �        -    <    Z    i    r        �    �    �    �    �    �    �    �    �    �    �    	    5	    D	    b	    q	    z	    �	    �	    �	    �	    �	    �	    �	    �	    �	    �	    �	    
    
    =
    L
    j
    y
    �
    �
    �
    �
    �
    �
    �
    �
    �
    �
    �
    �
            E    T    r    �    �    �    �    �    �    �    �    �    �    �    �            &    M    \    z    �    �    �    �    �    �    �    �    �    �    �    �            8    }    �    �    �    �    �            -    ;    J    f    �    �    �    �    �        #    ?    i    s    �    �    �    �    �    �    #    .    =    d    p    �    �    �    �    �        +    7    V    f    v    �    �    �    �            -    =    M    k    �    �    �    �    �            $    B    o    z    �    �    �    �    �    �        F    Q    `    �    �    �    �    �    �        (    7    ^    j    �    �    �    �    �    �    
        9    H    U    g    v    �    �    �    �    �    �    	        3    A    P    Z    i    �    �    �    �    �    �    �            =    G    V    q        �    �    �    �    �    �            4    C    S    ^    m    |    �    �    �    �    �                .    >    E    T    q    |    �    �    �    �    �    �    �            "    ^    n    ~    �    �    �    �    �    �    �            )              {           P     p     �     �     �     �         0    P    p    �    �    �    �        0    P    p    �    �    �    �        0    P    p    �    �    �    �        0    P    p    �    �    �    �        0    P    p     .symtab .strtab .shstrtab .rel.text .data .bss .rodata .rel.debug_info .debug_abbrev .rel.debug_aranges .rel.debug_line .debug_str .comment .note.GNU-stack .rel.eh_frame                                                       4   �L                    	   @       ��  `              %             M                     +             M                    0             M  H                 <              `d  9                 8   	   @       �  �              H              ��                   Z              ��                     V   	   @       ��        	         m              ς  /                 i   	   @       ��                 y      0       ��  �                �      0       ʒ  5                 �              ��                     �              �  �                 �   	   @       ��  X                            ,�  �                                ��  `              	              �  �                                                                                                                                                                                                                                                 Makefile                                                                                            0000664 0001751 0001751 00000000322 13063101235 011453  0                                                                                                    ustar   admin                           admin                                                                                                                                                                                                                  
a.out: main_test.o linked_list.o
	gcc -g main_test.o linked_list.o 

main_test.o: main_test.c 
	gcc -g -c main_test.c


linked_list.o: linked_list.c linked_list.h 
	gcc -g -c linked_list.c

clean:
	rm -f *.o

                                                                                                                                                                                                                                                                                                              readMe.txt                                                                                          0000664 0001751 0001751 00000002302 13064060425 011757  0                                                                                                    ustar   admin                           admin                                                                                                                                                                                                                  Developed by Sharath Kunnanath, Carleton University, 100897060
Date: 20/03/2017

TO DO STILL: Test on VM - Completed and tested

Purpose of software: The purpose of this software is to manipulate employee records at Carleton
University using a linked list implementation. The software can add, delete, search, print and remove
duplicates.

Software organization: Functions are defined in linked_list.h then implemented in linked_list.c
test_main.c and bubblesort.o provide functionality to test the functions in linked_list.c


Compliation instructions(with example):

a.out: main_test.o linked_list.o
	gcc -g main_test.o linked_list.o 

main_test.o: main_test.c 
	gcc -g -c main_test.c


linked_list.o: linked_list.c linked_list.h 
	gcc -g -c linked_list.c

clean:
	rm -f *.o

Then type ./a.out to rest program. type valgrind -v ./a.out to test for memory leaks
        


Known issues / limitations :
Functions assume correct input


How to use(including what my mergelist does) :
Follow the compilation instructions to test the program.
The bonus I implemented,mergelist, merges two linked lists and returns a list with the head pointing
to the first list and the second list connected to the end of the first list
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              