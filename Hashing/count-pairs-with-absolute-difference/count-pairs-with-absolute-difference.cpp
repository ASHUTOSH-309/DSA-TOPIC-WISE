#include <iostream>
#include <vector>
#include <unordered_map>
#include <cmath>

using namespace std;

int countPairsWithDifference(vector<int>& b, int k) {
    unordered_map<int, int> freqMap; // To store frequency of elements
    int count = 0;

    for (int num : b) {
        // Check if complement values exist in the map
        if (freqMap.find(num - k) != freqMap.end()) {
            count += freqMap[num - k];
        }
        if (k != 0 && freqMap.find(num + k) != freqMap.end()) {
            count += freqMap[num + k];
        }
        // Update the frequency map
        freqMap[num]++;
    }

    return count;
}

int main() {
    vector<int> b = {1, 5, 3, 4, 2};
    int k = 2;
    cout << "Number of pairs with difference " << k << ": " << countPairsWithDifference(b, k) << endl;
    return 0;
}
