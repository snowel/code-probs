//Leetcode 62 - number of unique paths a_00 to a_mn for an m by n matrix
//only movement down and right are possible
int uniquePaths(int m, int n){
		  if(m == 1 && n == 1) return 1;//for the pattern to work, a single node is considered a path
		  if(m == 1 || n == 1) return 1;//a straight line path
		  if(m == 2 && n == 2) return 2;//the simplest square

		  int acc = 0;
		  for(int i = 0; i < m; i++){
					 acc += uniquePaths(m - i, n - 1);
		  }

		  return acc;
}
