
typedef struct mmdllNode {
		  char character;
		  struct mdllNode* ccw; // Counter-ClockWise
		  struct mdllNode* cw; // ClockWise
}mdllNode;

typedef struct {
		  mmdllNode* ref;
}mmdll;

/*
 *
 * General function nomenclatru notess:
 * rm reffers to memory freeing removals
 *
 *
 *
 *
 * */

mdll* newDll();
//Create a new list and retrun the pointer to that list

void appendDll(mdll* myList, char appendChar);
//Append a single character to the end of the list

int appendBuffDll(mdll* list, char* string);
//Append a string to the end of the list

int countDll(mdll* list);
//Counts the number of elements in a list and returns that number

char popDll(mdll* list);
//Remove the last element of the list and return that element

mdllNode* indexToPointer(dll* list, int n);
//Return the index of a node by inptuing a pointer to that node

int pointerToIndex(mdllNode* start);
//Returns the index of a given node

void insertDll(mdll* list, char elem, int index);
//Insert character at a given index, pushing the elements at and after that index one down

char popDex(mdll* list, int index);
//Remove and return the element at index

char rmNode(mdll* list, int index);
//Remove and free a node

int rmNodes(mdll* list, int index, int nnodes);
//Remove and free several nodes from a starting point. If the end of the list is reached, we leave it at that. reutnrs the numer of nodes removed.

int rmList(mdll* list);
//Free a list and every node in it

//TODO BOOL
int matchBuff(mdllNode* start, char* buff);
//Evalueate if the buffer matches the list (from the start node to the end of the buffer)
//i.e. Evaluates weather or not the string is present as a subset of the list or mathces the list entirely

int charSearch(mdllNode* start, char searchChar);
//Search the next instance of a character and retrun the index of that match TODO if it's absent? (-1?)
//Does Not wrap around the search!

mdllNode* charSearchPtr(dllNode* start, char searchChar);
//Search the next instance of a character and returns the pointer to the node at which that character is found, or NULL if it's unfound

int subStrSearch(mdllNode* start, char* string);
//Search for the next occurence of the substring in the list and returns the index of the firxt mathcing character

int countSubStrOcc(mdll* list, char* string);
//Count the occurences of a substring in the list

int* searchAllSubStr(mdll* list, char* string);
//Returns an array of indeces of all occurences of the string
//Experimentally, the first elemnt will be the length of the array i.e. number of occurences + 1

void insertBuff(mdll* list, int index, char* string);
//Insert a buffer at a certain index, moving anything previously at or following that index back by the length of the buffer

//TODO should this be in a seperate header/source file? Is there a standard li function for it?
int countString(char* string);
//Count the number of character in a string, null term not included

//TODO
void wholePatternDel(mdllNode* start, char* string);
//Deletes the next occurence of the substring if the whole pattern in found

//TODO
void substituteSubStr(mdllNode* start, char* oldString, char* newString);
//replaces the next occurrence of the oldString with newString

mdll* concatDll(dll* frontList, dll* backList);
//concatenate two lists into another and remove the firs two lists
