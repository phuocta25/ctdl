#include <iostream>
using namespace std;

struct Node{

   int key;
   int bal; // 0: can bang // -1: lech trai // 1:lech phai
   Node *left;
   Node *right;
   Node *parent;
};

struct Tree{
   Node *root;
   int NumberNode;
   int NumeberLeaf;
   int Hight;

};
Node* createNode(int k);
void InitTree(Tree &T);
int Put(Node *&root, Node* x, Node* parent);
int PutNodeTree(Tree &tree, int x);
void Rotate_LL(Node *&T);
void Rotate_LR(Node *&T);
void Rotate_RR(Node *&T);
void Rotate_RL(Node *&T);
void duyetLNR(Node *p);
void duyetNLR(Node *p);
int kiem_tra_x(Node*p,int &x);
Node *search(Node *root, int x);
int dem_buoc(Node*p,int x,int dem);
int NumberLeaf(Node *root);
int HightTree(Node *root);
int countNode1(Node *root);
int countNode2(Node *root);
int sum(Node *p);
int main()
{
    Tree AVL;
    int x,dem=0;
    InitTree(AVL);
    PutNodeTree(AVL,1);
    PutNodeTree(AVL,3);
    PutNodeTree(AVL,5);
    PutNodeTree(AVL,7);
    PutNodeTree(AVL,9);
    PutNodeTree(AVL,12);
    PutNodeTree(AVL,15);
    PutNodeTree(AVL,17);
    PutNodeTree(AVL,21);
    PutNodeTree(AVL,23);
    PutNodeTree(AVL,25);
    PutNodeTree(AVL,27);
    cout<<"nhap vao khoa x: "<<endl;
    cin>>x;
    kiem_tra_x(AVL.root,x);
    // duyetLNR(AVL.root);
    duyetNLR(AVL.root);cout<<endl;
    search(AVL.root,21);cout<<endl;
    cout<<"so buoc la: "<<dem_buoc(AVL.root,21,0)<<endl;
    cout<<NumberLeaf(AVL.root)<<endl;
    cout<<HightTree(AVL.root)+1<<endl;
    cout<<countNode1(AVL.root)<<endl;
    cout<<countNode2(AVL.root)<<endl;
    cout<<sum(AVL.root)<<endl;
    //.....
    return 0;
}
Node* createNode(int k){
   Node *n=new Node;
   n->key=k;
   n->bal=0;
   n->left=NULL;
   n->right=NULL;
   n->parent=NULL;
   return n;
}

void InitTree(Tree &T){
   T.root=NULL;
   T.NumberNode=0;
   T.NumberNode=0;
   T.NumeberLeaf=0;
   T.Hight=0;
}

int Put(Node* &root, Node * x, Node* parent)
{
    // return 0 neu khong lm thay doi chieu cao
    // return 1 chieu cao thay doi
    // return -1 khong chen
    int res=0;
	if(root!=NULL)
	{
		if(root->key == x->key)return -1;
		if(root->key>x->key){

                res=Put(root->left, x,root);
                if(res<1) return res;  // khong lm thay doi chieu cao

                switch(root->bal){
                  case -1: if(root->left->bal==-1)  // LL
                           Rotate_LL(root);
                           else
                             if(root->left->bal==1)   // LR
                             Rotate_LR(root);
                           return 0;
                  case 0:  root->bal=-1; return 1;
                  case 1:  root->bal=0 ;  return 0;
                }
              }
		else {
            // continue  ????
            res=Put(root->right, x,root);
                if(res<1) return res;  // khong lm thay doi chieu cao

                switch(root->bal){
                  case 1: if(root->right->bal==-1)
                           Rotate_RL(root);
                           else
                             if(root->right->bal==1)
                             Rotate_RR(root);
                           return 0;
                  case 0:  root->bal=1; return 1;
                  case -1: root->bal=0 ;  return 0;

                }

	         }
    }

	//Node *tmp = createNode(x);
	x->parent=parent;
	root=x;
	return 1;
}
int PutNodeTree(Tree &tree, int x){ //insert node into tree
    Node *p=tree.root;
    Node *X = createNode(x);
    if(Put(tree.root,X,NULL)!=-1){
        if(tree.root==NULL)
            tree.root=X;
        tree.NumberNode++;

        }
    return tree.NumberNode;
}
// #define LH -1 Cây con trái cao hơn
// #define EH 0 Cây con trái bằng cây con phải
// #define RH 1 Cây con phải cao hơn

