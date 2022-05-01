//Retunr true if the interger is a power of 3 (i.e. 3^x == n)
#include <stdio.h>

enum bool {false, true};

enum bool isPowThree(int myInt){
		  enum bool answer;
		  int num = myInt;

		  while(num > 3){
					 num /= 3;
		  }

		  if(num == 3){
					 answer = true;
		  } else {
					 answer = false;
		  }

		  return answer;
}

void main(){
		  enum bool ans = isPowThree(3*3*3*3*3*3);
		  printf("%d\n\n", ans);
}
