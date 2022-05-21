//leetcode 202
#define HAPPY_TEST 19
//helper to break down an int into its digits. Retruns the first (right-most) digit and removes it from the input
int cutLastDigit(int num){
		  int lastDigit = num % 10;
		  num -= lastDigit;
		  num /= 10;
		  //TODO I don't understand why these side-effects don't work...

		  return lastDigit;
}

//external side effects for the cuntion above
int sideEffect(int num, int lastDigit){
		  int inFunc = num;
		  inFunc -= lastDigit;
		  inFunc /= 10;
		  return inFunc;
}

//sum of squared digits
int sumSqurDigits(int num){
		  int acc = 0;
		  int digit;
		  int remainder = num;
		  while(remainder != 0){
					 digit = cutLastDigit(remainder);
					 acc += digit * digit;
					 remainder = sideEffect(remainder, digit);
		  }

		  return acc;
}

int isHappy(int n){
		  int trans = n;
		  int breakOff = 0;
		  do{
					 trans = sumSqurDigits(trans);
					 if(trans == 1) return 1;
					 breakOff++;//in case it doesn't find a happy in the first 300
					 if(breakOff > 400000) return 0;
		  }
		  while(trans != n);
		 return 0;

}
