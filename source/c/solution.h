#define SOLUTION_H
#ifdef SOLUTION_H

#include <stdlib.h>

int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    // 📌 We always return 2 indices
    returnSize[0] = 2;

    // 📦 Allocate memory for result and initialize
    int* result = (int*) malloc(returnSize[0] * sizeof(int));
    result[0] = -1;
    result[1] = -1;

    // 👈👉 Two pointers: start from left and right ends
    int leftIndex = 0;
    int rightIndex = numbersSize - 1;

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

#endif