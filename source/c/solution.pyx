from libc.stdlib cimport malloc, free

# 🔹 Declare the external C function from solution.h
cdef extern from 'solution.h':
    int* twoSum(int* numbers, int numbersSize, int target, int* returnSize)

# 🔹 Cython wrapper for the C twoSum function
cdef class cSolution:
    def c_twoSum(self, numbers, target):
        """
        🧪 Python wrapper for the C twoSum function
        - Converts Python list to C array using malloc
        - Calls the C function
        - Converts the C array result back to Python list
        - Frees all allocated C memory
        """

        # 🔹 Number of elements in the input list
        cdef int c_numbersSize = len(numbers)

        # 🔹 Target value
        cdef int c_target = target

        # 🔹 Allocate C array for input numbers
        cdef int* c_numbers = <int*> malloc(c_numbersSize * sizeof(int))

        # 🔹 Allocate C array for storing the size of the returned result
        cdef int* c_returnSize = <int*> malloc(sizeof(int))
        c_returnSize[0] = 0  # Initialize return size to 0

        # 🔄 Copy Python list into the allocated C array
        for i in range(len(numbers)):
            c_numbers[i] = numbers[i]

        # ⚙️ Call the C function twoSum
        cdef int* cpp_result = twoSum(
            c_numbers, 
            c_numbersSize, 
            c_target, 
            c_returnSize
        )

        # 🔄 Convert C array result to Python list
        result = []
        if cpp_result is not NULL:
            for i in range(c_returnSize[0]):
                result.append(cpp_result[i])

            # 🧹 Free the memory allocated by the C function for the result
            free(cpp_result)

        # 🧹 Free local C arrays
        free(c_numbers)
        free(c_returnSize)

        # 🔙 Return the Python list result
        return result