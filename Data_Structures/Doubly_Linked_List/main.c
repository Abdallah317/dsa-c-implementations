#include <stdio.h>
#include <stdlib.h>
#include"Double_Linked_Lists.h"
int main()
{
    Node *Head=NULL;
    int *ptr=NULL;
    int arr[8]={42, 17, 89, 5, 63, 28,74,991};
    ptr=arr;
    Insert_Node_At_Beginning(&Head,ptr);
    for(int i=1;i<7;i++)
    {
        ptr=arr+i;
        Insert_Node_At_End(&Head,ptr);
    }
    List_Display(Head);
    printf("==================================\n");
    ptr=arr+7;
    //Insert_Node_Before(&Head,ptr);
    Insert_Node_Before_1(Head,ptr);
    List_Display(Head);
    printf("==================================\n");
    Delete_Node_At_Beginning(&Head);
    Delete_Node_At_End(Head);
    List_Display(Head);
    printf("==================================\n");
    Delete_Node(Head);
    List_Display(Head);
    return 0;
}
