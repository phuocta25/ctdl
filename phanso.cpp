#include <iostream>
using namespace std;
struct Node {
        double T;
        double M;
        Node* Next;
    };
struct List
{
    Node* Head;
    Node* Tail;
};
void CreateList(List& l)
{
    l.Head = NULL;
    l.Tail = NULL;
}
void AddTail(List& l, Node* p)
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
Node* CreateNode(double x,double y)
{
    Node* p = new Node;
    p->T = x;
    p->M = y;
    p->Next = NULL;
    return p;
}
void NhapList(List& l, int& n,int  *tu,int *mau) {
     
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap tu so : ";
        cin >> tu[i];
        cout << "nhap mau so : ";
        cin >> mau[i];
        while (mau[i] == 0)
        {
            cout << "Nhap sai, hay nhap lai mau so";
            cout << "Nhap mau so : "; cin >> mau[i];
        }

        Node* p = CreateNode(tu[i], mau[i]);
        AddTail(l, p);
    }

}
    double ucln(double T, double M) {
        if (T == 0 || M == 0) {
            return T + M;
        }
        while (T != M) {
            if (T > M)
            {
                T -= M;
            }
            else
            {
                M -= T;
            }
        }
        return T;
    }
    void xuatps(List l) {
        Node* p = l.Head;
        while (p != NULL)
        {
            double u = ucln(p->T, p->M);
                p->T= p->T / u;
                p->M = p->M / u;
                cout << p->T << "/" << p->M;
                p = p->Next;
                cout << endl;
        }
       
    }
int main()
{
    int n;
    cout << "Nhap so luong phan so: ";
    cin >> n;
    int* tu, * mau;
    tu = new int[n];
    mau = new int[n];
    List l;
    CreateList(l);
    NhapList(l,n,tu,mau);
    cout << "Nhung phan so sau khi rut gon " << endl;
    xuatps(l);
    system("pause");
}