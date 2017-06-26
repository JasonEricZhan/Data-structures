list* push(int a,int b,int c,list*first)//push the data into the stack
{
    list *newnode;
    newnode = malloc(sizeof(list));
    //Put the new data
    newnode->a = a;
    newnode->b = b;
    newnode->c= c;
    if(!newnode) // if the new pointer is null then it is fail to allocate memory
    {
        printf("Fail to allocate memory");
        exit(1);//unusual exit out the program
    }
    else
    {
        newnode->next=first;//The new node point to the old head of link list
    }
    return newnode; //return the new node pointer
    
}



================================================
//Wrong:
list *list
pop(list);
list* pop(list *first)//Pop out the record data
{
    list*t;
    //make the new node to store the data temporarily
    //list*data=malloc(sizeof(list)); //
    t=first;
    //copy the data
    /*data->start=first->start;
    data->end=first->end;
    data->maxvalue=first->maxvalue;
    data->next=NULL;*/
    if(t)
    {
        first=first->next; this will not change list position only: list=pop(list);
    }
    //free(t);//Free the node
    return t;
}
//Ex: call by address
int a,b;
void swap(*a,*b)
{
    int temp=*a;
    *a=*b;
    temp=*b;
}
swap(&a,&b);//changing the value by calling variable's address
//so must call out of address
=====================================================

list* pop(int *a,int *b ,int *c,list *first)//Pop out the data
{
    list*t;
    //make temporary pointer point to the first node
    t=first;
    //Copy the data to input pointer's content
    *a=first->start;
    *b=first->end;
    *c=first->sum;
    //The pointer go to next position
    first = first->next;
    free(t);//Free the allocated memory space which t points to
    return first; //return the next pointer
}
list*Top
int a,b,c;
Top=pop(&a,&b ,&c,Top)






