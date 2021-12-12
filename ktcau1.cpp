
typedef struct tagNode
{
int Info;
struct tagNode *Next;
}Node;
typedef struct tagList
{
Node *Head;
Node *Tail;
}List;
Node *createnode(int Infor){
    Node *p=new Node;
    p->Info=Info;
    p->next=NULL;
    return p;
}
void addlist(tagList &l){
    l.head=l.tail=NULL;
}
void addtail(Node *p,tagList &l){
    if(l.head == NULL){
        l.head=l.tail=p;
    }
    else
    {
        l.tail->next=p;
        l.tail=p;
    }
}
void nhapds(tagList &l,int &x,int n){
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        Node *p=createnode(x);
        addtail(p,l);
    } 
}
List reverseList(List l){
    List temp;
    iniList(temp);
    Node *p = l.Head;
    while(p != NULL){
        addFirst(temp, createNode(p->Info));
        p = p->Next;
    }
    return temp;
}
bool ktraDoiXung(List P, List Q){
    Node* p = P.Head;
    while(p != NULL){
        if(p->Info != Q.Tail.Info){
            return false;
        }
        p = p->Next;
        deleteTail(Q);
    }
    return true;
}
void deleteTail(List& L){
    if(L.tail != NULL){
        node* p = L.head;
        while(p->next != L.tail){
            p = p->next;
        }
        L.tail = p;
        p = p->next;
        L.tail->next = NULL;
        delete p;
    }
 }
int main(){
    List l, Q;
    nhapds(l,x,n);
    Q = reverseList(l);
    if(ktraDoiXung(Q, l)){
        cout << "\nDanh sach doi xung";
    }
    else cout << "\nDanh sach khong doi xung";
}
//cau 2:
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
}

int Fibonacci(int x)
{
    if (x == 1 || x == 2)
        return 1;
    return Fibonacci(x - 1) + Fibonacci(x - 2);
}
Node *searchfib(Node *p, int x)
{
    if (p != NULL)
    {
        if (p->info == Fibonacci(x))
            return p;
        else if (x > p->info)
            return search(p->right, x);
        else
            return search(p->left, x);
    }
    return NULL;
}
int main(){
    int n;
    InsertNode(root,8);
    InsertNode(root,5);
    InsertNode(root,6);
    InsertNode(root,7);
    InsertNode(root,15);
    InsertNode(root,13);
    InsertNode(root,27);
    InsertNode(root,14);
    duyetLNR(root);
    searchfib(root,5);
    searchfib(root,8);
    searchfib(root,13);
    Delete(root,5);
    Delete(root,8);
    Delete(root,13);
}
