#include "Queue.h"

Queue_DS *Create_Queue(uint32 Max_Size, Queue_Status *Status)
{
    Queue_DS *Queue = NULL;

    if (Status != NULL) // First: check if Status is not NULL
    {
        *Status = Queue_NOK; // Default status

        Queue = (Queue_DS *)malloc(sizeof(Queue_DS));
        if (Queue == NULL)
        {
            *Status = Queue_NULL_Pointer;
        }
        else
        {
            Queue->Queue_Array = (void **)calloc(Max_Size, sizeof(void *));
            if (Queue->Queue_Array == NULL)
            {
                free(Queue);
                Queue = NULL;
                *Status = Queue_NOK;
            }
            else
            {
                // Allocated
                Queue->Element_Count = 0;
                Queue->Max_Size = Max_Size;
                Queue->Queue_Front = -1;
                Queue->Queue_Rear = -1;
                *Status = Queue_Ok;
            }
        }
    }
    // else: Status is NULL, can't assign anything

    return Queue;
}
Queue_Status Enqueue(Queue_DS *Obj, void *item_ptr)
{
    Queue_Status Status = Queue_NOK; // Default Value
    if ((Obj == NULL) || (item_ptr == NULL))
    {
        Status = Queue_NULL_Pointer;
    }
    else
    {
        if(Obj->Element_Count==Obj->Max_Size)
        {
            //Queue Is FULL
            Status=Queue_Full;
        }
        else
        {
             if(Obj->Element_Count==0)
                {
                    Obj->Queue_Front=0;
                }

            if(Obj->Queue_Rear == Obj->Max_Size-1){
                Obj->Queue_Rear = 0;
            }
            else
            {
                Obj->Queue_Rear++;
            }

            *(Obj->Queue_Array+Obj->Queue_Rear)=item_ptr;
            Obj->Element_Count++;
            Status=Queue_Ok;
        }
    }
    return Status;
}
void *Dequeue(Queue_DS *Obj, Queue_Status *Status)
{
    void *Element = NULL;

    if ((Obj == NULL) || (Status == NULL))
    {
        if (Status != NULL)
        {
            *Status = Queue_NULL_Pointer;
        }
        Element = NULL;
    }
    else
    {
        if (Obj->Element_Count == 0)
        {
            *Status = Queue_Empty;
            Element = NULL;
        }
        else
        {
            Element = Obj->Queue_Array[Obj->Queue_Front];

            // Move front forward (circular logic)
            if (Obj->Queue_Front == Obj->Max_Size - 1)
            {
                Obj->Queue_Front = 0;
            }
            else
            {
                Obj->Queue_Front++;
            }

            Obj->Element_Count--;

            if (Obj->Element_Count == 0)
            {
                // Queue became empty, reset positions
                Obj->Queue_Front = -1;
                Obj->Queue_Rear = -1;
            }
            else
            {
                // Do nothing
            }

            *Status = Queue_Ok;
        }
    }

    return Element;
}
void *Queue_Rear(Queue_DS *Obj,Queue_Status *Status)
{
    void *Rear=NULL;
    if((Obj==NULL))
    {
        if(Status!=NULL)
        {
            *Status=Queue_NULL_Pointer;
        }
        Rear=NULL;
    }
    else
    {
        if(Obj->Element_Count==0)
        {
            Rear=NULL;
            *Status=Queue_Empty;
        }
        else
        {
            Rear=*(Obj->Queue_Array+Obj->Queue_Rear);
            *Status=Queue_Ok;
        }
    }
    return Rear;
}
Queue_Status Destroy_Queue(Queue_DS *Obj)
{
    Queue_Status Status=Queue_NOK; //initialization
    if(Obj==NULL)
    {
        Status=Queue_NULL_Pointer;
    }
    else
    {
        free(Obj->Queue_Array);
        free(Obj);
        Status=Queue_Ok;
    }
    return Status;
}
Queue_Status Get_Queue_Count(Queue_DS *Obj,uint32 *Count)
{
    Queue_Status Status=Queue_NOK; //initialization
    if((Obj==NULL) || (Count ==NULL))
    {
        Status=Queue_NULL_Pointer;
    }
    else
    {
        *Count=Obj->Element_Count;
        Status=Queue_Ok;
    }
    return Status;

}
void Queue_Display(Queue_DS *Obj)
{
    if (Obj == NULL)
    {
        printf("NULL Pointer Passed!\n");
    }
    else
    {
        if (Obj->Element_Count == 0)
        {
            printf("Queue Is Empty!\n");
        }
        else
        {
            printf("\n====================================================================\n");
            printf("Queue Data: ");

            sint32 index = Obj->Queue_Front;
            for (sint32 counter = 0; counter < Obj->Element_Count; counter++)
            {
                printf("%.3f   ", *((float *)(Obj->Queue_Array[index])));

                index++; // Move to next index
                if (index == Obj->Max_Size) // Wrap around manually
                {
                    index = 0;
                }
            }

            printf("\n====================================================================\n");
        }
    }
}




