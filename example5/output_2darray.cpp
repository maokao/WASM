#include <stdio.h>

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

    int* fun2dto1dArray(int **input_ptr, int n, int p)
    {
        int* output_ptr = new int [n*p];

        for(int i=0; i<p; i++)
        {
            for(int j=0; j<n; j++)
            {
                output_ptr[i*n+j] = input_ptr[i][j];       
            }
        }

        return output_ptr;
    }

    void getArray(int *input_ptr, int *output_ptr, int n, int p)
    {
        int **output_array = fun1dto2dArray(input_ptr,n,p);
        for(int i=0; i<p; i++)
        {
            for(int j=0; j<n; j++)
            {
                output_array[i][j]=output_array[i][j]*2;
            }
        }
        int *output_ptr_inside = fun2dto1dArray(output_array,n,p);

        for(int i=0; i<n*p; i++)
        {
            output_ptr[i] = output_ptr_inside[i];  
            printf("%d\n", output_ptr_inside[i]);  
        }
            
    }
 

#ifdef __cplusplus
}
#endif