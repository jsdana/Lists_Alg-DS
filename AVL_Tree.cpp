#include<iostream>
using namespace std;

struct node {               
    int key;
    struct node* left;
    struct node* right;
    int height;
    int left_c ;
    int right_c;
    int cnt ;
};

//mudando a altura das folhas para -1 
    int h(struct node* n){
        if(n == NULL)
            return -1;
        return n->height;
    }

    struct node* rightRotate(struct node* n){
        struct node* l = n->left;
        struct node* lr = l->right;
        l->right = n;
        n->left = lr;
        n->height = max(h(n->left),h(n->right))+1;
        l->height = max(h(l->left),h(l->right))+1;
        n->left_c = l->right_c;
        l->right_c = (n->right_c + n->left_c) + 1;
        return l;
    }
    struct node* leftRotate(struct node* n){
        struct node* r = n->right;
        struct node* rl = r->left;
        r->left = n;
        n->right = rl;
        n->height = max(h(n->left),h(n->right)) + 1;
        r->height = max(h(r->left),h(r->right)) + 1;
        n->right_c = r->left_c;
        r->left_c = (n->left_c + n->right_c) + 1;
        return r;
    }

    int getBalance(struct node* n){
        if(n == NULL)
            return 0;
        return h(n->left) - h(n->right);
    }

    struct node* insert(struct node* n, int k){
        if(n == NULL){
            struct node* temp = new node();
            temp->key = k;
            temp->left = NULL;
            temp->right = NULL;
            temp->height = 0;
            temp->left_c = 0;
            temp->right_c = 0;
            temp->cnt = 1;
            return temp;
        }
        if(k == n->key){
            n->cnt += 1;
            return n;
        }
        if(k < n->key)
            n->left = insert(n->left, k);
        else if(k > n->key)
            n->right = insert(n->right, k);
        else
            return n;

        n->height = max(h(n->left),h(n->right))+1;
        if(n->right != NULL )
            n->right_c = n->right->right_c + n->right->left_c + 1;
        
        if(n->left != NULL)
            n->left_c = n->left->right_c + n->left->left_c + 1;
        
        int balance = getBalance(n);
        if(balance > 1 && k < n->left->key)
            return rightRotate(n);
        if(balance < -1 && k > n->right->key)
            return leftRotate(n);
        if(balance > 1 && k > n->left->key){
            n->left = leftRotate(n->left);
            return rightRotate(n);
        }
        if(balance < -1 && k < n->right->key){
            n->right = rightRotate(n->right);
            return leftRotate(n);
        }
        return n;
    }

    bool found(struct node* root, int k){
        if(root == NULL)
            return false;
        if(root->key == k)
            return true;
        else if(root->key < k)
            return found(root->right, k);
        else
            return found(root->left, k);
    }
    int index(struct node* root, int k){
        if(root->key == k)
            return root->left_c + 1;
        else if ( root->key < k)
            return 1 + root->left_c + index(root->right, k);
        else
            return index(root->left, k);
    }

    int main(){
        struct node* root = NULL;
        int size;
        cin >> size;
        
        for(int i = 1; i <= size; i++){
            int op;
            cin >> op;
            if(op == 1){
                int curr;
                cin >> curr;
                root = insert(root, curr);
            }
            else{
                int curr;
                cin >> curr;
                if(found(root, curr) == false)
                    cout << "Data tidak ada" << "\n";
                else
                    cout << index(root,curr) << "\n";
            }
        }
    }
