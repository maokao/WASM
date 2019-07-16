#ifdef __cplusplus
extern "C"
{
#endif
    int** fun1dto2dArray(int *input_ptr, int n, int p)
    {
        int** output_ptr = new int* [p];
        for(int i=0; i<p; i++)
        {
            output_ptr[i] = new int[n];   
        }

        for(int i=0; i<n*p; i++)
        {
            int x = i/n;
            int y = i%n;
            output_ptr[x][y]=input_ptr[i];
        }

        return output_ptr;
    }

    void getArray(int *input_ptr, int *output_ptr, int n, int p)
    {
        int **output_array = fun1dto2dArray(input_ptr,n,p);
        for(int i=0; i<n; i++)
        {
            output_ptr[i]=output_array[0][i]+output_array[1][i];
        }
    }
 

#ifdef __cplusplus
}
#endif