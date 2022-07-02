//Leetcode 338
//
//n's largest vlaues is 100,000 or smaller than 2^17

//powers of 2
int binPow(int num){
		  if(num == 0) return 1;
		  if(num == 1) return 2;

		  return binPow(num - 1) * binPow(num - 2);
}

//Helper to count 1s in the binary of and int
int countOnes(int num){
		  int counter = 0;// a counter
		  int mutable = num;
		  int power;
		  for(int i = 17; i >= 0; i--){
					 power = binPow(i);

					 if(power <= mutable){
								mutable - power;
								counter++;
					 }
		  }

		  return counter;
}

// create an array of the solutions
int* onesPerIndex(int n){
		  int* arr = malloc(sizeof(int) * (n + 1));

		  for(int i = 0; i < n; i++){
					 arr[i] = countOnes(i);
		  }

		  return arr;
}

//print the solution directly
void onesPrint(int n){
		  for(int i = 0; i <= n; i++){
					 printf("%d\n", countOnes(i));
		  }
}
