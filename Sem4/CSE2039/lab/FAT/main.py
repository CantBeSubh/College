import random

def gen(a):
    A=[]
    for i in range(a):
        A.append([random.random()*100-50,random.random()*100-50])
    
    return A

def kMed(val,k):
    centroids=[]
    for i in range(k):
        centroids.append([random.random()*100-50,random.random()*100-50])

    print(centroids)
    clusters=[]
    for i in val:
        dis=[]
        for j in centroids:
            d=((j[1]-i[1])**2+(j[0]-i[0])**2)**.5
            dis.append(d)
        
        cluster=dis.index(min(dis))
        clusters.append(cluster)
    
    return clusters


def main():
    N=int(input('Enter N: '))
    k=int(input('Enter k: '))
    val=gen(N)
    print(val)
    clusters=kMed(val,k)
    print(clusters)
main()