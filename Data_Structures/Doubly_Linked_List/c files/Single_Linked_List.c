#include "Single_Linked_List.h"

void Insert_Node_At_Beginning(Node **List_Head)
{
    Node *Temp = (Node *)malloc(sizeof(Node));
    if (Temp == NULL)
    {
        // Do Nothing
    }
    else
    {
        printf("Enter Node Data : ");
        scanf("%i", &(Temp->Node_Data));
        if (*List_Head == NULL)
        {
            Temp->Node_Link = NULL;
            *List_Head = Temp;
        }
        else
        {
            Temp->Node_Link = *List_Head;
            *List_Head = Temp;
        }
    }
}

void Insert_Node_At_End(Node **List_Head)
{
    Node *Temp = (Node *)malloc(sizeof(Node));
    Node *Last_Node = NULL;
    if (Temp == NULL)
    {
        // Do Nothing
    }
    else
    {
        printf("Enter Node Data : ");
        scanf("%i", &(Temp->Node_Data));
        Temp->Node_Link = NULL;
        if (*List_Head == NULL)
        {
            *List_Head = Temp;
        }
        else
        {
            Last_Node = *List_Head;
            while (Last_Node->Node_Link != NULL)
            {
                Last_Node = Last_Node->Node_Link;
            }
            Last_Node->Node_Link = Temp;
        }
    }
}

void Insert_Node_After(Node *List_Head)
{
    Node *After = NULL, *Temp = NULL;
    int Node_Position = 0, Node_Counter = 0, List_Length = 0;
    printf("Enter the position of node (first node position = 1): ");
    scanf("%i", &Node_Position);
    List_Length = Get_Length(List_Head);
    if (Node_Position > List_Length)
    {
        printf("Invalid index, maximum index is %i", List_Length);
    }
    else
    {
        After = List_Head;
        while (Node_Counter < Node_Position)
        {
            Node_Counter++;
            After = After->Node_Link;
        }
        Temp = (Node *)malloc(sizeof(Node));
        if (Temp == NULL)
        {
            // Do Nothing
        }
        else
        {
            printf("Enter the data of Node :");
            scanf("%i", &Temp->Node_Data);

            Temp->Node_Link = After->Node_Link;
            After->Node_Link = Temp;
        }
    }
}

unsigned int Get_Length(Node *List_Head)
{
    unsigned int Length = 0;
    while (List_Head != NULL && List_Head->Node_Link != NULL)
    {
        Length++;
        List_Head = List_Head->Node_Link;
    }
    if (List_Head != NULL) // to count the last node
        Length++;
    return Length;
}

void Delete_Node_At_Beginning(Node **List_Head)
{
    Node *Temp = NULL;
    if (*List_Head == NULL)
    {
        printf("List Is Empty!\n");
    }
    else
    {
        Temp = *List_Head;
        *List_Head = (*List_Head)->Node_Link;
        Temp->Node_Link = NULL;
        free(Temp);
    }
}

void Delete_Node(Node *List_Head)
{
    int Node_Position = 0, length = Get_Length(List_Head), Node_Counter = 1;
    Node *Temp = NULL, *Temp_Next = NULL;
    if (List_Head == NULL)
    {
        printf("List Is Empty!\n");
    }
    else
    {
        printf("Enter index of Node to be deleted (first node index=1) :");
        scanf("%i", &Node_Position);
        if ((length == 1) || (Node_Position > length))
        {
            if (length == 1)
            {
                printf("Please Use Delete At Beginning \n");
            }
            else
            {
                printf("Invalid Node Position, Maximum Position: %i", length);
            }
        }
        else
        {
            Temp = List_Head;
            while (Node_Counter < (Node_Position - 1))
            {
                Node_Counter++;
                Temp = Temp->Node_Link;
            }
            Temp_Next = Temp->Node_Link;
            Temp->Node_Link = Temp_Next->Node_Link;
            Temp_Next->Node_Link = NULL;
            free(Temp_Next);
        }
    }
}

void List_Display(Node *List_Head)
{
    Node *Temp = List_Head;
    if (Temp == NULL)
    {
        printf("List Is Empty!!\n");
    }
    else
    {
        printf("List Data: ");
        while (Temp != NULL)
        {
            printf("%i ", Temp->Node_Data);
            Temp = Temp->Node_Link;
        }
        printf("\n");
    }
}
Node *Create_List(unsigned int Size)
{
    Node *Head=NULL;
    int i=0;
    Insert_Node_At_Beginning(&Head);
    for(i=1;i<Size;i++)
    {
        Insert_Node_At_End(&Head);
    }
    return Head;
}
