#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#include "leetcode.62.c"
#include "leetcode.70.c"
#include "leetcode.190.c"
#include "leetcode.202.c"
#include "leetcode.118.c"

int main(){
		  
		  int rows = 5;
		  int** pasc = pascal(rows);
		  printTriangle(pasc, rows);
		  rmPascArr(pasc, rows);
		  return 0;
}
