import Polygen2D
import numpy as np
import matplotlib.pyplot as plt
coord = [[1,1],[1,2],[1.5,2.5],[2,2], [2,1],[1,1]]
xs,ys = zip(*coord) # create lists of x and y values
plot1= plt.figure(1)
plt.plot(xs,ys)
A=np.array([[1, 0],[0,-1]])
B= np.array([[1,1],[1,2],[1.5,2.5],[2,2],[2,1],[1,1]])
print(B)
B1=B.transpose((1, 0))
print(B1)
C = np.matmul(A, B1)
print(C)
xs1,ys1 = (C)
#plot2=plt.figure(2)
plt.plot(xs1,ys1)
plt.legend(["Reflection in y-Axis "], loc="upper right")
plt.show()