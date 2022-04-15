#include"readline.h"
#include<stdio.h>
#include<ctype.h>
#include<string.h>

int read_line(char *str) {
	int size = strlen(str);
	for(int i = 0; i < size -1; i++) {
		if(isdigit(str[i]) == 0) {
			return 0;
		}
	}
	return 1;
}
