with open("input.txt") as f:
    lines = f.readlines()


class File:
    def __init__(self, name, size, parent):
        self.name = name
        self.children = {}
        self.parent = parent
        self.size = size

    def add_child(self, file):
        self.children[file.name] = file


root = File("/", 0, None)
curr = root

for line in lines[1:]:
    args = line.split()
    if "dir" in line:
        new_dir = File(args[1], 0, curr)
        curr.add_child(new_dir)
    elif "$" not in line:
        new_file = File(args[1], int(args[0]), curr)
        curr.add_child(new_file)
    elif "ls" in line:
        continue 
    elif "cd" in line:
        if args[2] == "..":
            curr = curr.parent
        else:
            curr = curr.children[args[2]]


cum_sum = 0

def sizes(file):
    global cum_sum
    size = file.size
    for name, child in file.children.items():
        size += sizes(child)
    if (len(file.children) > 0 and size <= 100000):
        print(file.name, size)
        cum_sum += size
    return size

sizes(root)

print(cum_sum)
        





