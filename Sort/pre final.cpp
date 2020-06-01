#include <iostream>
#include <vector>
#include <algorithm> 

using namespace std;

void swaper(int& xp, int& yp)
{
	int temp = xp;
	xp = yp;
	yp = temp;
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
	void cocktailSort();
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
void ordenamiento<m_traits>::bubbleSort()
{
	int i, j;
	for (i = 0; i < n - 1; i++)
		for (j = 0; j < n - i - 1; j++)
			if (cmp(arr[j + 1], arr[j]))
				swap(arr + j, arr + j + 1);
}

template<typename m_traits>
void ordenamiento<m_traits>::cocktailSort()
{
	bool swapped = true;
	int start = 0;
	int end = n - 1;

	while (swapped) {
		swapped = false;

		for (int i = start; i < end; ++i) {
			if (cmp(arr[i], arr[i + 1])) {
				swaper(arr[i], arr[i + 1]);
				swapped = true;
			}
		}

		if (!swapped)
			break;

		swapped = false;

		--end;

		for (int i = end - 1; i >= start; --i) {
			if (cmp(arr[i], arr[i + 1])) {
				swaper(arr[i], arr[i + 1]);
				swapped = true;
			}
		}
		++start;
	}
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
	int arr[10] = { 9,5,3,1,8,7,10,2,6,4 };
	int n = 10;

	ordenamiento<m_traits> orden(arr, n);
	cout << "desordenado" << endl;
	orden.imprimir();

	cout << "ordenado" << endl;
	orden.countingSort();
	orden.imprimir();

	return 0;
}
