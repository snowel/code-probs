
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
void appendDll(dll* myList, char appendChar);
int countDll(dll* list);
char popDll(dll* list);
dllNode* indexToPointer(dll* list, int n);
void insertDll(dll* list, char elem, int index);
char rmNode(dll* list, int index);
int rmList(dll* list);
