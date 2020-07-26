#include <iostream> 
#include <vector>
using namespace std;

/* A utility function to check whether a word
   is present in dictionary or not. An array of
   strings is used for dictionary.  Using array
   of strings for dictionary is definitely not
   a good idea. We have used for simplicity of
   the program*/
int dictionary(string word)
{
    string dictionary[] = { "mobile", "samsung", "sam",
                            "sung", "man", "mango",
                            "icecream", "and", "go",
                            "i", "like", "ice", "cream" };
    int size = sizeof(dictionary) / sizeof(dictionary[0]);
    for (int i = 0; i < size; i++)
        if (dictionary[i].compare(word) == 0)
            return 1;
    return 0;
}

// Returns true if string can be segmented into space 
// separated words, otherwise returns false 

// Driver code 
int main()
{
    string s = "ilikesamsung"; 
    int n = s.size();
    bool res;
    if (n == 0)
        return true;

    // Create the DP table to store results of subroblems. 
    // The value dp[i] will be true if str[0..i] can be 
    // segmented into dictionary words, otherwise false. 
    vector<bool> dp(n + 1, 0); // Initialize all values 
    // as false. 

    // matched_index array represents the indexes for which 
    // dp[i] is true. Initially only -1 element is present 
    // in this array. 
    vector<int> matched_index;
    matched_index.push_back(-1);

    for (int i = 0; i < n; i++) {
        int msize = matched_index.size();

        // Flag value which tells that a substring matches 
        // with given words or not. 
        int f = 0;

        // Check all the substring from the indexes matched 
        // earlier. If any of that substring matches than 
        // make flag value = 1; 
        for (int j = msize - 1; j >= 0; j--) {

            // sb is substring starting from matched_index[j] 
            // + 1  and of length i - matched_index[j] 
            string sb = s.substr(matched_index[j] + 1, i - matched_index[j]);

            if (dictionary(sb)) {
                f = 1;
                break;
            }
        }

        // If substring matches than do dp[i] = 1 and 
        // push that index in matched_index array. 
        if (f == 1) {
            dp[i] = 1;
            matched_index.push_back(i);
        }
    }
    res = dp[n - 1];
    cout << res;
    return 0;
}