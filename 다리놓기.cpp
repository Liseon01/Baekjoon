#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int>bridge(int n, vector<pair<int, int>> input) {
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(combination(input[i].first, input[i].second));
        }
        return res;
    }
private:
    int combination(int n, int k) {
        if (k > n) return 0;
        if (k == 0 || k == n) return 1;

        int result = 1;
        if (k > n - k) k = n - k;

        for (int i = 1; i <= k; ++i) {
            result = result * (n - i + 1) / i;
        }
        return result;
    }
};

int main() {
    Solution sol;
    vector<int> res;
    int count;

    cin >> count;
    vector<pair<int, int>> input(count);
    for (int i = 0; i < count; i++) {
        cin >> input[i].second >> input[i].first;
    }

    res = sol.bridge(count, input);

    for (int i = 0; i < count; i++) {
        cout << res[i] << endl;
    }
    


    return 0;
}
