// Permutations
#include <iostream>
#include <string>
#include <cctype>
using namespace std;

void swap_char(char &a , char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void permutation(string &str , int start , int end , int &count) {
    //if all the positions are fixed, print the perm
    if(start == end) {
        cout << str << endl;
        count++;
        return;
    }

    for(int i = start ; i <= end ; i++) {
        swap_char(str[start] , str[i]); // swap current index with start to fix a character at start and permute the rest/a`
        permutation(str , start + 1 , end , count);
        // swap_char(str[start] , str[i]); // backtracking-------- restore original string for next iteration
    }
}

int main() {
    string str;

    while(true) {
        cout<<"Enter a string of alphabets: ";
        getline(cin , str);

        int n = str.length();

        // Validation 1: empty string
        if(n == 0) {
            cout<<"Invalid input - Empty string not allowed\n";
            continue;
        }

        // Validation 2: large input protection - doesn't go ahead of 8 characters cuz 8! = 40320 which is manageable, but 9! = 362880 which is too large to handle in a reasonable time frame.
        if(n > 8) {
            cout<<"Input too large. Please enter at most 8 characters.\n";
            continue;
        }

        // Validation 3: only alphabets
        bool valid = true;
        for(int i = 0 ; i < n ; i++) {
            if(!isalpha(str[i])) {
                valid = false;
                break;
            }
        }

        if(!valid) {
            cout<<"Invalid input - Only alphabets allowed\n";
            continue;
        }

        // valid input -> exit loop
        break;
    }

    int count = 0;
    cout<<"\nAll permutations are:\n";
    permutation(str , 0 , str.length()-1 , count);
    cout<<"\nTotal permutations = " << count << endl;
    return 0;
}