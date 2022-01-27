import sys
from termcolor import colored, cprint


def dfs(graph,start):
  stack=[start]
  parents={start: start}
  path=list()
  count=0
  while stack:
    vertex=stack.pop(-1)
    for candidate in graph[vertex]: 
      if candidate not in parents:
        parents[candidate]=vertex
        stack.append(candidate)
    count+=1
    path.append(parents[vertex]+'>'+vertex)
  return (path[1:],count)

# Colors
color = ["red", "green", "yellow", "blue", "magenta", "cyan", "white"]

process = color[4]
_input = color[5]
output = color[1]

# MAIN CODE
cprint(
    """
DDDDDDDDDDDDD______FFFFFFFFFFFFFFFFFFFFFF___SSSSSSSSSSSSSSS_
D::::::::::::DDD___F::::::::::::::::::::F_SS:::::::::::::::S
D:::::::::::::::DD_F::::::::::::::::::::FS:::::SSSSSS::::::S
DDD:::::DDDDD:::::DFF::::::FFFFFFFFF::::FS:::::S_____SSSSSSS
__D:::::D____D:::::D_F:::::F_______FFFFFFS:::::S____________
__D:::::D_____D:::::DF:::::F_____________S:::::S____________
__D:::::D_____D:::::DF::::::FFFFFFFFFF____S::::SSSS_________
__D:::::D_____D:::::DF:::::::::::::::F_____SS::::::SSSSS____
__D:::::D_____D:::::DF:::::::::::::::F_______SSS::::::::SS__
__D:::::D_____D:::::DF::::::FFFFFFFFFF__________SSSSSS::::S_
__D:::::D_____D:::::DF:::::F_________________________S:::::S
__D:::::D____D:::::D_F:::::F_________________________S:::::S
DDD:::::DDDDD:::::DFF:::::::FF___________SSSSSSS_____S:::::S
D:::::::::::::::DD_F::::::::FF___________S::::::SSSSSS:::::S
D::::::::::::DDD___F::::::::FF___________S:::::::::::::::SS_
DDDDDDDDDDDDD______FFFFFFFFFFF____________SSSSSSSSSSSSSSS___
""",
    "green",
)

cprint("[*]Booting...", process)

def print_paths(graph):#Print the paths
    for node in graph:
        print(node,'->',end=' ')
        print(*graph[node],sep=',')

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

cprint('[*]Graph1: ',process)
print_paths(graph1)
cprint('[*]Graph2: ',process)
print_paths(graph2)

cprint("[+]Possible path: \n", output)
(steps,count)=dfs(graph1, '5')
print(*steps,'|',len(steps),'steps@',count,'iterations\n')

cprint("[+]Possible path: \n", output)
(steps,count)=dfs(graph2, '25')
print(*steps,'|',len(steps),'steps@',count,'iterations\n')