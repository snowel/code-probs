/*
You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.
 * */
#include <stdio.h>

int testRay1[] = {1, 2, 4 , 0, 0, 0};
int testRayL1 = 6;
int* pTestRay1 = &testRay1[0];

int testRay2[] = {3, 7, 33};
int testRayL2 = 3;
int* pTestRay2 = &testRay2[0];

//Helper to print array values
void printArr(int* arr, int arrLength){
		  for(int i = 0; i < arrLength; i++){
					 printf("%d", *(arr + i));
					 printf("\n");
		  }
}

//Helper to insert a new value into an array of known length, moving all values after that index on space to the right (last element is lost)
void insertOnDex(int* arr, int index, int new, int lengthOf){
		  for(int i = lengthOf - 1; i > index; i--){
					 int* curntIndex = arr + i; 
					 int* prevIndex = curntIndex - 1;
					 *curntIndex = *prevIndex;
		  }

		  int* relIndex = arr + index;
		  *relIndex = new;
}

void merge(int* nums1, int m, int* nums2, int n){
		  for(int i = 0; i < n; i++){
					 for(int j = 0; j < m; j++){
								if(*(nums1 + j) > *(nums2 + i)){
										  insertOnDex(nums1, j, *(nums2 + i), m);
										  break;
								} else if(*(nums1 + j) == 0){
										  insertOnDex(nums1, j, *(nums2 + i), m);
										  break;
								}
					 }
		  }
}

int main(){
		  printf("The vals for array 1 are:\n");
		  printArr(pTestRay1, testRayL1);
		  printf("\nThe vals for array 2 are;\n");
		  printArr(pTestRay2, testRayL2);

		  merge(pTestRay1, testRayL1, pTestRay2, testRayL2);

		  printf("The new vals of array 1 are:\n");
		  printArr(pTestRay1, testRayL1);

		  return 0;
}
