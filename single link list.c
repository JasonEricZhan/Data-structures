#include <stdio.h>
typedef struct node
{
    int a;
    int b;
    int c;
    struct node*next;   //self reference
}list;   //become the list until all above are done

list *Front;


list * createnode(int data)
{
    list * newNode = malloc(sizeof(list));
    newNode->c =data;
    newNode->next = NULL;
    return newNode; //return the pointer of data type newNode
} //use to create the first node 


list* insert(int a,int b,int c,list*first)
{
    list *newnode;
    newnode = malloc(sizeof(list));
    if(newnode == NULL)
    {
        printf("Fail");
        exit(1);//Allocate fail and exit the program and return 1
    }
    else
    {
        newnode->next=first;  //point to the head of link list
    }
    newnode->a = s;
    newnode->b = e;
    newnode->c= c;
    return newnode;
}
Front=insert(int a,int b,int c,Front) //insert to the front and front keep at the head of link list

list* search(int value,list *first)
{
    list *ptr;
    ptr = first;//searching from the first node
    while(ptr)
    {          //if not null and fit the condition then  return pointer
        if(condtion )
        {
            return ptr;  // if found then return the pointer
        }
        ptr= ptr->next;//if didn't then go to next position
    }
    return ptr;
}


void cleanall(list*first)
{
    list*t;
    t= first;
    while( t != NULL )
    {
        t= t->next;
        cleanall(t);
    }
    free(t);
}//free all the memory

