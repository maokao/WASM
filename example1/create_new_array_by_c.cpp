#ifdef __cplusplus
extern "C"
{
#endif

    int *getArray(int n)
    {
        int* newArray = new int[n];
        for(int i=0; i<n; i++)
        {
            newArray[i]=i;
        }

        return newArray;
    }
 

#ifdef __cplusplus
}
#endif