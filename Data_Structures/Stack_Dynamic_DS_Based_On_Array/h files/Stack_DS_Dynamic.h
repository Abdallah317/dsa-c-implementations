#ifndef Stack_DS_Dynamic
#define Stack_DS_Dynamic
#include<stdio.h>
#include<stdlib.h>
#include "PLATFORM.h"
typedef struct Stack_Ds_dynamic
{
void **Stack_Array;//points to the array that allocated in the heap ,pointer to void pointers ,why void pointer ? to can store different data type elements !
uint32 Element_Count;  //has the actual number of elements in the stack
uint32 Stack_Max_Size; //has the maximum number of elements in the stack
sint32 Stack_Top;      //has the index of the top element  in the stack

}Stack_Ds_dynamic;
typedef enum Stack_Status
{
    Stack_NOK=0,          //Stack Operation Not performed Successfully
    Stack_OK,             //stack Operation performed Successfully
    Stack_FULL,           //Stack is FULL
    Stack_Empty,          //Stack is Empty
    Stack_NULL_Pointer    //NULL Pointer passed to the Stack Operations
}Stack_Status;
Stack_Ds_dynamic *Create_Stack(uint32 Max_Size,Stack_Status *Status);
Stack_Ds_dynamic *Destroy_Stack(Stack_Ds_dynamic *Obj,Stack_Status *Status);
Stack_Status Stack_Push(Stack_Ds_dynamic *Obj,void *item_ptr);
void *Stack_Pop(Stack_Ds_dynamic *Obj,Stack_Status *Status);
void *Stack_Top(Stack_Ds_dynamic *Obj,Stack_Status *Status);
Stack_Status Stack_Count(Stack_Ds_dynamic *Obj,uint32 *Element_Count);
#endif // Stack_DS_Dynamic
