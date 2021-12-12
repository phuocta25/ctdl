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
node *createnode(int x){
    node *p=new node;
    p->data=x;
    p->next=NULL;
    return p;
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
void xuatlist (list l){
    node *p=l.head;
        while (p != NULL)
    {    
        cout<<p->data;
         p=p->next;
         cout<<endl;
    }
}
void nhapds(list &l,int &x,int &n){
    for (int i = 0; i < n; i++)
    {
        cout<<"nhap vao ds so nguyen";
        cin>>x;
        node*p=createnode(x);//them x vao node
        addtail(p,l);   //them node vào  list
    }
    
}
int main(){
    list l;
    int x,n;
    cin>>n;
    addlist(l);
    nhapds(l,x,n);
    xuatlist(l);
}