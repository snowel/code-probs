//LEETCODE 28
#include <stdio.h>

//count the number of characters in a string, EXCLUDINGthe null termination char
int countStr(char* string){
		  int counter = 0;
		  char* travel = string;

		  while(*travel != '\0'){
					 counter++;
					 travel++;
		  }
		  return counter;
}

//for a string and a sub string, checks that the whole substring appeare in the occurence
int idSubStr(char* metaStr, char* subStr){
		  int i = 0;
		  while(*(subStr + i) == *(metaStr + i) && *(subStr + i) != '\0'){
					 i++;
		  }

		  if(*(subStr + i) == '\0'){//if the substring matches each character of its length, i will be increment enough to reach the null term character
					 return 1;
		  } else {
					 return 0;
		  }

}

int strInStr(char* needle, char* haystack){
		  int needleLength = countStr(needle);
		  int haystackLength = countStr(haystack);

		  if(needleLength == 0){
					 return 0;
		  }

		  for(int i = 0; i < haystackLength; i++){
					 if(*(haystack + i) == *needle && idSubStr(haystack + i, needle)){
								return i;
					 }
		  }

		  return -1;
}

int main(){

		  char bigStr[] = "Like a cloud.";
		  char smlStr[] = "";

		  char* haystack = &bigStr[0];
		  char* needle = &smlStr[0];

		  int val = strInStr(needle, haystack);

		  printf("Haystack: %s\nNeddle: %s\nIndex: %d\n", bigStr, smlStr, val);
		  return 0;
}
