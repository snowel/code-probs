//Leetcode porblem 70

int climbStairs(int steps){
		  if(steps == 1) return 1;
		  if(steps == 2) return 2;
		  return climbStairs(steps - 1) + climbStairs(steps - 2);
}
