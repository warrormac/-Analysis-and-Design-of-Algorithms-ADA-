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

	void countingSort();
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
void ordenamiento<m_traits>::countingSort()
{
    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {

        swapped = false;

        for (int i = start; i < end; ++i) {
            if (arr.at(i) > arr.at(i + 1)) {
                swap(arr.at(i), arr.at(i + 1));
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        --end;

        for (int i = end - 1; i >= start; --i) {
            if (arr.at(i) > arr.at(i + 1)) {
                swap(arr.at(i), arr.at(i + 1));
                swapped = true;
            }
        }

        ++start;
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
	typedef functorMenor<T> F;
};

int main()
{
	vector<int> arr = { 9,5,3,1,8,7,10,2,6,4 };
	int n = 10;

	ordenamiento<m_traits> orden(arr, n);
	cout << "desordenado" << endl;
	orden.imprimir();

	cout << "ordenado" << endl;
	orden.countingSort();
	orden.imprimir();

	return 0;
}