// C99 Complementary Multiply With Carry generator
// C99 Complementar Multiplicar com o gerador Carry
#include <bits/stdc++.h>

// CMWC working parts
// Peças de trabalho CMWC
#define CMWC_CYCLE 4096 // as Marsaglia recommends // como Marsaglia recomenda
#define CMWC_C_MAX 809430660 // as Marsaglia recommends // como a Marsaglia recomenda

struct cmwc_state{
	uint32_t Q[CMWC_CYCLE];
	uint32_t c;	// must be limited with CMWC_C_MAX // deve ser limitado com CMWC_C_MAX
	unsigned i;
};

// Make 32 bit random number (some systems use 16 bit RAND_MAX [Visual C 2012 uses 15 bits!])
//Cria  um número aleatório de 32 bits (alguns sistemas usam RAND_MAX de 16 bits [Visual C 2012 usa 15 bits!]) Uint32_t rand32 ( void )
uint32_t rand32(void){
	uint32_t result = rand();
	return result << 16 | rand();
}

// Init the state with seed
// Inicia o estado com semente
void initCMWC(struct cmwc_state *state, unsigned int seed){
	srand(seed);
	for (int i = 0; i < CMWC_CYCLE; i++)
		state->Q[i] = rand32();
	do
		state->c = rand32();
	while (state->c >= CMWC_C_MAX);
	state->i = CMWC_CYCLE - 1;
}

// CMWC engine
// Mecanismo CMWC
uint32_t randCMWC(struct cmwc_state *state){  //EDITED parameter *state was missing // O parâmetro EDITED * state estava ausente
	uint64_t const a = 18782; // as Marsaglia recommends  // como Marsaglia recomenda
	uint32_t const m = 0xfffffffe; // as Marsaglia recommends // como Marsaglia recomenda
	uint64_t t;
	uint32_t x;

	state->i = (state->i + 1) & (CMWC_CYCLE - 1);
	t = a * state->Q[state->i] + state->c;
	/* Let c = t / 0xfffffff, x = t mod 0xffffffff */
    // Vamos c = t / 0xfffffff, x = t mod 0xffffffff
	state->c = t >> 32;
	x = t + state->c;
	if (x < state->c) {
		x++;
		state->c++;
	}
	return state->Q[state->i] = m - x;
}

int main(){
	struct cmwc_state cmwc;
	unsigned int seed = time(NULL);

	initCMWC(&cmwc, seed);
	uint32_t num;
    for(int h=0; h<1000; h++){
		num = randCMWC(&cmwc);
		// printf("Random CMWC: %u\n", (randCMWC(&cmwc)%10));
	    printf("%u %u\n",(num),(num%10));
    }
}
