#include<iostream>
using namespace std;
struct node
{
    int data;
    node*next;
};
/* hàm khởi tạo 1 cái node */
node* createnode(int x){
    //tạo mới một NODE
    node *p=new node;
    // đưa dữ liệu của biến x vào trong cái data của node p
    p->data=x;
    p->next=NULL;
    return p;
}
typedef struct node node;
typedef struct stack{
     node *head=NULL;
} stack;
bool isEmpty(stack s){
    if(s.head==NULL)return 0;
    return 1;
}
void push(stack &s,node *p){
    if(s.head==NULL){
        s.head=p;
    }
    else
    {
        p->next=s.head;
        s.head=p;
    }
}
void pop(stack &s,int &x){
   if(s.head!=NULL){
    node *p=s.head;
    s.head=s.head->next;
    x=p->data;
    }
}
int top(stack s){
    if(s.head!=NULL)return s.head->data;
}
void chuyen_co_so(stack &s,int cosocandoi,int hethapphan){
    while (hethapphan!=0)
    {

        int x = hethapphan % cosocandoi;
        node *p = createnode(x); 

        push(s, p);
        hethapphan /= cosocandoi;
    

    }
}
void xuatStack(stack &s)
{
    while (isEmpty(s) == true)
    {
        int x;
        pop(s, x);
        if (x < 10)
        {
            cout << x;
        }
        else
        {
            if (x == 10)
            {
                cout << "A";
            }
            else if (x == 11)
            {
                cout << "B";
            }
            else if (x == 12)
            {
                cout << "C";
            }
            else if (x == 13)
            {
                cout << "D";
            }
            else if (x == 14)
            {
                cout << "E";
            }
            else if (x == 15)
            {
                cout << "F";
            }
        }
    }
}int main()
{
    stack s;
    int hethapphan,cosocandoi;
    cout << "\nnhap gia tri thap phan can chuyen: ";
    cin >> hethapphan;
  do{
    cout << "\nnhap co so can chuyen (2, 8, 16):  ";
      cin >> cosocandoi;
  }while(cosocandoi != 2 && cosocandoi != 8 && cosocandoi != 16);
 
    chuyen_co_so(s, cosocandoi, hethapphan);
    cout << "\nket qua:\n";
    xuatStack(s);
    cout << endl;
}