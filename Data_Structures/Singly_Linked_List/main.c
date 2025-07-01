#include <stdio.h>
#include <stdlib.h>
#include"Single_Linked_List.h"
int main()
{
    Node *Head=NULL;
    Delete_Node(Head);
    Head=Create_List(5);
    List_Display(Head);
    printf("=======================================\n");
    Delete_Node(Head);
    printf("=======================================\n");
    List_Display(Head);
    return 0;
}
