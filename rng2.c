#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include  <stdint.h>
#include  <time.h>

static unsigned long Q[4096], c = 362436; 

/* choose random initial c<809430660 and */
/* 4096 random 32-bit integers for Q[]   */

unsigned long mwc(void){
	// for(int s=0; s<10; s++){

    unsigned long long t, a = 18782LL;
    static unsigned long i = 4095;
    unsigned long long x, r = 0xfffffffe;
	
	// srand(time(NULL));
	// c = rand();

    i= (i+1) & 4095;
    t = a * Q[i] + c;
    c=(t >> 32); 
    x = t + c; 
    if(x < c){
        x++;
        c++;
    }
    return (Q[i] = r - x);   
	// }
}

int main(void){
	// for(int i=0; i<10; i++){
		printf("\nRandom Number generated : %lld\n", mwc());
		printf("\nRandom Number generated : %lld\n", mwc());
		printf("\nRandom Number generated : %lld\n", mwc());
		printf("\nRandom Number generated : %lld\n", mwc());
		printf("\nRandom Number generated : %lld\n", mwc());
		printf("\nRandom Number generated : %lld\n", mwc());
	// }
  	return 0;
}