#ifndef Queue_H
#define Queue_H
#include<stdio.h>
#include<stdlib.h>
#include "PLATFORM.h"
typedef struct{
void **Queue_Array;
uint32 Max_Size;
uint32 Element_Count;
sint32 Queue_Front;
sint32 Queue_Rear;
}Queue_DS;
typedef enum{
Queue_Ok,   //0
Queue_NOK,  //1
Queue_Full, //2
Queue_Empty, //3
Queue_NULL_Pointer //4
}Queue_Status;
Queue_DS *Create_Queue(uint32 Max_Size,Queue_Status *Status);
Queue_Status Enqueue(Queue_DS *Obj,void *item_ptr);
void *Dequeue(Queue_DS *Obj, Queue_Status *Status);
void *Queue_Rear(Queue_DS *Obj,Queue_Status *Status);
Queue_Status Destroy_Queue(Queue_DS *Obj);
Queue_Status Get_Queue_Count(Queue_DS *Obj,uint32 *Count);
void Queue_Display(Queue_DS *Obj);
#endif // Queue
