#ifndef MATRIX_H
#define MATRIX_H

typedef struct lm_node{//a cell withing a matrix
		  //pointers to each neighbouring cell in 2D
		  struct lm_node* up;
		  struct lm_node* right;
		  struct lm_node* left;
		  struct lm_node* down;

		  //each cell can contain various datatypes
		  int val;
		  char character;
		  int* arr;
		  char* str;

		  //the index of the element
		  int n;//number of the col containing this elem - 0 indexed
		  int m;//number of the row containing this elem - 0 indexed
		  //TODO is my oriignal naming convertion xIndex/yIndex better?
}lm_node;

typedef struct lm {//a batrix of linked nodes, contianing the origin a_00 and the dimensions
		  int rows;
		  int cols;
		  
		  lm_node* node00;
}lm;


lm* newLM(int m, int n);


lm_node* createMNode();

lm_node* stepHorz(int steps, lm_node* start);
lm_node* stepVert(int steps, lm_node* start);

lm_node* appendVert(int col, lm* matrixInQuestion);
lm_node* appendHorz(int row, lm* matrixInQuestion);
void rmMNode(lm_node* node);
void rmMatrix(lm* matrix);

#endif //MATRIX_H
