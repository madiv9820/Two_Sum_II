# [🎯 Two Sum II — Sorted Array Challenge](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/?envType=study-plan-v2&envId=top-interview-150)

You’re given a **1-indexed** array of integers **`numbers`** 📊, already sorted in **non-decreasing order**. Your task is to find **two distinct elements** whose sum equals a given **`target`** 🎯.

Let those elements be:
- **`numbers[index1]`**
- **`numbers[index2]`**

with the condition:
👉 **`1 <= index1 < index2 <= numbers.length`**

### 🧩 What You Need to Do

Return the indices of these two numbers as:
```
[index1, index2]
```
📌 Both indices should be **1-based** (not 0-based).

### ⚠️ Important Rules
- ✅ Exactly **one valid solution** exists.
- 🚫 You **cannot reuse** the same element.
- ⚡ Your solution must use **constant extra space** (O(1)).

### 📌 Examples
#### Example 1
```
Input:  numbers = [2, 7, 11, 15], target = 9  
Output: [1, 2]
```
💡 Because 2 + 7 = 9

#### Example 2
```
Input:  numbers = [2, 3, 4], target = 6  
Output: [1, 3]
```
💡 Because 2 + 4 = 6

#### Example 3
```
Input:  numbers = [-1, 0], target = -1  
Output: [1, 2]
```
💡 Because -1 + 0 = -1

### 📏 Constraints
- 🔢 `2 <= numbers.length <= 3 * 10⁴`
- 🔢 `-1000 <= numbers[i] <= 1000`
- 📈 Array is **sorted in non-decreasing order**
- 🎯 `-1000 <= target <= 1000`
- ✅ Exactly **one solution guaranteed**

This problem is all about leveraging the **sorted nature of the array** while respecting strict constraints 🚀

---