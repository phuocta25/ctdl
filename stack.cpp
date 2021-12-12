#include<iostream>>
using namespace std;
struct node
{
    int data;
    node*next;
};

node* createnode(int x){
    node *p=new node;
    p->data=x;
    p->next=NULL;
    return p;
}
typedef struct node node;
typedef struct stack{
     node *head=NULL;
} stack;
bool isEmpty(stack s){
    if(s.head==NULL)return 1;
    return 0;
}
void push(stack &s,int x){
    node *p=createnode(x);
    if(s.head==NULL){
        s.head=p;
    }
    else
    {
        p->next=s.head;
        s.head=p;
    }
}
void pop(stack &s){
    if(s.head==NULL)return;
    node *tam=s.head;
    s.head=s.head->next;
    delete tam;
}
int top(stack s){
    if(s.head!=NULL)return s.head->data;
}
