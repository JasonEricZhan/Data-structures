//
//  chain_list.hpp
//  double_link_list
//
//  Created by Eric on 2017/10/22.
//  Copyright © 2017年 Eric. All rights reserved.
//

#ifndef chain_Queue_hpp
#define chain_Queue_hpp

//#include <stdio.h>
#include <iostream>

template<class type>
class chainNode
{
public:
    template<class type2>
    friend class stackList;
    template<class type3,class type4,class type5>
    friend class circList;

    
protected:
   chainNode *next;
   type value;
};



template<class type>
struct Node
{
    Node *next;
    type value;
    
};


template<class type>
class chainQueue
{
    //template<class T>
public:
    //friend class chainNode;
    chainQueue(){};
    //template<class type>
    chainQueue(type data):capacity(data){
        Node<type> *link=new Node<type>;
        link->value=data;
        head=link;
        link->next=0;

    };
    //template<class type>
    void insertFront(type data){
        Node<type> *link=new Node<type>;
        link->value=data;
        link->next=head;
        head=link;
    };
    Node<type> *top(){
        return head;
    };
    void reverse(){
        Node<type> *curr=head;Node<type> *prev=0;
        //last=head;
        while(!curr)
        {
            Node<type> *temp=prev;
            prev=curr;
            curr=curr->next;
            prev->next=temp;
        }
        head=prev;
    };
    void show()
    {
        Node<type> *ptr=head;
        while(ptr->next)
        {
            std::cout<<ptr->value<<std::endl;
            ptr=ptr->next;
        }
        std::cout<<ptr->value<<std::endl;
    };
    
    
private:
    //template<class type>
    Node<type> *head;
    Node<type> *last;
    //int stackCapacity;
    int capacity;
    //chainNode *head;
};




#endif /* chain_list_hpp */
