#include <stdio.h>
#include <stdlib.h>
void Selectio_Sort_Algorithm(int *arr,int Size);
int main()
{
    int Data[6]={3,6,1,8,4,5};
    int Data_Check_Stability[10]={8,1,9,5,8,7,8,2,4,6};
    /*after 1st iteration :1,8,9,5,8,7,8,2,4,6
      after 2nd iteration :1,2,9,5,8,7,8,8,4,6
      after 3rd iteration :1,2,4,5,8,7,8,8,9,6
      after 4th iteration :1,2,4,5,8,7,8,8,9,6
      after 5th iteration :1,2,4,5,6,7,8,8,9,8 >>see the 6 and 8 was swapped but 8 does not came adjacent to 8's that are placed in index 6,7
      after 6th iteration :1,2,4,5,6,7,8,8,9,8
      after 7th iteration :1,2,4,5,6,7,8,8,9,8
      after 8th iteration :1,2,4,5,6,7,8,8,9,8
      after 9th iteration :1,2,4,5,6,7,8,8,8,9 /*done*/
    /********************************************************/
    /*Selectio_Sort_Algorithm(Data,6);
      for(int i=0;i<6;i++)
      printf(" %i ",Data[i]);*/
    printf("\n");
    Selectio_Sort_Algorithm(Data_Check_Stability,10);
   /* for(int i=0;i<7;i++)
        printf(" %i ",Data_Check_Stability[i]);*/
    return 0;
}
void Selectio_Sort_Algorithm(int *arr,int Size)
{
    int i=0,j=0,min_index=0,temp=0;
    for(i=0;i<Size-1;i++) //(n-1) iteration
    {
        min_index=i;
        for(j=i+1;j<=Size-1;j++)
        {
            if(arr[min_index]>arr[j])
            {
                min_index=j;
            }
            else
            {
                /*Nothing*/
            }
        } //now min_index is the index of minimum value
        temp=arr[i];
        arr[i]=arr[min_index];
        arr[min_index]=temp;
         for(int i=0;i<10;i++)
        printf(" %i ",arr[i]);
        printf("\n");
    }

}
