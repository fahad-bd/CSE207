#include<stdio.h>
#include<stdlib.h>

int main()
{
    int *arr;
    int n,number;
    int arr_element = -1;
    int Size = 5;

    arr = (int*)malloc(Size * sizeof(int));

    while(1)
    {
        printf("0. Exit\n");
        printf("1. Add a element\n");
        printf("2. Print all element\n");
        printf("Enter your input: ");
        scanf("%d",&n);
        if(n==0) break;
        else if(n==1)
        {
            printf("Enter number: ");
            scanf("%d",&number);
            arr_element++;
            if(arr_element >= Size){
                int *temp = (int *)realloc(arr, sizeof(int)*(arr_element*2));
                arr = temp;
                free(temp);
                Size = arr_element*2;
            }
            arr[arr_element] = number;
        }
        else if(n==2)
        {
            for(int i=0;i<=arr_element;i++){
                printf("%d ",*(arr+i));
            }
            printf("\n");
        }
        else{
            printf("Worng input!");
        }
    }

    return 0;
}