#include <stdio.h>
#include <stdlib.h>
#define NDBUG
#include <assert.h>
#include <string.h>

char smallest_character(char[],char,int);
void printInput(char str[],char);

int main(void)
{
	char input_arr[] = {'c','f','j','p','v','y'};
    	char key[] = {'a','c','j','s','z'};
	int inputlen = sizeof(input_arr)/sizeof(input_arr[0]);
	int keylen = sizeof(key)/sizeof(key[0]);
	int i=0;
	for(i=0;i<keylen;i++){
		printInput(input_arr, key[i]);
		printf("Output: %c\n\n",smallest_character(input_arr, key[i],inputlen));
	}
	return 0;
}

//print input array and key
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

//find smallest character larger than key recursively
char smallest_character(char str[], char c, int l)
{
	assert(strlen(str)>0);
        if(c < str[l-1])
            return smallest_character(str,c,l-1);
        else if(l == strlen(str) || l == 0)
		return str[0];
	else
		return str[l];
}
