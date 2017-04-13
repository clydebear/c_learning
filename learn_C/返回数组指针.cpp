#include <bits/stdc++.h>

int (*func())[20];

int main(void)
{
    int (*result)[20]; //数组指针
    int i = 0;

    result = func();

    for(i = 0; i < 20; i++){
        printf("%d\n", (*result)[i]);
    }

    free(result);
    return 0;

}

int (*func())[20]
{
    int (*a)[20];
    int i = 0;

    a = (int(*)[20] )malloc(20*sizeof(int));
    if(a == NULL){
        printf("malloc error");
        exit(1);
    }

    for(i = 0; i < 20; i++){
        (*a)[i]=i;
    }

    return a;
}
