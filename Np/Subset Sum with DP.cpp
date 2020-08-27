#include <iostream>
#include <numeric>
#include <unordered_map>
#include <string> 
#include <utility>

using namespace std;


bool subsetSum(int S[], int n, int a, int b, int c, unordered_map<string, bool> lookup)
{
	// returna true si no se encuentra el subset
	if (a == 0 && b == 0 && c == 0)
		return true;

	// caso base: no quedan items
	if (n < 0)
		return false;

	// crea una llave a un unico mapa de DP input
	string key = to_string(a) + "|" + to_string(b) + "|" + to_string(c) +
		"|" + to_string(n);

	// si un subproblema es contrado, lo resulve y lo ingresa al mapa
	if (lookup.find(key) == lookup.end())
	{
		// Caso 1, items es parte de subset
		bool A = false;
		if (a - S[n] >= 0)
			A = subsetSum(S, n - 1, a - S[n], b, c, lookup);

		// Caso 2. items es parte del segundo subset
		bool B = false;
		if (!A && (b - S[n] >= 0))
			B = subsetSum(S, n - 1, a, b - S[n], c, lookup);

		// Caso 3. items es parte del tercer subset
		bool C = false;
		if ((!A && !B) && (c - S[n] >= 0))
			C = subsetSum(S, n - 1, a, b, c - S[n], lookup);

		// returna true si se obtienen las 3 soluciones
		lookup[key] = A || B || C;
	}

	// return the subproblem solution from the map
	return lookup[key];
}

// Function for solving 3-partition problem. It return true if given
// set S[0..n-1] can be divided into three subsets with equal sum
bool partition(int S[], int n)
{
	if (n < 3)
		return false;

	unordered_map<string, bool> lookup;

	// get sum of all elements in the set
	int sum = accumulate(S, S + n, 0);

	// return true if sum is divisible by 3 and the set S can
	// be divided into three subsets with equal sum
	return !(sum % 3) && subsetSum(S, n - 1, sum / 3, sum / 3, sum / 3, lookup);
}

// main function for 3-partition problem
int main()
{
	// Input: set of integers
	int S[] = { 7, 3, 2,  5, 4, 8 };

	// number of items in S
	int n = sizeof(S) / sizeof(S[0]);

	if (partition(S, n))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}