#include <iostream>

using namespace std;

int maxVal(int a, int b)
{
	return (a > b) ? a : b;
}

void sumMax_n2()
{
	int n = 10;
	int arr[10] = { 31,-41,59,26,-53,58,97,-93,-23,84 };
	int vecSum, sumMax;
	vecSum = sumMax = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j < n; j++)
		{
			vecSum = vecSum + arr[j];
			sumMax = maxVal(sumMax, vecSum);
		}
		vecSum = 0;
	}
	if (sumMax < 0)
		cout << "negativa" << endl;
	else
		cout << sumMax << endl;
}

int main()
{
	sumMax_n2();
	return 0;
}