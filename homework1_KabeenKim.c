#include <stdio.h>

int fibonacci (int n){
    if (n==0)
        return 0;
    else if (n==1)
        return 1;
    else 
        return fibonacci(n-1)+fibonacci(n-2);
}

int main() {
    int input,i;

    // get a number from a user
    printf("Please enter a number : ");
    scanf("%d", &input);


    for(i=0; i<input; i++){
        printf("%d ", fibonacci(i));
    }

    printf(".");
    return 0;
}
