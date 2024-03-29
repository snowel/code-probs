#include "matrix.h"

//new empty node
lm_node* createMNode(){
		  lm_node* new = (lm_node*)malloc(sizeof(lm_node));

		  //init all neightbouring position to NULL, for clarity
		  new->up = NULL;
		  new->down = NULL;
		  new->right = NULL;
		  new->left = NULL;

		  return new;
}

//create a new matrix of some size without assigning any vals
lm* newLM(int m, int n){
       //in case one of the dimensions is zero
       if(m <= 0 || n <=0)return NULL;

		 lm* new = (lm*)malloc(sizeof(lm));
		 new->rows = m;
		 new->cols = n;
		 
		 int i;//rows
		 int j;//cols


		 //create the origin node
		 lm_node* origin = createMNode();
		 origin->n = 0;
		 origin->m = 0;
		 new->node00 = origin;
		 

		  //create the first column
		  for(j = 1; j < m; j++){
					 lm_node* appended = appendVert(0, new);
					 //add the indexs
					 appended->m = j;
					 appended->n = 0;
		  }
		  
		  //fill out each row
		  for(i = 0; i < m; i++){
					 j = 0;
					 while(j < n){
								appendHorz(i, new);
								j++;
					 }
		  }
		

		  return new;
}


//move horizontally, positive int to the right, negative int to the left
lm_node* stepHorz(int steps, lm_node* start){
		  int direction;// right=1 left=0
		  int stepsNormed;
		  //determin the direction of the movement
		  if(steps > 0){
					 stepsNormed = steps;
					 direction = 1;
		  } else if(steps < 0){//this could be removed, but perhapse for code clarity it is nicer to keep
					 stepsNormed = -1 * steps;
					 direction = 0;
		  } else{
					 return start;
		  }
		  
		  lm_node* travel = start;

		  if(direction == 1){
					 while(travel != NULL && stepsNormed != 0){//TODO this could be recursize...
								travel = travel->right;
								stepsNormed--;
					 }
		  }else if(direction == 0){
					 while(travel != NULL && stepsNormed != 0){
								travel = travel->left;
								stepsNormed--;
					 }
		  }

		  return travel;
}

//move vertically, positive int to down, negative int to the up
lm_node* stepVert(int steps, lm_node* start){
		  int direction;// up=0 down=1
		  int stepsNormed;
		  //determin the direction of the movement
		  if(steps > 0){
					 stepsNormed = steps;
					 direction = 1;
		  } else if(steps < 0){//this could be removed, but perhapse for code clarity it is nicer to keep
					 stepsNormed = -1 * steps;
					 direction = 0;
		  } else{
					 return start;
		  }
		  
		  lm_node* travel = start;

		  if(direction == 0){
					 while(travel != NULL && stepsNormed != 0){
								travel = travel->up;
								stepsNormed--;
					 }
		  }else if(direction == 1){
					 while(travel != NULL && stepsNormed != 0){
								travel = travel->down;
								stepsNormed--;
					 }
		  }

		  return travel;
}


//adds an empty node to the end of a col (far down)
lm_node* appendVert(int col, lm* matrixInQuestion){

		  //check it's in range
		  if(col > matrixInQuestion->cols) return NULL;

		  //moving through the matrix
		  lm_node* travel = matrixInQuestion->node00;//start at the origin
		  travel = stepHorz(col, travel);//walk right until we are at the upper most element of the column in question
		  while(travel->down != NULL){//walk down untill we reach the last element
					 travel = travel->down;
		  }

		  //create the empty node dynamically
		  lm_node* new = createMNode();
		  //link the two
		  travel->down = new;
		  new->up = travel;

		  //link the new node to the node left of it, if applicable
		  if(travel->left != NULL && travel->left->down != NULL){
					 lm_node* newsLeft = travel->left->down;
					 newsLeft->right = new;
					 new->left = newsLeft;
		  }
		  //link the new node to the node right of it, if applicable
		  if(travel->right != NULL && travel->right->down != NULL){
					 lm_node* newsRight = travel->right->down;
					 newsRight->left = new;
					 new->right = newsRight;
		  }
		  return new;
}


//adds an empty node to the end of a row (far right)
lm_node* appendHorz(int row, lm* matrixInQuestion){

		  //check it's in range
		  if(row > matrixInQuestion->rows) return NULL;

		  //moving through the matrix
		  lm_node* travel = matrixInQuestion->node00;//start at the origin
		  travel = stepVert(row, travel);//walk down until we are at the left most element of the row in question
		  while(travel->right != NULL){//walk right untill we reach the last element
					 travel = travel->right;
		  }

		  //create the empty node dynamically
		  lm_node* new = createMNode();
		  //link the two
		  travel->right = new;
		  new->left = travel;

		  //link the new node to the node above of it, if applicable
		  if(travel->up != NULL && travel->up->right != NULL){
					 lm_node* newsUp = travel->up->right;
					 newsUp->down = new;
					 new->up = newsUp;
		  }
		  //link the new node to the node right of it, if applicable
		  if(travel->down != NULL && travel->down->right != NULL){
					 lm_node* newsDown = travel->up->right;
					 newsDown->up = new;
					 new->down = newsDown;
		  }
		  return new;
}

//remove a single node from a matrix
void rmMNode(lm_node* node){
		  //set all adjacent nodes pointing to it to null
		  //TODO is this technically necessary? Could I jsut kill that node and let things point to the freed memory?
		  if(node->left != NULL) node->left->right = NULL;
		  if(node->right != NULL) node->right->left = NULL;
		  if(node->up != NULL) node->up->down = NULL;
		  if(node->down != NULL) node->down->up = NULL;

		  free(node);
}

//erase a whole matrix TODO remane typedefs to squre graph... weather or not this is a porblem
void rmMatrix(lm* matrix){
		  int rows = matrix->rows;
		  int cols = matrix->cols;
		  lm_node* deadNode;
		  
		  for(int i = cols; i > 0; i--){
					 int colErazeCounter = rows-1;
					 while(colErazeCounter >= 0){
								deadNode = stepHorz((i-1), matrix->node00);
								deadNode = stepVert(colErazeCounter, deadNode);

								rmMNode(deadNode);
					 }
		  }

		  free(matrix);
}
