#include<iostream>
#include<string>
using namespace std;

struct Node //định nghĩa
{
    string ten;
    int mssv;
    int namsinh;
    float diemtb;
    Node*Next;
};
struct List 
{
    Node*Head;
    Node*Tail;
};
void Addlist(List &l){
    l.Head=l.Tail=NULL;
}
Node *createnode(string ten,int mssv,int namsinh,float diemtb){// khởi tạo
    Node *p=new Node;
    p->ten=ten;
    p->namsinh=namsinh;
    p->mssv=mssv;
    p->diemtb=diemtb;
    p->Next=NULL;
    return p;
}
void AddTail(List &l, Node *p)
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
void nhapds(List &l,int &n){
    string ten;
    int mssv;
    int namsinh;
    float diemtb;
    cout<<"nhap vao danh sach sv"<<endl;
    cin>>n;
    int i=0;
    while (i<n)
    {   
        cin.ignore();
        getline(cin,ten);
        cin>>mssv>>namsinh>>diemtb;
        Node *p=createnode(ten,mssv,namsinh,diemtb);
        AddTail(l,p);
        i++;
    }
}
void xuatds(List l){
    Node *p=l.Head;
    while (p!=NULL)
    {
        cout<<p->ten<<" "<<p->mssv<<" "<<p->namsinh<<" "<<p->diemtb<<endl;
        p=p->Next;
    }
}
// void chensv(List l,int &mssv){
//     cin>>mssv;
//     string ten;
//         int namsinh;
//         float diemtb;
//         cin.ignore();
//         getline(cin,ten);
//         cin>>mssv>>namsinh>>diemtb;
//         Node *q=createnode(ten,mssv,namsinh,diemtb);
//     Node *p=l.Head;
//     while (p != NULL)
//     {
//         if (p->mssv==mssv)
//         {   
        
//             if (p !=l.Tail)
//             {
//                 p->Next=q->Next;
//                 q->Next=p;
//             }
//             // else 
//             // {
//             //     if (l.Tail != NULL)
//             //     {
//             //         l.Tail->Next=p;
//             //     }
//             //     else
//             //     {
//             //         l.Head=l.Tail=p;
//             //     }
                
//             // }
            
//         }
        

//     }
    
// }
int main(){
    List l;
    int n,mssv;
    Addlist(l);
    nhapds(l,n);
    xuatds(l);
    chensv(l,mssv);
    xuatds(l);
    system("pause");
}
