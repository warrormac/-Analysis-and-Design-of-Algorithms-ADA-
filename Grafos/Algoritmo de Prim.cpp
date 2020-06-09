#include <iostream> 
using namespace std;

#define V 9  


void print(int parent[], int graph[V][V])
{
    cout << "Nodos \tPeso\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " - " << i << " \t" << graph[i][parent[i]] << " \n";
}



int menorValor(int key[], bool mstSet[])
{
    int min = INT_MAX, indx;

    for (int v = 0; v < V; v++)
        if (mstSet[v] == 0 && key[v] < min)
        {
            min = key[v];
            indx = v;
        }


    return indx;
}

void prim(int graph[V][V])
{
    int node[V], key[V];
    bool arr[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        arr[i] = 0;
    }


    key[0] = 0;
    node[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = menorValor(key, arr);
        arr[u] = 1;

        for (int v = 0; v < V; v++)
            if (graph[u][v] && arr[v] == 0 && graph[u][v] < key[v])
            {
                node[v] = u;
                key[v] = graph[u][v];
            }

    }

    print(node, graph);
}


int main()

{
    cout << "tabla de su grafo: \n";
  
                        // 0  1   2   3   4   5   6   7   8 
    int graph[V][V] = { { 0, 4,  0,  0,  0,  0,  0,  7,  0 }, //0
                        { 4, 0,  8,  0,  0,  0,  0,  11, 0 }, //1
                        { 0, 1,  0,  7,  0,  4,  0,  0,  2 }, //2
                        { 0, 0,  7,  0,  9,  14, 0,  0,  0 }, //3
                        { 0, 0,  0,  9,  0,  10, 0,  0,  0 }, //4
                        { 0, 0,  4,  14, 10, 0,  2,  0,  0 }, //5
                        { 0, 0,  0,  0,  0,  2,  0,  1,  8 }, //6
                        { 8,11,  0,  0,  0,  0,  1,  0,  7 }, //7
                        { 0, 0,  2,  0,  0,  0,  6,  7,  0 } };//8
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            cout <<"\t"<< graph[i][j];

        }
        cout << endl;
    }
    prim(graph);

}
