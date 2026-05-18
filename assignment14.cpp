#include <iostream>
#include <vector>
#include <string>
using namespace std;

class LCS {
public:
    string solve(const string& str1, const string& str2) {
        int n = str1.length();
        int m = str2.length();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }

        // backtrack to find the LCS string
        string result = "";
        int i = n, j = m;
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                result = str1[i - 1] + result;
                i--;
                j--;
            } else if (dp[i - 1][j] > dp[i][j - 1]) {
                i--;
            } else {
                j--;
            }
        }

        return result;
    }
};

int takeValidInput() {
    int target;
    while (true) {
        cin >> target;
        if (cin.fail()) {
            cout << "Invalid input! Please enter a valid integer.\n";
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Enter your choice: ";
        } else {
            break;
        }
    }
    return target;
}

int main() {
    LCS obj;

    while (true) {
        cout << "\n1. Find LCS\n";
        cout << "2. Exit\n";
        cout << "Enter your choice: ";

        int choice = takeValidInput();
        cin.ignore(1000, '\n');

        switch (choice) {
            case 1: {
                string str1, str2;
                bool valid;

                while (true) {
                    cout << "Enter str1: ";
                    getline(cin, str1);
                    valid = true;
                    for (int k = 0; k < str1.length(); k++) {
                        if (!isalpha(str1[k])) {
                            valid = false;
                            break;
                        }
                    }
                    if (str1.empty() || !valid) {
                        cout << "Invalid input! Enter only A-Z or a-z characters.\n";
                    } else {
                        break;
                    }
                }

                while (true) {
                    cout << "Enter str2: ";
                    getline(cin, str2);
                    valid = true;
                    for (int k = 0; k < str2.length(); k++) {
                        if (!isalpha(str2[k])) {
                            valid = false;
                            break;
                        }
                    }
                    if (str2.empty() || !valid) {
                        cout << "Invalid input! Enter only A-Z or a-z characters.\n";
                    } else {
                        break;
                    }
                }

                string result = obj.solve(str1, str2);
                cout << result << "\n";
                break;
            }
            case 2:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}