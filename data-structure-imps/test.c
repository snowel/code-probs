//This is the test main, where I run the code from the vairous "modules" or "libraries"

#include <stdio.h>

#include "dll.c"

#include "matrix.c"
#include "matrix.h"

#include "bitree.c"
#include "bitree.h"


int main(){

		 printf("Reworking my file structure."); 

		 lm* matr = newLM(7,3);
		 treeNode* treeM = newTreeFromMatrix(matr->node00);
		 rmMatrix(matr);

		 int ans = countLeaves(treeM);

		 printf("There are %d unique paths... Warning, this software may leak memory...", ans);
		  
		 rmTree(treeM);
		  return 0;
}
