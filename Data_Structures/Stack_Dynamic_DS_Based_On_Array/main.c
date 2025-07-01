#include <stdio.h>
#include <stdlib.h>
#include "Stack_DS_Dynamic.h"
#include "PLATFORM.h"
Stack_Ds_dynamic *St1=NULL;
Stack_Status Status=Stack_NOK; //initialize
char Var1='z';
float Var2=2.55;
uint16 Var3=2;
int main()
{
    St1=Create_Stack(5,&Status);
    void *Pop=NULL;
    if(Status==Stack_OK)
    {
        printf("Stack Created !\n");
    }
    else
    {
        printf("there is an error while creating Stack!\n");
    }
    if(Stack_Push(St1,&Var1)==Stack_OK)
        printf("Pushed !\n");
    if(Stack_Push(St1,&Var2)==Stack_OK)
        printf("Pushed !\n");
    if(Stack_Push(St1,&Var3)==Stack_OK)
        printf("Pushed !\n");
        if(Stack_Push(St1,&Var3)==Stack_OK)
        printf("Pushed !\n");
        if(Stack_Push(St1,&Var3)==Stack_OK)
        printf("Pushed !\n");
        if(Stack_Push(St1,&Var3)==Stack_OK)
        printf("Pushed !\n");
        else
            printf("Status =%i\n",Stack_Push(St1,&Var3));  //will give 2 >>>Stack_IS FULL !!
             printf("=============================================\n");
             void *top=Stack_Top(St1,&Status);
             if(Stack_OK==Status)
             {
                 printf("top :%i\n",*((uint16 *)top)); //Var3 >>>=2
             }

             printf("=============================================\n");
        Pop=Stack_Pop(St1,&Status);
        if(Status==Stack_OK)
        {
            printf("Value %i Is Poped!!\n",*((uint16 *)Pop));
        }
         Pop=Stack_Pop(St1,&Status);
        if(Status==Stack_OK)
        {
            printf("Value %i Is Poped!!\n",*((uint16 *)Pop));
        }
         Pop=Stack_Pop(St1,&Status);
        if(Status==Stack_OK)
        {
            printf("Value %i Is Poped!!\n",*((uint16 *)Pop));
        }
         Pop=Stack_Pop(St1,&Status);
        if(Status==Stack_OK)
        {
            printf("Value %f Is Poped!!\n",*((float *)Pop));
        }
        Pop=Stack_Pop(St1,&Status);
        if(Status==Stack_OK)
        {
            printf("Value %c Is Poped!!\n",*((char *)Pop));
        }
        Pop=Stack_Pop(St1,&Status);
        if(Status==Stack_OK)
        {
            printf("Value %c Is Poped!!\n",*((char *)Pop));
        }
        else
        {
            printf("Status =%i\n",Status);  // will print 3 >>>Stack_Empty
        }

            printf("=============================================\n");
    if(NULL==Destroy_Stack(St1,&Status))
    {
        printf("Stack Destroyed !\n");
    }
    else
    {
        printf("there is an error while destroying Stack!\n");
    }
    return 0;
}
