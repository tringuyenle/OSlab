#include <stdio.h>
#include <stdlib.h>

long runner(long totalpoints) {
    long incircle = 0;

    unsigned int rand_state = rand();
    long i;
    for (i = 0; i < totalpoints; i++) {
        double x = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        double y = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;

        if (x * x + y * y < 1) {
            incircle++;
        }
    }

    return incircle;
}

int main(int argc, const char *argv[])
{
    	if (argc != 2) {
		fprintf(stderr, "usage: ./pi_serial <total points>\n");
		exit(1);
	}	    
    long totalpoints = atol(argv[1]);

    long incircle = runner(totalpoints);    
    printf("Pi: %f\n", (4. * (double)incircle) / ((double)totalpoints));

    return 0;
}
