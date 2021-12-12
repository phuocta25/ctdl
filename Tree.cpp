#include <iostream>

using namespace std;
struct Node {
    int key;
    Node* left;
    Node* right;
    Node* parent;
};

struct Tree {
    Node* root;
    int NumberNode;
};
Node* createNode(int);
void InitTree(Tree&);
bool put(Node*, Tree&);
void TravelNLR(Node*);
void TravelLNR(Node*);
void TravelLRN(Node*);


int main()
{
    Tree T;
    InitTree(T);
    // Node* n;
    put(createNode(54), T);
    put(createNode(31), T);
    put(createNode(43), T);
    put(createNode(29), T);
    put(createNode(65), T);
    put(createNode(10), T);
    put(createNode(20), T);
    put(createNode(36), T);
    put(createNode(78), T);
    put(createNode(59), T);

    cout << "--------Duyet theo NLR-------\n";
    TravelNLR(T.root);
    cout << "--------Duyet theo LNR-------\n";
    TravelLNR(T.root);
    cout << "--------Duyest theo LRN-------\n";
    TravelLRN(T.root);

    return 0;
}
Node* createNode(int k) {
    Node* n = new Node;
    n->key = k;
    n->left = NULL;
    n->right = NULL;
    n->parent = NULL;
    return n;
}
void InitTree(Tree& T) {
    T.root = NULL;
    T.NumberNode = 0;
}
bool put(Node* n, Tree& T) {
    Node* p = T.root;
    if (T.root == NULL) {
        T.root = n;
        return true;
    }
    while ((n->key > p->key && p->right != NULL) || (n->key < p->key && p->left != NULL)) {
        if (n->key == p->key)
            return false;
        else {
            if (n->key > p->key)
                p = p->right;
            else
                p = p->left;
        }
    }

    if (n->key > p->key)
        p->right = n;
    else
        p->left = n;
    n->parent = p;
    return true;

}

void TravelNLR(Node* p) {

    if (p != NULL) {
        cout << p->key << '\n';
        TravelNLR(p->left);
        TravelNLR(p->right);
    }
}
void TravelLNR(Node* p) {
    if (p != NULL) {
        TravelLNR(p->left);
        cout << p->key << '\n';
        TravelLNR(p->right);
    }
}
void TravelLRN(Node* p) {
    if (p != NULL) {
        TravelLRN(p->left);
        TravelLRN(p->right);
        cout << p->key << '\n';
    }
}
