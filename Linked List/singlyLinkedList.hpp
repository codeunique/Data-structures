#include <iostream>
#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

using namespace std;

// structure for a singly linked list node.
typedef struct singlyLLNode
{
    int data;
    struct singlyLLNode *next;
} SllNode;



class singlyLinkedList

{   public:
      SllNode* head;
      int size;
    
      singlyLinkedList()
      
      {
          head=NULL;
          size=0;
          cout<<"constructor of singly Linked list has been called."<<endl;
          cout<<"List is empty right now, populate the list."<<endl;
      }
    void addToList(int data);
    void deleteFromList(int data);
    void removeNodeAtPos(int pos);
    void showList();
    SllNode* reverse();
    bool isCircular();
    void palindrome();
};
#endif
