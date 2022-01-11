#global vars
graph = {}
all_paths=[]
data=[]
vertices_no = 0


def add_vertex(v):                                          # Add a vertex to the dictionary
  global graph
  global vertices_no
  if v in graph:
    print("Vertex ", v, " already exists.")
  else:
    vertices_no = vertices_no + 1
    graph[v] = []


def add_edge(v1, v2, e):                                    # Add an edge between vertex v1 and v2 with edge weight e
  global graph
  if v1 not in graph:
    print("Vertex ", v1, " does not exist.")
  elif v2 not in graph:
    print("Vertex ", v2, " does not exist.")
  else:
    graph[v1].append((v2, e))



def print_graph():                                          # Print the graph
  global graph
  for vertex in graph:
    for edges in graph[vertex]:
      print(vertex, " -> ", edges[0], " edge weight: ", edges[1])


def find_all_paths(start, end, path=[]):   
    global graph                                            #find all possible paths
    path = path + [start]
    if start == end:
        return [path]
    if not(start in [*graph]):
        return []
    paths = []
    for node,wt in graph[start]:
        if node not in path: 
            newpaths = find_all_paths(node, end, path)
            for newpath in newpaths:
                paths.append(newpath)               
    return paths


def weight(path):                                           #Calculate weight for given path
    global graph
    total_weight=0
    for i in range(0,len(path)):
        if i+1==len(path):
            break
        _from=path[i]
        _to=path[i+1]
        nodes=graph[_from]
        for node,wt in nodes:
            if node==_to:
                total_weight+=wt        
                break
    return total_weight


def cook_data():                                            #cook data
    global graph
    global all_paths
    global data

    for path in all_paths:
        data.append((path,weight(path)))
    return data


def find_shortest_path():                               #shortest Path
    global data
    min_path=[]
    min_wt=1000000
    for path,wt in data:
        if wt<min_wt:
            min_wt=wt
            min_path=path.copy()
    return min_path,min_wt

def print_paths():
    print(all_paths)