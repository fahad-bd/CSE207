#include<iostream>
using namespace std;
struct Node
{
    int data;
    Node *left, *right;

    Node(int value){
        data=value;
        left=NULL;
        right=NULL;
    }
};

Node *insert_at_BST(Node *root, int val){
    if(root==NULL){
        return new Node(val);
    }
    if(val<root->data){
        root->left = insert_at_BST(root->left,val);
    }
    else{
        root->right = insert_at_BST(root->right,val);
    }

    return root;
}

void display_inOrder(Node *root){
    if(root==NULL){
        return;
    }
    display_inOrder(root->left);

    cout<<root->data<<" ";

    display_inOrder(root->right);
    
}

void display_preOrder(Node *root){
    if(root==NULL){
        return;
    }
    
    cout<<root->data<<" ";

    display_preOrder(root->left);

    display_preOrder(root->right);   
}

void display_postOrder(Node *root){
    if(root==NULL){
        return;
    }

    display_postOrder(root->left);

    display_postOrder(root->right);   

    cout<<root->data<<" ";
}

int main()
{
    Node *root = NULL;

    root = insert_at_BST(root,30);
    insert_at_BST(root,20);
    insert_at_BST(root,40);
    insert_at_BST(root,70);
    insert_at_BST(root,60);
    insert_at_BST(root,80);

    cout<<"In order: ";
    display_inOrder(root);
    cout<<endl;

    cout<<"Pre order: ";
    display_preOrder(root);
    cout<<endl;

    cout<<"Post order: ";
    display_postOrder(root);
    cout<<endl;
    return 0;
}