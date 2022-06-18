/* 
 * My first FizzBuzz
 * 
 * */


void fizzbuzz(unsigned int n){

		  unsigned int counter = 0;

		  while(counter != n){
					 while(counter % 5 == 0 && counter % 3 == 0){
								printf("FizzBuzz"); 
								printf("\n");
								counter++;
					 }

					 while(counter % 3 == 0 && counter % 5 != 0){
								printf("Fizz"); 
								printf("\n");
								counter++;

					 }
					 
					 while(counter % 5 == 0 && counter % 3 != 0){
								printf("Buzz"); 
								printf("\n");
								counter++;

					 }
					 while(counter % 3 != 0 && counter % 5 != 0){
								printf("%d", counter); 
								printf("\n");
								counter++;

					 }
		  }
		  
}
