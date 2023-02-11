#include<bits/stdc++.h>
using namespace std;

void increaseSize(int *arr, int count)
{
    int *temp = new int[count*2];
    arr = temp;
    delete [] temp;
}

int main()
{
    int *arr = new int[5];
    int n;
    int count = -1;
    int Size = 5;
    int element;


    while(1)
    {
        cout<<"0. Exit\n";
        cout<<"1. Add a element\n";
        cout<<"2. Print all element\n";
        cout<<"Enter your input: ";
        cin>>n;
        if(n==0)break;
        else if(n==1)
        {
            cout<<"Enter element: ";
            cin>>element;
            count++;
            if(count >= Size)
            {
                increaseSize(arr, count);
            }
            arr[count] = element;
        }
        else if(n==2)
        {
            for(int i=0;i<=count;i++) cout<<arr[i]<<" ";
            cout<<'\n';
        }
        else {
            cout<<"Wrong input!";
        }
    }
    return 0;
}