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

	void countingSort();
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
void ordenamiento<m_traits>::countingSort()
{
	int i, j, k;
	int idx = 0;
	int min, max;

	min = max = arr[0];
	for (i = 1; i < n; i++) {
		min = (arr[i] < min) ? arr[i] : min;
		max = (arr[i] > max) ? arr[i] : max;
	}

	k = max - min + 1;
	/* creates k buckets */
	int* B = new int[k];
	for (i = 0; i < k; i++) B[i] = 0;

	for (i = 0; i < n; i++) B[arr[i] - min]++;
	for (i = min; i <= max; i++)
		for (j = 0; j < B[i - min]; j++) arr[idx++] = i;


	delete[] B;
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
	int n = 1000;

	int* arr = NULL;
	arr = new int[n];
	generadorNumeros(arr, n);

	ordenamiento<m_traits> orden(arr, n);
	//cout << "desordenado" << endl;
	//orden.imprimir();
	cout << "sorting... \n";
	//cout << "ordenado" << endl;
	inicio = clock();
	orden.countingSort();

	cout << "\n";
	duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
	cout << " Tiempo :" << duracion << endl;
	cout << "-------------------------------------" << endl;

	//orden.imprimir();

	return 0;
}
