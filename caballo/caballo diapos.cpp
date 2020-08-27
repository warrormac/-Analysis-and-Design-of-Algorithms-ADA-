#include<iostream>
#include <chrono> 
#include <ctime> 
using namespace std::chrono;
using namespace std;
#define N 8


//verifica valides
int valido(int x, int y, int sol[N][N])
{
    return (x >= 0 && x < N&& y >= 0 && y < N&& sol[x][y] == -1);
}

//la recursion
int runrec(int x, int y, int movei, int sol[N][N], int xMove[N], int yMove[N])
{
    int k, next_x, next_y;
    if (movei == N * N)
        return 1;

    //se prueba todos las movidas
    for (k = 0; k < 8; k++)
    {
        next_x = x + xMove[k];
        next_y = y + yMove[k];
        if (valido(next_x, next_y, sol))
        {
            sol[next_x][next_y] = movei;
            if (runrec(next_x, next_y, movei + 1, sol, xMove, yMove) == 1)
                return 1;
            else
                sol[next_x][next_y] = -1;// backtracking 
        }
    }

    return 0;
}




void print(int sol[N][N])
{
    for (int x = 0; x < N; x++)
    {
        for (int y = 0; y < N; y++)
            cout << sol[x][y] << "\t ";
        cout << endl;
    }
}


int run()
{
    int pos[N][N];
    int val1 = rand() % N;
    int val2 = rand() % N;

    /* Initialization of solution matrix */
    for (int x = 0; x < N; x++)
        for (int y = 0; y < N; y++)
            pos[x][y] = -1;

    int xMove[8] = { 2, 1, -1, -2, -2, -1,  1,  2 };
    int yMove[8] = { 1, 2,  2,  1, -1, -2, -2, -1 };


    pos[0][0] = 0;

    //comienza a solucionar

    if (runrec(0, 0, 1, pos, xMove, yMove) == 0)
    {
        cout << "No tiene solucion";
    }
    else
        print(pos);

    return 1;
}




int main()
{
    milliseconds mil(1000);

    mil = mil * 60;
    auto start = std::chrono::system_clock::now();
    run();
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "tiempo " << elapsed_seconds.count() << endl;
}