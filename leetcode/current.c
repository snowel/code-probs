#include <stdio.h>
#include <stdint.h>

#include "leetcode.62.c"
#include "leetcode.70.c"
#include "leetcode.190.c"


int main(){
		  printf("The answer is: %d\n", reverse32Bits(4));
		  return 0;
}

//Given taxicab geometry, we know that the units of mevement will always be the same no matter the path.
//This movement in m-1 units down and n-1 units right.
//
//If we have an array of legnth (m-1)+(n-1) with (m-1) symbols for down and (n-1) symbols for right, the numbe rof unique paths is the number of arangements/orders of that array
//
//BETTER, is that the matrix is essentially (exactly) a binary tree. If we create a binary branch from each path then count the leaves, we're golden.
