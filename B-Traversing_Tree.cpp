#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class BSTnode{
public:
    unsigned short int key;
    BSTnode* left;
    BSTnode* right;

    BSTnode(){
        left = right = NULL;
    }
    BSTnode(unsigned short int k, BSTnode* l = NULL, BSTnode* r = NULL){
        key = k; left = l; right = r;
    }
};

class BST{
private:
    BSTnode* root;
    short int nodeCounter;

    void clearHelp(BSTnode* n){
        if(n == NULL)
            return;
        clearHelp(n->left);
        clearHelp(n->right);
        delete n;
    }

    BSTnode* insertHelp(BSTnode* n, unsigned short int k, unsigned short int e){
        if(n == NULL)
            return new BSTnode(k, NULL, NULL);
        if(n->key > k)
            n->left = insertHelp(n->left, k, e);
        else{
            n->right = insertHelp(n->right, k, e);
        }
        return n;
    }

    void preOrder(BSTnode* n){
        if(n != NULL){
            cout << n->key << " ";
            preOrder(n->left);
            preOrder(n->right);
        }
    }
    void inOrder(BSTnode* n){
        if(n!= NULL){
            inOrder(n->left);
            cout << n->key << " ";
            inOrder(n->right);
        }
    }
    void postOrder(BSTnode* n){
        if(n != NULL){
            postOrder(n->left);
            postOrder(n->right);
            if(n!=root)
                cout << n->key << " ";
            else
                cout << n->key;
        }
    }

public:
    BST(){
        root = NULL;
        nodeCounter = 0;
    }
    ~BST(){clearHelp(root);}

    void insert(unsigned short int e){
        unsigned short int k = e;
        root = insertHelp(root, k, e);
        nodeCounter++;
    }

    void prePrint(){
        preOrder(root);
        cout << endl;
    }
    void inPrint(){
        inOrder(root);
        cout << endl;
    }
    void postPrint(){
        postOrder(root);
        cout << endl;
    }
};

int main(){
    BST be;
    short int size; 
    unsigned short int atual;
    cin >> size;
    for(short int i=0; i<size; i++){
        cin >> atual;
        be.insert(atual);
    }

    cout << "Pre order : ";
    be.prePrint();
    cout << "In order  : ";
    be.inPrint();
    cout << "Post order: ";
    be.postPrint();

    return 0;
}
