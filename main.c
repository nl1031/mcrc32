/*
 * main.c
 *
 *  Created on: Dec 4, 2020
 *      Author: ln
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "crc32.h"

#define MAXSIZE 1024*256


int main(int argc, char *argv[])
{
	FILE *infile;
	unsigned char buf[MAXSIZE];
	int rc;
	unsigned int crc32_checksum;

	if (argc < 2) {
		printf("\ngenerate crc32 checksum of file for MCU(without last 4 bytes). file size limited is 256k bytes\nusage: %s %s\n", argv[0], "input file");
		exit(1);
	}

	infile  = fopen(argv[1], "rb");

	if (infile == NULL) {
		printf("file not exist\n");
		exit(1);
	}

	memset(buf,0,sizeof(buf));

	rc = fread(buf, sizeof(unsigned char), MAXSIZE, infile);
	crc32_checksum = crc32(buf, rc - 4);
	printf("%x\n",crc32_checksum);
	fclose(infile);


	return 0;
}
