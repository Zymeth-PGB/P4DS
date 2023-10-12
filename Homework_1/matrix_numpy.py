import random as rd
import numpy as np
import time as t

# Random size of square matrix
n = rd.randint(100, 500)

# Generate matrix A and B with value in range -10 -> 10
matrix1 = np.random.randint(-10, 10, size = (n, n))
matrix2 = np.random.randint(-10, 10, size = (n, n))

# Record start time
start = t.time()

# Multiplication matrix
matrix = np.matmul(matrix1, matrix2)

# Record end time
end = t.time()

# Calculate runtime of function multiply two matrix
print("Runtime : ", end="")
print("{0:.10f}".format((end - start) * 10**3))