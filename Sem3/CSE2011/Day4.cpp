#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct Node {
	int data;
	struct Node* link;
};

struct Queue {
	struct Node *front, *rear;
};

void Insert(Queue* q, int value){
	struct Node* temp = new Node;
	temp->data = value;
	if (q->front == NULL)
		q->front = temp;
	else
		q->rear->link = temp;

	q->rear = temp;
	q->rear->link = q->front;
}

int Delete(Queue* q){
	if (q->front == NULL) {
		printf("Queue is empty");
		return INT_MIN;
	}
	int value;
	if (q->front == q->rear) {
		value = q->front->data;
		free(q->front);
		q->front = NULL;
		q->rear = NULL;
	}
	else
	{
		struct Node* temp = q->front;
		value = temp->data;
		q->front = q->front->link;
		q->rear->link = q->front;
		free(temp);
	}

	return value;
}

void RevDisplay(struct Queue* q,Node* a){
	if(a->link == q->front) 
        {cout<<a->data<<endl;return;}
	RevDisplay(q,a->link);
	cout<<a->data<<endl;
}

bool Search(Queue* q,int a){
    Node* temp=q->front;
    if (q->front == NULL) {
		cout<<"Queue is empty"<<endl;
		return false;
	}
    while(temp->link!=q->front){
        if(temp->data==a){
            return true;
        }
        temp=temp->link;
    }
    return false;
}

int main(){
	Queue* q = new Queue;
	q->front = q->rear = NULL;
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
    )";
int a,b;
mm:
	cout<<R"(
---------------------------------------------------------------------------------------------------
1.Insert
2.Delete
3.Search
4.Display(reverse)
5.Exit
	)"<<endl;
	cin>>a;
	switch(a){
		case(1):
			cout<<"Enter Value : ";
			cin>>b;
			Insert(q,b);
			goto mm;
		case(2):
			cout<<"Deleted element=> "<<Delete(q)<<endl;
			goto mm;
		case(3):
			cout<<"Enter Value : ";
			cin>>b;
			if(Search(q,b)==true){
				cout<<"FOUND"<<endl;
			}
			else{
				cout<<"NOT FOUND"<<endl;
			}
			goto mm;
		case(4):
			cout<<"Elements: "<<endl;RevDisplay(q,q->front);
			goto mm;
		case(5):
			cout<<"Goodbye!"<<endl;
			getch();
		default:
			cout<<"Enter Valid option!"<<endl;
	}
    return 0;
}
