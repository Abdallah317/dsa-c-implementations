#ifndef Single_Linked_List_H
#define Single_Linked_List_H
#include<stdio.h>
#include<stdlib.h>
typedef struct
{
    unsigned int Node_Data;
    struct Node *Node_Link;
}Node;
void Insert_Node_At_Beginning(Node **List_Head);
void Insert_Node_At_End(Node **List_Head);
void Insert_Node_After(Node *List_Head);
unsigned int Get_Length(Node *List_Head);
void Delete_Node_At_Beginning(Node **List_Head);
void Delete_Node(Node *List_Head);
Node *Create_List(unsigned int Size);
#endif
