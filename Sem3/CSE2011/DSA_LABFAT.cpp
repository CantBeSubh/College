#include <iostream>
using namespace std;

struct Node {
   char data;
   struct Node *next;
   struct Node *prev;
};

struct SLL{
    Node* head=NULL;
    Node* end= NULL;
};

struct DLL{
    Node* head=NULL;
    Node* end= NULL;
};

void insertS(SLL* a,char new_data) {
   struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
   new_node->data = new_data;
   if(a->head==NULL){
       a->head=new_node;
       a->end=new_node;
   }
   new_node->next = NULL;
   a->end->next = new_node;
   a->end=new_node;
}

void insertD(DLL* b,char newdata) {
   struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
   newnode->data = newdata;
   newnode->prev = NULL;
   newnode->next = b->head;
   if(b->head != NULL)
   b->head->prev = newnode ;
   b->head = newnode;
}

void display(Node* head) {
   struct Node* ptr;
   ptr = head;
   while (ptr != NULL) {
      cout<< ptr->data <<" ";
      ptr = ptr->next;
   }
}

void create(DLL* dll,SLL* sll){
    Node* temp2=sll->head;

    while(temp2!=NULL){
        insertD(dll,temp2->data);
        temp2=temp2->next;
        cout<<"h";
    }

    cout<<endl<<"tmp list";
    display(dll->head);
}

int main() {
    SLL* a;
    DLL* b;
   insertS(a,'a');
   insertS(a,'b');
   insertS(a,'c');
   insertS(a,'d');
   insertS(a,'e');
   cout<<"The linked list is: ";
   display(a->head);

   Node* temp=a->head;
   return 0;
}