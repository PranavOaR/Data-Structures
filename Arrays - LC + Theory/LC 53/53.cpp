/*
 * LeetCode 53: Maximum Subarray
 * 
 * Problem: Find the contiguous subarray with the largest sum
 * 
 * Approaches to implement:
 * 1. Brute Force - O(n²) or O(n³)
 * 2. Kadane's Algorithm - O(n) [Optimal]
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

// ========================================
// APPROACH 1: Brute Force
// Time Complexity: O(n²)
// Space Complexity: O(1)
// ========================================
int maxSubArrayBruteForce(vector<int>& nums) {
    // TODO: Implement brute force solution
    // Hint: Use two nested loops to check all possible subarrays
    int sum=0,maxi=INT_MIN;
    for(int i=0;i<nums.size();i++){
        int sum=0;
        for(int j=i;j<nums.size();j++){
            sum+=nums[j];
            maxi = max(sum,maxi);
        }
    }
    return maxi;
    
    return 0;
}

// ========================================
// APPROACH 2: Kadane's Algorithm (Optimal)
// Time Complexity: O(n)
// Space Complexity: O(1)
// ========================================
int maxSubArrayKadane(vector<int>& nums) {
    // TODO: Implement Kadane's Algorithm
    int n=nums.size(),sum=0,maxi=INT_MIN;
    if(n==1)return nums[0];
    for(int i=0;i<n;i++){
        sum+=nums[i];

        if(sum>maxi){
            maxi=sum;
        }

        if(sum<0){
            sum=0;
        }
    }
    return maxi;
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
// TEST CASES
// ========================================
void runTests() {
    cout << "==================================" << endl;
    cout << "Testing Maximum Subarray Solutions" << endl;
    cout << "==================================" << endl << endl;
    
    // Test Case 1
    vector<int> test1 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << "Test 1: ";
    printArray(test1);
    cout << "Expected: 6 (subarray [4,-1,2,1])" << endl;
    cout << "Brute Force: " << maxSubArrayBruteForce(test1) << endl;
    cout << "Kadane's: " << maxSubArrayKadane(test1) << endl;
    cout << endl;
    
    // Test Case 2
    vector<int> test2 = {1};
    cout << "Test 2: ";
    printArray(test2);
    cout << "Expected: 1" << endl;
    cout << "Brute Force: " << maxSubArrayBruteForce(test2) << endl;
    cout << "Kadane's: " << maxSubArrayKadane(test2) << endl;
    cout << endl;
    
    // Test Case 3
    vector<int> test3 = {5, 4, -1, 7, 8};
    cout << "Test 3: ";
    printArray(test3);
    cout << "Expected: 23 (entire array)" << endl;
    cout << "Brute Force: " << maxSubArrayBruteForce(test3) << endl;
    cout << "Kadane's: " << maxSubArrayKadane(test3) << endl;
    cout << endl;
    
    // Test Case 4: All negative numbers (Edge case!)
    vector<int> test4 = {-5, -2, -8, -1};
    cout << "Test 4 (Edge - All Negative): ";
    printArray(test4);
    cout << "Expected: -1 (least negative)" << endl;
    cout << "Brute Force: " << maxSubArrayBruteForce(test4) << endl;
    cout << "Kadane's: " << maxSubArrayKadane(test4) << endl;
    cout << endl;
    
    // Test Case 5: Mix of positive and negative
    vector<int> test5 = {5, -3, 5};
    cout << "Test 5: ";
    printArray(test5);
    cout << "Expected: 7 (entire array)" << endl;
    cout << "Brute Force: " << maxSubArrayBruteForce(test5) << endl;
    cout << "Kadane's: " << maxSubArrayKadane(test5) << endl;
    cout << endl;
}

// ========================================
// MAIN FUNCTION
// ========================================
int main() {
    runTests();
    
    // Add your own test cases here
    cout << "==================================" << endl;
    cout << "Add your custom tests below:" << endl;
    cout << "==================================" << endl;
    
    return 0;
}

/*
 * IMPLEMENTATION CHECKLIST:
 * 
 * □ Read through 53.MD completely
 * □ Understand subarrays vs subsequences
 * □ Implement brute force solution first
 * □ Test brute force with all test cases
 * □ Study Kadane's algorithm walkthrough
 * □ Implement Kadane's algorithm
 * □ Test Kadane's with all test cases
 * □ Handle edge case: all negative numbers
 * □ Compare time taken for both approaches (optional)
 * □ Try implementing without looking at notes
 * 
 * DEBUGGING TIPS:
 * - Print currentSum and maxSum at each step
 * - Verify your initialization (use INT_MIN or nums[0], NOT 0)
 * - Test with all-negative array specifically
 * - Draw out the array and trace through manually first
 */
