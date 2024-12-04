#include <iostream>
#include <unordered_set>
#include <vector>

using namespace std;

bool twoSum(const vector<int>& nums, int target) {
    unordered_set<int> seen;

    for (int num : nums) {
        int complement = target - num;

        // Check if the complement exists in the hashset
        if (seen.find(complement) != seen.end()) {
            return true; // Pair found
        }

        // Add the current number to the hashset
        seen.insert(num);
    }

    return false; // No pair found
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    if (twoSum(nums, target)) {
        cout << "Pair exists!" << endl;
    } else {
        cout << "No pair exists." << endl;
    }

    return 0;
}
