with open("input.txt") as f:
    lines = f.readlines()


def print_matrix(m):
    for row in m:
        for v in row:
            print(v, end=', ')
        print()
    print()


heights = [[int(y) for y in x.rstrip()] for x in lines]
LENGTH = len(heights[0])
HEIGHT = len(heights)

vis = []
for i in range(HEIGHT):
    vis.append([1] * LENGTH)

max_left = []
max_right = []
for i in range(HEIGHT):
    max_left.append((-1, 0, i, []))
    max_right.append((-1, 0, i, []))

max_top = []
max_bottom = []
for i in range(LENGTH):
    max_top.append((-1, 0, i, []))
    max_bottom.append((-1, 0, i, []))

debug_x = 3
debug_y = 1

for x in range(LENGTH):
    for y in range(HEIGHT):
        tree = heights[y][x]
        score = 1
        for between in max_left[y][3]:
            if tree > between:
                score += 1
            else:
                break
        if tree > max_left[y][0]:
            score += max_left[y][1]
            if (y == 0 or y == HEIGHT - 1 or x == 0 or x == LENGTH -1):
                score = 0
            max_left[y] = (tree, score, x, [])
        else:
            max_left[y][3].insert(0, tree)
        if (x == debug_x and y == debug_y):
            print("left", tree, max_left[y], score)
        vis[y][x] *= score
        score = 1
        for between in max_top[x][3]:
            if tree > between:
                score += 1
            else:
                break
        if tree > max_top[x][0]:
            score += max_top[x][1]
            if (y == 0 or y == HEIGHT - 1 or x == 0 or x == LENGTH -1):
                score = 0
            max_top[x] = (tree, score, y, [])
        else:
            max_top[x][3].insert(0, tree)
        if (x == debug_x and y == debug_y):
            print("top", tree, max_top[x], score)
        vis[y][x] *= score

for x in reversed(range(LENGTH)):
    for y in reversed(range(HEIGHT)):
        tree = heights[y][x]
        score = 1
        for between in max_right[y][3]:
            if tree > between:
                score += 1
            else:
                break
        if tree > max_right[y][0]:
            score += max_right[y][1]
            if (y == 0 or y == HEIGHT - 1 or x == 0 or x == LENGTH -1):
                score = 0
            max_right[y] = (tree, score, x, [])
        else:
            max_right[y][3].insert(0, tree)
        if (x == debug_x and y == debug_y):
            print("right", tree, max_right[y], score)
        vis[y][x] *= score
        score = 1
        for between in max_bottom[x][3]:
            if tree > between:
                score += 1
            else:
                break
        if tree > max_bottom[x][0]:
            score += max_bottom[x][1]
            if (y == 0 or y == HEIGHT - 1 or x == 0 or x == LENGTH -1):
                score = 0
            max_bottom[x] = (tree, score, y, [])
        else:
            max_bottom[x][3].insert(0, tree)
        if (x == debug_x and y == debug_y):
            print("bottom", tree, max_bottom[x], score)
        vis[y][x] *= score

print_matrix(heights)
print_matrix(vis)

m = 0
for row in vis:
    for v in row:
        if v > m:
            m = v
print(m)








