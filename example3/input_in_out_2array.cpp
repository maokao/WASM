#ifdef __cplusplus
extern "C"
{
#endif

    void getArray(int *input_ptr, int *output_ptr, int n)
    {
        for(int i=0; i<n; i++)
        {
            output_ptr[i]=input_ptr[i]+10;
        }
    }
 

#ifdef __cplusplus
}
#endif