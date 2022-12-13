with open("input.txt") as f:
    lines = f.readlines()

cols = int(len(lines[0])/4)

stacks = []
for i in range(cols):
    stacks.append([])

for line in lines:
    if "[" in line:
        for i, c in enumerate(line):
            if c.isalpha():
                stacks[int((i-1)/4)].insert(0, c)
    if "move" in line:
        parts = line.split()
        num = int(parts[1])
        src = int(parts[3])
        dest = int(parts[5])
        crates = stacks[src-1][-num:]
        for i in range(num):
            stacks[dest-1].append(crates[i])
            val = stacks[src-1].pop()

for stack in stacks:
    print(stack.pop(), end='')
print()



