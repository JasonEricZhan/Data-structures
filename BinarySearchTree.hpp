
//
//  BinarySearchTree.hpp
//  Trees
//
//  Created by Eric on 2017/12/20.
//  Copyright © 2018年 Eric. All rights reserved.
//


#ifndef BinarySearchTree_hpp
#define BinarySearchTree_hpp

#include <iostream>

using namespace std;


template<class T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *leftChild; TreeNode<T> *rightChild;
};



class BST
{
public:
    TreeNode<int> *root;
    BST(){ root=NULL;};
    BST(TreeNode<int> *k,int number){ root=k;NumOfNodes=number;};
    int RootData(){return root->data;};
    int findMin();
    bool isEmpty(){return root==NULL;};
    int Least_Bound(int k);
    int Least_Combined(int k,TreeNode<int> *m,TreeNode<int> *n);
    void Insert(int k);
    void Delete(int k);
    void Inorder(TreeNode<int> *Node);
    void Inorder_sub(TreeNode<int> *Node);
    void PutNode(TreeNode<int> *Node);
    void CountNodes(void);
    int NumOfNodes=0;
    void setArray(void)
    { InorderArr=new TreeNode<int>[NumOfNodes];counter=0;};
    int counter;
    TreeNode<int> *InorderArr;
    int m;int n;
    int Least_Combine(int k);
    
};


#endif /* BinarySearchTree_hpp */
