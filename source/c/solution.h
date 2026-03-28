#define SOLUTION_H
#ifdef SOLUTION_H

#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    
    // 📌 We always return 2 indices
    returnSize[0] = 2;

    // 📦 Allocate memory for result
    int* result = (int*) malloc(returnSize[0] * sizeof(int));

    // ❌ Initialize with invalid indices
    result[0] = -1, result[1] = -1;

    // 🔁 Iterate through each element
    for(int currentIndex = 0; currentIndex < numbersSize; ++currentIndex) {

        // 🧮 Calculate the required complement
        int lostNumber = target - numbers[currentIndex];

        // 🔍 Binary Search boundaries (search in right part only)
        int leftIndex = currentIndex + 1;
        int rightIndex = numbersSize - 1;

        int searchIndex = -1; // ❌ Not found initially

        // 🔁 Binary Search loop
        while(leftIndex <= rightIndex) {

            // ⚖️ Find middle index safely
            int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

            // 🎯 Found the required number!
            if(numbers[midIndex] == lostNumber) {
                searchIndex = midIndex;
                break;
            }

            // ⬅️ Move left (shrink search space)
            else if(numbers[midIndex] > lostNumber)
                rightIndex = midIndex - 1;

            // ➡️ Move right (expand search space)
            else
                leftIndex = midIndex + 1;
        }

        // ✅ If complement found, store 1-based indices
        if(searchIndex != -1) {
            result[0] = currentIndex + 1;
            result[1] = searchIndex + 1;
            break; // 🚀 Exit early
        }
    }

    // 📤 Return final result
    return result;
}

#endif