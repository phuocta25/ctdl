#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
typedef struct node node;
typedef struct queue
{
    node *head = NULL;
    node *tail = NULL;
} queue;
node *createnode(int x)
{
    node *p = new node;
    p->data = x;
    p->next = NULL;
    return p;
}
bool isEmpty(queue q)
{
    if (q.head = NULL)
        return 1;
    return 0;
}
void push(queue &q, int x)
{                            //them dau
    node *p = createnode(x); //khoi tao node
    if (q.head == NULL)
    {
        q.head = q.tail = p;
    }
    else //n pt
    {
        p->next = q.head;
        q.head = p; //cap nhap
    }
}
void pop(queue &q)
{ //xoa dau
    if (q.head == NULL)
        return;
    if (q.head == q.tail && q.head != NULL)
    {
        delete q.head;
        q.head = q.tail = NULL;
    }
    else
    {
        node *tam = q.head;
        q.head = q.head->next;
        delete tam;
    }
}
int front(queue q)
{
    if (q.head != NULL)
        return q.head->data;
}
int back(queue q)
{
    if (q.head != NULL)
        return q.tail->data;
}
int main()
{
    queue q, b, c;
    int n;
    cout << "nhap vao n: ";
    cin >> n;
    for (int j = 1; j <= n; j++)
    {
        push(q, j);
    }
    cout << "nhap vao thu tu can co: ";
    int d[100];
    int i;
    for (i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    system("pause");
}