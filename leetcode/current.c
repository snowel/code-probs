#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <stdlib.h>

#include "leetcode.62.c"
#include "leetcode.70.c"
#include "leetcode.190.c"
#include "leetcode.202.c"
#include "leetcode.118.c"
#include "leetcode.55.c"

int main(){
		  
		  int len = 10;
		  int arr[] = {1, 4, 1, 1, 1, 3, 2, 3, 1, 1};
		  int jumps = isJumpable(&arr[0], len);
		  printf("This array is %d\n", jumps);
		  jumps = isJumpableSimple(&arr[0], len);
		  printf("This array is %d\n", jumps);
		  return 0;
}
