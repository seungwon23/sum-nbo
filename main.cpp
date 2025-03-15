// main.cpp

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>
#include "nbo.h"

int main(int argc, char *argv[]) {
	if(argc < 2) {
		fprintf(stderr, "We need more files.\n");
		return 0;
	}

	uint32_t sum = 0;
	
	for(int i = 1; i < argc; i++){
		if(i > 1) printf("+ ");
		uint32_t num = nbo(argv[i]);
		sum += num;
	}

	printf("= %u(0x%04x)\n", sum, sum);
	return 0;
}

