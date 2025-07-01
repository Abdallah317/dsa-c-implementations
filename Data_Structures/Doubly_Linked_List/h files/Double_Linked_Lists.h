#ifndef Double_Linked_Lists_H
#define Double_Linked_Lists_H
#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int Data;
    struct Node *Next;
    struct Node *Previous;
}Node;
void Insert_Node_At_Beginning(Node **List_Head,int *Data);
void Insert_Node_At_End(Node **List_Head,int *Data);
void Insert_Node_After(Node *List_Head,int *Data);
void Insert_Node_Before(Node **List_Head,int *Data);
void Insert_Node_Before_1(Node *List_Head,int *Data);
void List_Display(Node *List);
void Delete_Node_At_Beginning(Node **List_Head);
void Delete_Node_At_End(Node *List_Head);
void Delete_Node(Node *List_Head);
int Get_Length(Node *List_Head);
#endif
