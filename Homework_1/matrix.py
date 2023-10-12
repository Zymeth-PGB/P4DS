import random as rd
import time as t

def generate_matrix(n):
    matrix = []
    
    for i in range(n):
        matrix.append([])
        for j in range(n):
            matrix[i].append(rd.randint(-10, 10))
    
    return matrix

def mul_matrix(n, m1, m2):
    m = []
    
    for i in range(n):
        m.append([])
        for j in range(n):
            m[i].append(0)
            
    i, h = 0, 0
    
    while i != n:
        temp = 0
        for j in range(n):
            temp += m1[i][j] * m2[j][h]        
        m[i][h] = temp
        h += 1
        if h == n:
            i += 1
            h = 0
    
    return m

# Random size of square matrix
n = rd.randint(100, 500)

# Generate matrix A and B with value in range -10 -> 10
matrix1 = generate_matrix(n)
matrix2 = generate_matrix(n)

# Record start time
start = t.time()

# Multiplication matrix
matrix = mul_matrix(n, matrix1, matrix2)

# Record end time
end = t.time()

# Calculate runtime of function multiply two matrix
print("Runtime : ", end = "")
print("{0:.10f}".format((end - start) * 10**3))