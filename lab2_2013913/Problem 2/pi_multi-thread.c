#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

long incircle = 0;
long points_per_thread;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *runner() {
    long incircle_thread = 0;

    unsigned int rand_state = rand();
    long i;
    for (i = 0; i < points_per_thread; i++) {
        double x = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;
        double y = rand_r(&rand_state) / ((double)RAND_MAX + 1) * 2.0 - 1.0;

        if (x * x + y * y < 1) {
            incircle_thread++;
        }
    }
    
    pthread_mutex_lock(&mutex);
    incircle += incircle_thread;
    pthread_mutex_unlock(&mutex);
}

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "usage: ./pi_multi-thread <total points>\n");
        exit(1);
    }

    long totalpoints = atol(argv[1]);
    int thread_count = 8;
    points_per_thread = totalpoints / thread_count;

    pthread_t *threads = malloc(thread_count * sizeof(pthread_t));

    pthread_attr_t attr;
    pthread_attr_init(&attr);

    int i;
    for (i = 0; i < thread_count; i++) {
        pthread_create(&threads[i], &attr, runner, (void *) NULL);
    }

    for (i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);
    free(threads);

    printf("Pi: %f\n", (4. * (double)incircle) / ((double)totalpoints));

    return 0;
}
