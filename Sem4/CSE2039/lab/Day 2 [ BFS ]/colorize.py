from termcolor import colored,cprint
import random

color=[
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

def rand(text):
    final=''
    for i in text:
        final+=colored(i,random.choice(color))
    return final

print_green_on_green = lambda x: cprint(x, 'green', 'on_green')