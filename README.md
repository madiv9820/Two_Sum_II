# Two Sum II — Two Pointer Approach 👈👉
### 💡 Intuition

Since the array is **sorted**, we can use **two pointers** to find the pair efficiently:
- Start with one pointer at the **beginning** and another at the **end**.
- Calculate the sum of the two numbers.
- If the sum is **less than the target**, move the left pointer to the right.
- If the sum is **greater than the target**, move the right pointer to the left.
- If the sum equals the target, we’ve found the solution. ✅

Think of it as **“closing the gap from both ends”** until you hit the target. 🎯

### ⚡ Approach
1. 🔁 Initialize two pointers: **`left = 0`** and **`right = n - 1`**.
2. 🧮 While **`left < right`**:
    - Calculate **`currentSum = numbers[left] + numbers[right]`**.
    - If **`currentSum == target`**, return [**`left+1, right+1]`** (1-based).
    - If **`currentSum < target`**, increment **`left`**.
    - If **`currentSum > target`**, decrement **`right`**.
3. ✅ Return the result.

### 📝 Pseudocode
```
function twoSum(numbers, target):
    left = 0
    right = numbers.length - 1

    while left < right:
        currentSum = numbers[left] + numbers[right]

        if currentSum == target:
            return [left+1, right+1]  # 1-based indices
        else if currentSum < target:
            left += 1
        else:
            right -= 1

    return [-1, -1]  # No solution found
```

### ⏱️ Complexity Analysis
| **Aspect** | **Complexity** | **Explanation**                             |
| ------ | ---------- | --------------------------------------- |
| Time   | **`O(n)`**     | Single pass using two pointers          |
| Space  | **`O(1)`**     | Constant extra space (excluding output) |

### 💡 Key Takeaways
- Works only for **sorted arrays**.
- Returns **1-based indices**.
- ⬆️ Simpler, faster, and cleaner than binary search inside a loop.
- Handles **positive, negative, duplicates, and edge cases** efficiently.
- Excellent for learning **two-pointer pattern** – a fundamental technique in array problems. 🧩

---