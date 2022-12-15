with open("input.txt") as f:
    lines = f.readlines()

visited = set()

knots = []
for i in range(10):
    knots.append([0, 0])

for line in lines:
    parts = line.split()
    d = parts[0]
    n = int(parts[1])

    for i in range(n):
        if d == "R":
            knots[0][0] += 1
        elif d == "L":
            knots[0][0] -= 1
        elif d == "U":
            knots[0][1] += 1
        elif d == "D":
            knots[0][1] -= 1

        for i in range(1, len(knots)):
            prev = knots[i-1]
            knot = knots[i]

            snap = True
            if abs(prev[0] - knot[0]) > 1 and abs(prev[1] - knot[1]) > 1:
                snap = False

            if prev[0] - knot[0] > 1:
                if snap:
                    knot[1] = prev[1]
                knot[0] += 1
            if prev[0] - knot[0] < -1:
                if snap:
                    knot[1] = prev[1]
                knot[0] -= 1

            if prev[1] - knot[1] > 1:
                if snap:
                    knot[0] = prev[0]
                knot[1] += 1
            if prev[1] - knot[1] < -1:
                if snap:
                    knot[0] = prev[0]
                knot[1] -= 1

        visited.add(tuple(knots[-1]))

print(knots)
print(len(visited))

