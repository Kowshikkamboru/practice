#include <stdio.h>

int main(void) {
    int a = 8;
    int b;
    
    int *pa = &a;
    int *pb;

    b = *pa;
    pb = &b;

    printf("a (value): %d\n", a);
    printf("&a (address): %p\n", (void *)&a);
    printf("pa (pointer, holds address of a): %p\n", (void *)pa);
    printf("*pa (value pointed to by pa): %d\n", *pa);

    printf("\n");

    printf("b (value): %d\n", b);
    printf("&b (address): %p\n", (void *)&b);
    printf("pb (pointer, holds address of b): %p\n", (void *)pb);
    printf("*pb (value pointed to by pb): %d\n", *pb);

    return 0;
}