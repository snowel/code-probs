// given an n x m matrix, and an element with positions xn xm, return an array of all matrix element coordinates in increasing order fo their sitance to the element
//distance is the sum of the absolute values of the diffferences of each coordinate

//helper for the absolute value
int absVal(int val){
		  if(val >= 0){
					 return val;
		  } else {
					 return -1*val;
		  }
}

//Helper to get the distance between two cells
int distance(int* cellA, int* cellB){
		  int rowDif = *cellA - *cellB;
		  int colDif = *(cellA + 1) - *(cellB+1);
		  int absRowDif = absVal(rowDif);
		  int absCowDif = absVal(colDif);
		  int totalDist = absRowDif + abdColDif;
		  
		  return totalDist;

}

//create a list of all cells as arrays of their coordinates
int** matrixCells(int n, int m){
		  int numberOfElements = n*m;
		  int* allCoords[numberOfElements];
		  int counter;

		  for(int i = 0; i < n; i++){
					 for(int j = 0; j < m; j++;){
								int thisCell[] = {i, j};
								int* cellPtr = &thisCell[0];
								allCoords[counter] = cellPtr;//I think this may not work... if I'm creating a new variable of the same name, does it remove my pointer? Or is scope well enoguht intuitive?
								counter++;
					 }
		  }

		  return &allCoords[0];
}

//crate a list of cells with a third value of distance to a reference cell i.e. [0,1] is 1 point away from [0,0] so it becomes [0,1,0]
int** augmentCells(int** cellList, int cellListLength, int* refCell){
		  int* augCells[cellListLength];
		  for(int i = 0; i < cellListLength; i++){
					 int* currentCell = *(cellList + i);
					 int currentRow = *currentCell;
					 int currentCol = *(currentCell + 1);
					 int distanceToRef = distance(currentCell, refCell);
					 int augCell[] = {currentRow, currentCol, distanceToRef};//same point erpormble her I think
					 augCells[i] = &augCell[0];
		  }
		  
		  return &augCells[0];
}


int** cellDistanceOrder(int n, int m, int xn, int xm){
		  int numberOfElements = n*m;
		  int* tuplePtrs[numberOfElements]
}

int main(){

		  return 0;
}
