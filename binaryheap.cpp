#include"./binaryheap.hpp"
#include<iostream>
using namespace std;

void binaryheap::swap(int* num1,int* num2)
{
       int temp = *num1;
       *num1 = *num2;
       *num2 = temp;
}
 binaryheap::binaryheap(int cap)
{
    capacity = cap;
    harr = new int[capacity];
    size =0;
}

void binaryheap::heapify(int index)
{
    int largest = index;
    int leftindex = 2*index+1;
    int rightindex = leftindex+1;
    // if left child node > largest node then assign largest to leftchild.
    if(leftindex<size&&harr[leftindex]>harr[largest])
        largest = leftindex;
    if(rightindex<size&& harr[rightindex]>harr[largest])
        largest = rightindex;
    if(largest!= index)
    {   
        swap(&harr[largest],&harr[index]);
        heapify(largest);

    }        
}
void binaryheap::buildHeap()    
{
    int n = size;
    for(int i =(n/2)-1;i>=0;i--)
      heapify(i);
}
void binaryheap::insert(int data)
{
    /*if(size==0)
    {
        harr[0]=data;
        size++;
    }
    else
    {
          int i= size-1;
          harr[i]= data;
          size++;
          // calculating index of parent of node index.
          //To-do: try to think of a recursive approach for this same function.
         int Iparent = i%2==0?(i-1)/2:i/2; 
         while(harr[Iparent]<data&&i>0)
        {
           swap(&harr[Iparent],&harr[i]);
           i = Iparent;
          Iparent = i%2==0?(i-1)/2:i/2;
        }
    }*/
    if(size==0)
    {
        harr[0]=data;
        size++;
    }
    else
    {
        harr[size++] = data;
        buildHeap();
    }
}
void binaryheap::showHeapArray()
{
         std::cout<<"heap is represented by following array:"<<endl;
       for(int i=0;i<size;i++)
       {
          cout<<harr[i]<<" ";
       }
    }

void binaryheap::extractMax()
{
       swap(&harr[size-1],&harr[0]);
       size--;
       heapify(0);
}
void binaryheap::heapsort()
{
    int length = size;
    for(int i=size-1;i>0;i--)
    {
        extractMax();
    }
    size = length;
}