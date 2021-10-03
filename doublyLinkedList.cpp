#include<iostream>

#include"./doublyLinkedList.hpp"


using namespace std;

      void doublyLinkedList::addToList(int data)
      {
          DllNode* dNode = new DllNode;
          dNode->data = data;
          dNode->next = NULL;
          dNode->prev=NULL;
          if(head ==NULL)
            head=dNode;
          else
          {
              DllNode* curr =head;
              while(curr->next!=NULL)
              {
                  curr= curr->next;
            
              }
              curr->next = dNode;
              dNode->prev = curr;

          }
         size++;   
      }

       void doublyLinkedList::deleteFromList(int data)
      {  
          DllNode* curr = head;
          if(head->data == data)
            {
                head = head->next;
                head->prev = NULL;
                delete curr;

            }
           else
           {
               while (curr->data != data)
                   curr = curr->next;

               curr->prev->next = curr->next;
               if(curr->next!=NULL)
               curr->next->prev = curr->prev;
               delete curr;
           }
     
          size--;  
      }


     void doublyLinkedList::showList()
    {
        DllNode *curr = head;
        while (curr != NULL)
        {
            std::cout << curr->data << " ";
            curr = curr->next;
        }
    }
    void doublyLinkedList::removeNodeAtPos(int pos)
   {
        if (pos > size || pos < 1)
            std::cout << "invalid position entered.";
       int tpos=1;
       DllNode* curr = head;
          if(pos==1)
            {
                head = head->next;
                head->prev = NULL;
                delete curr;

            }
           else
           {
               while (tpos!=pos)
                   {
                      curr = curr->next;
                      tpos++;
                   }

               curr->prev->next = curr->next;
               if(curr->next!=NULL)
               curr->next->prev = curr->prev;
               delete curr;
           }
           size--;
   }
