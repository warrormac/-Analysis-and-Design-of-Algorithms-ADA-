#include <iostream>
#include <time.h>

using namespace std;


template <class T>
constexpr void generadorNumeros(T* arr, T tam)
{
	for (auto i = 0; i < tam; i++)
		*(arr + i) = rand() % 100000000;

}
constexpr void swaper(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}


template<typename T>
struct functorMayor
{
	constexpr inline bool operator()(T a, T b)
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

	int getMax();
	void countSort(int);
	void radixsort();
	void imprimir();
};

template<typename m_traits>
ordenamiento<m_traits>::ordenamiento(T* arr, int n)
{
	this->arr = arr;
	this->n = n;
}

template<typename m_traits>
ordenamiento<m_traits>::~ordenamiento() {}


template<typename m_traits>
int ordenamiento<m_traits>::getMax()
{
	int* p = arr;
	for (auto i = 1; i < n; i++)
		if (cmp(arr[i], *p)) { *p = arr[i]; }
	return *p;
}

template<typename m_traits>
void ordenamiento<m_traits>::countSort(int exp)
{
	int* output = new int[n]; // output array 
	int i, count[10] = { 0 };

	for (i = 0; i < n; i++)
		count[(arr[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(arr[i] / exp) % 10] - 1] = arr[i];
		count[(arr[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		arr[i] = output[i];
}

template<typename m_traits>
void ordenamiento<m_traits>::radixsort()
{
	int m = getMax();

	for (auto exp = 1; m / exp > 0; exp *= 10)
		countSort(exp);
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
	int n = 10000000;

	int* arr = NULL;
	arr = new int[n];
	generadorNumeros(arr, n);

	ordenamiento<m_traits> orden(arr, n);
	//cout << "desordenado" << endl;
	//orden.imprimir();
	cout << "sorting... \n";
	//cout << "ordenado" << endl;
	inicio = clock();
	orden.radixsort();

	cout << "\n";
	duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
	cout << " Tiempo :" << duracion << endl;
	cout << "-------------------------------------" << endl;

	//orden.imprimir();

	return 0;
}