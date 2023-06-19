#include <stdio.h>

int main(void) {
    // int a = 42;
    // double b = a;  // inplicit conversion cast
    // double c = (double)a;  // explicit conversion cast

    // double d = a;
    // int e = d;  // lose precision - bits change
    // int f = (int)d;  // tell to compiler that you are aware of the precision lost

    float a = 420.042f;
    void* b = &a;  // implicit reinterpretation cast
    void* c = (void*) &a;  // Explicit reinterpretetion cast

    void* d = &a;  // implicit promotion: ok
    int* e = d;  // implicit demotion: Harzadous! - bits doesn't change
    int* f = (int*)d;  // explicit demotion: Ok, I obey

    printf("%p, %f\n", &a, a);
    printf("%p\n", b);
    printf("%p\n", c);

    printf("%p\n", d);
    printf("%p, %d\n", e, *e);
    printf("%p, %d\n", f, *f);

}
