#include <iostream>
#include <iomanip>
#include <array>
#include <string>
#include <tuple>
#include <algorithm>
#include <chrono> 
#include <ctime>
using namespace std;
#define N 20
#define S 8

class Tablero
{
public:
    array<pair<int, int>, 8> moves;
    array<array<int, N>, N> data;

    Tablero()
    {
        moves[0] = make_pair(2, 1);
        moves[1] = make_pair(1, 2);
        moves[2] = make_pair(-1, 2);
        moves[3] = make_pair(-2, 1);
        moves[4] = make_pair(-2, -1);
        moves[5] = make_pair(-1, -2);
        moves[6] = make_pair(1, -2);
        moves[7] = make_pair(2, -1);
    }

};

class Recorrido :public Tablero
{
public:
    array<tuple<int, int, int, array<int, S>>, N* N> O;

    array<int, S> comp(int x, int y) const
    {
        array<tuple<int, int>, S> counts;
        for (int i = 0; i < 8; ++i)
        {
            int dx = get<0>(moves[i]);
            int dy = get<1>(moves[i]);

            int c = 0;
            for (int j = 0; j < S; ++j)
            {
                int x2 = x + dx + get<0>(moves[j]);
                int y2 = y + dy + get<1>(moves[j]);

                if (x2 < 0 || x2 >= N || y2 < 0 || y2 >= N)
                    continue;
                if (data[y2][x2] != 0)
                    continue;

                c++;
            }

            counts[i] = make_tuple(c, i);
        }

        // Lexicographic sort
        sort(counts.begin(), counts.end());

        array<int, S> out;
        for (int i = 0; i < S; ++i)
            out[i] = get<1>(counts[i]);
        return out;
    }

    void rec()
    {

        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                data[i][j] = 0;

        int nextX = 0;
        int nextY = 0;
        data[0][0] = 1;


        O[0] = make_tuple(nextX, nextX, 0, comp(nextX, nextX));

        int n = 0;
        while (n < N * N - 1)
        {
            int x = get<0>(O[n]);
            int y = get<1>(O[n]);

            bool  m = false;
            for (int i = get<2>(O[n]); i < S; ++i)
            {
                int dx = moves[get<3>(O[n])[i]].first;
                int dy = moves[get<3>(O[n])[i]].second;

                if (x + dx < 0 || x + dx >= N || y + dy < 0 || y + dy >= N)
                    continue;
                if (data[y + dy][x + dx] != 0)
                    continue;

                get<2>(O[++n]) = i + 1;
                //++n;
                data[y + dy][x + dx] = n + 1;
                O[n] = make_tuple(x + dx, y + dy, 0, comp(x + dx, y + dy));
                m = true;
                break;
            }

            if (m == false) // Failed. Backtrack.
            {
                data[y][x] = 0;
                --n;
            }
        }
    }
    friend ostream& operator<<(ostream& out, const Tablero& b);

};



ostream& operator<<(ostream& out, const Tablero& b)
{
    for (int v = 0; v < N; ++v)
    {
        for (int u = 0; u < N; ++u)
            cout << setw(3) << b.data[v][u] << "\t";
        cout << endl;
    }
    return out;
}



int main()
{

    auto start = std::chrono::system_clock::now();
    Tablero b1;
    Recorrido x;
    x.rec();

    cout << x;
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed_seconds = end - start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);
    cout << "tiempo " << elapsed_seconds.count() << endl;
}