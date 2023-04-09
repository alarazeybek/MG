//
// Created by Dell on 4/9/2023.
//

#ifndef CS202EXAM_HEAP_H
#define CS202EXAM_HEAP_H


class Heap {
public:
    Heap();
    ~Heap();

    bool isEmpty();
    bool heapInsert(const int newItem);
    bool heapDelete(int& rootItem);     // root item deleted itemtype olarak initilize ediliyor o yüzden parametre
    void heapSort();
protected:
    void heapRebuild(int root);
private:
    int size;
    int items[100];
};


#endif //CS202EXAM_HEAP_H
