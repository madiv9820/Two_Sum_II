# Two Sum II — Binary Search Approach 🔍
### 💡 Intuition
Since the array is **sorted**, we don’t need to check every possible pair.
- For each number **`numbers[i]`**, we can calculate the number we need (**`target - numbers[i]`**).
- Instead of scanning the rest of the array linearly, we can use **binary search** to quickly find the complement.
- This reduces unnecessary comparisons and leverages the sorted property of the array. ⚡

Think of it as **“hunting your missing number in a sorted lineup**” rather than guessing every pair. 🎯

### ⚡ Approach – Binary Search Inside a Loop
1. 🔁 Iterate through each number in the array.
2. 🧮 Compute the complement:
    ```
    lostNumber = target - numbers[currentIndex]
    ```
3. 🔍 Perform **binary search** on the **right side of the array** (from **`currentIndex + 1`** to end) to find **`lostNumber`**.
4. ✅ If found, return the **1-based indices** immediately.

### 📝 Pseudocode
```
function twoSum(numbers, target):
    for currentIndex from 0 to numbers.length-1:
        lostNumber = target - numbers[currentIndex]
        left = currentIndex + 1
        right = numbers.length - 1
        
        # Binary Search for lostNumber
        while left <= right:
            mid = left + (right - left) / 2
            if numbers[mid] == lostNumber:
                return [currentIndex + 1, mid + 1]  # 1-based indices
            else if numbers[mid] < lostNumber:
                left = mid + 1
            else:
                right = mid - 1
                
    return [-1, -1]  # No solution found
```

### ⏱️ Complexity Analysis
| **Aspect** | **Complexity**   | **Explanation**                                          |
| ------ | ------------ | ---------------------------------------------------- |
| Time   | **`O(n log n)`** | Iterate through n numbers × binary search **`O(log n)`** |
| Space  | **`O(1)`**       | Constant extra space (excluding output)              |

### 💡 Key Takeaways
- Works only on **sorted arrays**.
- Returns **1-based indices**.
- Excellent for practicing **binary search in iterative loops**.
- Handles **positive, negative, duplicate, and edge case numbers**.
- Demonstrates how **divide-and-conquer** can reduce search time efficiently. 🧩
---