//leetcode 53
#include <stdio.h>

//helper to avoid triple for loop
//sum of a sub array of some range a to b, given a pointer to the frist element of the array
int subSum(int a, int b, int* arr){
		  int sum = 0;
		  int* travel = arr + a;

		  for(int i = 0; i <= b; i++){
					 sum += *(travel+i);
		  }
		  return sum;
}


int biggestSubStringSum(int* arr, size_t len){
		 int* travel = arr; 
		 int biggestSum = *arr;//init as the first values, to not compare an undeclare int
		 int localSum;

		 for(int i = 0; i < len; i++){
					 for(int j = 0; j < len - i; j++){
								localSum = subSum(i, j, arr);
								if(localSum > biggestSum){
										  biggestSum = localSum;
								}
					 }
		 }

		 return biggestSum;
}

int main(){
		  
		  int test[] = {2, 3, 4, -1, 3, -100, 4, 4, -5, -6, -3, 0, 3, -49, 6, 6, 0};
		  int* ptest = &test[0];
		  size_t testLen = sizeof(test)/sizeof(int);

		  int start = 0;
		  int end = 2;
		  int sub = subSum(start, end, ptest);

		  int testOut = biggestSubStringSum(ptest, testLen);

		  printf("The biggest sum is %d\n", testOut);
		  printf("The sum from index %d to %d is %d\n", start, end, sub);

		  return 0;
}
