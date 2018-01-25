//
//  circularList.hpp
//  double_link_list
//
//  Created by Eric on 2017/10/25.
//  Copyright © 2017年 Eric. All rights reserved.
//

#ifndef circularList_hpp
#define circularList_hpp

#include <iostream>
#include "chainStack.hpp"





template<class type,class type2,class type3>
class circList:public chainQueue<type2>,stackList<type3>
{
    //template<class T>
public:
    //friend class chainNode;
    circList(){};
    //template<class type>
    circList(type data){
        chainNode<type> *link=new chainNode<type>;
        link->value=data;
        last=head=link->next=link;
    };
    //template<class type>
    void insertFront(type data){
        chainNode<type> *link=new chainNode<type>;
        link->value=data;
        link->next=head;
        last->next=head=link;
    };
    void reverse(){
        chainNode<type> *curr=head;chainNode<type> *prev=last;
        //last=head;
        do
        {
            chainNode<type> *temp=prev;
            prev=curr;
            curr=curr->next;
            prev->next=temp;
        }while(curr!=head);
        head=prev;
    };
    void show()
    {
        chainNode<type> *ptr=head;
        while(ptr->next!=head)
        {
            std::cout<<ptr->value<<std::endl;
            ptr=ptr->next;
        }
        std::cout<<ptr->value<<std::endl;
    };
    
    
private:
    //template<class type>
    chainNode<type> *head;
    chainNode<type> *last;
    //chainNode *head;
};

#endif /* circularList_hpp */
