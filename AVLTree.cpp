#include <iostream>

using namespace std;

struct Node{

   int key;
   int bal; // 0: can bang // -1: lech trai // 1:lech phai
   Node *left;
   Node *right;
   Node *parent;
   int height;
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

void TravelNLR(Node *p);
void TravelLNR(Node *p);
void TravelLRN(Node *p);

int main()
{
    Tree AVL;
    InitTree(AVL);
    //  50 20 30 10 -5 7 15 35 57 65 55 -1

    PutNodeTree(AVL,50);
    PutNodeTree(AVL,20);
    PutNodeTree(AVL,30);
    PutNodeTree(AVL,10);
    PutNodeTree(AVL,-5);
    PutNodeTree(AVL,7);
    PutNodeTree(AVL,15);
    PutNodeTree(AVL,35);
    PutNodeTree(AVL,57);
    PutNodeTree(AVL,65);
    PutNodeTree(AVL,55);
    PutNodeTree(AVL,-1);
    //.....

    TravelNLR(AVL.root);

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
int PutNodeTree(Tree &tree, int x)
{
    Node *p=tree.root;
    Node *X = createNode(x);
    if(Put(tree.root,X,NULL)!=-1)
        {
        if(tree.root==NULL)
            tree.root=X;
        tree.NumberNode++;

        }

}

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) -
           height(N->right);
}


void Rotate_LL(Node * &T)
{
    Node *T1 = T->left;
	T->left = T1->right; T1->right=T;

	T->bal = getBalance(T);
	T1->bal=0;
	T=T1;
}

void Rotate_LR(Node *&T)
{
    Node *T1=T->left, *T2=T1->right;
	T->left=T2->right; T2->right=T;
	T1->right= T2->left; T2->left = T1;

	T->bal = getBalance(T);
	T1->bal = getBalance(T1);

	T2->bal =0;
	T=T2;
}
void Rotate_RR(Node *&T){
    Node  *T1= T->right;
	T->right=T1->left;
	T1->left=T;

	T->bal = getBalance(T);

	T1->bal = 0;
	T=T1;
}
void Rotate_RL(Node *&T){
    Node *T1= T->right, *T2=T1->left;
	T->right = T2->left; T2->left = T;
	T1->left = T2->right; T2->right = T1;

	T->bal = getBalance(T);
	T1->bal = getBalance(T1);
	T2-> bal=0;
	T=T2;

}

void TravelNLR(Node *p){

   if(p!=NULL){
     cout<<p->key<<'\n';
     TravelNLR(p->left);
     TravelNLR(p->right);
   }
}
void TravelLNR(Node *p){
    if(p!=NULL){
      TravelLNR(p->left);
      cout<<p->key<<'\n';
      TravelLNR(p->right);
   }
}
void TravelLRN(Node *p){
    if(p!=NULL){
      TravelLRN(p->left);
      TravelLRN(p->right);
      cout<<p->key<<'\n';
   }
}
