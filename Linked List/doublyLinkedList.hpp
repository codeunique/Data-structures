#include <iostream>
#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
using namespace std;
// structure for a doubly linked list node.
typedef struct doublyLLNode
{
    int data;
    doublyLLNode *next;
    doublyLLNode *prev;
} DllNode;



class doublyLinkedList

{   private:
      DllNode* head;
      int size;
    public:
      doublyLinkedList()
      {
          head=NULL;
          size=0;
          cout<<"constructor of doubly linke list has been called."<<endl;
          cout<<"populate the doubly linked list"<<endl;
      }
    void addToList(int data);
    void deleteFromList(int data);
    void removeNodeAtPos(int pos);
    void showList();
};
#endif


