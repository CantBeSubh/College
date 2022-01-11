#1 possible paths
#2 path cost
#3 best path(Dijikstra)
import graph

graph.add_vertex(0)
graph.add_vertex(1) 
graph.add_vertex(2)
graph.add_vertex(3)
graph.add_vertex(4)
graph.add_vertex(5)
graph.add_vertex(6)
graph.add_vertex(7)
graph.add_vertex(8)


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

