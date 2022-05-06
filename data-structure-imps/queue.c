#include <stdlib.h>
#include <stdio.h>

typedef struct queueNode {
		  char character;
		  struct queueNode* next;
}queueNode;

typedef struct queue {
		  queueNode* head;//The first in the queue (i.e. nest pushed)
		  queueNode* tail;
}queue;


//new queue
queue* newQueue(){
		  queue* newQ = (queue*)malloc(sizeof(queue));

		  newQ->head = NULL;
		  newQ->tail = NULL;

		  return newQ;
}


//push
int pushQ(queue* line, char pushChar){
		  queueNode* newSlot = (queueNode*)malloc(sizeof(queueNode));
		  newSlot->character = pushChar;
		  newSlot->next = NULL;
		  line->tail->next = newSlot;

		  return 0;
}

char popQ(queue* line){
		  queueNode* oldSlot = line->head;
		  char outChar = oldSlot->character;

		  //set new head
		  line->head = oldSlot->next;
		  
		  free(oldSlot);

		  return outChar;

}

int main(){
		  
		  return 0;
}
