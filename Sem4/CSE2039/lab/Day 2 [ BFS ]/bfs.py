#BFS in BST by 20BRS1064
#11th Jan 2021
from termcolor import colored,cprint
import random
color=[
    'grey',
    'red',
    'green',
    'yellow',
    'blue',
    'magenta',
    'cyan',
    'white'
]
def rand():
    return random.choice(color)

#insert Left to Right
graph1 = {
  '5' : ['3','7'],
  '3' : ['2', '4'],
  '7' : ['8'],
  '2' : [],
  '4' : ['8'],
  '8' : []
}

graph2 = {
    '25':['20','36'],
    '20':['10','22'],
    '36':['30','40'],
    '10':['5','12'],
    '22':[],
    '30':['28'],
    '40':['38','48'],
    '5':[],
    '12':[],
    '28':[],
    '38':[],
    '48':[]
}

visited = [] 
queue = []     

def bfs(visited, graph, node):
  visited.append(node)
  queue.append(node)
  cprint('[+] ','green',end='')
  while queue:          
    temp = queue.pop(0) 
    cprint(temp+" ",rand(),end=' ') 

    for neighbour in graph[temp]:
      if neighbour not in visited:
        visited.append(neighbour)
        queue.append(neighbour)

print("--------Breadth-First Search--------")
cprint('[*] Graph 1','green')
bfs(visited, graph1, '5')
cprint('\n[*] Graph 2','green')
bfs(visited, graph2, '25')
