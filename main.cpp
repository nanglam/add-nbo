#include<stdio.h>
#include<stdint.h>
#include<stddef.h>
#include<arpa/inet.h>
#include<stdlib.h>

uint32_t fp_ntohl(char* dest) {
	uint32_t data;
	FILE *fp = fopen(dest, "rb");

	if (fp == NULL) {
		fprintf(stderr,"[Error] Can't Open File\n");
		exit(1);
	}
	
	fread(&data, sizeof(uint32_t), 1, fp);

	fclose(fp);

	return ntohl(data);
}

int main(int argc, char* argv[]) {
	uint32_t data1, data2;

	if (argc != 3) {
		printf("syntax : add-nbo <file1> <file2>\n");
		return 1;
	}
	
	data1 = fp_ntohl(argv[1]);
	data2 = fp_ntohl(argv[2]);


	printf("%u(0x%x) + %u(0x%x) = %u(0x%x)\n", data1, data1, data2, data2, data1+data2, data1+data2);


	return 0;
}
