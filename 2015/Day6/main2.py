brightness = [[0] * 1000 for _ in range(1000)] # All brightness starts at 0

with open('input.txt', 'r') as f:
    for line in f:
        line = line.strip()
        parts = line.split()

        if parts[0] == "toggle":
            action = "toggle"
            starts_coords = parts[1]
            end_coords = parts[3]
        else:
            action = parts[0] + " " + parts[1]
            starts_coords = parts[2]
            end_coords = parts[4]

        x1, y1 = map(int, starts_coords.split(','))
        x2, y2 = map(int, end_coords.split(','))

        for x in range(min(x1,x2), max(x1,x2) + 1):
            for y in range(min(y1,y2), max(y1, y2) +1):
                if action == "turn on":
                    brightness[x][y] += 1 
                elif action == "turn off":
                    brightness[x][y] = max(0, brightness[x][y] -1)
                elif action == "toggle":
                    brightness[x][y] += 2

total = sum(sum(row) for row in brightness)
print(total)
