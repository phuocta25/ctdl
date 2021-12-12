#include<iostream>
#include<string>
#include<iomanip>

using namespace std;

struct TP{
    string ten;
    double dienTich;
    unsigned int danSo;
};
struct node{
    TP tp;
    node *next;
};
struct linkedList{
    node* head;
    node* tail;
};
void nhapTP(TP &tp){
    cout << "\nTen: ";
    getline(cin,tp.ten);
    cout <<"\nDien tich: ";
    cin >> tp.dienTich;
    cout << "\nDan so: ";
    cin >> tp.danSo;
}
void xuatTP(TP tp){
    cout << "Ten: " << tp.ten << endl;
    cout << "Dien tich: " << setprecision(2) << fixed << tp.dienTich << endl;
    cout << "Dan so: " << tp.danSo << endl;
}
node* createElement(TP tp){
    node* e = new node;
    e->tp = tp;
    e->next = NULL;
    return e;
}
void iniLinkedList(linkedList& L){
    L.head = L.tail = NULL;
}
void insertFirst(linkedList& L, node* e){
    if(L.head == NULL){
        L.head = L.tail = e;
    }
    else {
        e->next = L.head;
        L.head = e;
    }
}
void insertTail(linkedList& L, node *e){
    if(L.tail == NULL){
        L.head = L.tail = e;
    }
    else {
        L.tail->next = e;
        L.tail = e;
        e->next = NULL;
    }
}
void insertAfterP(node *p, node *e){
    if(p!= NULL){
        e->next = p->next;
        p->next = e;
    }
}
void xuatDS(linkedList DS){
    node* p = DS.head;
    while(p != NULL){
         cout << "\n\t\tTHONG TIN THANH PHO\n" << endl;
         xuatTP(p->tp);
         p = p->next;
    }
}
void deleteHead(linkedList& L){
    if(L.head != NULL){
        node* p = L.head;
        L.head = L.head->next;
        delete p;
    }
 }
void deleteTail(linkedList& L){
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
void deleteP(linkedList& L, node* p){
    if(p == L.head){
        deleteHead(L);
    }
    else if(p == L.tail){
        deleteTail(L);
    }
    else {
        node* temp = L.head;
        while(temp != NULL){
            if(temp->next == p){
                temp->next = p->next;
                delete p;
                break;
            }
            temp = temp->next;
        }
    }
 }
node* TPCoDanSoLonNhat(linkedList DS){
    node* p = DS.head;
    node* maxDS = DS.head;
    while(p != NULL){
        if(maxDS->tp.danSo < p->tp.danSo){
            maxDS = p;
        }
        p = p->next;
    }
    delete p;
    return maxDS;
}
void deleteLinkedList(linkedList& l){
    node* p =l.head;
    while(l.head != NULL){
        l.head = p->next;
        delete p;
    }
}
void menu(){
    linkedList DS;
    iniLinkedList(DS);
    while(true){
        system("cls");
        int luaChon;
        cout << "\n\t\tMENU";
        cout << "\n1. Nhap danh sach";
        cout << "\n2. In danh sach";
        cout << "\n3. Tim thong tin TP co dien tich lon nhat va them vao sau no 1 thanh pho";
        cout << "\n4. Xoa khoi danh sach thanh pho \"Ha Noi\" neu co";
        cout << "\n5. Sap xep danh sach theo chieu tang dan cua dan so";
        cout << "\n0. Ket thuc chuong trinh";
        cout << "\n\t\tEND\n";
        cout << "nhap lua chon: ";
        cin >> luaChon;
        if(luaChon < 0 || luaChon > 5) {
            cout << "lua chon khong hop le, moi nhap lai";
            cin >> luaChon;
        }
        if(luaChon == 0) break;
        else if(luaChon == 1){
            int stop;
            while(true){
                system("cls") ;
                cout <<"Nhap lua chon:\n1.nhap thanh pho\n0.dung\nLua chon: ";
                cin >> stop;
                if(stop == 0) break;
                cout << "\n\t\tNHAP THONG TIN THANH PHO\n";
                TP tp;
                cin.ignore();
                nhapTP(tp);
                insertTail(DS, createElement(tp));
            }
        }
        else if(luaChon == 2){
            xuatDS(DS);
        }
        else if(luaChon == 3){
            TP tp;
            cout << "\n\t\tNHAP THONG TIN THANH PHO CAN CHEN";
            cin.ignore();
            nhapTP(tp);
            cout << "\n\t\tTHONG TIN THANH PHO CO DAN SO LON NHAT\n";
            if(TPCoDanSoLonNhat != NULL){
                xuatTP(TPCoDanSoLonNhat(DS)->tp);
                insertAfterP(TPCoDanSoLonNhat(DS), createElement(tp));
            }
            else if(TPCoDanSoLonNhat(DS) == DS.tail || TPCoDanSoLonNhat(DS) == NULL) {
                insertTail(DS, createElement(tp));
            }
        }
        else if(luaChon == 4){
            node* p = DS.head;
            while(p != NULL){
                if((p->tp.ten).compare("Ha Noi") == 0){
                    deleteP(DS,p);
                    break;
                }
                p = p->next;
            }
        }
        else {
            node* p = DS.head;
            while(p->next != NULL){
                node* i = p->next;
                 while(i != NULL){
                    if(p->tp.danSo > i->tp.danSo){
                       TP temp;
                       temp = p->tp;
                       p->tp = i->tp;
                       i->tp = temp;
                    }
                    i = i->next;
                }
                p = p->next;
            }
        }
        system("pause") ;
    }
}
int main(){
    menu();
}
