#1 possible paths
#2 path cost
#3 best path

import graph

n=int(input('Enter number of vertex: '))
for i in range(n):
    graph.add_vertex(i)

while(True):
    opt=input('Add an edge?(Y for yes | N for No) ')
    if(opt.upper()=='N'):
        break
    _from=int(input('From: '))
    _to=int(input('To: '))
    _weight=int(input('Weight: '))
    graph.add_edge(_from,_to,_weight)
    
graph.add_edge(0,1,3)
graph.add_edge(0,8,4)
graph.add_edge(0,3,2)

graph.add_edge(1,0,3)
graph.add_edge(1,7,4)

graph.add_edge(2,7,2)
graph.add_edge(2,3,6)
graph.add_edge(2,5,1)

graph.add_edge(3,4,1)
graph.add_edge(3,0,2)
graph.add_edge(3,2,6)

graph.add_edge(4,8,8)
graph.add_edge(4,3,1)

graph.add_edge(5,6,8)
graph.add_edge(5,2,1)

graph.add_edge(6,5,8)

graph.add_edge(7,1,4)
graph.add_edge(7,2,2)

graph.add_edge(8,4,8)
graph.add_edge(8,0,4)

graph.print_graph()
print ("Internal representation: ", graph.graph)

start=int(input('Enter start position: '))
end=int(input('Enter end position: '))

graph.all_paths=graph.find_all_paths(start,end)
graph.print_paths()

graph.cook_data()
print(graph.find_shortest_path())

