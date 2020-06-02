#include <iostream>
#include <time.h>

using namespace std;


template <class T>
void generadorNumeros(T* arr, T tam)
{
	for (auto i = 0; i < tam; i++)
	{
		*(arr + i) = rand() % 100000000;
	}


}
void swaper(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

template<typename T>
struct functorMayor
{
	inline bool operator()(T a, T b)
	{
		return a < b;
	}
};

template<typename T>
struct functorMenor
{
	inline bool operator()(T a, T b)
	{
		return a > b;
	}
};

template<typename m_traits>
struct ordenamiento
{
	typedef typename m_traits::T T;
	typedef typename m_traits::F F;

	T* arr;
	int n;
	F cmp;

	ordenamiento(T*, int);
	~ordenamiento();
	void insertionSort(int min, int max);
	void merge(int , int , int );
	void mergeSort(int min, int max, int threshold);
	void imprimir();
};

template<typename m_traits>
ordenamiento<m_traits>::ordenamiento(T* arr, int n)
{
	this->arr = arr;
	this->n = n;
}

template<typename m_traits>
ordenamiento<m_traits>::~ordenamiento()
{
	//T* tmp = arr;
	//delete tmp;
}


template<typename m_traits>
void ordenamiento<m_traits>::insertionSort( int min, int max)
{
	int key;
	for (int j = min + 1; j <= max; j++)
	{
		key = arr[j];
		int i = j - 1;

		while (i >= min && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i--;
		}
		arr[i + 1] = key;
	}
}
template<typename m_traits>
void ordenamiento<m_traits>::merge( int min, int max, int mid)
{
	int i = min, j = mid + 1, k = 0;
	int* temp = new int[max - min + 1];

	while (i <= mid && j <= max)
	{
		if (cmp(arr[i] , arr[j]))               //comparison step && swap symbol to go from ascending to descending
			temp[k++] = arr[i++];

		else
			temp[k++] = arr[j++];

	}

	while (i <= mid)
		temp[k++] = arr[i++];


	while (j <= max)
		temp[k++] = arr[j++];


	for (i = min; i <= max; i++)
		arr[i] = temp[i - min];



	return;
}

template<typename m_traits>
void ordenamiento<m_traits>::mergeSort( int min, int max, int threshold)
{
	
		if ((max - min + 1) <= threshold)
		{
			insertionSort( min, max);
		}
		else
		{
			int mid = (max + min) / 2;

			mergeSort(min, mid, threshold);
			mergeSort(mid + 1, max, threshold);

			merge(min, max, mid);
		}
	
}



template<typename m_traits>
void ordenamiento<m_traits>::imprimir()
{
	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << " -> ";
	}
	cout << "//" << endl;
}

struct m_traits
{
	typedef int T;
	typedef functorMenor<T> F;
};

int main()
{
	clock_t inicio;
	float duracion;
	int n = 50000000;
	int threshold = 10;

	int* arr = NULL;
	arr = new int[n];
	generadorNumeros(arr, n);

	ordenamiento<m_traits> orden(arr, n);
	//cout << "desordenado" << endl;
	//orden.imprimir();
	cout << "sorting... \n";
	//cout << "ordenado" << endl;
	inicio = clock();
	orden.mergeSort(0, n - 1, threshold);

	cout << "\n";
	duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
	cout << " Tiempo :" << duracion << endl;
	cout << "-------------------------------------" << endl;

	//orden.imprimir();

	return 0;
}