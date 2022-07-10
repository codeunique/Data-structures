#ifndef BINARYTREE_H
#define BINARYTREE_H
#include<iostream>

typedef struct Treenode
{
    int data;
    Treenode* left;
    Treenode* right;
    
}Treenode;

class BST
{
    
    public:
   /* void buildBST(Treenode* root,int* arr,int len)
    {
        for(int i=0;i<len;i++)
        {
            insert(root,arr[i]);
        }
    }*/
    Treenode* createNode()
    {
        return new Treenode;
    }
   Treenode* insert(Treenode* root,int data)
   {
       
       if(root==NULL)
        {
            Treenode* newNode = createNode();
            
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        } 
        else if(data <= root->data)
        {
           root->left= insert(root->left,data);
        }
        else if(data > root->data)
         root->right =insert(root->right,data);
        
        return root;
   }
   int findMaxEle(Treenode* root)
   {
       if(root==NULL)
        {
            std::cout<<"root of tree is null."<<std::endl;
            return -1;
        }
       if(root->left==NULL && root->right==NULL)
          return root->data;
       else
          findMaxEle(root->right);  
   } 
  int findMinEle(Treenode* root)
  {
      if(root==NULL)
        {
            std::cout<<"root of tree is null."<<std::endl;
            return -1;
        }
      else if(root->left==NULL && root->right==NULL)
          return root->data;
      else
         return findMinEle(root->left);    
  } 
  Treenode* Search(Treenode* root,int data)
  {
      if(root==NULL)
       {
          std::cout<<"NO elments are present in the tree."<<std::endl;
       return NULL; 
       }
     if(root->data<data)
        return Search(root->right,data);
      else if(root->data > data)
        return Search(root->left,data);
      else
       {
           std::cout<<"element found in BST";
          return root; 
       } 
              
      
  }
 /* void removeNode(Treenode* root,int data)
  {
      Treenode* parent = nullptr;
        parent = root;
     if(root==nullptr)
      {
          std::cout<<"NO elements present in BST to delete."<<endl;
          
      }
     else if(root->data< data)
     {
       
          removeNode(root->right,data);
     } 
     else if(root->data > data)
     {
          removeNode(root->left,data);
     }   
     

  }*/
  void inorder(Treenode* root)
  {
      if(root==nullptr)
        return;
     inorder(root->left);
     std::cout<<root->data<<" ";
     inorder(root->right);


  }
  void preorder(Treenode* root)
  {
      if(root==nullptr)
        return;
     std::cout<<root->data<<" ";
     preorder(root->left);
     preorder(root->right);   
  }
  void postorder(Treenode* root)
  {
      if(root==nullptr)
        return;
      postorder(root->left);
      postorder(root->right);
      std::cout<<root->data<<" ";  
  }
};

#endif