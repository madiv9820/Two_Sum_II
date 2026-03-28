#define SOLUTION_HPP
#ifdef SOLUTION_HPP

#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        
        // 🔍 Binary Search Helper (Lambda Function)
        function<int(int, int, int)> binarySearch = [&](
            int lostNumber, 
            int leftIndex, 
            int rightIndex
        ) -> int {
            // 🔁 Continue while search space is valid
            while(leftIndex <= rightIndex) {
                
                // ⚖️ Calculate middle index safely
                int midIndex = leftIndex + (rightIndex - leftIndex) / 2;
                
                // 🎯 Target found!
                if(numbers[midIndex] == lostNumber)
                    return midIndex;
                
                // ⬅️ Move left (shrink right boundary)
                else if(numbers[midIndex] > lostNumber)
                    rightIndex = midIndex - 1;
                
                // ➡️ Move right (shift left boundary)
                else
                    leftIndex = midIndex + 1;
            }

            // ❌ Target not found
            return -1;
        };

        // 📦 Initialize result with default invalid indices
        vector<int> result(2, -1);
        
        // 🔁 Iterate through each element
        for(int currentIndex = 0; currentIndex < numbers.size(); ++currentIndex) {
            
            // 🧮 Calculate the required complement
            int lostNumber = target - numbers[currentIndex];
            
            // 🔍 Perform Binary Search on remaining array
            // 👉 Start from currentIndex + 1 to avoid reusing same element
            int searchIndex = binarySearch(
                lostNumber,
                currentIndex + 1,
                numbers.size() - 1
            );

            // ✅ If complement found, store 1-based indices
            if(searchIndex != -1) {
                result[0] = currentIndex + 1;
                result[1] = searchIndex + 1;
                break; // 🚀 Exit early once solution is found
            }
        }

        // 📤 Return final result
        return result;
    }
};

#endif