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


//Get the index of a certain node
int pointerToIndex(dllNode* start){
		  dllNode* travel = start;

		  int counter = 0;

		  while(travel->prev != NULL){
					 counter++;
					 travel = travel->prev;
		  }

		  return counter;
		  
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

//Append character buffer to the end of the list
int appendBuffDll(dll* list, char* string){
		  int travel = 0;
		  char travelChar;
		  while(string[travel] != '\0'){
					 travelChar = string[travel];
					 appendDll(list, travelChar);
					 travel++;
		  }

		  return 0;
}


int matchBuff(dllNode* start, char* buff){
		  dllNode* travel = start;
		  int buffIndex = 0;
		  //Defaults to true, if at any point a character deos not match or the list or the string ends before the other, it retruns false

		  while(buff[buffIndex] != '\0'){
					 if(travel == NULL) return 0;//if the string exceeds the length of the list(from the starting position)
					 if(buff[buffIndex] != travel->character) return 0;//if one of the characters don't match

					 //increment and update travel
					 buffIndex++;
					 travel = travel->next;
		  }

		  return 1;
}

int charSearch(dllNode* start, char searchChar){
		  dllNode* travel = start;
		  
		  while(travel->character != searchChar){
					 if(travel->next == NULL) return -1;
					 travel = travel->next;
		  }
		  //If the function executes to here, the character was found and travel points to that node
		  int index = pointerToIndex(travel);
		  return index;
}

dllNode* charSearchPtr(dllNode* start, char searchChar){
		  dllNode* travel = start;
		  
		  while(travel->character != searchChar){
					 if(travel->next == NULL) return NULL;
					 travel = travel->next;
		  }
		  //If the function executes to here, the character was found and travel points to that node
		  return travel;
}
int subStrSearch(dllNode* start, char* string){
		  //pointer to the first occurence of the frist character(if found, otherwise -1)
		  dllNode* travel = charSearchPtr(travel, string[0]);

		  //if the first character of the searched string is not found, the string is not found
		  if(travel == NULL) return -1;

		  //if the pattern matches we return the index of travel
		  if(matchBuff(travel, string) == 1){
					 int index = pointerToIndex(travel);
					 return index;
		  }

		  //if the pattern doesn't match but we've reached the end of the list, we know the pater won't match
		  travel = travel->next;
		  if(travel == NULL) return -1;
		 
		  //otherwise, we recusively repeat from when travel is now (the travel->next above makes sure we don't get stuck evaluating the same pattern infinitely)
		  return subStrSearch(travel, string);
}	
