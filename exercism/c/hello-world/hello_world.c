// Include the standard definitions header from the standard library, so that we
// have access to 'NULL'. This can be removed if your changes remove the need
// for 'NULL'.
#include <stdlib.h>

#include "hello_world.h"
#define STR_LEN 14

// Define the function itself.
const char *hello(void)
{

  const char msg[] = "Hello, World!";
  char* msgPtr = malloc(sizeof(char) * STR_LEN); // This seems messy to free, but I don't see how else to make it work without declaring a global char[]

  for(int i = 0; i < STR_LEN; i++){
		  msgPtr[i] = msg[i];
  }
  const char* helloPtr = msgPtr; 
  return helloPtr;
}
