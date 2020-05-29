#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;



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

	T arr;
	int n;
	F cmp;

	ordenamiento(vector<int>&, int);
	~ordenamiento();
	void heapify(vector<int>&, int,int);
	void heapSort();
	void imprimir();
};

template<typename m_traits>
ordenamiento<m_traits>::ordenamiento(vector<int>& arr, int n)
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
void ordenamiento<m_traits>::heapify(vector<int> &arr, int n, int i)
{
	int largest = i; // Initialize largest as root 
	int l = 2 * i + 1; // left = 2*i + 1 
	int r = 2 * i + 2; // right = 2*i + 2 

	// If left child is larger than root 
	if (l < n && arr[l] < arr[largest])
		largest = l;

	// If right child is larger than largest so far 
	if (r < n && arr[r] < arr[largest])
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
		cout << arr.at(i) << " -> ";
	}
	cout << "//" << endl;
}

struct m_traits
{
	typedef vector<int> T;
	typedef functorMayor<T> F;
};

int main()
{
	vector<int> arr = { 9,5,3,1,8,7,10,2,6,4 };
	int n = 10;

	ordenamiento<m_traits> orden(arr, n);
	cout << "desordenado" << endl;
	orden.imprimir();

	cout << "ordenado" << endl;
	orden.heapSort();
	orden.imprimir();

	return 0;
}