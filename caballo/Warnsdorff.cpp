#include <iostream> 
#include "time.h"
#include <chrono>  
#include <ctime> 

using namespace std;

#define N 20
#define S 8

static int cx[S] = { 2, 1, -1, -2, -2, -1,  1,  2 };
static int cy[S] = { 1, 2,  2,  1, -1, -2, -2, -1 };

class Tablero
{
public:


    bool valido(int x, int y)
    {
        return ((x >= 0 && y >= 0) && (x < N&& y < N));
    }

    bool isempty(int a[], int x, int y)
    {
        return (valido(x, y)) && (a[y * N + x] < 0);
    }


    int getDegree(int a[], int x, int y)
    {
        int count = 0;
        for (int i = 0; i < N; ++i)
            if (isempty(a, (x + cx[i]), (y + cy[i])))
                count++;

        return count;
    }
};

class run : public Tablero
{
public:

    void print(int a[])
    {
        for (int i = 0; i < N; ++i)
        {
            for (int j = 0; j < N; ++j)
                printf("%d\t", a[j * N + i]);
            printf("\n");
        }
    }

    bool runrec(int a[], int* x, int* y)
    {
        int min_deg_idx = -1, c, min_deg = (N + 1), nx, ny;

        int start = rand() % N;
        for (int count = 0; count < N; ++count)
        {
            int i = (start + count) % N;
            nx = *x + cx[i];
            ny = *y + cy[i];
            if ((isempty(a, nx, ny)) && (c = getDegree(a, nx, ny)) < min_deg)
            {
                min_deg_idx = i;
                min_deg = c;
            }
        }

        // btng
        if (min_deg_idx == -1)
            return false;

        nx = *x + cx[min_deg_idx];
        ny = *y + cy[min_deg_idx];

        a[ny * N + nx] = a[(*y) * N + (*x)] + 1;
        *x = nx;
        *y = ny;

        return true;
    }



    bool check(int x, int y, int xx, int yy)
    {
        int i = 0;
        while (++i < N)
            if (((x + cx[i]) == xx) && ((y + cy[i]) == yy))
                return true;

        return false;
    }

    bool runer()
    {

        int a[N * N];
        for (int i = 0; i < N * N; ++i)
            a[i] = -1;

        int sx = 0;
        int sy = 0;


        int x = sx, y = sy;
        a[0] = 1;

        for (int i = 0; i < N * N - 1; ++i)
            if (runrec(a, &x, &y) == 0)
                return 0;

        if (!check(x, y, sx, sy))
            return false;



        print(a);
        return true;
    }


};

int main()
{
    std::chrono::time_point<std::chrono::system_clock> start, end;

    start = std::chrono::system_clock::now();
    Tablero x;
    run y;

    while (!y.runer());
    end = std::chrono::system_clock::now();

    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    std::cout << "tiempo: " << elapsed_seconds.count() << "s\n";
    return 0;
}