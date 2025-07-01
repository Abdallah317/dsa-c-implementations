#include <stdio.h>
#include <stdlib.h>
void Bubble_Sort(int *arr,unsigned int size);
void Array_Print(int *arr,unsigned int size);
int main()
{
    int Data[10] = {87,462,6235,12,945,308,731,1920,5,678};
    Bubble_Sort(Data,10);
    printf("\nSorted Array : ");
    for(int i=0;i<10;i++)
    {
        printf("%i ",Data[i]);
    }
    printf("\n");
    return 0;
}
void Bubble_Sort(int *arr,unsigned int size)
{
    unsigned char sort_flag=0;
    int i=0,j=0,temp=0;
    for(i=0;i<size-1;i++) //(n-1) iterations
    {
        for(j=0;j<=size-2-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                sort_flag=1;
            }

        }
        if(sort_flag==0)
        {
            return;
        }
        printf("%i iteration \n",i+1);
        Array_Print(arr,10);
        printf("\n\n\n\n\n");
    }
}
void Array_Print(int *arr,unsigned int size)
{
   for(int i=0;i<size;i++)
    {
        printf("%i ",arr[i]);
    }
}
