#ifndef STACK_DS_H
#define STACK_DS_H
#include<stdio.h>
#include<stdlib.h>
#include"PLATFORM.h"
#define Stack_Max_Size 5
typedef struct Stack_Ds{
    uint32 data[Stack_Max_Size]; //bigger of data written first in struct !!
    sint32 stack_pointer;  //points to last element of stack (top),its values from 0 to Max_Size-1  ,(index of array)
    //pointer =-1 when empty stack ,pointer =Max_Size-1 when stack is full !!
    //note that it's not a pointer its a variable but its name "Stack_pointer"!!
}Stack_Ds;
typedef enum stack_status
{
    Stack_Empty,  //0
    Stack_Full,   //1
    Stack_Not_Full //2
}stack_status;
return_status_t Stack_init(Stack_Ds* Obj);
stack_status stack_status_fun(Stack_Ds* Obj);
return_status_t Stack_push(Stack_Ds* Obj,sint32 top);
return_status_t Stack_pop(Stack_Ds* Obj,sint32 *Pop);
return_status_t Stack_top(Stack_Ds* Obj,sint32 *top);
return_status_t Stack_Size(Stack_Ds *Obj,uint32 *Stack_Size);
return_status_t Stack_display(Stack_Ds *Obj);
#endif // STACK_DS_H
