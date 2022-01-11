# Libraries
import sys

try:
    print("\n[*]Importing Modules/Libraries\n")
    from termcolor import colored, cprint
    from colorize import rand
    import graph
except:
    print("Module/Library not found!Refer README.md...\nExiting!")
    sys.exit()

# Colors
color = ["red", "green", "yellow", "blue", "magenta", "cyan", "white"]

process = color[4]
_input = color[5]
output = color[1]


# MAIN CODE
cprint(
    """
BBBBBBBBBBBBBBBBB___FFFFFFFFFFFFFFFFFFFFFF___SSSSSSSSSSSSSSS_  
B::::::::::::::::B__F::::::::::::::::::::F_SS:::::::::::::::S
B::::::BBBBBB:::::B_F::::::::::::::::::::FS:::::SSSSSS::::::S
BB:::::B_____B:::::BFF::::::FFFFFFFFF::::FS:::::S_____SSSSSSS
__B::::B_____B:::::B__F:::::F_______FFFFFFS:::::S____________
__B::::B_____B:::::B__F:::::F_____________S:::::S____________
__B::::BBBBBB:::::B___F::::::FFFFFFFFFF____S::::SSSS_________
__B:::::::::::::BB____F:::::::::::::::F_____SS::::::SSSSS____
__B::::BBBBBB:::::B___F:::::::::::::::F_______SSS::::::::SS__
__B::::B_____B:::::B__F::::::FFFFFFFFFF__________SSSSSS::::S_
__B::::B_____B:::::B__F:::::F_________________________S:::::S
__B::::B_____B:::::B__F:::::F_________________________S:::::S
BB:::::BBBBBB::::::BFF:::::::FF___________SSSSSSS_____S:::::S
B:::::::::::::::::B_F::::::::FF___________S::::::SSSSSS:::::S
B::::::::::::::::B__F::::::::FF___________S:::::::::::::::SS_
BBBBBBBBBBBBBBBBB___FFFFFFFFFFF____________SSSSSSSSSSSSSSS___
""",
    "green",
)

cprint("[*]Booting...", process)

n = int(input(colored("[?]Enter number of vertex(default=9): ", _input)))
for i in range(n):
    graph.add_vertex(i)

while True:
    opt = input(
        colored("[?]Add an edge?(Y for yes | N for No | D for Default ): ", _input)
    )
    if opt.upper() == "D":
        graph.add_edge(0, 1, 3)
        graph.add_edge(0, 8, 4)
        graph.add_edge(0, 3, 2)

        graph.add_edge(1, 0, 3)
        graph.add_edge(1, 7, 4)

        graph.add_edge(2, 7, 2)
        graph.add_edge(2, 3, 6)
        graph.add_edge(2, 5, 1)

        graph.add_edge(3, 4, 1)
        graph.add_edge(3, 0, 2)
        graph.add_edge(3, 2, 6)

        graph.add_edge(4, 8, 8)
        graph.add_edge(4, 3, 1)

        graph.add_edge(5, 6, 8)
        graph.add_edge(5, 2, 1)

        graph.add_edge(6, 5, 8)

        graph.add_edge(7, 1, 4)
        graph.add_edge(7, 2, 2)

        graph.add_edge(8, 4, 8)
        graph.add_edge(8, 0, 4)
        break

    if opt.upper() == "N":
        break

    _from = int(input("[?]From: "))
    _to = int(input("[?]To: "))
    _weight = int(input("[?]Weight: "))
    graph.add_edge(_from, _to, _weight)


cprint("[+]Final Graph\n", output)
graph.print_graph()
print(colored("\n[+]Internal Representation\n", output))
cprint(str(graph.graph), "white")

cprint("\n------------------------------------------------------------\n", "white")

start = int(input(colored("[?]Enter start position: ", _input)))
end = int(input(colored("[?]Enter end position: ", _input)))

cprint("[*]Finding all possible paths...", process)
graph.all_paths = graph.find_all_paths(start, end)
cprint("[*]Cooking Data...", process)
graph.cook_data()
cprint("[+]All possible paths: \n", output)
graph.print_paths()
print("\n")

cprint("___SHORTEST PATH___", "cyan", attrs=["reverse"])
p, wt = graph.find_shortest_path()
print("\n", end="")
print(*p, sep=" -> ", end=" | ")
print(wt)

cprint("------------------------------------------------------------\n", "white")
