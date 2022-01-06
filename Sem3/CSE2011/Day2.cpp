#include<iostream>
#include<conio.h>
#include<stdlib.h>
using namespace std;
int top=-1;

struct Stack{
    int arr[100];
    int check_full();
    void push(int i);
    void pop();
};

int Stack::check_full(){
    if (sizeof(arr)/sizeof(int) == top+1)
        return 1;
    else
        return 0;

}

void Stack::push(int i){
    if(check_full() == 1)
        cout<<"Failed!Stack is full"<<endl;
    else{
        top++;arr[top]=i;
    }
    return;
}

void Stack::pop(){
    int x=-1;
    if(top == -1)
        cout<<"Failed!Staack is empty";
    else{
        cout<<arr[top]<<endl;top--;
    }
    return;
}

int main(){
    int a;
    cout<<"Creating stack..."<<endl;
    Stack s;
    cout<<R"(
_____/\\\\\\\\\\\____/\\\\\\\\\\\\\\\_____/\\\\\\\\\___________/\\\\\\\\\__/\\\________/\\\_________
____/\\\/////////\\\_\///////\\\/////____/\\\\\\\\\\\\\______/\\\////////__\/\\\_____/\\\//_________
____\//\\\______\///________\/\\\________/\\\/////////\\\___/\\\/___________\/\\\__/\\\//___________
______\////\\\_______________\/\\\_______\/\\\_______\/\\\__/\\\_____________\/\\\\\\//\\\__________
__________\////\\\____________\/\\\_______\/\\\\\\\\\\\\\\\_\/\\\_____________\/\\\//_\//\\\________
______________\////\\\_________\/\\\_______\/\\\/////////\\\_\//\\\____________\/\\\____\//\\\______
________/\\\______\//\\\________\/\\\_______\/\\\_______\/\\\__\///\\\__________\/\\\_____\//\\\____
________\///\\\\\\\\\\\/_________\/\\\_______\/\\\_______\/\\\____\////\\\\\\\\\_\/\\\______\//\\\__
___________\///////////___________\///________\///________\///________\/////////__\///________\///__
)";
mainmenu:
    cout<<R"(
Choose:
    1. Push
    2. Pop
    3. Print
    4. Print Top element
    5. is empty?
    6. is full?
    7. Exit
    )"<<endl;
    cin>>a;
    switch(a){
    case 1:
        cout<<"Enter value: ";
        cin>>a;
        s.push(a);
        cout<<"Success!Returning to menu..."<<endl;
        goto mainmenu;
    case 2:
        s.pop();
        cout<<"Returning to menu..."<<endl;
        goto mainmenu;
    case 3:
        cout<<"Printing..."<<endl;
        if(top!=-1){
            for (int temp = top; temp > -1; temp--){
                cout<<temp<<"=> "<<s.arr[temp]<<endl;
            }
        }
        else{
            cout<<"Failed!Empty stack"<<endl;
        }
        cout<<"Returning to menu..."<<endl;
        goto mainmenu;
    case 4:
        if(top!=-1)
            {cout<<s.arr[top]<<endl;}
        else
            {cout<<"Failed!Empty stack"<<endl;}
        cout<<"Returning to menu..."<<endl;
        goto mainmenu;
    case 5:
        if(top == -1){
            cout<<"Yes, empty stack."<<endl;
        }
        else{
            cout<<"No, not empty."<<endl;
        }
        cout<<"Returning to menu..."<<endl;
        goto mainmenu;
    case 6:
        a=s.check_full();
        if(a == 1)
            {cout<<"Yes, its full"<<endl;}
        else    
            {cout<<"No"<<endl;}
        cout<<"Returning to menu..."<<endl;
        goto mainmenu;
    case 7:
        cout<<"Goodbye!\nPress any key to leave.";
        getch();
        return 0;
    default:
        cout<<"Nice try! Now enter number b/w 1-7"<<endl;
        cout<<"Returning to menu..."<<endl;
        goto mainmenu;
    }
}