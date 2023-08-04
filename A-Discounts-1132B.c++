#include <iostream>

void swap(int* Arr, int j, int k){
    int temp = Arr[j];
    Arr[j] = Arr[k];
    Arr[k] = temp;
}

int hoarePartitionD(int* Arr, int l, int r){
    int p = Arr[l];
    int i, j;
    i = l; j = r+1;
    do{
        do{
            i = i+1;
        }while(!(Arr[i]>=p || i>=r));
        do{
            j = j-1;
        }while(!(Arr[j]<=p));
        
        swap(Arr, i, j);
    }while(!(i>=j));

    swap(Arr, i, j);
    swap(Arr, l, j);
    return j;
}

void quickSortD(int* Arr, int l, int r){
    if(l<r){
        int s = hoarePartitionD(Arr, l, r);
        quickSortD(Arr, l, s-1);
        quickSortD(Arr, s+1, r);
    }
}

int main(){

    int size, sizeC;
    long long int soma = 0;
    int choco[300000];
    int atual;
    std::cin >> size;
    for(int i=0; i< size; i++){
        std::cin >> choco[i];
        soma+= choco[i];
    }

    quickSortD(choco, 0, size-1);

    std::cin >> sizeC;
    for(int i=0; i< sizeC; i++){
        std::cin >> atual;
        std::cout << soma - choco[size-atual] << std::endl;
    }

    return 0;
}
