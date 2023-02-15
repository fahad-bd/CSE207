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
        printf("5. Print all element\n");
        printf("6. Free the memory\n");
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
                Size = last_position*2;
            }
            arr[last_position] = number;
        }
        else if(n==2)
        {
            int to_delete;
            cout<<"Enter which value do you want to delete: ";
            cin>>to_delete;

            int flag = 0;

            for(int i=0;i<=last_position;i++)
            {
                if(arr[i] == to_delete)
                {
                    arr[i] = -1;
                    flag = 1;
                }
            }
            if(flag==1) cout<<"Delete Succeful!\n";
            else cout<<"Value not found in the array\n";
        }
        else if(n==3)
        {
            cout<<"Current size of the array is "<<Size<<'\n';
            int addSize;
            cout<<"Enter new additional size: ";
            cin>>addSize;
            int *temp = (int *)realloc(arr, sizeof(int)*(Size+addSize));
            arr = temp;
            Size = Size+addSize;
            cout<<"Size increase successful!\n";  
            cout<<"New size = "<<Size<<'\n';
        }
        else if(n==4)
        {
            cout<<"How much index you want to decrease: ";
            int dSize;
            cin>>dSize;
            int *temp = (int *)realloc(arr, sizeof(int)*(Size-dSize));
            arr = temp;
            Size = Size-dSize;
            cout<<"Size decrease successful!\n";  
            cout<<"New size = "<<Size<<'\n';
            if(Size < last_position)
            {
                last_position = Size;
            }
        }
        else if(n==5)
        {
            if(last_position == -1)
            {
                cout<<"Array is empty!\n";
            }
            else{
                for(int i=0;i<=last_position;i++){
                    if(arr[i]!=-1){
                        printf("%d ",*(arr+i));
                    }
                }
            }
            printf("\n");
        }
        else if(n==6)
        {
            free(arr);
            cout<<"Mamory is free now!"<<'\n';
            last_position = -1;
        }
        else{
            printf("Worng input!\nTry again!\n");
        }
    }
    return 0;
}