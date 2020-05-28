#include <iostream>

using namespace std;

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

	void bubbleSort();
	void insertionSort();
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
void ordenamiento<m_traits>::bubbleSort()
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (cmp(arr[j + 1], arr[j]))
				swap(arr + j, arr + j + 1);
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
	int arr[10] = { 9,5,3,1,8,7,10,2,6,4 };
	int n = 10;

	ordenamiento<m_traits> orden(arr, n);
	cout << "desordenado" << endl;
	orden.imprimir();

	cout << "ordenado" << endl;
	orden.insertionSort();
	orden.imprimir();

	return 0;
}