#include"readline.h"
#include"factorial.h"
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main(int argc , char *argv[]){
	char input[60];
	fgets(input, sizeof(input), stdin);
	if(strlen(input) <= 50) {
		if(read_line(input) == 1) {
			int x = atoi(input);
			printf("Factorial of %d is %d\n", x, factorial(x));
		}
		else printf("%d\n", -1);
	}
	else printf("%d\n", -1);
	return 0;
}
