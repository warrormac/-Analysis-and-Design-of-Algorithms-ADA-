#include<iostream> 
#include <set>
using namespace std;

#define iPair pair<int, int> 

set<iPair> hull;


//retrona el lado de p al respecto de p1 y p2
int Side(iPair p1, iPair p2, iPair p)
{
    int val = (p.second - p1.second) * (p2.first - p1.first) - (p2.second - p1.second) * (p.first - p1.first);

    if (val > 0)
        return 1;
    if (val < 0)
        return -1;
    return 0;
}

// distancia entre p, p1 y p2
int Dist(iPair p1, iPair p2, iPair p)
{
    return abs((p.second - p1.second) * (p2.first - p1.first) -
        (p2.second - p1.second) * (p.first - p1.first));
}


void quickHull(iPair a[], int size, iPair p1, iPair p2, int side)
{
    int ind = -1;
    int max_dist = 0;

    // el punto mas alto/bajo 
    for (int i = 0; i < size; i++)
    {
        int temp = Dist(p1, p2, a[i]);
        if (Side(p1, p2, a[i]) == side && temp > max_dist)
        {
            ind = i;
            max_dist = temp;
        }
    }

    if (ind == -1)
    {
        hull.insert(p1);
        hull.insert(p2);
        return;
    }

    //los putos del medio
    quickHull(a, size, a[ind], p1, -Side(a[ind], p1, p2));
    quickHull(a, size, a[ind], p2, -Side(a[ind], p2, p1));
}

void printhull()
{
    cout << "los puntos del Convex Hull son:\n";
    while (!hull.empty())
    {
        cout << "(" << (*hull.begin()).first << "," << (*hull.begin()).second << "),\n";
        hull.erase(hull.begin());
    }
}

void print(iPair a[], int size)
{

    int minim = 0, maxi = 0;

    //punto derecha y izquierda 
    for (int i = 1; i < size; i++)
    {
        if (a[i].first < a[minim].first)
            minim = i;
        if (a[i].first > a[maxi].first)
            maxi = i;
    }

    //punto mas arriba
    quickHull(a, size, a[minim], a[maxi], 1);

    quickHull(a, size, a[minim], a[maxi], -1);

    printhull();
}

int main()
{
    iPair a[] = { {0, 0}, {0, 3},
                    {1, 1}, {1, 2},
                    {2, 2},
                    {3, 1}, {3, 3},
                    {4, 4} };


    int size = sizeof(a) / sizeof(a[0]);
    if (size > 3)
        print(a, size);
    return 0;
}