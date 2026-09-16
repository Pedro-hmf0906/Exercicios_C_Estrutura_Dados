#include <stdio.h>
void f(int v[])
{
    printf("Dentro de f:\n");
    printf("sizeof(v)=%zu\n", sizeof(v));
}
int main()
{
    int v[10];
    printf("No main:\n");
    printf("sizeof(v)=%zu\n", sizeof(v));
    f(v);
    return 0;
}