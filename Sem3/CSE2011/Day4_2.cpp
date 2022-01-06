#include <bits/stdc++.h>
#include <conio.h>

using namespace std;

struct Node {
	int data;
	struct Node* link;
};

struct Queue {
	struct Node *front, *rear;
	int sum,mean,median,mode;
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

void Display(Queue* q){
	Node* tmp=q->front;
	q->sum=0;
	int i=0;
	while(tmp->link != q->front) {
		q->sum+=tmp->data;
		i++;
		cout<<tmp->data<<endl;
	}
	cout<<tmp->data<<endl;
	q->mean=q->sum/i;
	cout<<"SUM: "<<q->sum<<endl<<"MEAN: "<<q->mean <<endl;
	free(tmp);
	tmp=q->front;
	for(int j=0;j*2<=i;j++){
		tmp=tmp->link;
	}
	q->median=tmp->data;
	q->mode=3*q->median-2*q->mean;
	cout<<"Median: "<<q->median<<endl<<"Mode: "<<q->mode;//3*median-2*Mean=Mode
	return;
}

void Remove(Queue* q,int a){
    Node* temp=q->front;
    if (q->front == NULL) {
		cout<<"Queue is empty"<<endl;
		return;
	}
    while(temp->link!=q->front){
        if(temp->link->data==a){
            temp->link=temp->link->link;
			cout<<"Removed!";
			return;
        }
        temp=temp->link;
    }
	cout<<"Failed!";
    return;
}

bool prime(int a){
	for(int i=2;i<a;i++){
		if(a%i==0)
			return true;
	}
	return false;
}

void Sort(Queue* a,Queue* b,Queue* c,Queue* d){
	Node* tmp=a->front;
	for(int i=1;tmp->link!=a->front;i++){
		if(prime(tmp->data)==true){
			Insert(d,tmp->data*86.5);
			tmp=tmp->link;
			continue;
		}
		else if(i%2==0){
			Insert(b,tmp->data*73);
			tmp=tmp->link;
			continue;
		}
		else{
			Insert(c,tmp->data);
			tmp=tmp->link;
			continue;			
		}
	}
}

int main(){
	Queue* main = new Queue;
	main->front = main->rear = NULL;
	Queue* USD = new Queue;
	USD->front = USD->rear = NULL;
	Queue* INR = new Queue;
	INR->front = INR->rear = NULL;
	Queue* EUR = new Queue;
	EUR->front = EUR->rear = NULL;
	int a,b,c;
mm:
	cout<<R"(
---------------------------------------------------------------------------------------------------
1.Insert
2.Delete
3.Sort
4.Display
5.Remove
6.Exit
	)"<<endl;
	cin>>a;
	switch(a){
		case(1):
			cout<<"Enter Value : ";
			cin>>b;
			Insert(main,b);
			goto mm;
		case(2):
			cout<<"Deleted element=> "<<Delete(main)<<endl;
			goto mm;
		case(3):
			Sort(main,USD,INR,EUR);
			cout<<"Sorted!"<<endl;
			goto mm;
		case(4):
			cout<<"USD: "<<endl;Display(USD);
			cout<<"INR: "<<endl;Display(INR);
			cout<<"EUR: "<<endl;Display(EUR);
			goto mm;
		case(5):
			cout<<"Enter amount(INR),List(1=USD,2=INR,3=EUR): ";
			cin>>b,c;
			switch(c){
				case(1):
					Remove(USD,b);
					break;
				case(2):
					Remove(INR,b);
					break;
				case(3):
					Remove(EUR,b);
					break;
				default: 
					cout<<"Enter Correct Option.Eg: 73 1";
					goto mm;
			}
			goto mm;	
		case(6):
			cout<<"Goodbye!"<<endl;
			getch();
		default:
			cout<<"Enter Valid option!"<<endl;
	}
    return 0;
}
