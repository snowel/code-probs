//Leetcode 55


//This is my solution based on the concept of "dynamic programming", and the first solution I thought when readding the question***

int isJumpable(int* nums, int length){
		  //base patterns which are obvious to work out
		  if(length == 1) return 1;
		  if(length == 2 && nums[0] > 0) return 1;
		  if(length == 2 && nums[0] <= 0) return 0;

		  //otherwise we break down the arrray into every possible sub array based no the first jump

		  for(int i = nums[0]; i > 0; i--){
					 if(isJumpable(&nums[i], length - i) == 1) return 1;
		  }

		  return 0;

}



//*** But! Based on the fact that the array values is the MAXIMUM jump, and not the MINIMUM... The questions breaks down to if there is a 0 or not in the array (excluding the last element).
//Here is a much more sensible solution:

int isJumpableSimple(int* nums, int length){
		  for(int i = 0; i < length - 1; i++){
					 if(nums[i] == 0) return 0;
		  }

		  return 1;
}
