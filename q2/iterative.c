#include <stdio.h>
#include <stdlib.h>
#define NDBUG
#include <assert.h>
#include <string.h>

char smallest_character(char[],char);
void printInput(char str[],char);

int main(void)
{
	char input_arr[] = {'c','f','j','p','v'};
    	char key[] = {'a','c','j','s','z'};
	int keylen = sizeof(key)/sizeof(key[0]);
	int i=0;
	for(i=0;i<keylen;i++){
		printInput(input_arr, key[i]);
		printf("Output: %c\n\n",smallest_character(input_arr, key[i]));
	}
	return 0;
}

//print Input array and key
void printInput(char str[], char c){
	int i = 0;
	int len = strlen(str);
	printf("Input: [");
	for(i=0; i<len; i++){
		if(i!=len-1)
			printf("'%c' ", str[i]);
		else	printf("'%c'", str[i]);
	}
	printf("], '%c'\n",c);
	printf("strlen(str) = %d\n", len);
}

//find smallest character larger than key iteratively
char smallest_character(char str[], char c){
	int i;
	for(i=0; i<strlen(str); i++){
		if(c < str[i])
			return str[i];
			
	}
	return str[0];
}