void Rotate_LL(Node * &T)
{	Node *T1 = T->left;
	T->left = T1->right; T1->right=T;
	switch(T1->bal)
	{
		case 0:	 T->bal =0;
                 T1->bal=1;
                 break;
		case -1: T->bal=0;
                 T1->bal=0;
				 break; 
	}
	T=T1;
}
void Rotate_LR(Node *&T){
// continue ???
    Node *T1=T->left;
    Node *T2=T1->right;
    T->left=T2->right;
    T2->right=T;
    T1->right=T2->left;
    T2->left=T1;
    switch (T2->bal)
    {
    case -1: T->bal=0;
             T1->bal=1;
            break;
    case  0: T->bal=0;
             T1->bal=0;
             break;
    case  1: T->bal=-1;
             T1->bal=0;
             break;
    }
    T2->bal=0;
    T=T2;

}
void Rotate_RR(Node *&T){
// continue ???
    Node *T1 = T->right;
	T->right = T1->left; 
    T1->left=T;
    switch(T->bal)
	{
		case 0:	 T->bal =0;
                //  T1->bal=-1;
                 break;
		case 1: T->bal=0;
                // T1->bal=0;
				 break;
	}
    T1->bal=0;
	T=T1;  
}
void Rotate_RL(Node *&T){
// continue ???
    Node *T1=T->right;
    Node *T2=T1->left;
    T->right=T2->left;
    T2->left=T;
    T1->left=T2->right;
    T2->right=T1;
    switch (T2->bal)
    {
    case 1: T->bal=0;
            T1->bal=-1;
            break;
    case 0: T->bal=0;
            T1->bal=0;
            break;
    case -1: T->bal=1;
            T1->bal=0;
            break;
    }
    T2->bal=0;
    T=T2;
}

void duyetLNR(Node *p) {
    if (p != NULL) {
    duyetLNR(p->left);
    cout<<p->key<<" ";
    duyetLNR(p->right);
    } 
}
void duyetNLR(Node *p) {
    if (p != NULL)
    { 
    cout<<p->key<<" ";
    duyetNLR(p->left);
    duyetNLR(p->right);
    } 
}
int kiem_tra_x(Node*p,int &x){
    while (p!=NULL)
    {
        if (p->key == x){
            cout<<"khoa x nam trong cay AVl"<<endl;
            return 0;}
        else {
            if (p -> key > x) p=p -> left;
                else 
                    p=p -> right;}                                           
    }
    cout<<"khoa x khong nam trong cay AVl"<<endl;
        return 0;
}
int dem_buoc(Node*p,int x,int dem){
    if (p != NULL)
    {   
        dem+=1;
        if (p->key == x){
            return dem;}
        else 
        if (x > p->key)
            return dem_buoc(p->right, x,dem);
        else
            return dem_buoc(p->left, x,dem);
    }
    return dem;
}
Node *search(Node *root, int x)//tìm kiếm trên cây
{   Node*p=root;
    if (p != NULL)
    {   
        cout<< root->key << " ";
        if (p->key == x){
            return root;}
        else 
        if (x > p->key)
            return search(p->right, x);
        else
            return search(p->left, x);
    }
    return NULL;
}
int NumberLeaf(Node *root){
     Node* p=root;
     if(p==NULL) return 0;
     if(p->left==NULL && p->right==NULL)
        return 1;
     else return NumberLeaf(p->left)+NumberLeaf(p->right);
}
int HightTree(Node *root){
    Node *p=root;
    if(p==NULL) return -1;
     if(p->left==NULL&&p->right==NULL)
        return 0;
     else {
            int T=HightTree(p->left);
            int P=HightTree(p->right);
            return T>P?T+1:P+1;

          }
}
int countNode1(Node *root)
{
    int count=0;
    if(root==NULL) return 0;
    else
           if((root->left!=NULL && root->right==NULL) ||(root->left==NULL && root->right!=NULL)) 
                 count=1;
    return count+countNode1(root->left) + countNode1(root->right);
}
int countNode2(Node *root)
{
    int count=0;
    if(root==NULL) return 0;
    else
           if (root->left!=NULL && root->right!=NULL)  
           count=1;
    return count+countNode2(root->left) + countNode2(root->right);
}
int sum(Node *p)
{
    int s=0;
    if(p==NULL) return 0;
    else
    {
         s = p->key;
         return s + sum(p->left) + sum(p->right);
    }
}