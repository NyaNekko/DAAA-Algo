#include<iostream>
#include<vector>
using namespace std;

class fibo {
public:

    // 1. Recursive Approach
    long long fibRecursive(long long n) {

        // Base case
        if (n <= 1) {
            return n;
        }

        // Recursive relation
        return fibRecursive(n - 1) + fibRecursive(n - 2);
    }

    // 2. Top-Down (Memoization)
    long long fibTopDown(int n) {

        // DP array initialized with -1
        vector<long long> dp(n + 1, -1);

        return solve(n, dp);
    }

private:
    // Helper function
    long long solve(int n, vector<long long> &dp) {

        // Base case
        if (n <= 1) {
            return n;
        }

        // This is already computed
        if (dp[n] != -1) {
            return dp[n];
        }

        // Store result
        dp[n] = solve(n - 1, dp) + solve(n - 2, dp);

        return dp[n];
    }

public:

    // 3. Bottom-Up (Tabulation)
    long long fibBottomUp(int n) {

        // Base case
        if (n <= 1) {
            return n;
        }

        vector<long long> dp(n + 1);

        dp[0] = 0;
        dp[1] = 1;

        for (int i = 2; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }

        return dp[n];
    }

};

int main() {

    fibo obj;
    int n;

    while (true) {

        cout << "Enter n (0 to 40): ";

        if (cin >> n) {

            if (n >= 0 && n <= 40) {
                break;
            } else {
                cout << "Invalid input! Enter value between 0 and 40.\n\n";
            }

        } else {
            cout << "Invalid input! Enter integer only.\n\n";

            cin.clear(); // clear error
            cin.ignore(10000, '\n'); // remove invalid input
        }
    }

    cout << "\nFibonacci Results:\n\n";

    cout << "Recursive: " << obj.fibRecursive(n) << endl;
    cout << "Top-Down : " << obj.fibTopDown(n) << endl;
    cout << "Bottom-Up : " << obj.fibBottomUp(n) << endl;

    return 0;
    
}