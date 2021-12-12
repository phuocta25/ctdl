#include <iostream>
#include<string>
using namespace std;

struct SinhVien{
	string name;
	string id;
};
typedef SinhVien SV;
struct Node{
   SV key;
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
Node* createNode(SV k){
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
void Rotate_LL(Node * &T)
{	Node *T1 = T->left;
	T->left = T1->right; T1->right=T;
	switch(T1->bal)
	{
		case 0:	 T->bal = 0;
                 break;
		case -1: T->bal= 1;
				 break;
	}
	T1->bal=0;
	T=T1;

}

void Rotate_LR(Node *&T){
// continue ???
    Node* T1 = T->left;
    Node* T2 = T1->right;
    T1->right = T2->left;
    T2->left = T1;
    T->left =T2->right;
    T2->right = T;
    switch(T2->bal){
        case 0: T->bal = 0;
            T1->bal = 0;
            break;
        case 1: T1->bal = 0;
            T->bal = -1;
            break;
        case -1: T1->bal = 1;
            T->bal = 0;
            break;
    }
    T2->bal = 0;
    T = T2;
}
void Rotate_RR(Node *&T){
// continue ???
    Node* R1 = T->right;
    T->right = R1->left;
    R1->left = T;
    switch(R1->bal){
        case 0: T->bal = 0;
            break;
        case 1: T->bal = -1;
            break;
    }
    R1->bal = 0;
    T = R1;
}
void Rotate_RL(Node *&T){
// continue
    Node* R1 = T->right;
    Node* R2 = R1->left;
    R1->left = R2->right;
    T->right = R2->left;
    R2->left = T;
    R2->right = R1;
    switch(R2->bal){
        case 0: T->bal = 0;
            R1->bal = 0;
            break;
        case 1: T->bal = 0;
            R1->bal = -1;
            break;
        case -1: T->bal = 1;
            R1->bal = 0;
            break;
    }
    R2->bal = 0;
    T = R2;
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
                if(res < 1) return res;
                else{
                    switch(root->bal){
                        case 1: if(root->right->bal == -1){   //RL
                                Rotate_RL(root);
                            }
                            else
                                if(root->right->bal == 1){    // RR
                                Rotate_RR(root);
                                }
                            return 0;
                        case 0: root->bal = 1;
                            return 1;
                        case -1: root->bal = 0;
                            return 0;
                    }
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
    if(Put(p,X,NULL)!=-1){
        if(tree.root==NULL){
            tree.root=X;
        }
        tree.NumberNode++;
        tree.root = p;
    }

}
void displayTree(Node* root){
    if(root != NULL){
        displayTree(root->left);
        cout << root->key << " ";
        displayTree(root->right);
    }
}

