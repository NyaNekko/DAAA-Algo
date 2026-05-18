#include <iostream>
#include <vector>
using namespace std;

class SubsetSum {
public:

    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, int target, bool &found) {
        if (i == nums.size()) {
            int sum = 0;

            for (int x : ans)
                sum += x;

            if (sum == target) {
                found = true;

                cout << "{ ";
                for (int x : ans)
                    cout << x << " ";
                cout << "}" << endl;
            }

            return;
        }

        // include
        ans.push_back(nums[i]);
        getAllSubsets(nums, ans, i + 1, target, found);

        ans.pop_back();

        // exclude
        getAllSubsets(nums, ans, i + 1, target, found);
    }
};

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    while (n <= 0) {
        cout << "Invalid input. Enter positive number: ";
        cin >> n;
    }

    vector<int> nums(n);

    while (true) {
        cout << "Enter " << n << " elements:\n";

        for (int i = 0; i < n; i++)
            cin >> nums[i];

        if (cin.peek() != '\n') { // extra input detected
            cout << "You are out of size. Please enter only " << n << " numbers.\n\n";
            cin.ignore(1000, '\n');   // discard extra input
            // Ignore maximum 1000 characters
            // Stop when newline \n is found
            continue;                // ask again
        }

        break; // correct input
    }

    int target;
    cout << "Enter target sum: ";
    cin >> target;

    SubsetSum *obj = new SubsetSum();

    vector<int> ans;
    bool found = false;

    cout << "\nSubsets with sum = " << target << " are:\n";

    obj->getAllSubsets(nums, ans, 0, target, found);

    if (!found)
        cout << "{ }" << endl;

    delete obj;

    return 0;
}