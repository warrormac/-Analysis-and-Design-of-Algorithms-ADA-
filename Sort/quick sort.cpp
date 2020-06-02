#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

using namespace std;

template <class T>
void generadorNumeros(T* arr, T tam)
{
    for (auto i = 0; i < tam; i++)
    {
        *(arr + i) = rand() % 100000000;
    }
}

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

template<class T>
class Asc
{
public:
    inline constexpr bool operator()(T a, T b)
    {
        return a > b;
    }
};

template<class T>
class Des
{
public:
    inline constexpr bool operator()(T a, T b)
    {
        return a < b;
    }
};



template<class traits>
class Ordenamiento
{
public:
    typedef typename traits::T T;
    typedef typename traits::Functor F;
    T* Arr;
    int izq, der;
    F cmp;

    Ordenamiento(T*, int, int);
    ~Ordenamiento();
    int Separacion(int*, int, int);
    void QuickSort(int*, int, int);
    void printArray(int*, int);


};
template<typename traits>
Ordenamiento<traits>::Ordenamiento(T* Arr, int izq, int der)
{
    this->Arr = Arr;
    this->izq = izq;
    this->der = der;
}

template<typename traits>
Ordenamiento<traits>::~Ordenamiento()
{

}


template<class traits>
int Ordenamiento<traits>::Separacion(int* Arr, int izq, int der)
{
    int pivote = Arr[der];
    int iterator = (izq - 1);
    for (auto j = izq; j <= der - 1; j++)
    {
        if (cmp(Arr[j], pivote))
        {
            iterator++;
            swap(&Arr[iterator], &Arr[j]);
        }
    }
    swap(&Arr[iterator + 1], &Arr[der]);
    return (iterator + 1); //posicion del pivote
}


template<class traits>
void Ordenamiento<traits>::QuickSort(int* Arr, int izq, int der)
{
    if (izq < der)
    {
        int masterPivote = Separacion(Arr, izq, der);
        QuickSort(Arr, izq, masterPivote - 1);
        QuickSort(Arr, masterPivote + 1, der);
    }
}


struct traits
{
    typedef int T;
    typedef Des<int> Functor;
};


template<class traits>
void Ordenamiento<traits>::printArray(int* Arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << Arr[i] << " ";
    cout << endl;
}




int main()
{
    clock_t inicio;
    float duracion;

    srand(time(NULL));
    int tam = 1000;
    //cout<<"Indique tamanio del arreglo: ";cin>>tam;
    cout << "\n";
    cout << "Tamanio: " << tam << endl;
    int* arr = NULL;
    arr = new int[tam];
    generadorNumeros(arr, tam);

    inicio = clock();

    Ordenamiento<traits> SORT(arr, 0, tam);
    SORT.QuickSort(arr, 0, tam - 1);

    //SORT.printArray(arr,tam);


    cout << "\n";
    duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
    cout << " Tiempo :" << duracion << endl;
    cout << "-------------------------------------" << endl;

    /* int arr[] = { 10, 7, 8, 9, 1, 5,45,76,32,45,76,90,12,101,99 };
     int n = sizeof(arr) / sizeof(arr[0]);
     QuickSort(arr, 0, n - 1);
     cout << "Sorted array: \n";
     printArray(arr, n);*/

}