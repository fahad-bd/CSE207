/*

Implement the following operation of a dynamic array.
a) add element
b) remove element
c)increase size of the array
d) decrease size of the array
e) free the memory

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int *arr;
    int n,number;
    int last_position = -1;
    int Size = 2;

    arr = (int*)malloc(Size * sizeof(int));

    while(1)
    {
        printf("1. Add element\n");
        printf("2. Remove element\n");
        printf("3. Increase size of the array\n");
        printf("4. Decrease size of the array\n");
        printf("5. Free the memory\n");
        printf("6. Print all element\n");
        printf("0. Exit\n");
        printf("Enter your input: ");
        scanf("%d",&n);
        if(n==0) break;
        else if(n==1)
        {
            printf("Enter number: ");
            scanf("%d",&number);
            last_position++;
            if(last_position >= Size){
                int *temp = (int *)realloc(arr, sizeof(int)*(last_position*2));
                arr = temp;
                free(temp);
                Size = last_position*2;
            }
            arr[last_position] = number;
        }
        else if(n==6)
        {
            for(int i=0;i<=last_position;i++){
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