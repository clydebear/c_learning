#include <stdio.h>
#include "add.h"
#include "sub.h"

int main(){
    int a = 10,b = 20;
    int c = add(a,b);
    int d = sub(a,b);    
    printf("the sum of %d and %d is %d\n",a,b,c);
    printf("teh sub of %d and %d is %d\n",a,b,d);
    return 0;
}
