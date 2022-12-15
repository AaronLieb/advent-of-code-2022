# Here was what the bug was
def print_matrix(m):
    for row in m:
        for v in row:
            print(v, end='')
        print()
    print()

matrix = [[0] * 5] * 5
print_matrix(matrix)

matrix[0][1] = 1
print_matrix(matrix)

