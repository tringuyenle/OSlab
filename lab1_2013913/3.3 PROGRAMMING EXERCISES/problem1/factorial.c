#include "factorial.h"
#include<stdio.h>

int factorial(const int aNumber) {
    if (aNumber>=1)
        return aNumber*factorial(aNumber-1);
    else return 1;
}
