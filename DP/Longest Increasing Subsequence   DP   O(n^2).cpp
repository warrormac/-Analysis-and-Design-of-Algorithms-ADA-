#include<iostream>  
#include <algorithm>  
using namespace std;


/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int size = sizeof(arr) / sizeof(arr[0]);

    int* lis = new int[size];
    lis[0] = 1;

    /* Compute optimized LIS values in
       bottom up manner */
    for (int i = 1; i < size; i++)
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++)
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;

    }

    // Return maximum value in lis[] 

    cout<<"tamaño de la lista es: "<< *max_element(lis, lis + size);

    return 0;
}