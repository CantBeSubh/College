import numpy as np
import matplotlib.pyplot as plt

D=np.array([
    [0,0],
    [.5,0],
    [.5,6.42],
    [6,0],
    [6,8],
    [5.5,8],
    [5.5,1.58],
    [0,8],
    [0,0]
])
x,y=zip(*D)
plot1=plt.figure(1)
plt.plot(x,y)
d1=D.transpose((1,0))
A=np.array([
    [1,.25],
    [0,1]
])
C=np.matmul(A,d1)
print(C)
x,y=(C)
plt.plot(x,y)
plt.show()