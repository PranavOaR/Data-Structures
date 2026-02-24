/*
 * LeetCode 1: Two Sum
 * 
 * Problem: Given an array and a target, find indices of two numbers that add up to target
 * 
 * Approaches to implement:
 * 1. Brute Force - O(n²)
 * 2. Hash Map - O(n) [Optimal for unsorted]
 * 3. Two Pointers (Greedy) - O(n log n) [Works by sorting]
 */

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// ========================================
// APPROACH 1: Brute Force
// Time Complexity: O(n²)
// Space Complexity: O(1)
// ========================================
vector<int> twoSumBruteForce(vector<int>& nums, int target) {
    // TODO: Implement brute force solution
    // Hint: Use two nested loops to check all pairs
    int n = nums.size();
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {}; // No solution found
}

// ========================================
// APPROACH 2: Hash Map (Optimal)
// Time Complexity: O(n)
// Space Complexity: O(n)
// ========================================
vector<int> twoSumHashMap(vector<int>& nums, int target) {
    // TODO: Implement hash map solution
    // Hint: Store complement in map as you iterate
    unordered_map<int, int> numMap; // value -> index
    
    for(int i = 0; i < nums.size(); i++) {
        int complement = target - nums[i];
        
        // Check if complement exists in map
        if(numMap.find(complement) != numMap.end()) {
            return {numMap[complement], i};
        }
        
        // Add current number to map
        numMap[nums[i]] = i;
    }
    
    return {}; // No solution found
}

// ========================================
// APPROACH 3: Two Pointers (Greedy)
// Time Complexity: O(n log n) - due to sorting
// Space Complexity: O(n) - for storing pairs
// ========================================
vector<int> twoSumTwoPointers(vector<int>& nums, int target) {
    // Create pairs of (value, original_index)
    vector<pair<int, int>> numWithIndex;
    for(int i = 0; i < nums.size(); i++) {
        numWithIndex.push_back({nums[i], i});
    }
    
    // Sort by value
    sort(numWithIndex.begin(), numWithIndex.end());
    
    // Two pointers approach
    int left = 0;
    int right = nums.size() - 1;
    
    while(left < right) {
        int sum = numWithIndex[left].first + numWithIndex[right].first;
        
        if(sum == target) {
            // Return original indices (in sorted order)
            int idx1 = numWithIndex[left].second;
            int idx2 = numWithIndex[right].second;
            return {min(idx1, idx2), max(idx1, idx2)};
        }
        else if(sum < target) {
            left++; // Need larger sum
        }
        else {
            right--; // Need smaller sum
        }
    }
    
    return {}; // No solution found
}

// ========================================
// HELPER: Print array for debugging
// ========================================
void printArray(vector<int>& nums) {
    cout << "[";
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

// ========================================
// HELPER: Print result
// ========================================
void printResult(vector<int>& result) {
    if(result.empty()) {
        cout << "No solution found" << endl;
    } else {
        cout << "[" << result[0] << ", " << result[1] << "]" << endl;
    }
}

// ========================================
// TEST CASES
// ========================================
void runTests() {
    cout << "==================================" << endl;
    cout << "Testing Two Sum Solutions" << endl;
    cout << "==================================" << endl << endl;
    
    // Test Case 1
    vector<int> test1 = {2, 7, 11, 15};
    int target1 = 9;
    cout << "Test 1: ";
    printArray(test1);
    cout << "Target: " << target1 << endl;
    cout << "Expected: [0, 1]" << endl;
    cout << "Brute Force: ";
    vector<int> result1_bf = twoSumBruteForce(test1, target1);
    printResult(result1_bf);
    cout << "Hash Map: ";
    vector<int> result1_hm = twoSumHashMap(test1, target1);
    printResult(result1_hm);
    cout << "Two Pointers: ";
    vector<int> result1_tp = twoSumTwoPointers(test1, target1);
    printResult(result1_tp);
    cout << endl;
    
    // Test Case 2
    vector<int> test2 = {3, 2, 4};
    int target2 = 6;
    cout << "Test 2: ";
    printArray(test2);
    cout << "Target: " << target2 << endl;
    cout << "Expected: [1, 2]" << endl;
    cout << "Brute Force: ";
    vector<int> result2_bf = twoSumBruteForce(test2, target2);
    printResult(result2_bf);
    cout << "Hash Map: ";
    vector<int> result2_hm = twoSumHashMap(test2, target2);
    printResult(result2_hm);
    cout << "Two Pointers: ";
    vector<int> result2_tp = twoSumTwoPointers(test2, target2);
    printResult(result2_tp);
    cout << endl;
    
    // Test Case 3
    vector<int> test3 = {3, 3};
    int target3 = 6;
    cout << "Test 3: ";
    printArray(test3);
    cout << "Target: " << target3 << endl;
    cout << "Expected: [0, 1]" << endl;
    cout << "Brute Force: ";
    vector<int> result3_bf = twoSumBruteForce(test3, target3);
    printResult(result3_bf);
    cout << "Hash Map: ";
    vector<int> result3_hm = twoSumHashMap(test3, target3);
    printResult(result3_hm);
    cout << "Two Pointers: ";
    vector<int> result3_tp = twoSumTwoPointers(test3, target3);
    printResult(result3_tp);
    cout << endl;
    
    // Test Case 4: Negative numbers
    vector<int> test4 = {-1, -2, -3, -4, -5};
    int target4 = -8;
    cout << "Test 4 (Negatives): ";
    printArray(test4);
    cout << "Target: " << target4 << endl;
    cout << "Expected: [2, 4]" << endl;
    cout << "Brute Force: ";
    vector<int> result4_bf = twoSumBruteForce(test4, target4);
    printResult(result4_bf);
    cout << "Hash Map: ";
    vector<int> result4_hm = twoSumHashMap(test4, target4);
    printResult(result4_hm);
    cout << "Two Pointers: ";
    vector<int> result4_tp = twoSumTwoPointers(test4, target4);
    printResult(result4_tp);
    cout << endl;
    
    // Test Case 5: Large numbers
    vector<int> test5 = {1000000000, 2, 3, 1000000000};
    int target5 = 2000000000;
    cout << "Test 5 (Large Numbers): ";
    printArray(test5);
    cout << "Target: " << target5 << endl;
    cout << "Expected: [0, 3]" << endl;
    cout << "Brute Force: ";
    vector<int> result5_bf = twoSumBruteForce(test5, target5);
    printResult(result5_bf);
    cout << "Hash Map: ";
    vector<int> result5_hm = twoSumHashMap(test5, target5);
    printResult(result5_hm);
    cout << "Two Pointers: ";
    vector<int> result5_tp = twoSumTwoPointers(test5, target5);
    printResult(result5_tp);
    cout << endl;
}

// ========================================
// MAIN
// ========================================
int main() {
    runTests();
    return 0;
}
