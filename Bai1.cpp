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

Node * SearchTreeDQ(Node *root, int x);

int NumberLeaf(Node *root);

int HightTree(Node *root);

int countNode1(Node *root);
int countNode2(Node *root);

int sum(Node *p);

bool printLevel(Node* root, int level);
void levelTravel(Node* root);

int main()
{
    Tree AVL;
    InitTree(AVL);
    //  1  3  5  7  9  12  15  17  21  23  25  27

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
    //.....

    TravelNLR(AVL.root);

    cout<< "Seach 21 : ";
    SearchTreeDQ(AVL.root, 27);

    cout<< "\nSo node la : " << NumberLeaf(AVL.root);

    cout<< "\nChieu cao cua cay : " << HightTree(AVL.root)+1;

    cout<< "\nSo Node co bac 1 la : "<< countNode1(AVL.root);

    cout<< "\nSo Node co bac 2 la : "<< countNode2(AVL.root);

    cout<< "\nTong cac Node la : "<< sum(AVL.root);

    cout<< "\nLevel Travel:\n";
    levelTravel(AVL.root);
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


Node * SearchTreeDQ(Node *root, int x){
    Node* p=root;
    if(p==NULL) return NULL;
    else  {
        cout<< root->key << " ";
        if(p->key==x) return root;
        if(p->key>x) return SearchTreeDQ(p->left,x);
        if(p->key<x) return SearchTreeDQ(p->right,x);
    }
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
    int dem=0;
    if(root==NULL) return 0;
    else
           if((root->left!=NULL && root->right==NULL) ||(root->left==NULL && root->right!=NULL)) 
             dem=1;
    return dem+countNode1(root->left) + countNode1(root->right);
}

int countNode2(Node *root)
{
    int dem=0;
    if(root==NULL) return 0;
    else
           if (root->left!=NULL && root->right!=NULL)  
           dem=1;
    return dem+countNode2(root->left) + countNode2(root->right);
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

bool printLevel(Node* root, int level)
{
    if (root == NULL) {
        return false;
    }

    if (level == 1)
    {
        cout << root->key << " ";
        return true;
    }

    bool left = printLevel(root->left, level - 1);
    bool right = printLevel(root->right, level - 1);

    return left || right;
}


void levelTravel(Node* root)
{
    int level = 1;

    for (int i=0;i<=HightTree(root);i++)
    {
        cout<< "Level " << level-1 << ": ";
        printLevel(root, level);
        level++;
        cout<< "\n";
    }
}
