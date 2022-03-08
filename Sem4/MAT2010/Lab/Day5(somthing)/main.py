import numpy as np
from scipy.linalg import svd
# define a matrix

def SVD(arr):
    print(arr)
    # SVD
    U, s, VT = svd(arr)
    print(U)
    print(s)
    print(VT)
    print('--'*30)

A = np.array([[1, 1,0], [0, 0, 1]])
SVD(A)
B = np.array([[0,0],[0,3],[-2,0]])
SVD(B)
C=np.array([[1,1],[1,0],[0,1]])
SVD(C)
print('$'*30)

