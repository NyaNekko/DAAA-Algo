#include <iostream>
#include <vector>
#include <limits>
using namespace std;

int getValidInput(string prompt) {
    int x;
    while (true) {
        cout << prompt;
        cin >> x;

        if (cin.fail() || x < 0) {
            cout << "Invalid input! Enter a non-negative integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        } else {
            return x;
        }
    }
}

int knapsack(int n, int W, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    val[i - 1] + dp[i - 1][w - wt[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    //---------------------backtracking -----------------------
    int w = W;
    cout << "\nSelected items (weight, value):\n";

    for (int i = n; i > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "(" << wt[i - 1] << ", " << val[i - 1] << ")\n";
            w -= wt[i - 1];
        }
    }
    return dp[n][W];
}

int main() {
    int n = getValidInput("Enter number of items: ");

    vector<int> weights(n), values(n);

    cout << "\nEnter weights of items:\n";
    for (int i = 0; i < n; i++) {
        weights[i] = getValidInput("Weight " + to_string(i + 1) + ": ");
    }

    cout << "\nEnter values of items:\n";
    for (int i = 0; i < n; i++) {
        values[i] = getValidInput("Value " + to_string(i + 1) + ": ");
    }

    int capacity = getValidInput("\nEnter knapsack capacity: ");

    int maxProfit = knapsack(n, capacity, weights, values);

    cout << "\nMaximum Profit: " << maxProfit << endl;

    return 0;
}