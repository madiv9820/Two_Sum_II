import os, json, unittest
from typing import List
from timeout_decorator import timeout
from source.c.solution import cSolution

class test_cSolution(unittest.TestCase):
    def setUp(self):
        """
        🛠️ Setup method:
        - Loads test cases from JSON 📂
        - Initializes the solution instance 🧠
        """
        # 📍 Get the current directory of this test file
        currentDirectory = os.path.dirname(os.path.abspath(__file__))

        # 📄 Construct path to test_cases.json
        filePath = os.path.join(currentDirectory, 'cases/cases.json')

        # 📖 Read and load JSON test cases
        with open(filePath, mode="r", encoding="utf-8") as read_file:
            self.__testcases = json.load(read_file)

            # 🧠 Initialize solution class
            self.__solution = cSolution()

        return super().setUp()
    
    @timeout(1)  # ⏱️ Ensure each test runs within 1 second
    def test(self):
        """
        🧪 Main test runner:
        Iterates over all test cases and validates outputs ✅
        """
        for testcases in self.__testcases:

            # 🏷️ Extract test case details
            testname: str = testcases['title']
            numbers: List[int] = testcases['input']['numbers']
            target: int = testcases['input']['target']
            expectedOutput: List[int] = testcases['output']

            # 🔍 Run each test as a subTest for better isolation
            with self.subTest(testname):

                # ⚙️ Call the solution method
                actualOutput: bool = self.__solution.c_twoSum(
                    numbers=numbers,
                    target=target
                )

                # ✅ Assert the result matches expected output
                self.assertEqual(len(actualOutput), len(expectedOutput))

                 # ✅ Check that each element matches the expected output
                self.assertTrue(
                    all(
                        actual == expected 
                        for actual, expected in 
                        zip(actualOutput, expectedOutput)
                    )
                )

# 🚀 Entry point to run tests
if __name__ == '__main__':
    unittest.main()