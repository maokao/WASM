#ifdef __cplusplus
extern "C"
{
#endif

    int *getArray(int *input_ptr, int n)
    {
        int* newArray = new int[n];
        for(int i=0; i<n; i++)
        {
            newArray[i]=input_ptr[i]+10;
        }

        return newArray;
    }
 

#ifdef __cplusplus
}
#endif