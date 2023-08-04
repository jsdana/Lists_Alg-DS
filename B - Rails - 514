#include <iostream>
#include <stdlib.h>

using namespace std;

class Link{
public:
    int element;
    Link* next;

    Link(int e, Link* n){
        element = e;
        next = n;
    }
    Link(Link* n = NULL){
        next = n;
    }
};

class Stack{
private:
    Link* top;
    int size;

public:
    Stack(){
        top = NULL;
        size = 0;
    }
    ~Stack(){
        clear();
    }

    void clear(){
        while(size>0)
            pop();  
    }
    void push(int e){
        top = new Link(e, top);
        size++;
    }
    int pop(){
        if(top == NULL)
            return -1;
        int it = top->element;
        top = top->next;
        size--;
        return it;
    }

    int getTop(){
        return top->element;
    }
    int getSize(){
        return size;
    }
};

class Queue{
private:
    Link* front;
    Link* rear;
    int size;
public:
    Queue(){
        front = rear = new Link(NULL);
        size = 0;
    }
    ~Queue(){
        clear();
    }
    void clear(){
        while(size>0)
            dequeue();
    }

    void enqueue(int e){
        rear->next = new Link(e, NULL);
        rear = rear->next;
        size++;
    }

    int dequeue(){
        if(size == 0)
            return -1;
        int it = front->next->element;
        front->next = front->next->next;
        if(front->next == NULL)
            rear = front;
        size--;
        return it;
    }

    int getFront(){
        return front->next->element;
    }
};

int main(){

    Stack station;
    Queue trains;
    int size, atual, counter = 0;
    bool flag = true;
    bool nums = true;

    while(flag){
        cin >> size; 
        if(size==0){
            flag = false;
            nums = false;
        }
        while(nums){
            for(int i=0; i<size; i++){
                cin >> atual;
                if(atual==0){
                    i = size;
                    nums = false;
                }else{
                    trains.enqueue(atual);
                }
            }

            if(nums){
                for(int j=1; j<=size; j++){
                    station.push(j);

                    if(trains.getFront() == station.getTop()){
                        trains.dequeue();
                        station.pop();
                    }
                    counter = station.getSize();
                    while(counter>0){
                        if(trains.getFront() == station.getTop()){
                            trains.dequeue();
                            station.pop();
                        }
                        counter--;
                    }
                }

                if(station.getSize() == 0 )
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            }
            station.clear();
            trains.clear();
        }
        if(atual==0 && size!=0)
            cout<<endl;
        nums = true;           
    }

    return 0;
}
