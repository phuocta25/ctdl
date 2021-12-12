#include<iostream>
using namespace std;
struct node{
    int data;
    node *next;
};
node *createnode(int data){
    node *p=new node;
    p->data=data;
    p->next=NULL;
    return p;
}
