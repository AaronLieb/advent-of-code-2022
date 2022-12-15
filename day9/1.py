with open("input.txt") as f:
    lines = f.readlines()

visited = set()

head = [0, 0]
tail = [0, 0]

for line in lines:
    parts = line.split()
    d = parts[0]
    n = int(parts[1])

    for i in range(n):
        if d == "R":
            head[0] += 1
        elif d == "L":
            head[0] -= 1
        elif d == "U":
            head[1] += 1
        elif d == "D":
            head[1] -= 1

        # head = 5, 2
        # tail = 3, 2
        if head[0] - tail[0] > 1:
            tail[1] = head[1]
            tail[0] += 1
        if head[0] - tail[0] < -1:
            tail[1] = head[1]
            tail[0] -= 1

        if head[1] - tail[1] > 1:
            tail[0] = head[0]
            tail[1] += 1
        if head[1] - tail[1] < -1:
            tail[0] = head[0]
            tail[1] -= 1

        visited.add(tuple(tail))

print(len(visited))

