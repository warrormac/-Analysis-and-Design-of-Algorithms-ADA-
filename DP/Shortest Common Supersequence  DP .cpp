#include<bits/stdc++.h> 

using namespace std;

// returns shortest supersequence of X and Y 
string printSSS(string X, string Y)
{
	int x = X.length();
	int y = Y.length();

	// dp[i][j] contains length of shortest supersequence 
	// for X[0..i-1] and Y[0..j-1] 
	int dp[x + 1][y + 1];


	// Fill table in bottom up manner 
	for (int i = 0; i <= x; i++)
	{
		for (int j = 0; j <= y; j++)
		{
			(!i) ? dp[i][j] = j : (!j) ? dp[i][j] = i : (X[i - 1] == Y[j - 1]) ? dp[i][j] = 1 + dp[i - 1][j - 1] : dp[i][j] = 1 + min(dp[i - 1][j],
				dp[i][j - 1]);

		}
	}


	// Following code is used to print shortest supersequence 
	int index = dp[x][y];
	// dp[m][n] stores the length of the shortest supersequence 
	// of X and Y 
	

	// string to store the shortest supersequence 
	string str;

	// Start from the bottom right corner and one by one 
	// push characters in output string 
	int i = x, j = y;
	while (i > 0 && j > 0)
	{
		// If current character in X and Y are same, then 
		// current character is part of shortest supersequence 
		if (X[i - 1] == Y[j - 1])
		{
			// Put current character in result 
			str.push_back(X[i - 1]);

			// reduce values of i, j and index 
			i--, j--, index--;
		}

		// If current character in X and Y are different 
		else if (dp[i - 1][j] > dp[i][j - 1])
		{
			// Put current character of Y in result 
			str.push_back(Y[j - 1]);

			// reduce values of j and index 
			j--, index--;
		}
		else
		{
			// Put current character of X in result 
			str.push_back(X[i - 1]);

			// reduce values of i and index 
			i--, index--;
		}
	}

	// If Y reaches its end, put remaining characters 
	// of X in the result string 
	for(;i>0;i-- && index--)
		str.push_back(X[i - 1]);
		
	

	// If X reaches its end, put remaining characters 
	// of Y in the result string 
	for (; j > 0; j-- && index--)
		str.push_back(Y[j - 1]);
		
	

	// reverse the string and return it 
	reverse(str.begin(), str.end());
	return str;
}

int main()
{
	string X = "AGGTAB";
	string Y = "GXTXAYB";

	cout << printSSS(X, Y);

	return 0;
}