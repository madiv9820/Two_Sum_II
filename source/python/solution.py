from typing import List

class pySolution:
    def py_twoSum(self, numbers: List[int], target: int) -> List[int]:
        # 🔍 Binary Search Helper Function
        def binarySearch(
            lostNumber: int, 
            leftIndex: int = 0, 
            rightIndex: int = len(numbers) - 1
        ) -> int:
            # 🔁 Continue searching while valid range exists
            while leftIndex <= rightIndex:
                # ⚖️ Find middle index
                midIndex: int = leftIndex + (rightIndex - leftIndex) // 2
                
                # 🎯 Target found!
                if numbers[midIndex] == lostNumber:
                    return midIndex
                
                # ⬅️ Move left (reduce search space)
                elif numbers[midIndex] > lostNumber:
                    rightIndex = midIndex - 1
                
                # ➡️ Move right (increase search space)
                else:
                    leftIndex = midIndex + 1
            
            # ❌ Target not found
            return -1
        
        # 📦 Initialize result with default invalid indices
        result: List[int] = [-1, -1]
        
        # 🔁 Iterate through each number
        for currentIndex in range(len(numbers)):
            # 🧮 Calculate the number needed to reach target
            lostNumber: int = target - numbers[currentIndex]
            
            # 🔍 Search for the required number using Binary Search
            # 👉 Note: search starts from currentIndex + 1 to avoid reusing same element
            searchIndex: int = binarySearch(
                lostNumber=lostNumber, 
                leftIndex=currentIndex + 1
            )
            
            # ✅ If found, store 1-based indices (as required by problem)
            if searchIndex != -1:
                result[0] = currentIndex + 1
                result[1] = searchIndex + 1
                break  # 🚀 Exit early since solution is found
        
        # 📤 Return final result
        return result