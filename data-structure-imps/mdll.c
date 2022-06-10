#include <stdio.h>
#include <stdlib.h>

#include "mdll.h"

//new list
mdll* newDll(){
		  mdll* newList = (mdll*)malloc(sizeof(mdll));
		  newList->ref = NULL;

		  return newList;
}

//append to list
void appendDll(mdll* myList, char appendChar){
		  //Previous last character
		  mdllNode* oldTail = myList->tail;


		  //Preparing the new node
		  mdllNode* newNode = (dllNode*)malloc(sizeof(dllNode));
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
int countDll(mdll* list){
		  mdllNode* travel = list->head;
		  int counter = 0;

		  while(travel != NULL){
					 counter++;
					 travel = travel->next;
		  }

		  return counter;
}

//pop last element of the list
char popDll(mdll* list){
		  //grab the pointer to the last element
		  mdllNode* poppedNode = list->tail;
		  if(poppedNode == NULL){
					 return '\0';
		  }
		  char poppedChar = poppedNode->character;

		  //set the new tail node's next to NULL and set the new tail
		  mdllNode* newTail = poppedNode->prev;
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

//get the pointer to the node of index n
mdllNode* indexToPointer(dll* list, int n){
		  mdllNode* travel = list->head;
		  int counter = 0;

		  while(n != counter && travel != NULL){
					 counter++;
					 travel = travel->next;
		  }

		  return travel;//Out of bounds or empt list both return NULL pointer
}


//Get the index of a certain node
int pointerToIndex(mdllNode* start){
		  mdllNode* travel = start;

		  int counter = 0;

		  while(travel->prev != NULL){
					 counter++;
					 travel = travel->prev;
		  }

		  return counter;
		  
}


//push to index
void insertDll(mdll* list, char elem, int index){
		  //get pointer to current node at given index
		  mdllNode* target = indexToPointer(list, index);

		  //create new node
		  mdllNode* newNode = (mdllNode*)malloc(sizeof(mdllNode));
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
char rmNode(mdll* list, int index){
		  mdllNode* poppedNode = indexToPointer(list, index);

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
int rmList(mdll* list){
		  mdllNode* travel = list->head;
		  while(travel != NULL){
					 popDll(list);
					 travel = list->head;
		  }

		  free(list);
		  return 0;
}

//Append character buffer to the end of the list
int appendBuffDll(mdll* list, char* string){
		  int travel = 0;
		  char travelChar;
		  while(string[travel] != '\0'){
					 travelChar = string[travel];
					 appendDll(list, travelChar);
					 travel++;
		  }

		  return 0;
}


int matchBuff(mdllNode* start, char* buff){
		  mdllNode* travel = start;
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

int charSearch(mdllNode* start, char searchChar){
		  mdllNode* travel = start;
		  
		  while(travel->character != searchChar){
					 if(travel->next == NULL) return -1;
					 travel = travel->next;
		  }
		  //If the function executes to here, the character was found and travel points to that node
		  int index = pointerToIndex(travel);
		  return index;
}

mdllNode* charSearchPtr(dllNode* start, char searchChar){
		  mdllNode* travel = start;
		  
		  while(travel->character != searchChar){
					 if(travel->next == NULL) return NULL;
					 travel = travel->next;
		  }
		  //If the function executes to here, the character was found and travel points to that node
		  return travel;
}

int subStrSearch(mdllNode* start, char* string){
		  //pointer to the first occurence of the frist character(if found, otherwise -1)
		  mdllNode* travel = charSearchPtr(start, string[0]);

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

//Helper to recurse while specifying only the mdll rather than the node, to avoid starting from the middle
int countSubStrOccFromHead(mdllNode* listHead, char* string){
		  //pointer to the first occurence of the firxt character of the string
		  mdllNode* travel = charSearchPtr(listHead, string[0]);
		  
		  //if the first character is not found past that point, return 0
		  if(travel == NULL) return 0;

		  //if the pattern matches, we return 1 + the continued search from that point
		  if(matchBuff(travel, string) == 1) return 1 + countSubStrOccFromHead(travel->next, string);
}

//TODO is there a more elegant way to preserve the recursion than splitting it into two functions?
int countSubStrOcc(mdll* list, char* string){
		  return countSubStrOccFromHead(list->head, string);
}

int* searchAllSubStr(mdll* list, char* string){
		  int length = countSubStrOcc(list, string) + 1;
		  //TODO would it be much smarter to have an arbitrary array size and then a counter, progressively reallocing as needed, rather than going through the whole list twice? 

		  //create an array of the appropriate size
		  int* arr = malloc(sizeof(int) * length);
		  //set the first element
		  arr[0] = length;

		  //create a travel and counter
		  mdllNode* travel;
		  int i, index;

		  for(i = 1; i < length; i++){
					 index = subStrSearch(travel, string);
					 arr[i] = index;
					 travel = travel->next;
		  }

		  return arr;
}

void insertBuff(mdll* list, int index, char* string){
		  int i = 0;//loop counter

		  while(string[i] != '\0'){
					 insertDll(list, index + i, string[i]);
					 i++;
		  }
}


char popDex(mdll* list, int index){
		  mdllNode* popped = indexToPointer(list, index);
		  if(popped == NULL) return '\0';//out of bounds retruns a null termination character
		  
		  //save pointers to the next and previous node
		  mdllNode* popNext = popped->next;
		  mdllNode* popPrev = popped->prev;

		  //update the next and prev nodes
		  popNext->prev = popPrev;
		  popPrev->next = popNext;

		  //grab the character and remove the popped node
		  char elem = popped->character;
		  free(popped);

		  return elem;
}

int rmNodes(mdll* list, int index, int nnodes){
       mdllNode* safety = indexToPointer(list, index);
       int i;
		 for(i = 0; i < nnodes; i++){
					if(safety == NULL) return i;
					 rmNode(list, index);
		 } 

		 return i;
}

int countString(char* string){
		  int counter = 0;
		  char travel = string[0];

		  while(travel != '\0'){
					 counter++;
					 travel = string[counter];
		  }

		  return counter;
}

mdll* concatDll(dll* frontList, dll* backList){
		  mdll* new = malloc(sizeof(dll));
		  
		  //set the head and tail of the new list
		  new->head = frontList->head;
		  new->tail = backList->tail;

		  //set the end of the front to point to the beigng of the back and vice-versa
		  frontStitch = frontList->tail;
		  backStitch = backList->head;

		  frontStitch->next = backStitch;
		  backStitch->prev = frontstich;

		  //free the two previous list structs
		  free(frontList);
		  free(backList);

		  return new;

}
