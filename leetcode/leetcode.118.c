//Leetcode 118, return a pascal triangle
#include <stdio.h>


//debugging test for segmentations faults
void mallocFail(void * p){
		  if(p == NULL){
					 printf("Malloc failled.");
		  }
}

//prints the contense of an int array
void printArr(int* arr, int arrLength){
		  int i = 0;

		  while(i != arrLength){
					 printf("%d", arr[i]);
					 if(i != (arrLength - 1)) printf("_"); 
					 i++;
		  }
}

//prints a triangle of int arrays, assuming each array is one element longer than the previous and there are "rows" number of elements
void printTriangle(int** pasc, int rows){
		  int whiteSpace, triLayer;
		  unsigned int i, j;

		  //estimate the number of whitespaces before the row start to keep things roughtly triangular
		  if(rows % 2 == 0){
					 whiteSpace = rows /2;
		  } else {
					 whiteSpace = (rows + 1)/2;
		  }

		  for(triLayer = 0; triLayer < rows; triLayer++){
					printf("---");
					 /* TODO this loop is infinite????
					 for(i = 0; i < (whiteSpace - triLayer); i++){
								printf(" ");
					 }
					 i = whiteSpace - triLayer;
					 j = 0;
					 while(i > j){
								printf(" ");
								j++;
					 }

					 */
					 printArr(pasc[triLayer], (triLayer + 1));

					 printf("\n");

		  }
}

int* pascalRowGen(int ithRow, int* prevRow){
		  //alloc a piece of memory of the rigth size
		  int* row = malloc(ithRow * sizeof(int));
		  
		  //first row is just a {1}
		  if(ithRow == 1){
					 row[0] = 1;
					 return row;
		  }

		  //second row is {1, 1}
		  if(ithRow == 2){
					 row[0] = 1;
					 row[1] = 1;
					 return row;
		  }

		  //third row and beyond are variable
		  //set the frist element to 1
		  row[0] = 1;

		  //variable for the sum that will define each element
		  int upRight, upLeft, i;
		  //for each element of the row, define it as a function of element sof the previous row
		  for(i = 1; i < (ithRow - 1); i++){
					 upLeft = prevRow[i-1];
					 upRight = prevRow[i]; 
					 row[i] = (upRight + upLeft);
		  }
		  
		  //set the last element to 1
		  row[ithRow - 1] = 1;

		  return row;
}

int** pascal(int rows){
		  int** outerArr = (int**)malloc(rows * sizeof(int*));
		  mallocFail(outerArr);

		  int prevRowIndex, rowNumber, *thisRow;
		  for(int i = 0; i < rows; i++){//this i refers to the index of the given row
					 rowNumber = i + 1;
					 prevRowIndex = i - 1;
					 //prevRowNumber would be i

					 if(i == 0) thisRow = pascalRowGen(rowNumber, NULL);
					 if(i == 1) thisRow = pascalRowGen(rowNumber, NULL);
					 if(i > 1) thisRow = pascalRowGen(rowNumber, outerArr[prevRowIndex]);

					 outerArr[i] = thisRow; 

		  }

		  return outerArr;
}


//rm and free an array
void rmPascArr(int ** arr, int rows){//rows = length
		  for(int i = 0; i < rows; i++){
					 free(arr[0]);
		  }

		  free(arr);
}
