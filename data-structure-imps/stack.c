#include <stdio.h>

typedef struct stackItem {
		  char character;
		  stackItem* nextDown;
}stackItem;

//new stack
stackItem* newStack(){
		  stackItem* stackHead = (stackItem*)malloc(sizeof(stackItem));
		  stackHead->nextDown = NULL;

		  return stackHead;
}

//add item to the stack
int stackAdd(stackItem* myStack, char item){
		  stackItem* newItem = (stackItem*)malloc(sizeof(stackItem));
		  newItem->character = item;

		  newItem->nextDown = myStack->nextDown;
		  myStack->nextDown = newItem;

		  return 0;

}
