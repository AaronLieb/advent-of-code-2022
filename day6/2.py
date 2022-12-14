with open("input.txt") as f:
    lines = f.readlines()


line = lines[0] 

prev = []
for i, c in enumerate(line):
    prev.insert(0, c)
    if (len(prev) > 14) :
        prev.pop()
    if len(set(prev)) == 14:
        print(i + 1)
        break



