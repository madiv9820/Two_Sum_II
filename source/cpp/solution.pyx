from libcpp.vector cimport vector

# 🔹 Declare the external C++ Solution class from solution.hpp
cdef extern from 'solution.hpp':
    cdef cppclass Solution:
        Solution() except +  # Constructor may throw exceptions
        vector[int] twoSum(vector[int]& numbers, int target)  # Method to solve Two Sum II

# 🔹 Cython wrapper for the C++ Solution class
cdef class cppSolution:
    cdef Solution *ptr  # Pointer to hold the C++ Solution instance

    def __init__(self) -> None:
        """
        🛠️ Initialize the C++ Solution object
        """
        self.ptr = new Solution()  # Allocate C++ object

    def __dealloc__(self) -> None:
        """
        🗑️ Clean up memory when Python object is deleted
        """
        del self.ptr  # Free C++ object memory
    
    def cpp_twoSum(self, numbers, target):
        """
        🧪 Python wrapper for the C++ twoSum method
        - Converts Python list to C++ vector
        - Calls the C++ method
        - Converts result back to Python list
        """
        cdef vector[int] cpp_numbers  # C++ vector to hold input numbers
        cdef int cpp_target = target   # C++ int for target

        # 🔄 Convert Python list to C++ vector
        for i in range(len(numbers)):
            cpp_numbers.push_back(numbers[i])
        
        # ⚙️ Call the C++ twoSum method
        cdef vector[int] cpp_result = self.ptr.twoSum(cpp_numbers, cpp_target)

        # 🔄 Convert C++ vector result to Python list
        result = [cpp_result[i] for i in range(cpp_result.size())]

        # 🧹 Clear temporary C++ vector memory
        vector[int]().swap(cpp_result)

        return result  # Return Python list