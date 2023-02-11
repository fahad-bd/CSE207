#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter who many number do you want to add in array: ");
    scanf("%d", &n);
    int *p;
    p = (int*) malloc(n * sizeof(int));
    printf("Enter element: ");
    for(int i=0;i<n;i++){
        scanf("%d",(p+i));
    }

    for(int i=0;i<n;i++){
       printf("%d ",*(p+i));
    }
    return 0;
}
