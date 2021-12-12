#include<iostream>
#include<string>

using namespace std;

struct SV{
    string maSo;
    string hoTen;
    unsigned short int namSinh;
    double diemTB;
};
struct node{
    SV sv;
    node *next;
};
struct linkedList{
    node* head;
    node* tail;
};
void nhapSV(SV &sv){
    cout << "MSSV: ";
    cin >> sv.maSo;
    cin.ignore();
    cout <<"Ho ten: ";
    getline(cin,sv.hoTen);
    cout << "Nam sinh: ";
    cin >> sv.namSinh;
    cout << "Diem trung binh: ";
    cin >> sv.diemTB;
}
void xuatSV(SV sv){
    cout << "MSSV: " << sv.maSo << endl;
    cout << "Ho ten: " << sv.hoTen << endl;
    cout << "Nam sinh: " << sv.namSinh << endl;
    cout << "Diem trung binh: " << sv.diemTB << endl;
}
node* createElement(SV sv){
    node* e = new node;
    e->sv = sv;
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
         cout << "\n\t\tTHONG TIN SINH VIEN\n" << endl;
         xuatSV(p->sv);
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
void findName(linkedList DS, string hoTen){
    node* p = DS.head;
    bool check = false;
    while(p != NULL){
        if((p->sv.hoTen).compare(hoTen) == 0){
            cout << "\n\n\t\tTHONG TIN SINH VIEN\n";
            xuatSV(p->sv);
            check = true;
            break;
        }
        else {
            p = p->next;
        }
    }
    if(!check){
        cout << "khong co sv phu hop";
    }
}
void chenSV(linkedList& DS, string maSV, node* sv){
    node* p = DS.head;
    bool check = false;
    while(p != NULL){
        if((p->sv.maSo).compare(maSV) == 0){
            insertAfterP(p, sv);
            check = true;
            break;
        }
        else {
            p = p->next;
        }
    }
    if(!check){
        cout << "khong co sv phu hop";
    }
}
void deleteLinkedList(linkedList& l){
    while(l.head != NULL){
        node* p =l.head;
        l.head = l.head->next;
        delete p;
    }
}
void menu(){
    linkedList DS;
    iniLinkedList(DS);
    SV sv; 
    while(true){
        system("cls");
        int luaChon;
        cout << "\n\t\tMENU";
        cout << "\n1. Nhap danh sach";
        cout << "\n2. In danh sach";
        cout << "\n3. Tim kiem 1 sinh vien theo ho va ten";
        cout << "\n4. Chen them 1 sinh vien vao sau sv co ma so chi dinh";
        cout << "\n5. Xoa 1 sinh vien co ma so chi dinh";
        cout << "\n6. Sap xep danh sach theo ma so sinh vien tang dan";
        cout << "\n7. Sap xep danh sach theo thu tu bang chu cai";
        cout << "\n8. Huy danh sach";
        cout << "\n0. Ket thuc chuong trinh";
        cout << "\n\t\tEND\n";
        cout << "nhap lua chon: ";
        cin >> luaChon;
        if(luaChon < 0 || luaChon > 8) {
            cout << "lua chon khong hop le, moi nhap lai";
            cin >> luaChon;
        }
        if(luaChon == 0) break;
        else if(luaChon == 1){
            int stop;
            while(true){
            system("cls") ;
            cout <<" nhap lua chon:\n1.nhap sv;\n0.dung\nLua chon: ";
            cin >> stop;
            if(stop == 0) break;
            cout << "\n\t\tNHAP THONG TIN SV\n";
            SV sv;
            cin.ignore();
            nhapSV(sv);
            insertTail(DS, createElement(sv));
            }
        }
        else if(luaChon == 2){
            xuatDS(DS);
        }
        else if(luaChon == 3){
            string hoTen;
            cout << endl << "nhap ho ten can tim: ";
            cin.ignore();
            getline(cin,hoTen);
            findName(DS, hoTen);
        }
        else if(luaChon == 4){
            SV sv;
            string maSV;
            cout <<"\nNhap Thong Tin SV Can Them Vao\n";
            nhapSV(sv);
            cout <<"\nNhap ma sv can chen vao sau: " ;
            cin.ignore();
            cin >> maSV;
            chenSV(DS, maSV, createElement(sv));
        }
        else if(luaChon == 5){
            cout <<"\nNhap ma so sinh vien can xoa: \n";
            cin.ignore();
            string s;
            cin >> s;
            node* p = DS.head;
            while(p != NULL){
                if((p->sv.maSo).compare(s) == 0){
                    deleteP(DS,p);
                    break;
                }
                p = p->next;
            }
        }
        else if(luaChon == 6){
            node* p = DS.head;

            while(p->next != NULL){
                node* i = p->next;
                 while(i != NULL){
                    if((p->sv.maSo) > (i->sv.maSo)){
                       SV temp;
                       temp = p->sv;
                       p->sv = i->sv;
                       i->sv = temp;
                    }
                    i = i->next;
                }
                p = p->next;
            }
        }
        else if(luaChon == 7){
            node* p = DS.head;
            while(p->next != NULL){
                node* i = p->next;
                 while(i != NULL){
                    if((p->sv.hoTen) > (i->sv.hoTen)){
                       SV temp;
                       temp = p->sv;
                       p->sv = i->sv;
                       i->sv = temp;
                    }
                    i = i->next;
                }
                p = p->next;
            }
        }
        if(luaChon == 8){
            deleteLinkedList(DS);
        }
        system("pause");
    }
}
int main(){
    menu();
}
