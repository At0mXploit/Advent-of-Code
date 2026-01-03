lights = [[0] * 1000 for _ in range(1000)]

with open('input.txt', 'r') as f:
    for line in f:
        line = line.strip()
        parts = line.split()

        if parts[0] == "toggle":
            action = "toggle"
            start_coords = parts[1]
            end_coords = parts[3]
        else:
            # parts[0] is "turn", parts[1] is "on" or "off"
            action = parts[0] + " " + parts[1]  # e.g., "turn on" or "turn off"
            start_coords = parts[2]
            end_coords = parts[4]

        x1, y1 = map(int, start_coords.split(','))
        x2, y2 = map(int, end_coords.split(','))

        # Ensure we go from min to max in case coordinates are given in reverse
        # (though AoC input usually gives x1 <= x2 and y1 <= y2, but being safe doesn't hurt)
        # Also added 1 at for loop to be inclusive meaning range(a,b) gives number from a up to but not including b we don't want that so we added 1
        for x in range(min(x1, x2), max(x1, x2) + 1):
            for y in range(min(y1, y2), max(y1, y2) + 1):
                if action == "turn on":
                    lights[x][y] = 1
                elif action == "turn off":
                    lights[x][y] = 0
                elif action == "toggle":
                    lights[x][y] = 1 - lights[x][y]  # flips 0↔1

# Count total lit lights
total = sum(sum(row) for row in lights)
print(total)
