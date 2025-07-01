    #include <stdio.h>
    #include <stdlib.h>
    #include "PLATFORM.h"
    #include "Queue.h"
    int main()
    {
        Queue_Status Status = Queue_NOK;
        Queue_DS *Queue = NULL;

        Queue = Create_Queue(5, &Status);
        if (Status == Queue_Ok)
        {
            printf("Queue Created Successfully \n");
        }
        else
        {
            printf("Error While Creating Queue!\n");

        }

        // Enqueue multiple float values (each with dynamic memory)
        float values[] = {9.95, 55.745, 101.2, 204.43, 995.96, 346.96};

        for (int i = 0; i < sizeof(values) / sizeof(values[0]); i++)
        {
            float *ptr = (float *)malloc(sizeof(float));
            if (ptr == NULL)
            {
                printf("Memory allocation failed!\n");
                continue;
            }

            *ptr = values[i];
            Status = Enqueue(Queue, ptr);

            if (Status == Queue_Ok)
            {
                printf("Enqueued %.3f Successfully!\n", *ptr);
            }
            else if (Status == Queue_Full)
            {
                printf("Queue Is Full! Could not enqueue %.3f\n", *ptr);
                free(ptr); // free the memory if not enqueued
            }
        }
        // Display queue contents
        Queue_Display(Queue);
        void* Dequeue_ptr=NULL;
        for(int i=0;i<2;i++)
        {
            Dequeue_ptr=Dequeue(Queue,&Status);
            if(Status==Queue_Ok)
            {
                printf("Dequeued %.3f Successfully!\n",*((float *) Dequeue_ptr));
            }
            else if(Status==Queue_Empty)
                printf("Queue Is Empty Could not dequeue \n");

        }

    // Display queue contents
        Queue_Display(Queue);
        for(int i=0;i<2;i++)
        {
            float *ptr=(float *)malloc(sizeof(float));
            *ptr=values[i+4];   // when i=0 >>*ptr=995.960 ,when i=1 >>*ptr=346.960
            Status=Enqueue(Queue,ptr);
            if(Status==Queue_Ok)
            {
                printf("Enqueued %.3f Successfully!\n", *ptr);
            }
            else if(Status==Queue_Full)
            {
                printf("Queue Is Full! Could not enqueue %.3f\n", *ptr);
                free(ptr); // free the memory if not enqueued
            }
        }
        Queue_Display(Queue);
        return 0;
    }
