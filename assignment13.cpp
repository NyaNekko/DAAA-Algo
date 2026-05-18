#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class KaratsubaMultiplier {
private:
    // Remove leading zeros
    string removeLeadingZeros(string str) {
        int i = 0;
        while (i < str.length() - 1 && str[i] == '0')
            i++;
        return str.substr(i);
    }

    // Validate input
    bool isValidNumber(const string &str) {
        if (str.empty()) return false;
        for (char c : str) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    // Recursive Karatsuba multiplication
    long long karatsuba(long long x, long long y) {
      //base case like x*y for smaller numbers
        if (x < 10 || y < 10)
            return x * y;

        int n = max(to_string(x).length(), to_string(y).length());
        int half = n / 2;

        long long power = pow(10, half);


        // split the digits (x=a⋅10^m+b,y=c⋅10^m+d), same for y
        long long a = x / power;
        long long b = x % power;
        long long c = y / power;
        long long d = y % power;


        // 
        long long ac = karatsuba(a, c);
        long long bd = karatsuba(b, d);
        long long ad_bc = karatsuba(a + b, c + d) - ac - bd;

        // main formula: x*y = ac*10^(2*m) + (ad+bc)*10^m + bd
        return ac * pow(10, 2 * half) + ad_bc * power + bd;
    }

public:
    // Public interface method
    void multiply() {
        string input1, input2;

        cout << "Enter first number: ";
        cin >> input1;

        cout << "Enter second number: ";
        cin >> input2;

        // Validation
        if (!isValidNumber(input1) || !isValidNumber(input2)) {
            cout << "Error: Please enter valid non-negative integers only.\n";
            return;
        }

        input1 = removeLeadingZeros(input1);
        input2 = removeLeadingZeros(input2);

        long long num1 = stoll(input1);
        long long num2 = stoll(input2);

        long long result = karatsuba(num1, num2);

        cout << "Result: " << result << endl;
    }
};

int main() {
    KaratsubaMultiplier obj;
    obj.multiply();
    return 0;
}