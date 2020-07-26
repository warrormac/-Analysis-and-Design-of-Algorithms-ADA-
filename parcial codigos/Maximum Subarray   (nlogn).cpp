#include <iostream>

using namespace std;

int max(int a, int b)
{
	return (a > b) ? a : b;
}
int max(int a, int b, int c) 
{
	return max(max(a, b), c); 
}


int sumPart(int arr[], int ini,int mid, int fin)
{
	int sum = 0;
	int l = INT_MIN;
	for (int i = mid; i >= ini; i--)
	{
		sum = sum + arr[i];
		if (sum> l)
			l = sum;
		
	}
	sum= 0;
	int r = INT_MIN;
	for (int i = mid+1; i <= fin; i++)
	{
		sum = sum + arr[i];
		if (sum > r)
			r = sum;

	}
	return max(l + r, l, r);
	//return maxVal(sumMax_rec, sumVec_rec);
}

int sumRecurs(int arr[], int ini, int fin)
{
	if (ini == fin)
		return arr[1];

	if (ini < fin)
	{
		int mid = (ini + fin) / 2;
		
		return max(sumRecurs(arr, ini, mid), sumRecurs(arr, mid + 1, fin), sumPart(arr, ini, mid, fin));
		//cout << "suma: " << sumMax_rec << endl;
	}

}

void main()
{
	int n = 10;
	int arr[10] = { 31,-41,59,26,-53,58,97,-93,-23,84 };
	int vecSum, sumMax;
	vecSum = sumMax = 0;
	int temp = sumRecurs(arr, 0, 9);
	cout << temp;
}
