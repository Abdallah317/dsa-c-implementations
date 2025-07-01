#include <stdio.h>
#include <stdlib.h>
int Binary_Search(int *arr,unsigned int Start_Index,unsigned int End_Index,int value);
int Binary_Search_Recursive(int *arr,unsigned int Start_Index,unsigned int End_Index,int value);
int main()
{
    int Data[10]={-142,-3,-2,-1,1,2,3,55,66,77}; //sorted array
    printf("Found At Index : %i\n",Binary_Search(Data,0,10-1,66));
    printf("Found At Index : %i\n",Binary_Search(Data,0,10-1,-142));
    printf("Found At Index : %i\n",Binary_Search(Data,0,10-1,-1));
    printf("=====================\n");
    printf("Found At Index : %i\n",Binary_Search_Recursive(Data,0,10-1,3));
    printf("Found At Index : %i\n",Binary_Search_Recursive(Data,0,10-1,55));
    printf("Found At Index : %i\n",Binary_Search_Recursive(Data,0,10-1,-3));

    return 0;
}
int Binary_Search(int *arr,unsigned int Start_Index,unsigned int End_Index,int value)
{
    unsigned int Mid_Index=0;
    while(Start_Index<=End_Index)
    {
        Mid_Index=Start_Index+((End_Index-Start_Index)/2);
        if(value==arr[Mid_Index])
        {
            return Mid_Index;
        }
        else if(value>arr[Mid_Index])
        {
            //remove lhs
            Start_Index=Mid_Index+1;
        }
        else
        {
            //remove rhs
            End_Index=Mid_Index-1;
        }
    }
    return -1;
}
int Binary_Search_Recursive(int *arr,unsigned int Start_Index,unsigned int End_Index,int value)
{
    unsigned int Mid_Index=0;
    while(Start_Index<=End_Index)
    {
        Mid_Index=Start_Index+((End_Index-Start_Index)/2);
        if(value==arr[Mid_Index])
        {
            return Mid_Index;
        }
        else if(value>arr[Mid_Index])
        {
            //remove lhs
            return Binary_Search_Recursive(arr,Mid_Index+1,End_Index,value);
        }
        else
        {
            //remove rhs
            return Binary_Search_Recursive(arr,Start_Index,Mid_Index-1,value);
        }
    }
    return -1;
}
