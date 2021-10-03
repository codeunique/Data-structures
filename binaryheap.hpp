
#ifndef BINARYHEAP_H
#define BINARYHEAP_H
using namespace std;
 class binaryheap
{
  private:
    int* harr;
  public:
     int capacity;
     int size;
     binaryheap(int capacity);
     void swap(int* num1,int* num2);
    void insert(int data);
    void extractMax();
    void heapify(int index);
    void buildHeap();
    void showHeapArray();
    void heapsort();
    
};
#endif