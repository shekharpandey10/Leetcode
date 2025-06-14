#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Placeholder for user logic
vector<string> buildArray(vector<int>& target, int n) {
    // User should implement their logic here
    return {};
}

int main() {
    int m;
    cin >> m; // Read the number of elements in the target array

    vector<int> target(m);
    for (int i = 0; i < m; ++i) {
        cin >> target[i]; // Read elements of the target array
    }

    int n;
    cin >> n; // Read the integer N

    // Call the user logic function
    vector<string> result = buildArray(target, n);

    // Print the result as a space-separated string
    for (const string& operation : result) {
        cout << operation << " ";
    }
    cout << endl;

    return 0;
}