#include <iostream>
#include <numeric>

// Helper function to 3-partition problem
// It return true if there exists three subsets with given sum
bool subsetSum(int S[], int n, int a, int b, int c, int arr[])
{


	// return true if subset is found
	if (a == 0 && b == 0 && c == 0)
		return true;

	// base case: no items left
	if (n < 0)
		return false;

	// Case 1. current item becomes part of first subset
	bool A = false;
	if (a - S[n] >= 0)
	{
		arr[n] = 1;		// current element goes to first subset
		A = subsetSum(S, n - 1, a - S[n], b, c, arr);
	}

	// Case 2. current item becomes part of second subset
	bool B = false;
	if (!A && (b - S[n] >= 0))
	{
		arr[n] = 2;		// current element goes to second subset
		B = subsetSum(S, n - 1, a, b - S[n], c, arr);
	}

	// Case 3. current item becomes part of third subset
	bool C = false;
	if ((!A && !B) && (c - S[n] >= 0))
	{
		arr[n] = 3;			// current element goes to third subset
		C = subsetSum(S, n - 1, a, b, c - S[n], arr);
	}

	// return true if we get solution
	return A || B || C;
}

// Function for solving 3-partition problem. It prints the subset if
// given set S[0..n-1] can be divided into three subsets with equal sum
void partition(int S[], int n)
{
	// get sum of all elements in the set
	int sum = std::accumulate(S, S + n, 0);

	// construct an array to track the subsets
	// (arr[i] = k) represents i'th item of S is part of k'th subset
	int arr[7];

	// set result to true if sum is divisible by 3 and the set S can
	// be divided into three subsets with equal sum
	bool res = (n >= 3) && !(sum % 3) &&
		subsetSum(S, n - 1, sum / 3, sum / 3, sum / 3, arr);

	if (!res)
	{
		std::cout << "3-Partition of set is not Possible";
		return;
	}

	// print the partitions
	for (int i = 0; i < 3; i++)
	{
		std::cout << "Partition " << i << " is: ";
		for (int j = 0; j < n; j++)
			if (arr[j] == i + 1)
				std::cout << S[j] << " ";
		std::cout << std::endl;
	}
}

// main function for printing 3-partition problem
int main()
{
	// Input: set of integers
	int S[] = { 7, 3, 2,  5, 4, 8 };

	// number of items in S
	int n = sizeof(S) / sizeof(S[0]);

	partition(S, n);

	return 0;
}