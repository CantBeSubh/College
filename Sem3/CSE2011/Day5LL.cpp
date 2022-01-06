#include<iostream>
#include<conio.h>
#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node* next;
};

void Insert(node* n,int a){
    
}

node *add_node(int x){
    node* temp = new node;
    temp->data = x;
    temp->next = NULL;
    return temp;
}

void printList(node* n){
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

struct node* middle(node* start, node* last){
    if (start == NULL)
        return NULL;
 
    struct node* slow = start;
    struct node* fast = start -> next;
 
    while (fast != last){
        fast = fast -> next;
        if (fast != last){
            slow = slow -> next;
            fast = fast -> next;
        }
    }
 
    return slow;
}

struct node* binarySearch(node *head, int value){
    struct node* start = head;
    struct node* last = NULL;
 
    do{
        node* mid = middle(start, last);

        if (mid == NULL)
            return NULL;
 
        if (mid -> data == value)
            return mid;
 
        else if (mid -> data < value)
            start = mid -> next;
 
        else
            last = mid;
 
    } while (last == NULL ||
             last != start);
 
    return NULL;
}

int main(){
    int a=0;
    node *head=NULL;
    node *temp=head;
    
    while(true){
        cout<<"Enter element: ";
        cin>>a;
        if(a==-1){
            break;
        }
        if(head==NULL){
            head=add_node(a);
            temp=head->next;
            continue;
        }
        temp=add_node(a);
        temp=temp->next;
    }
    free(temp);
    temp=head;
    printList(temp);
    cout<<endl<<"BYE";
    return 0;
}