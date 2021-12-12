#include <iostream>
using namespace std;
struct Node
{
    int info;    // lưu trữ giá trị của phần tử, giá trị khóa của node
    Node *left;  // left lưu địa chỉ phần tử bên trái (cây con trái)
    Node *right; //right lưu trữ địa chỉ phần tử bên phải (cây con phải)
};
Node *root;
// cấu trúc 1 node
void tree_empty()//khởi tạo cây rỗng
{
    root = NULL;
}
// root là biến toàn cục;
Node *search(Node *p, int x)//tìm kiếm trên cây
{
    if (p != NULL)
    {
        if (p->info == x)
            return p;
        else if (x > p->info)
            return search(p->right, x);
        else
            return search(p->left, x);
    }
    return NULL;
}
void InsertNode(Node *&p, int x)// thêm 1 node vào cây
{
    if (p == NULL)
    {
        p = new Node;
        p->info = x;
        p->left = NULL;
        p->right = NULL;
    }
    else
    {
        if (p->info == x)
            return; // đã có node có giá trị x
        else if (p->info > x)
            return InsertNode(p->left, x);
        else
            return InsertNode(p->right, x);
    }
}
void duyetLNR(Node *p) {
    if (p != NULL) {
    duyetLNR(p->left);
    cout<<p->info<<" ";
    duyetLNR(p->right);
    } 
}
void duyetNLR(Node *p) {
    if (p != NULL)
    { 
    cout<<p->info<<" ";
    duyetLNR(p->left);
    duyetLNR(p->right);
    } 
}
void duyetLRN(Node *p) {
    if (p != NULL) {
    duyetLNR(p->left);
    duyetLNR(p->right);
    cout<<p->info<<" ";
    } 
}
void searchStandFor(Node *&p, Node *&q) {
    if (q->left == NULL) { 
        p->info == q->info;
        p = q;
        q = q -> right;
    }
    else 
    searchStandFor(p,q->left);
}
int Delete(Node *&T, int x)
{
    if (T== NULL) return 0;
        if (T->info == x)
        {
            Node *p = T; 
            if (T->left == NULL) 
                    T=T->right;
            else if (T -> right == NULL) 
                    T=T->left;
            else // có 2 con
                searchStandFor(p,T->right);
            delete p;
            return 1;
        }
            if(T->info<x) return Delete(T->right, x);
            if(T->info>x) return Delete(T->left, x);
    //return 0; lam mat warning
}
int main(){
    int x,y,z,x1,y1,z1;
    cin>>x>>y>>z>>x1>>y1>>z1;
    search(root,x);
    InsertNode(root,x);
    InsertNode(root,y);
    InsertNode(root,z);
    InsertNode(root,x1);
    InsertNode(root,y1);
    InsertNode(root,z1);
    Delete(root,x1);
    duyetLNR(root);
}