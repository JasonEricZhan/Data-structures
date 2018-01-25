//
//  doubleLinkList.hpp
//  double_link_list
//
//  Created by Eric on 2017/10/20.
//  Copyright © 2017年 Eric. All rights reserved.
//

#ifndef doubleLinkList_hpp
#define doubleLinkList_hpp

#include <stdio.h>
#include <iostream>
class node
{
public:
    friend class doubleLinkList;
private:
    node *prev;node *next;
    int value;
};


class doubleLinkList
{
public:
    doubleLinkList(){head=last=NULL;};
    doubleLinkList(int first_data){
        node *link = new node;
        link->value=first_data;
        link->next=link->prev=NULL;
        head=last=link;
    }
    void insertFirst( int data) {
        
        //create a link
        node *link = new node;
        link->value = data;
        
        if(!head) {
            
            last = link;
        } else {
            
            head->prev = link;
        }
        
        
        link->next = head;
        
       
        head = link;
    }
    
    void insertLast( int data) {
        
        //create a link
        node *link = new node;
        link->value = data;
        
        if(!last) {
            
            head = link;
        } else {
            
            last->next = link;
            
        }
        
        
        link->prev = last;
        
        
        last = link;
    }
    
    
    int deleteFirst() {
        
        //create a link
        int data=NULL;
        
        if(!head) {
            return data;
        } else {
            data=head->value;
            node *temp=head;
            head=head->next;
            delete temp;
        }
        return data;
    }

    
    int deleteLast() {
        
        //create a link
        int data=NULL;
        
        if(!last) {
            return data;
        } else {
            data=last->value;
            node *temp=last;
            last=last->prev;
            delete temp;
        }
        return data;
    }

    
private:
    node *head;
    node *last;
    
};
#endif /* doubleLinkList_hpp */
