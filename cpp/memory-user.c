#include<stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
    
    int num = atoi(argv[1]);

    int *myArr = (int *)malloc(sizeof(int) * num);

    for(int i = 0; i < num; i++){
        myArr[i] = 0;
    }

    for(int i = 1; i < num; i++){
        myArr[i] += 1 + myArr[i-1];
        printf("array[%d] = %d\n", i, myArr[i]);
        
    }

    free(myArr);

    return 0;
}