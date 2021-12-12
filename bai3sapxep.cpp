#include<iostream>
#include<string>

using namespace std;

struct node{
    int data;
    node* next;
};
struct Stack{
    node* head;
    int number;
};
struct Queue{
    node* head;
    node* tail;
    int number;
};
void iniStack(Stack& st){
    st.head = NULL;
    st.number = 0;
}
void iniQueue(Queue& qu){
    qu.head = NULL;
    qu.tail = NULL;
    qu.number = 0;
}
bool isEmpty(Stack& st){
    if(st.head == NULL) return true;
    else return false;
}
node* createElement(int data){
    node* temp = new node;
    temp->data = data;
    temp->next = NULL;
    return temp;
}
node* pop(Stack& st){
    if(st.head != NULL){
        node* p = st.head;
        st.head = st.head->next;
        st.number --;
        return p;
    }
    else return NULL;
}
node* deQueue(Queue& qu){
    if(qu.head == qu.tail){
        node* p = qu.head;
        qu.head = qu.tail = NULL;
        return p;
    }
    if(qu.tail != NULL){
        node* p = qu.head;
        while(p->next != qu.tail){
            p = p->next;
        }
        qu.tail = p;
        p = p->next;
        qu.tail->next=NULL;
        qu.number --;
        return p;
    }
    return NULL;
}

void push(Stack& st, node* e){
    if(st.head == NULL){
        st.head = e;
    }
    else{
        e->next = st.head;
        st.head = e;
    }
    st.number ++;
}
void enQueue(Queue& qu, node* e){
    if(qu.head == NULL){
        e->next = NULL;
        qu.head = qu.tail = e;
    }
    else{
        e->next = qu.head;
        qu.head = e;
    }
    qu.number ++;
}
void travelQueue(Queue qu){
    node*p = qu.head;
    while(p != NULL){
        cout << p->data << " ";
        p = p->next;
    }
}
void travelStack(Stack st){
    node* p = st.head;
    while(p != NULL ){
        cout << p->data << " ";
        p = p->next;
    }
}

void trans(int arr[],int n){
    Stack A;
    Queue B;
    iniStack(A);
    iniQueue(B);
    for(int i = n; i > 0; i-- ){
        push(A, createElement(i));
    }
    int i = 0;
    while(i < n){
        if(B.tail != NULL){
            if(isEmpty(A) && B.tail->data != arr[i]){
                system("cls");
                cout << "khong the chuyen";
                break;
            }
            if(B.tail->data != arr[i]){
                if(A.head->data != arr[i]){
                    enQueue(B, pop(A));
                    cout << "A->B\n";
                }
                else {
                    cout << "A->C\n";
                    delete pop(A);
                    i++;
                }
            }
            else {
                cout << "B->C\n";
                i++;
                delete deQueue(B);
            }
        }
        else{
            if(A.head->data == arr[i]){
                cout << "A->C\n";
                delete pop(A);
                i++;
            }
            else {
                cout << "A->B\n";
                enQueue(B, pop(A));
            }
        }
    }
}
int main(){
    int n;
    cout << "\nNhap so toa tau: ";
    cin >> n;
    int arr[n];
    cout << "\nNhap thu tu toa tau o C: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    trans(arr, n);
 }
