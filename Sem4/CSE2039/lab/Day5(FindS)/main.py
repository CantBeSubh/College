import csv
attributes = [
    ['Sunny', 'Rainy'],
    ['Warm', 'Cold'],
    ['Normal', 'High'],
    ['Strong', 'Weak'],
    ['Warm', 'Cool'],
    ['Same', 'Change']
]
size = len(attributes)
print(" \n The most general hypothesis : ['?','?','?','?','?','?']\n")
print("\n The most specific hypothesis : ['0','0','0','0','0','0']\n")
a = []
print("\n The Given Training Data Set \n")

with open('ws.csv', 'r') as csvFile:
    reader = csv.reader(csvFile)
    for row in reader:
        a.append(row)
        print(row)

print("\n The initial value of hypothesis: ")
hypothesis = ['0'] * size
print(hypothesis)
for j in range(0, size):
    hypothesis[j] = a[0][j]
print("\n Find S: Finding a Maximally Specific Hypothesis\n")
for i in range(0, len(a)):
    if a[i][size] == 'Yes':
        for j in range(0, size):
            if a[i][j] != hypothesis[j]:
                hypothesis[j] = '?'
            else:
                hypothesis[j] = a[i][j]
    print(" For Training Example No :{0} the hypothesis is ".format(i), hypothesis)
    
print("\n The Maximally Specific Hypothesis for a given Training Examples :\n")
print(hypothesis)