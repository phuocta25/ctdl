#include<iostream>

using namespace std;


struct DaThuc
{
	int a, x, n;
};

struct node {
	DaThuc data;
	struct node *Next;
};
typedef struct node NODE;

struct list 
{
	NODE* Head;
	NODE* Tail;
};
typedef struct list LIST;

void create_List(LIST& l)
{
	l.Head = NULL;
	l.Tail = NULL;
}

NODE* create_Note(DaThuc x) {
	NODE *p = new NODE;
	if (p == NULL) return NULL;
	p->data = x;
	p->Next = NULL;
	return p;
}
void AddTail(LIST & l, NODE* p)
{
    if (l.Head == NULL)
    {
        l.Head = p;
        l.Tail = p;
    }
    else
    {
        l.Tail->Next = p;
        l.Tail = p;
    }
}
void thempt(LIST & l,int x){
    NODE*p= create_Note(x);
    AddTail(l,p);
}
void xuatlist (LIST l){
    NODE *p=l.Head;
        while (p != NULL)
    {    
        cout<< p->data;
         p=p->Next;
         cout<<endl;
    }
}
void deleteP(NODE* q,LIST l){
     if(l.Tail!=NULL){
     NODE *p=l.Head;

     while(p->Next!=q)
        p=p->Next;
     p->Next=q->Next;

     delete q;

     }
}
int main(){
    int x;
    LIST l;
    create_List(l);
    thempt(l,x);
    deleteP(q,l);
}