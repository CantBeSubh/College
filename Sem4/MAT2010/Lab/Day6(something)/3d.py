import numpy as np
from mpl_toolkits.mplot3d.art3d import Poly3DCollection
import matplotlib.pyplot as plt
vertices = np.zeros([3, 8], dtype=int)
vertices[0, :] = [3, 1, 5, 7, 4, 2, 5, 7]
vertices[1, :] = [8, 4, 7, 3, 8, 6, 1, 3]
vertices[2, :] = [8, 4, 2, 6, 1, 5, 2, 6]
vertices = vertices - 1
rectp = np.zeros([8,3])
rectp[:,0] = [0, 1, 0, 1, 1, 0, 1, 0]
rectp [:,1] = [0, 2, 0, 2, 0, 2, 0, 2]
rectp [:,2] = [0, 0, 3, 3, 0, 0, 3, 3]
theta = 45
mat = np.zeros([3, 3])
mat[:,0] = [np.cos(theta), -np.sin(theta), 0]
mat[:, 1] = [np.sin(theta), np.cos(theta), 0]
mat[:, 2] = [0, 0, 1]
rectp = np.dot(rectp, mat)
plot1 = plt.figure(1)
ax = plot1.add_subplot(111, projection='3d')
ax.plot(rectp [vertices[0,:],0],rectp[vertices[0,:],1], rectp [vertices[0,:],2],color='g')
ax.plot(rectp[vertices[1,:],0], rectp[vertices[1,:],1], rectp [vertices[1,:],2],color='g')
ax.plot(rectp[vertices[2,:],0], rectp[vertices[2,:],1], rectp [vertices[2,:],2],color='g')
ax.set_xlabel('X')
ax.set_ylabel('Y')
ax.set_zlabel('Z')
plt.show()