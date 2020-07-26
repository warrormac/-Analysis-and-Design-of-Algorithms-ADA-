#include<iostream> 
using namespace std;

// Matrix Ai has dimension p[i-1] x p[i] 
// for i = 1..n 


// Driver Code 
int main()
{
    int arr[] = { 1, 2, 3, 4 };
    int size = sizeof(arr) / sizeof(arr[0]);


    int** m = new int* [size];
    for (int i = 0; i < size; ++i)
        m[i] = new int[size];

    int i, j, k, L, q;

    /* m[i,j] = Minimum number of scalar
    multiplications needed to compute the
    matrix A[i]A[i+1]...A[j] = A[i..j] where
    dimension of A[i] is p[i-1] x p[i] */

    // cost is zero when multiplying 
    // one matrix. 
    for (i = 1; i < size; i++)
        m[i][i] = 0;

    // L is chain length. 
    for (L = 2; L < size; L++)
    {
        for (i = 1; i < size - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                // q = cost/scalar multiplications 
                q = m[i][k] + m[k + 1][j] +
                    arr[i - 1] * arr[k] * arr[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    cout << "Minimum number of multiplications is "
        << m[1][size - 1];


   

   
}