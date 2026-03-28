from typing import List

class pySolution:
    def py_twoSum(self, numbers: List[int], target: int) -> List[int]:
        # 📦 Initialize result with default invalid indices
        result = [-1, -1]

        # 👈👉 Two pointers: start from left and right ends
        leftIndex: int = 0
        rightIndex: int = len(numbers) - 1

        # 🔁 Move pointers towards each other until they meet
        while leftIndex < rightIndex:
            # 🧮 Calculate current sum of numbers at both pointers
            currentSum: int = numbers[leftIndex] + numbers[rightIndex]

            # 🎯 Found the target sum!
            if currentSum == target:
                # 🔢 Store 1-based indices
                result[0] = leftIndex + 1
                result[1] = rightIndex + 1
                break

            # ⬆️ Sum too small → move left pointer to the right
            elif currentSum < target:
                leftIndex += 1

            # ⬇️ Sum too large → move right pointer to the left
            else:
                rightIndex -= 1
        
        # 📤 Return the result
        return result