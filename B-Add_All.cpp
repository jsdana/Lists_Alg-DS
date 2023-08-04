#include <iostream>
#include <stdlib.h>

using namespace std;

class Heap{
private:
    int size;
    int* list;
public:
    Heap(int max){
        size = 0;
        list = new int[max];
    }

    ~Heap(){
        delete [] list;
    }
    void clear(){
        size = 0;
    }

    void insert(long long int e){
        list[size+1] = e;
        size++;
        top_d();
    }

    long long int remove_min(){
        long long int it = list[1];
        int i = 1;
        while(i<size){
            list[i] = list[i+1];
            i++;
        }
        size--;
        bottom_up();
        return it;
    }

    void bottom_up(){
        for(int i = size/2; i>=1; i--){
            int k = i; int v = list[k];
            bool heap = false;
            while( !heap && 2*k <= size){
                int j = 2*k;
                if(j<size){
                    if(list[j] > list[j+1])
                        j = j+1;
                }
                if(v <= list[j])
                    heap = true;
                else{   
                    list[k] = list[j];
                    k = j;
                }

            }
            list[k] = v;
        }
    }

    int getsize(){
        return size;
    }

    int get_min(){
        return list[1];
    }

    void print(){
        for(int i= 1; i<=size; i++)
            cout << list[i] << " ";
            cout << "\n";
    }
    
       void swap(int j, int k){
            int temp = list[j];
            list[j] = list[k];
            list[k] = temp;
       }



    void top_d(){            
        int j = size;
        bool heap = false;
        while(!heap && (j/2)-1 >= 1){

            long long int val = list[j];
            if(val < list[(j/2)-1]){
                swap(j, (j/2)-1);
                j = (j/2)-1;
                val = list[j];
            }else
                heap = true;
        }
    }
};

int main(){

    Heap go(5000);
    long long int soma = 0, total = 0;
    int size = 1, curr;
    
    while( size != 0){
        cin >> size;

        if(size!=0){
            for(int i=1; i<=size; i++){
                cin >> curr;
                go.insert(curr);
            }
            go.bottom_up();
            //go.print();
            total = 0; soma  = 0;
            while(go.getsize() > 1){
                total = go.remove_min();
                total += go.remove_min();
                soma += total;
                go.insert(total);

            }
            cout << soma << "\n"; 
            go.clear();           
        }
    }
    
    
    return 0;
}
