//search for ellement divisible by 11
#include<iostream>
#include<conio.h>
#include <bits/stdc++.h>

using namespace std;

struct node{
    int data;
    node* next;
};

void printList(node* n){
    while (n != NULL) {
        cout << n->data << " ";
        n = n->next;
    }
}

bool binarySearch(int arr[], int l, int r, int x){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x)
            return true;
  
        if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);

        return binarySearch(arr, mid + 1, r, x);
    }
    return false;
}

node* head=NULL;

int main(){
    head= new node;
    head->data=-1;
    int arr[]={90,11,22,3,14,33,12,44,47,7,55,71,9,20,66};
    int n = sizeof(arr) / sizeof(arr[0]);
    sort(arr, arr + n);
    node* temp=head;
    for(int i=1;i<=n;i++){
        int a=11*i;
        if(binarySearch(arr,0,n-1,a)){
            cout<<"Found "<<a<<endl;
            temp->data=a;
            temp->next=new node;
            temp=temp->next;
        }
    }
    temp->data=-1;
    temp->next=NULL;
    printList(head);
    cout<<"Press Anything to exit"<<endl;
    getch();
    return 0;
}