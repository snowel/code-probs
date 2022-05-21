//leetcode 190
#define BIT_REVERSE_TEST 4294900000

uint32_t customPow(uint32_t x, uint32_t pow){
		  if(pow == 0) return 1;
		  if(pow == 1) return x;
		  
		  return customPow(x, pow - 1) * x; 
}

uint32_t reverse32Bits(uint32_t num){
		  uint32_t filter;
		  uint32_t singleBit;
		  uint32_t rev = 0; 

		  for(uint32_t i = 0; i < 32; i++){
					filter = customPow(2, i);//set filter bits to 0s except for the ith bit
					singleBit = num & filter;//set singleBit to 0 if the ith bit of num is 0, or non-zero if ith bit is not zero
					if(singleBit == 0) rev += filter;//if the ith bit is 0, set rev's ith bit to 1
					//if single bit is non-zero, the matching bit in rev should be zero, but it already is
		  }

		  return rev; 
}
