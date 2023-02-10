#include <iostream>
#include <stdlib.h>

template <typename E>
void swap(E* arr, int j, int k){
E temp = arr[j];
arr[j] = arr[k];
arr[k] = temp;
}

template <typename E>
int hoarePartition(E* arr, int l, int r){
    E p = arr[l];
    int i, j;
    i = l; j = r+1;
    do{
        do{
            i = i+1;
        }while(arr[i]<p && i<r);

        do{
            j = j-1;
        }while(arr[j]>p);
        
        swap(arr, i, j);

    }while(i<j);
    swap(arr, i, j);
    swap(arr, l, j);
    return j;
}

template <typename E>
void quickSort(E* arr, int l, int r){
    if(l<r){
        int s = hoarePartition(arr, l, r);
        quickSort(arr, l, s-1);
        quickSort(arr, s+1, r);
    }

}
template <typename E>
int BS(E* arr, int l, int r, int k){
    if(r>=l){
        int m = (l+r)/2;
        if(k == arr[m])
            return m;
        else if(k<arr[m])
            return BS(arr, l, m-1, k);
        else
            return BS(arr, m+1, r, k);
    }else
        return -1;
}

int main(){

    int size, key, counter = 0;
    int* array;
    std::cin >> size >> key;
    array = (int*) malloc(size * sizeof(int));
    for(int i=0; i<size; i++)
        std::cin >> array[i];

    quickSort(array, 0, size-1);
    for(int i=0; i<size; ++i){
        if(BS(array, i, size, array[i]+key)!=-1)
            counter++;
    }
    std::cout << counter;  

    free(array);
    return 0;
}
