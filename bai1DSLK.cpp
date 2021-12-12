#include <iostream>

using namespace std;

struct Element{
    int data;
    Element *pointer;
};

struct LinkedList{
    Element *head;
    Element *tail;
};


void initList(LinkedList& L){
    L.head=L.tail=NULL;
}

Element* CreateElement(int data){
    Element *e=new Element;
    e->data=data;
    e->pointer=NULL;
    return e;
}

void InsertFirst(Element *e, LinkedList &L){
   if(L.head==NULL)
    L.head=L.tail=e;
   else{
    e->pointer=L.head;
    L.head=e;
   }
}

void InsertTail(Element *e, LinkedList &L){
   if(L.tail==NULL)
    L.head=L.tail=e;
    else{
        L.tail->pointer=e;
        L.tail=e;
    }
}

void TravleList(LinkedList L){
     Element *p=L.head;
     while(p!=NULL){
        cout<<p->data<<'\t';
        p=p->pointer;
     }
     cout<< "\n";
}

void NhapDS(LinkedList&L, int n)
{
    int tmp;
    for (int i=1;i<=n;i++)
    {
        cin>>tmp;
        InsertTail(CreateElement(tmp),L);
    }
}

void SortList(LinkedList &L)
{
 for(Element *Tmp=L.head;Tmp!=NULL;Tmp=Tmp->pointer)
 {
  for(Element *Tmp2=Tmp->pointer;Tmp2!=NULL;Tmp2=Tmp2->pointer)
  {
    if(Tmp->data > Tmp2->data)
     {
       int t=Tmp->data;
       Tmp->data=Tmp2->data;
       Tmp2->data=t;
     }
  }
 }
}


void Merge(LinkedList&c, LinkedList&a, LinkedList&b)
{
    Element *t1=a.head;
    Element *t2=b.head;
    while (t1!=NULL && t2!=NULL)
    {
        if (t1->data > t2->data)
        {
            InsertTail(t2, c);
            t2=t2->pointer;
        }
        else
        {
            InsertTail(t1, c);
            t1=t1->pointer;
        }
    }
    if (t1!=NULL)
    {
        while (t1!=NULL)
        {
            InsertTail(t1, c);
            t1=t1->pointer;
        }
    }

    if (t2!=NULL)
    {
        while (t2!=NULL)
        {
            InsertTail(t2, c);
            t2=t2->pointer;
        }
    }
}

int main()
{
    LinkedList lA, lB;
    initList(lA);
    initList(lB);

    int n1, n2;
    cout<< "Nhap so luong phan tu cua lA : ";cin>>n1;
    cout<< "Nhap phan tu cua A : \n";
    NhapDS(lA, n1);
    cout<< "Nhap so luong phan tu cua lB : ";cin>>n2;
    cout<< "Nhap phan tu cua B : \n";
    NhapDS(lB, n2);

    cout<< "Danh sach lA:\n";
    TravleList(lA);
    cout<< "Danh sach lB:\n";
    TravleList(lB);

    SortList(lA);
    SortList(lB);

    LinkedList lC;
    initList(lC);
    Merge(lC, lA, lB);
    cout<< "Danh sach lC:\n";
    TravleList(lC);
}