#include<iostream>
#include"singlyLinkedList.hpp"
using namespace std;

 //Function to append an element at the end of list.
   void singlyLinkedList::addToList(int data)
    {
        SllNode *sNode = new SllNode;
        sNode->data = data;
        sNode->next = NULL;
        if (head == NULL)
            head = sNode;
        else
        {
            SllNode *curr = head;
            while (curr->next != NULL)
                curr = curr->next;

            curr->next = sNode;
        }
        size++;
    }
    // FUnction to Delete an item from the list.
    void singlyLinkedList::deleteFromList(int data)
    {

        SllNode *prev = NULL;
        if (head->data == data)
        {
            prev = head;
            head = head->next;
            delete prev;
        }
        else
        {
            SllNode *curr = head;
            while (curr->data != data)
            {
                prev = curr;
                curr = curr->next;
            }
            prev->next = curr->next;
            delete curr;
        }
        size--;
    }
    // Printing all elements of the List.

    void singlyLinkedList:: showList()
    {
        SllNode *curr = head;
        while (curr != NULL)
        {
            std::cout <<"("<< curr->data << ")-> ";
            curr = curr->next;
        }
    }
    void singlyLinkedList::removeNodeAtPos(int pos)
    {
        if (pos > size || pos < 1)
            std::cout << "invalid position entered.";
        else
        {
            SllNode *curr = head;
            SllNode *prev = NULL;
            int tpos = 1;
            if (pos == 1)
            {
                head = curr->next;
                delete curr;
                return;
            }

            while (tpos != pos)
            {
                prev = curr;
                curr = curr->next;
                tpos++;
            }
            prev->next = curr->next;
            delete curr;
            size--;
        }

    }
SllNode* singlyLinkedList::reverse()
{
        SllNode* current = head;
        SllNode* prev = NULL;
        
        while(current->next!=NULL)
        {
            SllNode* next= current->next;
            current->next = prev;
            prev = current;
            current = next;
            
        }
        current->next = prev;
        head = current;
        return head;
} 
bool singlyLinkedList::isCircular()
{
        SllNode*  temp = head;
       if( head==NULL)
         return true;
   
    
    while(true)
    {
       if(temp->next == head)
      return true;
    else if(temp->next == NULL)
      return false;
      else
        temp = temp->next;
    }
}   
void singlyLinkedList::palindrome()    
{
    if(head==NULL)
     {
       cout<<"Linked list is empty.";
       return;
     } 
    singlyLinkedList newlist;
    SllNode* temp = head;
    while(temp!=NULL)
    {
        newlist.addToList(temp->data);
        temp = temp->next;
    }
   SllNode* rhead = this->reverse();
    temp = rhead;
    SllNode* ntemp = newlist.head;
    while(temp!=NULL)
     {
          if(temp->data ==ntemp->data)
         {
             temp = temp->next;
             ntemp = ntemp->next;
         }
        else
         {
             cout<<"NO";
             return;
         } 
     } 
   cout<<"YES";
   return;  
}