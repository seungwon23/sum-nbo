// nbo.cpp

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <arpa/inet.h>
#include "nbo.h"

uint32_t nbo(const char *filename){
	FILE *file = fopen(filename, "rb");
	if(file == NULL){
		fprintf(stderr, "Open failed\n");
		exit(0);
	}

	uint32_t num, sum;
	size_t read_size = fread(&num, sizeof(uint32_t), 1, file);
	if(read_size != 1) {
		fprintf(stderr, "Failed to read 4 bytes from %s.\n", filename);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	num = ntohl(num);
	printf("%u(0x%04x) ", num, num);
	fclose(file);
	return num;
}

