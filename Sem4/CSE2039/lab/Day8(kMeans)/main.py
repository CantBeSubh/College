import numpy as np
import matplotlib as plt
from sympy import centroid
def rand(x,k):
    idx=[np.random.radiant(len(x) for i in range(k))]
    centeroids=[]
    for i in idx:
        centeroids.append(x[i])
    return centeroids

def assign(x,centeroids,k):
    cluster=[]
    for i in range(len(x)):
        dist=[]
        for j in range(k):
            dist.append(np.linalg.norm(np.subtract(x[i],centeroids[j])))
        idx=np.argmin(dist)
        cluster.append(idx)
    return np.asarray(cluster)

def compute(x,clusters,k):
    centroid=[]
    for i in range(k):
        temp=[]
        for j in range(len(x)):
            if clusters[j]==i:
                temp.append(x[j])
        centroid.append(np.mean(temp,axis=0))
    return np.asarray(centroid)

def diff(a,b):
    d=0
    for i in range(len(a)):
        d+=np.linalg.norm(a[i]-b[i])
    return d

def show(x,clusters,centroids,mainCentroids,markCentroids=True):
    cols={0:'r'}
    fig,ax=plt.subplots(figsize=(7.5,6))
    for i in range(len(centroids)):
        ax.scatter(x[i][0],x[i][1],color=cols[clusters[i]])
    for j in range(len(centroids)):
        ax.scatter(centroids[j][0],centroids[j][1],marker='*',color=cols[j])
    for i in range(len(centroids)):
        ax.add_artist(plt.Circle((mainCentroids[i][0],mainCentroids[j][1],marker="+",s=150,color=cols[j])))
