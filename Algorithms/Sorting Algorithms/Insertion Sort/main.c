#include <stdio.h>
#include <stdlib.h>
void Insertion_Sort(int *arr,unsigned int size);
int main()
{
    int Data[] = {42, -7, 19, 0, 85, -23, 16, 5, 91, 3};
    int i=0;
    Insertion_Sort(Data,10);
    printf("Sorted Data : ");
    for(i=0;i<10;i++)
    {
        printf("%i ",Data[i]);
    }
    printf("\n");
    return 0;
}
void Insertion_Sort(int *arr,unsigned int size)
{
    int i=0,key=0,k=0;
    for(i=0;i<size-1;i++) //(n-1) iterations
    {
        key=arr[i+1];
            k=i;
            while((key<arr[k])&&(k>=0))
            {
                arr[k+1]=arr[k];
                k--;
            }
            arr[k+1]=key; //to compensate last k-- that exited from loop condition !!
    }
}

