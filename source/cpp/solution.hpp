#define SOLUTION_HPP
#ifdef SOLUTION_HPP

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // 📦 Initialize result with default invalid indices
        vector<int> result(2, -1);

        // 👈👉 Two pointers: start from left and right ends
        int leftIndex = 0;
        int rightIndex = numbers.size() - 1;

        // 🔁 Move pointers towards each other until they meet
        while(leftIndex < rightIndex) {
            // 🧮 Calculate current sum of numbers at both pointers
            int currentSum = numbers[leftIndex] + numbers[rightIndex];

            // 🎯 Found the target sum!
            if(currentSum == target) {
                // 🔢 Store 1-based indices
                result[0] = leftIndex + 1;
                result[1] = rightIndex + 1;
                break;
            }
            // ⬆️ Sum too small → move left pointer to the right
            else if(currentSum < target) {
                ++leftIndex;
            }
            // ⬇️ Sum too large → move right pointer to the left
            else {
                --rightIndex;
            }
        }

        // 📤 Return the result
        return result;
    }
};

#endif