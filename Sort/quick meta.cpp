#include <iostream>

using namespace std;

template<class T>
void swap(T* a, T* b)
{
	T temp = *a;
	*a = *b;
	*b = temp;
}

template <int izq, int der, int Size, class Enable = void>
struct separacion;

template <int BeginIt, int EndIt, int Size>
struct separacion<BeginIt, EndIt, Size, typename std::enable_if<(BeginIt < EndIt)>::type> {

	template <class T>
	inline static void Partition(T* Arr, const T& pivot) {

		if (Arr[BeginIt] <= pivot) {
			return separacion<BeginIt + 1, EndIt, Size>::Partition(Arr, pivot);
		}

		if (Arr[EndIt - 1] > pivot) {
			return separacion<BeginIt, EndIt - 1, Size>::Partition(Arr, pivot);
		}

		swap(Arr[BeginIt], Arr[EndIt - 1]);
		separacion<BeginIt + 1, EndIt - 1, Size>::Partition(Arr, pivot);
	}
};

template <int BeginIt, int EndIt, int Size>
struct separacion<BeginIt, EndIt, Size, typename std::enable_if<(BeginIt >= EndIt)>::type > {

	template <class T>
	inline static void Partition(T* Arr, const T& pivot) {
		constexpr int pivote = BeginIt - 1;

		std::swap(Arr[0], Arr[pivote]);
		quicksort(Arr, const int_<pivote>());
		quicksort(Arr + pivote + 1, int_<Size - (pivote + 1)>());

	}
};

template <int Val>
class int_
{

};

template <class T, int Size>
inline auto quicksort(T* Arr, const int_<Size>&) -> typename std::enable_if<(Size >= 1)>::type {
	separacion<1, Size, Size>::Partition(Arr, Arr[0]);
}

template <class T, int Size>
inline auto quicksort(T* Arr, const int_<Size>&) -> typename std::enable_if<(Size < 1)>::type{ }











	int main()
{


	return 0;
}