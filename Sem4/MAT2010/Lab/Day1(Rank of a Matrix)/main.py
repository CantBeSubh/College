import numpy as np
import scipy.linalg as la
from termcolor import colored,cprint

A = np.array(
    [
        [1, 2, 1], 
        [1, -2, 3], 
        [3, -7, 4]
    ]
)

cprint(A,'green')
rank = np.linalg.matrix_rank(A)
print(rank)

A1 = np.array(
    [
        [1, -1, 2], 
        [1, 2, -1], 
        [0,2 , -2]
    ]
)
AB=  np.array(
    [
        [1, -1, 2, 3], 
        [1, 2, -1,-3], 
        [0,2 , -2,1]
    ]
)
print(np.linalg.matrix_rank(A1))
print(np.linalg.matrix_rank(A))

A2 = np.array(
    [
        [1, 5, 7], 
        [2, 3, 6], 
        [4,3,6]
    ]
)
b= np.array([4, 10, 12])
sol=np.linalg.solve(A2,b)
print(sol)

inverse=np.linalg.inv(A)
print(inverse)
a = np.array([[0, 1, 1],[1, 2, 1], [3, 9, 8]])
(P, L, U) = la.lu(a)
print(P)
print(L)
print(U)