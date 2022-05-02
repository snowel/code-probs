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

		  return popChar;
}

//pops a character at a specific position in the dll. 1 indexed
char popDllByDex(dll* myList, int dex){// the index type will change if made big ints
		  dllNode* travel = myList->head;
		  int counter = 0;
		  while(counter != dex){
					 travel = travel->next;
					 counter++;
		  }

		  char popChar = travel->character;
		  rmNode(myList, travel);

		  return popChar;
}

//creats a new dll which is a concatination of dll1 and dll2. DELETES THE INPUT DLLS TODO make a version which doesn't delete inputs but makes a copy
dll* concatDll(dll* myList1, dll* myList2){
		  dll* combList = (dll*)malloc(sizeof(dll));
		  dllNode* combHead = myList1->head;
		  dllNode* combTail = myList2->tail;
		  dllNode* deadHead = myList2->head;
		  dllNode* deadTail = myList1->tail;
		  dllNode* stitchFront = deadTail->prev;
		  dllNode* stitchBack = deadHead->next;

		  //stich the nodes together
		  stitchFront->next = stitchBack;
		  stitchBack->prev = stitchFront;

		  //free the unsued head/tail nodes and the lists
		  free(deadHead);
		  free(deadTail);
		  free(myList1);
		  free(myList2);

		  //ref the new head in combList
		  combList->head = combHead;
		  combList->tail =combTail;

		  return combList;


}

//count nodes of a dll, excluding tail/head
int countDll(dll* myList){
		  dllNode* travel = myList->head;
		  dllNode* tail = myList->tail;
		  int counter = 0;

		  while(travel != tail){
					counter++; 
					travel = travel->next;
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
		  
		  char myString[] = "Hello world! This is NOT a string. This was a string, an array of characters, coded into main(), but not any more.\nThis is now a doubly linked list! Printed to stdout by a custom function!";
		  char * pMyString = &myString[0];
		  
		  char myString2[] = "\n\nThat's great and all... but can I manipulate these things?\n\n";
		  char * pMyString2 = &myString2[0];

		  dll* myList = newDll(); 
		  dll* myList2 = newDll();


		  appendBuff(myList, pMyString);
		  appendBuff(myList2, pMyString2);
		  printDll(myList2);
		  printDll(myList);
		  printf("\n");

		  int elems = countDll(myList);

		  printf("This dll has %d characters.\n", elems);

		  dll* finalList = concatDll(myList, myList2);

		  printDll(finalList);
		  elems = countDll(finalList);
		  printf("This dll has %d characters.\n", elems);

		  delDll(finalList);
		  return 0;
}
