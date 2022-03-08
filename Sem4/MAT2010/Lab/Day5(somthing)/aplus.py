import numpy as np
from scipy.linalg import svd
A = np.array([[1, 1], [0, 0, 1]])
U, D, V = np.linalg.svd(A)
D_plus = np.zeros((A.shape[0], A.shape[1])).T
D_plus[:D.shape[0], :D.shape[0]] = np.linalg.inv(np.diag(D))
A_plus = V.T.dot(D_plus).dot(U.T)
print(A_plus)
print('--'*30)
# C=np.array([[1,1],[1,0],[0,1]])
# U, D, V = np.linalg.svd(C)
# D_plus = np.zeros((C.shape[0], C.shape[1])).T
# D_plus[:D.shape[0], :D.shape[0]] = np.linalg.inv(np.diag(D))
# C_plus = V.T.dot(D_plus).dot(U.T)
# print(C_plus)