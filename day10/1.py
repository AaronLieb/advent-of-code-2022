import sys
lines = [line.rstrip() for line in sys.stdin.readlines()]


WIDTH = 40
HEIGHT = 6

instructions = []
X = 1
cycle = 0

def tick():
    global cycle
    cycle += 1
    if ((cycle) % WIDTH == 1):
        print()
    if (abs((cycle%WIDTH) - X) < 2):
        print("🟧", end='')
    else:
        print("⬛️", end='')

for line in lines:
    tick()
    if "noop" in line:
        # consume cycle
        continue
    op, num = line.split()
    # is addx
    # run both cycles of current instruction
    X += int(num)
    tick()

print()

