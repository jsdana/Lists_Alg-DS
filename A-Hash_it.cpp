#include <iostream>
#include <string>

using namespace std;

struct list{
    int key;
    string element;
};

class Dictionary{
private:
    int maxsize;
    int cnt;
    list* map;
public:
    Dictionary(){
        maxsize = 101;
        cnt = 0;
        map = new list[maxsize];
        for(int i=0; i<maxsize; i++)
            map[i].key = -1;
    }
    ~Dictionary(){
        delete [] map;
    }

    void clear(){
        cnt = 0;
        for(int i=0; i<maxsize; i++){
            map[i].key = -1;
            map[i].element.clear();
        }
    }

    int Hash(string w){
        int k = 0;
        for(int i=0; i<w.size(); i++)
            k += (w.at(i) * (i+1));
        k *= 19;
        return k%101;
    }

    bool find(int k){
            if(map[k].key == k)
                return true;

        return false;
    }

    bool findSTR(string w){
        for(int i=0; i<maxsize; i++)
            if(map[i].element == w)
                return true;
        return false;
    }

    void insert(string w){
        int k = Hash(w);
        int j = 1, pos; bool placed = false;
        if(find(k) == false && findSTR(w) == false){
            map[k].key = k;
            map[k].element = w;
            cnt++;
            return;
        }else{

            while(j<20 && !placed && findSTR(w) == false){
                pos = (k + j*j + 23*j)%101;
                if(find(pos) == false){
                    map[pos].key = pos;
                    map[pos].element = w;
                    cnt++;
                    placed = true;
                    return;
                }
                j++;
                
            }
        }
    }

    void remove(string w){
        for(int i=0; i<maxsize; i++){
            if(map[i].element == w){
                map[i].element.clear();
                map[i].key = -1;
                cnt--;
            }
        }
    }

    int get_size(){
        return cnt;
    }

    void print(){
        for(int i=0; i<maxsize; i++){
            if(map[i].key != -1)
                cout << map[i].key << ":" << map[i].element << "\n";
        }
    }
};

int main(){

    int numT, nOp;
    string op, curr;
    Dictionary go;
    cin >> numT;
    for(int i=0; i<numT; i++){
        
        cin >> nOp;
        for(int j=0; j<nOp; j++){
            cin >> op;
            if(op.substr(0,3) == "ADD"){
                curr = op.substr(4);
                go.insert(curr);
            }else{
                curr = op.substr(4);
                go.remove(curr);
            }
        }
        cout << go.get_size() << "\n";
        go.print();
        go.clear();
    }   

    
}
