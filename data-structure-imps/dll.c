#include <stdio.h>
#include <stdlib.h>

//dll for doubly-linked-list

typedef struct dllNode{
		  char character;
		  struct dllNode* next;
		  struct dllNode* prev;
}dllNode;

typedef struct{
		  dllNode* head;
		  dllNode* tail;
}dll;

//Function to creat a new, empty dll
dll* newDll(){
		  //dll newList;
		  dll* listPtr = (dll*)malloc(sizeof(dll));
		  dllNode* headOfList = (dllNode*)malloc(sizeof(dllNode));
		  dllNode* tailOfList = (dllNode*)malloc(sizeof(dllNode));

		  headOfList->next = tailOfList;
		  tailOfList->prev = headOfList;

		  listPtr->head = headOfList;
		  listPtr->tail = tailOfList;
		  return listPtr;
}

//Delete a dll node
void delNode(dllNode * badNode){
		 free(badNode); 
}

//Remove a node from a list
void rmNode(dll* myList, dllNode* myNode){
		  dllNode* nodePrev = myNode->prev;
		  dllNode* nodeNext = myNode->next;
//TODO make sure the node isn't the tial or the head
		  nodePrev->next = nodeNext;
		  nodeNext->prev = nodePrev;

		  delNode(myNode);

}

//function to pop the last chracter value of a dll
char popDll(dll* myList){
		  dllNode* tail = myList->tail;
		  dllNode* popNode = tail->prev;
		  char popChar = popNode->character;

		  rmNode(myList, popNode);
}

//count nodes of a dll, excluding tail/head
int countDll(dll* myList){
		  dllNode* travel = myList->head;
		  dllNode* tail = myList->tail;
		  int counter = 0;

		  while((travel + counter) != tail){
					counter++; 
		  }

		  return counter-1;
}

//empty a dll by popping every element
void dumpDll(dll* myList){
		  int elements = countDll(myList);

		  while(elements > 0){
					 popDll(myList);
					 elements--;

		  }
}
//fun to delete a dll  and free the memory
void delDll(dll* myList){
		  dumpDll(myList);
		  free(myList->head);
		  free(myList->tail);
		  free(myList);
}


//function to create new node
dllNode newNode(char character, dllNode* pNext, dllNode* pPrev){
		  dllNode newCharaNode;
		  newCharaNode.next = pNext;
		  newCharaNode.prev = pPrev;
		  newCharaNode.character = character;

		  return newCharaNode;
}

//Appends to the end of the list(i.e at tail.prev)
int dllAppend(dll* myList, char myAppende){
		  
		  dllNode* tail = myList->tail;
		  dllNode* oldPretail = tail->prev;
		  dllNode* newPretail = (dllNode*)malloc(sizeof(dllNode));

		  newPretail->character = myAppende;
		  newPretail->next = tail;
		  newPretail->prev = oldPretail;

		  oldPretail->next = newPretail;
		  tail->prev = newPretail;
		  return 0;
}

//function to append the content of a string to a dll
void appendBuff(dll* myList, char * myString){
		  int counter = 0;
		  //const char nullRef = '\0'; If using nullRef instead of the literal it says comparing int rather that zero charater... Why? I guess it boils down to the same...just strange.
		  while(*(myString + counter) != '\0'){
					 dllAppend(myList, *(myString + counter));
					 counter += 1;
		  }
}

//Function to print the contense of a dll
void printDll(dll* myList){
		  dllNode* travel = myList->head->next;
		  dllNode* tail = myList->tail;

		  while(travel != tail){
					 char localChar = travel->character;
					 travel = travel->next;

					 printf("%c", localChar);
		  }
}

int main(){
		  
		  char myString[] = "This is my string...";
		  char * pMyString = &myString[0];
		  
		  dll* myList = newDll(); 

		 // dllAppend(myList, 'a');
		  appendBuff(myList, pMyString);
		  printDll(myList);

		  //delDll(myList);
		  return 0;
}
