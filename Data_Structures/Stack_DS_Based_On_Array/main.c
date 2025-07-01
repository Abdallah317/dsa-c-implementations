#include <stdio.h>
#include <stdlib.h>
#include"PLATFORM.h"
#include"STACK_DS.h"

Stack_Ds St1;
int main()
{
    uint8 i=1;
    sint32 Pop=0;
    if(Stack_init(&St1)==R_OK)
    {
        printf("Stack Is Initialized Successfully !!\n");
    }
    else
    {
        printf("Stack Is Not Initialized !!\n");
    }
    while(1){
    if(Stack_push(&St1,i*11)==R_OK)
    {
        printf("Added !!\n");
    }
    else
    {
        printf("Stack Is Full !\n");
        break;
    }
    i++;
    }
    if(Stack_display(&St1)==R_OK)
    {
        //done!!
    }
    uint32 Size=0;
    if(Stack_Size(&St1,&Size)==R_OK);
    {
        printf("Stack Size : %i\n",Size);
    }
    while(1){
    if(Stack_pop(&St1,&Pop)==R_OK)
    {
        printf("Poped Value : %i \n",Pop);
        if(Stack_Size(&St1,&Size)==R_OK);
    {
        printf("Stack Size : %i\n",Size);
    }
    }
    else
    {
        printf("Stack Is Empty !!\n");
        break;
    }
    }
    return 0;
}
