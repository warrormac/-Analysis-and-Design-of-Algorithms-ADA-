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
	void heapify(int arr[], int n, int i);
	void heapSort();
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
void ordenamiento<m_traits>::heapify(int arr[], int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && cmp(arr[l] , arr[largest]))
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && cmp(arr[r] , arr[largest]))
		largest = r;

	// If largest is not root 
	if (largest != i)
	{
		swap(arr[i], arr[largest]);

		// Recursively heapify the affected sub-tree 
		heapify(arr, n, largest);
	}
}
template<typename m_traits>
void ordenamiento<m_traits>::heapSort()
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);

	// One by one extract an element from heap 
	for (int i = n - 1; i > 0; i--)
	{
		// Move current root to end 
		swap(arr[0], arr[i]);

		// call max heapify on the reduced heap 
		heapify(arr, i, 0);
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
	int n = 1000000;

	int* arr = NULL;
	arr = new int[n];
	generadorNumeros(arr, n);

	ordenamiento<m_traits> orden(arr, n);
	//cout << "desordenado" << endl;
	//orden.imprimir();
	cout << "sorting... \n";
	//cout << "ordenado" << endl;
	inicio = clock();
	orden.heapSort();

	cout << "\n";
	duracion = (clock() - inicio) / (float)CLOCKS_PER_SEC;
	cout << " Tiempo :" << duracion << endl;
	cout << "-------------------------------------" << endl;

	//orden.imprimir();

	return 0;
}
