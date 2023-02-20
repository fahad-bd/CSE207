#include<bits/stdc++.h>
using namespace std;

class node{
    public:
        int data;
        node * next;
};

class LinkedList{
    public:
    node * head;
    int Size;

    LinkedList()
    {
        head = NULL;
        Size = 0;
    }

    //Creates a new node with data = value and next = null
    node* CreateNewNode(int value)
    {
        node * newNode = new node;
        newNode->data = value;
        newNode->next = NULL;

        return newNode;
    }

    //Insert new value at Head
    void InsertAtHead(int value) //O(1)
    {
        Size++;
        node * nNode = CreateNewNode(value);
        if(head == NULL)
        {
            head = nNode;
            return;
        }
        //If head is not NULL
        nNode->next = head;
        head = nNode;
    }

    //Inset new value at last position
    void InsertAtTail(int value)
    {
        Size++;
        node* newNode = CreateNewNode(value);
        if(head == NULL)
        {
            head = newNode;
            return;
        }

        node* temp = head;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    //Prints the linked list
    void Traverse()
    {
        node * x = head;
        while(x != NULL)
        {
            cout<<x->data<<" ";
            x = x->next;
        }
        cout<<'\n';
    }

    //Search for a single value
    int SearchDistinctValue(int value)
    {
        node* x = head;
        int index = 0;
        while(x != NULL)
        {
            if(x->data == value)
            {
                return index;
            }
            x = x->next;
            index++;
        }
        return -1;
    }

    //Search all possible occurence
    void SearchAllValue(int value)
    {
        node* x = head;
        int index = 0;
        while(x != NULL)
        {
            if(x->data == value)
            {
                cout<<value<<" is found at index "<<index<<'\n';
            }
            x = x->next;
            index++;
        }
    }

    //size wiht O(size of linked list)
    // int getSize()
    // {
    //     int sz = 0;
    //     node* x = head;
    //     while (x!=NULL)
    //     {
    //         sz++;
    //         x = x->next;
    //     }
    //     return sz;
    // }
    
    //size with O(1)
    int getSize()
    {
        return Size;
    }

    //insert value in any postion
    void InsertAtAnyIndex(int index, int value)
    {
        if(index < 0 || index > Size)
        {
            return;
        }
        if(index == 0){
            InsertAtHead(value);
            return;
        }
        Size++;
        node* x = head;
        int current_index = 0;
        while(current_index != index-1)
        {
            x = x->next;
            current_index++;
        }
        node* newNode = CreateNewNode(value);
        newNode->next = x->next;
        x->next = newNode;
    }

    //delete head
    void DeleteAtHead() //O(1)
    {
        if(head == NULL)
        {
            return;
        }
        Size--;
        node* x = head;
        head = x->next;
        delete x;
    }

    //delete node from any postion
    void DeleteAnyIndex(int index)
    {
        if(index < 0 || index > Size-1)
        {
            return;
        }

        if(index == 0)
        {
            DeleteAtHead();
            return;
        }

        Size--;
        node* x = head;
        int current_index = 0;
        while (current_index != index-1)    
        {
            x = x->next;
            current_index++;
        }
        node* node_to_delete = x->next;
        x->next = node_to_delete->next;

        delete node_to_delete;
    }

    //insert after a value
    void InsertAfterValue(int value, int data)
    {
        node* x = head;
        while (x != NULL)
        {
            if(x->data == value)
            {
                break;
            }
            x = x->next;
        }
        if(x == NULL)
        {
            cout<<"Value doesn't exist in linkedlist\n";
            return;
        }
        
        Size++;
        node* newNode = CreateNewNode(data);
        newNode->next = x->next;
        x->next = newNode;
    }

    //print linkedlist reverse with recursive
    void ReversePrintRecursive(node* x)
    {
        if(x == NULL)
        {
            return;
        }
        ReversePrintRecursive(x->next);
        cout<<x->data<<" ";
    }

    void ReversePrint()
    {
        ReversePrintRecursive(head);
        cout<<'\n';
    }
};

int main()
{
    LinkedList l;
    l.InsertAtHead(10);
    l.InsertAtHead(30);
    l.InsertAtHead(20);
    l.InsertAtHead(30);

    l.Traverse();

    cout<<"10 is found at "<< l.SearchDistinctValue(10)<<'\n';
    cout<<"5 is found at "<< l.SearchDistinctValue(5)<<'\n';

    l.SearchAllValue(30);
    cout<<"Size: "<<l.getSize()<<endl; //O(1)
    cout<<"All value: ";
    l.Traverse();
    
    l.InsertAtAnyIndex(1,50); //O(n)
    cout<<"After add in 1st position: ";
    l.Traverse();
    cout<<"Size: "<<l.getSize()<<endl;
    l.InsertAtAnyIndex(5,100);
    cout<<"After insert at last: ";
    l.Traverse();

    cout<<"After delete head: ";
    l.DeleteAtHead(); //O(1)
    l.Traverse();
    cout<<"Size after delete head: ";
    cout<<l.getSize()<<'\n';

    cout<<"After delete any position: ";
    l.DeleteAnyIndex(2); //O(n)
    l.Traverse();
    cout<<"Size after delete: ";
    cout<<l.getSize()<<'\n';

    cout<<"After Insert data after a value: ";
    l.InsertAfterValue(10,55);
    l.Traverse();

    cout<<"Reverse Print: ";
    l.ReversePrint();

    l.InsertAtTail(777);
    cout<<"After insert at end: ";
    l.Traverse();
    return 0;
}