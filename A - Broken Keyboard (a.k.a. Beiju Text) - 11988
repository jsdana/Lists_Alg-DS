#include <iostream>
#include <stdlib.h>

using namespace std;

class Link{
public:
    char element;
    Link* next;

    Link(char e, Link* n){
        element = e;
        next = n;
    }
    Link(Link* n){
        next = n;
    }
};

class llist{
private:
    Link* head;
    Link* curr;
    Link* tail;
    int cnt;
public:
    llist(){
        head = curr = tail = new Link(NULL);
        cnt = 0;
    }
    ~llist(){
        del();
    }

    void del(){
        curr = head;
        while(head->next != NULL)
            remove();
    }

    void clear(){
        del();
        head = curr = tail = new Link(NULL);
        cnt = 0;
    }
    
    void insert(char e){
        curr->next = new Link(e, curr->next);
        if(tail == curr)
            tail = curr->next;
        cnt++;
    }

    void remove(){
        if(curr->next != NULL){
            if(tail == curr->next)
                tail = curr;
            curr->next = curr->next->next;
            cnt--;
        }
    }

    void print(){
        curr = head;
        for(int i=0; i<cnt; i++){
            cout << curr->next->element;
            curr = curr->next;
        }
        cout << '\n';
    }

    void next(){
        if(curr->next!=NULL)
            curr = curr->next;
    }

    void moveToStart(){
        curr = head;
    }

    void moveToEnd(){
        curr = tail;
    }
};

int main(){

    llist bo;
    char atual;
    string phrase;

    while(cin >> phrase){
        for(int i=0; i<phrase.size();i++){
            if(phrase.at(i) == '['){
                bo.moveToStart();
            }else if(phrase.at(i) == ']')
                bo.moveToEnd();
            else{
                bo.insert(phrase.at(i));
                bo.next();
            }
        }    
        bo.print();
        bo.clear();
    }


    return 0;
}
