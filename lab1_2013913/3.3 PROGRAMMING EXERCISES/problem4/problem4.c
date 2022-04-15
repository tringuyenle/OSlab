#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>

int main()
{
	int arr[100];
	int i = 0;
	FILE *filenumbers;
	filenumbers = fopen("numbers.txt", "r");
	if (filenumbers == NULL) {
		printf("Error!\n");
		exit(1);
	}
	while (fscanf(filenumbers, "%d", &arr[i]) != EOF) i++;
	fclose(filenumbers);

    int size = i + 1;
    int count = 0;
    pid_t pid = fork();
    	
	if(pid == 0) {
        	for(i = 0; i < size; i++) {
            		if(arr[i] % 3 == 0) count++;
        	}
        	printf("%d\n", count);
    	}
    	else {
        	wait(NULL);
		printf("test %d\n", count);
        	for(i = 0; i < size; i++) {
            		if(arr[i] % 2 == 0) count++;
        	}
        	printf("%d\n", count);
    	}
    	return 0;
}
