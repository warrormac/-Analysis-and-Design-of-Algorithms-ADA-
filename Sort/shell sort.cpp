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
void swap(int* xp, int* yp)
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

	void shellSort();
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
void ordenamiento<m_traits>::shellSort()
{
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; i += 1)
		{
			int temp = arr[i];

			int j;
			for (j = i; j >= gap && cmp(arr[j - gap] , temp); j -= gap)
				arr[j] = arr[j - gap];
			arr[j] = temp;
		}
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
	typedef functorMayor<T> F;
};

int main()
{
	clock_t inicio;
	float duracion;
	int n = 1000000;

	int* arr = NULL;
	arr = new int[n];
	generadorNumeros(arr, n);

	ordenamiento<m_traits> orden(arr, n);
	cout << "desordenado" << endl;
	//orden.imprimir();

	cout << "ordenado" << endl;
	inicio = clock();
	orden.shellSort();

	cout << "\n";
	duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
	cout << " Tiempo :" << duracion << endl;
	cout << "-------------------------------------" << endl;

	//orden.imprimir();

	return 0;
}