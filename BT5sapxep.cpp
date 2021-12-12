#include<iostream>
#include<stack>
#include<queue>
#include<string>
using namespace std;
string getphantu(string &bieuThuc){
    int size=bieuThuc.size();
    string kqua;
    if(bieuThuc[0]=='('||bieuThuc[0]==')'){
        kqua.resize(1);
        kqua=bieuThuc[0];
        bieuThuc.erase(0,1);
        return kqua;
    }
    if(bieuThuc[0]=='+'||bieuThuc[0]=='-'||bieuThuc[0]=='*'||bieuThuc[0]=='/'){
        kqua.resize(1);
        kqua=bieuThuc[0];
        bieuThuc.erase(0,1);
        return kqua;
    }
    int i=0;
    while(i<size){
        if(bieuThuc[i]>='0'&&bieuThuc[i]<='9'){
            kqua.resize(i+1);
            kqua[i]=bieuThuc[i];
        }
        else
        	break;
        i++;
    }
    bieuThuc.erase(0,i);
    return kqua;
}
    int kiemtraPT(string temp){
    if(temp=="+"||temp=="-"||temp=="*"||temp=="/")
        return 1;
    else {
        if(temp=="("||temp==")")
            return -1;
        else
        return 0;
        
    }
}
    int giatri(string o){
        if(o=="*"||o=="/")
        return 2;
        if(o=="+"||o=="-")
        return 1;
    }
    void ChuyenBalan(string bieuThuc,stack<string>&mystack,queue<string>&myqueue){
    while(!bieuThuc.empty()){
        string temp= getphantu(bieuThuc);
        if(kiemtraPT(temp)==0)
            myqueue.push(temp);
        else{
            if(kiemtraPT(temp)==1){
                while (!mystack.empty()){
                    if(kiemtraPT(mystack.top())==1 && giatri(mystack.top())>=giatri(temp)){
                        myqueue.push(mystack.top());
                        mystack.pop();
                    } 
                    else
                    break;
                }
                 mystack.push(temp);
            }
            else{
                if(temp=="(")
                mystack.push(temp);
                else{
                    if(temp==")"){
                        while(!mystack.empty()){
                            if(mystack.top()!="("){
                                myqueue.push(mystack.top());
                                mystack.pop();
                            }
                            else
                            break;
                        }
                        mystack.pop();
                    }
                }
            }
        }
    }
    while(!mystack.empty()){
        myqueue.push(mystack.top());
            mystack.pop();
        
    }
 }
    float Tinh(string dau,float a,float b){
        if(dau=="+")
        return a+b;
        if(dau=="-")
        return a-b;
        if(dau=="*")
        return a*b;
        if(dau=="/")
        return a/b;
      
    }
    
    float KetQua(queue<string>myqueue,stack<float>mystack2){
        float kqua=0;
        while(!myqueue.empty()){
            string tmp=myqueue.front();
            myqueue.pop();
            if(kiemtraPT(tmp)== 0)
            mystack2.push(stof(tmp));
            else{
                if(mystack2.size()<2){
                    cout<<"\nloi bieu thuc"<<endl;
                    return 0;
                }
                else{
                    float num1=mystack2.top();
                    mystack2.pop();
                    float num2=mystack2.top();
                    mystack2.pop();
                    kqua=Tinh(tmp,num2,num1);
                    mystack2.push(kqua);
                }
            }
        }
         return kqua;
}

int main(){
    string bieuThuc;
    cout<<"\nMoi nhap bieu thuc ";
    getline(cin,bieuThuc);
    stack<string>mystack1;
    queue<string>myqueue;
    ChuyenBalan(bieuThuc,mystack1,myqueue);
    stack<float>mystack2;
    float kq=KetQua(myqueue,mystack2);
    cout<<"\nKet qua la:"<<kq;
    getchar();
}
