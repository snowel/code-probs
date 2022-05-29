#include <stdio.h>
#include <stdlib.h>

#include "dll.h"

//new list
dll* newDll(){
		  dll* newList = (dll*)malloc(sizeof(dll));
		  newList->head = NULL;
		  newList->tail = NULL;

		  return newList;
}

//append to list
void appendDll(dll* myList, char appendChar){
		  //Previous last character
		  dllNode* oldTail = myList->tail;


		  //Preparing the new node
		  dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));
		  newNode->character = appendChar;
		  newNode->next = NULL;
		  newNode->prev = oldTail;

		  //setting the new tail and head if applicable
		  myList->tail = newNode;
		  if(myList->head == NULL){
					 myList->head = newNode;
		  }

}


//count elements in a list
int countDll(dll* list){
		  dllNode* travel = list->head;
		  int counter = 0;

		  while(travel != NULL){
					 counter++;
					 travel = travel->next;
		  }

		  return counter;
}

//pop last element of the list
char popDll(dll* list){
		  //grab the pointer to the last element
		  dllNode* poppedNode = list->tail;
		  if(poppedNode == NULL){
					 return '\0';
		  }
		  char poppedChar = poppedNode->character;

		  //set the new tail node's next to NULL and set the new tail
		  dllNode* newTail = poppedNode->prev;
		  if(newTail == NULL){
					 list->head = NULL;
					 list->tail = NULL;
		  } else {
					 newTail->next = NULL;
					 list->tail = newTail;
		  }

		  //free the popped node
		  free(poppedNode);


		  return poppedChar;

}

//ge the pointer to the node of index n
dllNode* indexToPointer(dll* list, int n){
		  dllNode* travel = list->head;
		  int counter = 0;

		  while(n != counter && travel != NULL){
					 counter++;
					 travel = travel->next;
		  }

		  return travel;//Out of bounds or empt list both return NULL pointer
}

//push to index
void insertDll(dll* list, char elem, int index){
		  //get pointer to current node at given index
		  dllNode* target = indexToPointer(list, index);

		  //create new node
		  dllNode* newNode = (dllNode*)malloc(sizeof(dllNode));
		  newNode->character = elem;
		  newNode->next = target;

		  //TODO I hate how I have to check edge cases every time, seem like lost overhead... I think including a length to the struct would be good.
		  if(target == NULL && index == 0){//there are no elements in the list and the index is 0 TODO I could also default it to out of bounds...
					 newNode->prev = NULL;
					 list->head = newNode;
					 list->tail = newNode;
		  }else if(target->prev == NULL){//frist elementthe index is zero... I could also cheaac in index == 0;
					 newNode->prev = target->prev;
					 list->head = newNode;
					 target->prev = newNode;
		  } else{//any other position 
					 newNode->prev = target->prev; 
					 target->prev = newNode;

		  }
}

//pop node by index
char rmNode(dll* list, int index){
		  dllNode* poppedNode = indexToPointer(list, index);

		  //set the next node & tail
		  if(poppedNode == NULL){ //the list is either empty or the index is out of bounds
					 return '\0';//in this case there is no memory to free
		  } else if(poppedNode == list->head && poppedNode == list->tail) {//The list has one single element TODO why does this (poppedNode == list->head == list->tail) give me an error of comparing pointer to int?
					 char poppedChar = poppedNode->character; //TODO case to avoid repeating this? but then there's an if in a case which is not great either...
					 list->head = NULL;
					 list->tail = NULL;
					 free(poppedNode);

					 return poppedChar;
		  } else if(poppedNode == list->head){//The popped element is the first element(head)
					 char poppedChar = poppedNode->character;
					 list->head = poppedNode->next;
					 free(poppedNode);
					 return poppedChar;

		  } else if(poppedNode == list->tail){//the popped element is the last element(tail)
					 char poppedChar = poppedNode->character;
					 list->tail = poppedNode->prev;
					 poppedNode->prev->next = NULL;
					 free(poppedNode);
					 return poppedChar;

		  } else {//the popped element is between two other elements of the list
					 char poppedChar = poppedNode->character;
					 poppedNode->prev->next = poppedNode->next;
					 poppedNode->next->prev = poppedNode->prev;
					 free(poppedNode);
					 return poppedChar;

		  }
		  

}

//completely remove a list and free memory
int rmList(dll* list){
		  dllNode* travel = list->head;
		  while(travel != NULL){
					 popDll(list);
					 travel = list->head;
		  }

		  free(list);
		  return 0;
}
