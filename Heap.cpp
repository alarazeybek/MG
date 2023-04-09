//
// Created by Dell on 4/9/2023.
//

#include "Heap.h"

Heap::Heap() {
    size = 0;
}

Heap::~Heap() {
    size = 0;
}

bool Heap::isEmpty() {
    return size == 0;
}

bool Heap::heapInsert(const int newItem) {
    if(size >= 100){return false;} //heap is full
    else{
        items[size] = newItem;
        int firstInsertedPlace = size;
        int parentIndex = (firstInsertedPlace-1)/2;
        while(parentIndex>=0 && items[firstInsertedPlace] > items[parentIndex] ){
            //-------updating array location-elements
            int temp = items[firstInsertedPlace];
            items[firstInsertedPlace] = items[parentIndex];
            items[parentIndex] = temp;
            //-------going one step upward
            firstInsertedPlace = parentIndex;
            parentIndex = (firstInsertedPlace-1)/2;
        }
        size++;
        return true;
    }
}
bool Heap::heapDelete(int& rootItem) {
   if(isEmpty()){return false;}
   else{
       rootItem = items[0];
       items[0] = items[size-1];
       size--;
       heapRebuild(0);      //roottan itibaren rebuild yap
   }
}

void Heap::heapRebuild(int root) {
    int child = 2*root + 1;
    if(child < size){
        int right = child+1;
        if(right< size && items[child] < right){
            child = right;
        }
        if(items[root] < items[child]){
            int temp = items[child];
            items[child] = items[root];
            items[root] = temp;
            heapRebuild(child);
        }
    }
}

void Heap::heapSort() {

}