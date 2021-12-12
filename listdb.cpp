#include<iostream>
using namespace std;
struct node  {
    int data;
    node* next;
    node* prev;
};
struct listdb
{
    node*head;
    node*tail;
};
void addlist(listdb l){
    l.head=l.tail=NULL;
}
node *createnode(int data){
    node*p=new node;
    p->data=data;
    p->next=NULL;
    p->prev=NULL;
    return p;
}
void addhead(node *p,listdb &l){//thêm vào đầu
    if (l.head == NULL)
    {
        l.head=l.tail=p;
    }
    else
    {   
        l.head->prev=p;
        p->next=l.head;
        l.head=p;
    }
}
void addtail(node *p,listdb &l){//thêm vào cuối
    if (l.head == NULL)
    {
        l.head=l.tail=p;
    }
    else
    {
        l.tail->next=p;
        p->prev=l.tail;
        l.tail=p;
    }
}
void deletehead(node *p,listdb &l){//xóa đầu
    if (l.head == NULL)
    {
        return;
    }
    l.head=l.head->next;
    l.head->prev=NULL;
}
void deletetail(node *p,listdb &l){//xóa cuối
    if(l.head == NULL){
        return;
    }
    l.tail=l.tail->prev;
    l.tail->next=NULL;
}   
void xuatds(listdb l){//xuat list
    node* p=l.head;
    while (p != NULL)
    {
         p=p->next;
         cout<<endl;
    }
}
int main(){
    cout<<"tao 1 dslk ";
    listdb l;
    addlist(l);
}