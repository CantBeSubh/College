#include <iostream>
#include <queue> 
using namespace std;
  
void Print(queue<int> a){
    queue<int> tmp = a;
    cout<<"---------------------------------------------------------------------------------------------------"<<endl;
    while (!tmp.empty()){
        cout<<tmp.front()<<'\t';
        tmp.pop();
    }
    cout<<endl;
}

int prime(int a){
    for(int i=2;i<a;i++){
        if(a%i==0){
            return 0;
        }
    }
    return 1;
}
  
int main(){
    cout<<"Creating queue..."<<endl;
    queue<int> mq;
    queue<int> q1;
    queue<int> q2;
    queue<int> q3;
    queue<int> wl;
    int a,n;
    cout<<R"(
________/\\\________/\\\________/\\\__/\\\\\\\\\\\\\\\__/\\\________/\\\__/\\\\\\\\\\\\\\\_________
______/\\\\/\\\\____\/\\\_______\/\\\_\/\\\///////////__\/\\\_______\/\\\_\/\\\///////////_________
_____/\\\//\////\\\__\/\\\_______\/\\\_\/\\\_____________\/\\\_______\/\\\_\/\\\___________________
_____/\\\______\//\\\_\/\\\_______\/\\\_\/\\\\\\\\\\\_____\/\\\_______\/\\\_\/\\\\\\\\\\\__________
_____\//\\\______/\\\__\/\\\_______\/\\\_\/\\\///////______\/\\\_______\/\\\_\/\\\///////__________
_______\///\\\\/\\\\/___\/\\\_______\/\\\_\/\\\_____________\/\\\_______\/\\\_\/\\\________________
__________\////\\\//_____\//\\\______/\\\__\/\\\_____________\//\\\______/\\\__\/\\\_______________
______________\///\\\\\\___\///\\\\\\\\\/___\/\\\\\\\\\\\\\\\__\///\\\\\\\\\/___\/\\\\\\\\\\\\\\\__
_________________\//////______\/////////_____\///////////////_____\/////////_____\///////////////__
    )"<<endl;


    int opt;
mainmenu:
    cout<<R"(
---------------------------------------------------------------------------------------------------
1.Form main queue
2.Print Main queue
3.Sort
4.Print queue 1
5.Print queue 2
6.Print queue 3
7.Print WL
8.Exit
    )"<<endl;
    cin>>opt;
    switch(opt){
        case(1):
            cout<<"Enter number of passenger: ";
            cin>>n;
            cout<<"Enter ages: "<<endl;
            for(int i=0;i<n;i++){
                cout<<i+1<<". ";
                cin>>a;
                if(a>0){
                    mq.push(a);
                }
                else{
                    cout<<"Enter valid age!"<<endl;
                    i--;
                }
            }
            cout<<"Queue is ready."<<endl;
            goto mainmenu;
        case(2):
            Print(mq);
            goto mainmenu;
        case(3):
        cout<<"Sorting..."<<endl;
            goto c3;//coz we can't declare stl variable in side switch cases.
        case(4):
            Print(q1);
            goto mainmenu;
        case(5):
            Print(q2);
            goto mainmenu;
        case(6):
            Print(q3);
            goto mainmenu;
        case(7):
            Print(wl);
            goto mainmenu;
        case(8):
            cout<<"Goodbye!"<<endl;
            return 0;
        default:
            cout<<"Enter valid opt!";
            goto mainmenu;
    }

c3:
            queue<int> t=mq;
            while(t.empty()!=true){
                a=t.front();
                if(a%5==0)
                    {q1.push(a);}
                else if(a%11==0)
                    {q2.push(a);}
                else if(prime(a)==1)
                    {q3.push(a);}
                else
                    {wl.push(a);}
                t.pop();
            }
            goto mainmenu;
}