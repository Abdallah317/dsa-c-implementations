#include "Stack_DS_Dynamic.h"
Stack_Ds_dynamic *Create_Stack(uint32 Max_Size,Stack_Status *Status)
{
    Stack_Ds_dynamic *Obj=NULL; //initialization
if(Status==NULL)
{
    *Status=Stack_NULL_Pointer;
}
else
{
    Obj=(Stack_Ds_dynamic *)malloc(sizeof(Stack_Ds_dynamic));
    if(Obj!=NULL)
    {
        //Allocated !
        //initialization :
        Obj->Stack_Top=-1;
        Obj->Element_Count=0;
        Obj->Stack_Max_Size=Max_Size;
        Obj->Stack_Array=(void **)calloc(Obj->Stack_Max_Size,sizeof(void *)); //'calloc' to initialize all pointers to NULL
        if(Obj->Stack_Array!=NULL)
        {
            //allocated
            *Status=Stack_OK; //all is done !
        }
        else
        {
            //error so don't need to keep Obj anymore !!
            free(Obj);
            Obj=NULL;
            *Status=Stack_NOK;
        }
    }
    else
    {
        //error --->> Obj==NULL is true
        *Status=Stack_NOK; // don't put the NULL POINTER ERROR make this error if user put an argument has NULL value !
    }
}
return Obj;
}
Stack_Ds_dynamic *Destroy_Stack(Stack_Ds_dynamic *Obj,Stack_Status *Status)
{
if((Status==NULL)||(Obj==NULL))
{
    *Status=Stack_NULL_Pointer;
}
else
{
    free(Obj->Stack_Array);
    free(Obj);
    *Status=Stack_OK;
}
return NULL;
}
Stack_Status Stack_Push(Stack_Ds_dynamic *Obj,void *item_ptr)
{
    Stack_Status Status=Stack_NOK;//initialization
if((item_ptr==NULL)||(Obj==NULL))
{
    Status=Stack_NULL_Pointer;
}
else
{
    if(Obj->Element_Count==Obj->Stack_Max_Size)
    {
        //stack is full !!
        Status=Stack_FULL;
    }
    else
    {
        (Obj->Stack_Top)++;
        *(Obj->Stack_Array+Obj->Stack_Top)=item_ptr;
        (Obj->Element_Count)++;
        Status=Stack_OK;
    }
}

return Status;

}

void *Stack_Pop(Stack_Ds_dynamic *Obj,Stack_Status *Status)
{
    void *Pop=NULL;
if((Obj==NULL)||(Status==NULL))
{
    *Status=Stack_NULL_Pointer;
}
else
{
    if(Obj->Element_Count==0)
    {//Empty Stack
        *Status=Stack_Empty;
    }
    else
    {
        Pop=*(Obj->Stack_Array+Obj->Stack_Top);
        (Obj->Element_Count)--;
        (Obj->Stack_Top)--;
        *Status=Stack_OK;
    }
    return Pop;
}
}
void *Stack_Top(Stack_Ds_dynamic *Obj,Stack_Status *Status)
{
void *top=NULL; //initialization
if((Obj==NULL)||(Status==NULL))
{
    *Status=Stack_NOK;
    top=NULL;
}
else
{
      if(Obj->Element_Count==0)
    {//Empty Stack
        *Status=Stack_Empty;
        top=NULL;
    }
    else
    {
        top=*(Obj->Stack_Array+Obj->Stack_Top);
    }

}
return top;
}
Stack_Status Stack_Count(Stack_Ds_dynamic *Obj,uint32 *Element_Count)
{
Stack_Status Status=Stack_NOK;//initialization
if((Element_Count==NULL)||(Obj==NULL))
{
    Status=Stack_NULL_Pointer;
}
else
{

      if(Obj->Element_Count==0)
    {//Empty Stack
        Status=Stack_Empty;
        *Element_Count=0;
    }
    else
    {
        *Element_Count=Obj->Element_Count;
        Status=Stack_OK;
    }

}
return Status;
}
