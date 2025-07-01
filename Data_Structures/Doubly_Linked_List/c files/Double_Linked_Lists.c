#include"Double_Linked_Lists.h"
void Insert_Node_At_Beginning(Node **List_Head,int *Data)
{
    Node *Temp=(Node *)malloc(sizeof(Node));
    if(Temp==NULL)
    {
        printf("can't allocate new node !\n");
    }
    else
    {
       Temp->Data=*Data;
       if(*List_Head==NULL)
       {//Empty List
           Temp->Next=NULL;
           Temp->Previous=NULL;
           *List_Head=Temp;
       }
       else
       {
           Temp->Next=*List_Head;
           Temp->Previous=NULL;
           (*List_Head)->Previous=Temp;
           *List_Head=Temp;
       }
    }
}
void Insert_Node_At_End(Node **List_Head,int *Data)
{
    Node *Temp=(Node *) malloc(sizeof(Node));
    if(Temp==NULL)
    {
        printf("can't allocate new node!\n");
    }
    else
    {
        Temp->Data=*Data;
        if((*List_Head)==NULL)
        {
            Temp->Next=NULL;
            Temp->Previous=NULL;
            *List_Head=Temp;
        }
        else
        {
        Node *Last=*List_Head;
        while(Last->Next!=NULL)
        {
            Last=Last->Next;
        }
        Last->Next=Temp;
        Temp->Previous=Last;
        Temp->Next=NULL;
        }

    }
}
void Insert_Node_After(Node *List_Head,int *Data)
{
    Node *Temp=(Node *) malloc(sizeof(Node));
    if(Temp==NULL)
    {
        printf("can't allocate new node !\n");
    }
    else
    {
        Node *Position_ptr=List_Head;
        int Node_Position=0,Length=Get_Length(List_Head),Node_Counter=1;
        printf("Enter the position after which you want to insert the new node (position starts from 1): ");
        scanf("%i",&Node_Position);
        if(Node_Position>Length)
        {
            printf("invalid position!! \n");
        }
        else
        {
            Temp->Data=*Data;
            while(Node_Counter<Node_Position)
        {
            Position_ptr=Position_ptr->Next;
            Node_Counter++;
        }
        Temp->Next=Position_ptr->Next;
        Position_ptr->Next=Temp;
        Temp->Previous=Position_ptr;
        }

    }
}
void Insert_Node_Before(Node **List_Head,int *Data)
{
    Node *Temp=(Node *) malloc(sizeof(Node));
    if(Temp==NULL)
    {
        printf("can't allocate new node !\n");
    }
    else
    {
        Node *Position_ptr=*List_Head;
        Temp->Data=*Data;
        int Node_Position=0,Counter=1,Length=Get_Length(*List_Head);
        printf("Enter the position before which you want to insert the new node (position starts from 1): ");
        scanf("%i",&Node_Position);
        if(Node_Position>Length)
            printf("Invalid Position \n");
        else
        {
            while(Counter<Node_Position)
            {
                Position_ptr=Position_ptr->Next;
                Counter++;
            }
            Temp->Previous=Position_ptr->Previous;
            (Position_ptr->Previous)->Next=Temp;
            Temp->Next=Position_ptr;
            Position_ptr->Previous=Temp;
        }

    }
}
void List_Display(Node *List)
{
    printf("List Data : ");
    while(List!=NULL)
    {
        printf("%i ",List->Data);
        List=List->Next;
    }
    printf("\n");
}
int Get_Length(Node *List_Head)
{
    int Size=0;
    while(List_Head!=NULL)
    {
        Size++;
        List_Head=List_Head->Next;
    }
    return Size;
}
void Insert_Node_Before_1(Node *List_Head,int *Data)
{
    Node *Temp=(Node *) malloc(sizeof(Node));
    if(Temp==NULL)
    {
        printf("can't allocate new node !\n");
    }
    else
    {
        Temp->Data=*Data;
        int Node_Position=0,Counter=1,Length=Get_Length(List_Head);
        printf("Enter the position before which you want to insert the new node (position starts from 1): ");
        scanf("%i",&Node_Position);
        if(Node_Position>Length)
            printf("Invalid Position \n");
        else
        {
            while(Counter<Node_Position)
            {
                List_Head=List_Head->Next;
                Counter++;
            }
            Temp->Previous=List_Head->Previous;
            (List_Head->Previous)->Next=Temp;
            Temp->Next=List_Head;
            List_Head->Previous=Temp;
        }

    }
}
void Delete_Node_At_Beginning(Node **List_Head)
{
    if(*List_Head==NULL)
    {
        printf("Empty List Can't Delete any node !\n");
    }
    else
    {
        *List_Head=(*List_Head)->Next;
        free((*List_Head)->Previous);
        (*List_Head)->Previous=NULL;
    }
}
void Delete_Node_At_End(Node *List_Head)
{
    if(List_Head==NULL)
    {
        printf("Empty List Can't Delete any node !\n");
    }
    else
    {
        while(List_Head->Next!=NULL)
    {
        List_Head=List_Head->Next;
    }
    (List_Head->Previous)->Next=NULL;
    List_Head->Previous=NULL;
    free(List_Head);
    }

}
void Delete_Node(Node *List_Head)
{
    if(List_Head==NULL)
    {
        printf("Empty List Can't Delete any Node !\n");
    }
    else
    {
        int Node_Position=0,Length=Get_Length(List_Head),Node_Counter=1;
        printf("Enter Position of Node to Be Deleted (First Position =1 ) : ");
        scanf("%i",&Node_Position);
        if(Node_Position>Length)
        {
            printf("Invalid Position !\n");
        }
        else
        {
            while(Node_Counter<Node_Position)
            {
                List_Head=List_Head->Next;
                Node_Counter++;
            }
            (List_Head->Previous)->Next=List_Head->Next;
            (List_Head->Next)->Previous=List_Head->Previous;
            List_Head->Next=NULL;
            List_Head->Previous=NULL;
            free(List_Head);
        }
    }
}
