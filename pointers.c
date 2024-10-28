#include<stdio.h>
int main(void) {
int x = 5;

    int* y = &x;
    int** z = &y;

 printf("----------------------------------------\n");
    /* printf("size of int = %zu\n", (void *)sizeof(int)); */
    printf("*y = %d\n", *y);
    printf("y = %p\n", (void *)y);

    printf("*z = %p\n", (void *)*z);
    printf("**z = %d\n", **z);
    
    printf("Hello, World!\n");
    return(0);
} 