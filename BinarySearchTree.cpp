//
//  BinarySearchTree.cpp
//  Trees
//
//  Created by Eric on 2017/12/20.
//  Copyright © 2017年 Eric. All rights reserved.
//

#include "BinarySearchTree.hpp"




void BST::PutNode(TreeNode<int> *Node)
{
    InorderArr[counter]=*Node;counter++;
}

void BST::Inorder_sub(TreeNode<int> *Node)
{
    if(Node)
    {
        Inorder_sub(Node->leftChild);
        PutNode(Node);
        Inorder_sub(Node->rightChild);
    }
    return;
}


void BST::Inorder(TreeNode<int> *Node)
{
    setArray();Inorder_sub(Node);return;
}


void BST::Insert(int k) //iterative method
{
    if(isEmpty())
    {
        cout<<"It’s empty tree"<<endl;
        return; //If it is empty tree than return NULL
    }
    int rootValue; int L;
    L = rootValue = RootData(); // get the root data
    TreeNode<int> *currNode;
    currNode=root;
    do{
        if(k > rootValue)
        {
            TreeNode<int> *temp=currNode;
            currNode=currNode->rightChild; //traverse to right
            if(!currNode){
                TreeNode<int> *NewNode=new TreeNode<int>;
                temp->rightChild=NewNode;
                NewNode->data=k;NewNode->leftChild=NewNode->rightChild=NULL;
                NumOfNodes++;
                return ;}
            else{   rootValue=currNode->data;}
        }
        else if(k < rootValue)
        {
            TreeNode<int> *temp=currNode;
            currNode=currNode->leftChild;    //traverse to left
            if(!currNode){
                TreeNode<int> *NewNode=new TreeNode<int>;
                temp->leftChild=NewNode;
                NewNode->data=k;NewNode->leftChild=NewNode->rightChild=NULL;
                NumOfNodes++;
                return; }
            else{  rootValue=currNode->data;}
        }
        else
        {   cout<<"already in the tree"<<endl; return; } // when L equal to K case
        
    }while(currNode);return;
}


void BST::Delete(int k) //iterative method
{
    if(isEmpty())
    {
        cout<<"It’s empty tree"<<endl;
        return; //If it is empty tree than return NULL
    }
    int rootValue; int L;
    L = rootValue = RootData(); // get the root data
    TreeNode<int> *currNode;TreeNode<int> *prev;
    prev=currNode=root;
    do{
        if(k > rootValue)
        {
            prev=currNode;
            currNode=currNode->rightChild; //traverse to right
            if(!currNode){cout<<"not in the tree"<<endl;return ;}
            rootValue=currNode->data;
        }
        else if(k < rootValue)
        {
            prev=currNode;
            currNode=currNode->leftChild;    //traverse to left
            if(!currNode){cout<<"not in the tree"<<endl;return; }
            rootValue=currNode->data;
        }
        else
        {
            TreeNode<int> *tempRoot=currNode;
            if(currNode->leftChild)
            {   currNode=currNode->leftChild;
                while(currNode->rightChild)
                { prev=currNode;currNode=currNode->rightChild;}
            }
            else if(currNode->rightChild)
            {   currNode=currNode->rightChild;
                while(currNode->leftChild)
                { prev=currNode;currNode=currNode->leftChild;}
            }
            else
            {
                if(prev->data > k)
                {prev->leftChild=NULL;}
                else
                {prev->rightChild=NULL;}
                delete currNode;currNode=NULL;NumOfNodes-- ;return; }
            
            if(!tempRoot->rightChild) //skew subtree
            {
                if( prev->data < tempRoot->data )
                { prev->rightChild=currNode; }
                else
                { prev->leftChild=currNode; }
            }
            else if(!tempRoot->leftChild)  //skew subtree
            {
                if( prev->data < tempRoot->data )
                { prev->rightChild=currNode; }
                else
                { prev->leftChild=currNode; }
            }
            else{
                if(prev->data > k)
                {prev->leftChild=NULL;}
                else
                {prev->rightChild=NULL;}
            }
            tempRoot->data=currNode->data;
            delete currNode;currNode=NULL;NumOfNodes--;return; } // when L equal to K case
        
    }while(currNode);return;
}



int BST::Least_Bound(int k)//find the smallest number bigger than k
{
    if(isEmpty())
    {
        cout<<"It’s empty tree"<<endl;
        return NULL; //If it is empty tree than return NULL
    }
    int rootValue; int L;
    L = rootValue = RootData(); // get the root data
    TreeNode<int> *currNode=new TreeNode<int>;
    currNode=root;
    do{
        if(k > rootValue)
        {
            currNode=currNode->rightChild; //traverse to left
            if(!currNode){ break; }
            L=rootValue=currNode->data;
        }
        else if(k < rootValue)
        {
            L=currNode->data;
            //make the record first, it’s previous root value in next step
            currNode=currNode->leftChild;    //traverse to right
            if(!currNode){  return L; }
            rootValue=currNode->data;
            if(k > rootValue ){ return L;  }
            /* when k is smaller than anyone in the tree or k is bigger than the new root, both will return previous root value */
            L=currNode->data;
        }
        else
        {   return L; } // when L equal to K case
        
    }while(currNode);
    
    cout<<"can’t find value"<<endl;  return INT_MIN;
}






int BST::Least_Combined(int k,TreeNode<int> *m,TreeNode<int> *n)
    //find the smallest sum of two number bigger than k
{
    if(isEmpty())
    {
        cout<<"It’s empty tree"<<endl;
        return NULL; //If it is empty tree than return NULL
    }
    Inorder(root);
    if(NumOfNodes<=1){cout<<"Just one nodes in the tree"<<endl;return NULL;}
    int largestSum=InorderArr[NumOfNodes-1].data+InorderArr[NumOfNodes-2].data;
    if(largestSum < k)
    { cout<<"can’t find the answer of min sum"<<endl;
        return INT_MIN;}
    if(largestSum ==k)
    {   *m=InorderArr[NumOfNodes-1];
        *n=InorderArr[NumOfNodes-2];
        return largestSum;}
    
    int leftBound;int rightBound;int rootPtr=0;
    for(int i=0;i<NumOfNodes;i++)
    { if(RootData()==InorderArr[i].data)
    { rootPtr=i;break;}
    }
    if(k>InorderArr[0].data+InorderArr[1].data)
    { if(rootPtr+2<=NumOfNodes-1)
    {   if(InorderArr[rootPtr+1].data+InorderArr[rootPtr+2].data >=k)
    {leftBound=0;rightBound=rootPtr+2;}
    else if(InorderArr[rootPtr-1].data+InorderArr[rootPtr].data >=k)
    {leftBound=0;rightBound=rootPtr;}
    else
    {leftBound=0;rightBound=NumOfNodes;}
    }
    else
    {leftBound=0;rightBound=NumOfNodes;}
    }
    else{ *m=InorderArr[1];*n=InorderArr[0];
        return InorderArr[1].data+InorderArr[0].data;
    }
    int MIN_Sum=INT_MAX;int sum=0;
    for(int i=leftBound;i<rightBound;i++)
    {
        for(int j=i+1;j<rightBound;j++)
        {
            sum=InorderArr[i].data+InorderArr[j].data;
            if(sum < MIN_Sum && sum >= k )
            {   MIN_Sum=sum;  *m=InorderArr[i]; *n=InorderArr[j];}
        }
        if(MIN_Sum == k){break;}
    }
    return MIN_Sum;
}
