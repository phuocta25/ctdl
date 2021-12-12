#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
struct list
{
    node*head;
    node*tail;
};
void addlist(list &l){
    l.head=l.tail=NULL;
}
node *createnode(int data){
    node *p=new node;
    p->data=data;
    p->next=NULL;
    return p;
}

void addhead(node *p,list &l){
    if (l.head == NULL)
    {
        l.head=l.tail=p;
    }
    else
    {
        p->next=l.head;
        l.head=p;
    }
}
void addtail(node *p,list &l){
    if(l.head == NULL){
        l.head=l.tail=p;
    }
    else
    {
        l.tail->next=p;
        l.tail=p;
    }
}
void InsertAfterP(node *p, list &l){}//thêm vào sau p
void deletehead(node *p,list &l){
    if (l.head == NULL)
    {
        return;
    }
    else
    {
        l.head=l.head->next;
    }return head;
}
void deletetail(list &l,node *p){
    if(l.tail != NULL){
       node * p=l.Head;
    }
    while (p->next != l.tail)
    {
        p=p->next;
    }
    node *tam=l.tail;
    l.tail=p;
    p->next=NULL;
    delete tam;
}
