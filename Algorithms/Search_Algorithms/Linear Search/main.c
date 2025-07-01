#include <stdio.h>
#include <stdlib.h>
int Linear_Search_1(int *arr,int Value,unsigned int Size);
int Linear_Search_Improvement(int *arr,int Value,unsigned int Size);
int main()
{
    int Data[11]={-1,2,42,12,22,-14,-114,758,-142,199,50};
    printf("Index : %i\n",Linear_Search_1(Data,-142,11));
    printf("Index : %i\n",Linear_Search_Improvement(Data,199,11));
    return 0;
}
int Linear_Search_1(int *arr,int Value,unsigned int Size)
{
    unsigned int i=0,Left=0,Right=Size-1;
    for(i=0;i<Size;i++)
    {
        if(i%2==0)
        {
         if(arr[Left]==Value)
         {
            return Left;
         }
         Left++;
        }
        else
        {
            if(arr[Right]==Value)
         {
            return Right;
         }
         Right--;
        }

    }
    return -1;
}
int Linear_Search_Improvement(int *arr,int Value,unsigned int Size)
{
  unsigned int Right=Size-1,Left=0;
  for(Left=0;Left<=Right;(Left++,Right--))

  {
      if(Value==arr[Left])
        return Left;
      if(Value==arr[Right])
        return Right;
  }
  return -1;
}
