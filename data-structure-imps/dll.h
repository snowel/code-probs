
typedef struct dllNode {
		  char character;
		  struct dllNode* next;
		  struct dllNode* prev;
}dllNode;

typedef struct {
		  dllNode* head;
		  dllNode* tail;
}dll;

dll* newDll();
//Create a new list and retrun the pointer to that list

void appendDll(dll* myList, char appendChar);
//Append a single character to the end of the list

int appendBuffDll(dll* list, char* string);
//Append a string to the end of the list



int countDll(dll* list);
//Counts the number of elements in a list and returns that number

char popDll(dll* list);
//Remove the last element of the list and return that element

dllNode* indexToPointer(dll* list, int n);
//Return the index of a node by inptuing a pointer to that node

int pointerToIndex(dllNode* start);
//Returns the index of a given node

void insertDll(dll* list, char elem, int index);
char rmNode(dll* list, int index);
//Remove and free a node

int rmList(dll* list);
//Free a list and every node in it

//TODO BOOL
int matchBuff(dllNode* start, char* buff);
//Evalueate if the buffer matches the list (from the start node to the end of the buffer)
//i.e. Evaluates weather or not the string is present as a subset of the list or mathces the list entirely

int charSearch(dllNode* start, char searchChar);
//Search the next instance of a character and retrun the index of that match TODO if it's absent? (-1?)
//Does Not wrap around the search!

dllNode* charSearchPtr(dllNode* start, char searchChar);
//Search the next instance of a character and returns the pointer to the node at which that character is found, or NULL if it's unfound


int subStrSearch(dllNode* start, char* string);
//Search for the next occurence of the substring in the list and returns the index of the firxt mathcing character
