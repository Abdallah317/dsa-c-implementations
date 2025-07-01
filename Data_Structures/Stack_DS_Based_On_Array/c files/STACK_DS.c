#include "STACK_DS.h"
stack_status stack_status_fun(Stack_Ds* Obj)
{
    stack_status status=Stack_Empty; //initialize
    if(Obj->stack_pointer==Stack_Max_Size-1)
    {
        status=Stack_Full;
    }
    else if(Obj->stack_pointer==-1)
    {
        status=Stack_Empty;
    }
    else
    {
        status=Stack_Not_Full;
    }
    return status;
}
return_status_t Stack_init(Stack_Ds* Obj)
{
    return_status_t status=R_NOK; //initialize
    if(Obj==NULL)
    {
    status=R_NOK;
    #ifdef Stack_Debug
    printf("Null Pointer Is Passed--> initialization of stack failed !\n");
    #endif
    }
    else
    {
    Obj->stack_pointer=-1;
    status=R_OK;
    }
    return status;
}
return_status_t Stack_push(Stack_Ds* Obj,sint32 top)
{
    return_status_t status=R_NOK; //initialize
    if((stack_status_fun(Obj)==Stack_Full)||(Obj==NULL))
    {
        status=R_NOK; //stack is full or Obj is NULL!
    }
    else
    {
        Obj->stack_pointer++;
        Obj->data[Obj->stack_pointer]=top;
        status=R_OK;
    }
    return status;
}
return_status_t Stack_pop(Stack_Ds* Obj,sint32 *Pop)
{
    return_status_t status=R_NOK; //initialize
    if((Obj==NULL) || (stack_status_fun(Obj)==Stack_Empty) ||(Pop==NULL))
    {
        #ifdef Stack_Debug
        printf("Stack is Empty Or one of the two pointers (Obj or Por) is NULL,cant't pop any value !!\n");
        #endif
        status=R_NOK;
        // stack is empty or Obj is NULL or Pop is NULL!!
    }
    else
    {
    *Pop=Obj->data[Obj->stack_pointer];
    Obj->stack_pointer--;
    status=R_OK;
    #ifdef Stack_Debug
    printf("Poped Value :%i , Top Value Now :%i\n",*Pop,Obj->data[Obj->stack_pointer]);
    #endif
    }
    return status;
}
return_status_t Stack_top(Stack_Ds* Obj,sint32 *top)
{
return_status_t status=R_NOK; //initialization
if((Obj==NULL)||(top==NULL)||(stack_status_fun(Obj)==Stack_Empty))
{
    status=R_NOK;
    #ifdef Stack_Debug
    printf("Stack Is Empty Or one of arguments is NULL Pointer !!\n");
    #endif
}
else
{
    *top=Obj->data[Obj->stack_pointer];
    status=R_OK;
}
return status;
}
return_status_t Stack_Size(Stack_Ds *Obj,uint32 *Stack_Size)
{
    return_status_t status=R_NOK; //initialize
    if((Obj==NULL)||(Stack_Size==NULL))
    {
        status=R_NOK;
    #ifdef Stack_Debug
    printf("NULL Pointer is Passed to one of the arguments of the function !!\n");
    #endif
    }
    else
    {
        status=R_OK;
        *Stack_Size=Obj->stack_pointer+1;
    }
    return status;
}
return_status_t Stack_display(Stack_Ds *Obj)
{
    return_status_t status=R_NOK; //initialize
    sint8 counter=0;
    if((Obj==NULL)||((stack_status_fun(Obj))==Stack_Empty))
    {
        status=R_NOK;
        #ifdef Stack_Debug
        printf("NULL Pointer is passed or stack is empty !!");
        #endif
    }
    else
    {
        printf("Stack Data : ");
        for(counter=Obj->stack_pointer;counter>=0;counter--)
        {
            printf("%i ",Obj->data[counter]);
        }
        printf("\n");
        status=R_OK;
    }
    return status;
}
