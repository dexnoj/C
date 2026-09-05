#include <stdio.h>
int main(){
    double a; b; n; char e;
    printf("Eded1 emel eded2:  ");
    scanf("%lf %c %lf", &a, &e, &b);
    if (e == '+') n = a + b;
    else if (e == '-') n = a - b;
    else if (e == '*') n = a * b;
    else n = a / b;
    printf("Netice %.2lf\n", n);
    return 0;
}


