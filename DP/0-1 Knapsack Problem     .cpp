#include <stdio.h> 
#include <iostream>

using namespace std;

// A utility function that returns 
// maximum of two integers 
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Returns the maximum value that 
// can be put in a knapsack of capacity W 


int main()
{
    int valor[] = { 60, 100, 120 };
    int peso[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(valor) / sizeof(valor[0]);


    int i, w;
    int** K = new int*[n + 1]; 
    for (int i = 0; i < n+1; ++i)
        K[i] = new int[W+1];

    // Build table K[][] in bottom up manner 
    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (peso[i - 1] <= w)
                K[i][w] = max(
                    valor[i - 1] + K[i - 1][w - peso[i - 1]],
                    K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    cout<< K[n][W];

}