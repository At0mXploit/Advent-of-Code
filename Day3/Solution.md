# Day 3: Perfectly Spherical Houses in a Vacuum 
Santa is delivering presents to an infinite two-dimensional grid of houses.

He begins by delivering a present to the house at his starting location, and then an elf at the North Pole calls him via radio and tells him where to move next. Moves are always exactly one house to the north (^), south (v), east (>), or west (<). After each move, he delivers another present to the house at his new location.

However, the elf back at the north pole has had a little too much eggnog, and so his directions are a little off, and Santa ends up visiting some houses more than once. How many houses receive at least one present?

For example:

- `>` delivers presents to 2 houses: one at the starting location, and one to the east.
- `^>v<` delivers presents to 4 houses in a square, including twice to the house at his starting/ending location.
- `^v^v^v^v^v` delivers a bunch of presents to some very lucky children at only 2 houses.
## Solution

Santa starts at a house located at coordinates (0, 0) on an infinite 2D grid.

He follows a sequence of directions:

- `^` = move North → y increases by 1
- `v` = move South → y decreases by 1
- `>` = move East → x increases by 1
- `<` = move West → x decreases by 1

At every position he visits (including the starting point), he delivers one present to that house.

The catch: He might visit the same house multiple times, but we only care about how many unique houses got at least one present.

We need to track every unique location Santa visits as he follows the directions.

- Start at (0, 0) → mark this house as visited.
- For each move in the instruction string:
- Update Santa’s current position based on the direction.
- Mark the new position as visited.
- At the end, count how many unique positions were visited.
- Since we only care about uniqueness, we don’t need to count how many presents each house got — just whether it got at least one.


Take the input: `^>v<`

- Start at (0, 0) → visited houses: {(0,0)}
- `^` → move to (0, 1) → visited: {(0,0), (0,1)}
- `>` → move to (1, 1) → visited: {(0,0), (0,1), (1,1)}
- `v` → move to (1, 0) → visited: {(0,0), (0,1), (1,1), (1,0)}
- `<` → move to (0, 0) → already visited! Set stays the same.

Total unique houses = 4

Note: Even though he ends where he started, we don’t double-count.

# Part Two 
The next year, to speed up the process, Santa creates a robot version of himself, Robo-Santa, to deliver presents with him.

Santa and Robo-Santa start at the same location (delivering two presents to the same starting house), then take turns moving based on instructions from the elf, who is eggnoggedly reading from the same script as the previous year.

This year, how many houses receive at least one present?

For example:

- `^v` delivers presents to 3 houses, because Santa goes north, and then Robo-Santa goes south.
- `^>v<` now delivers presents to 3 houses, and Santa and Robo-Santa end up back where they started.
- `^v^v^v^v^v` now delivers presents to 11 houses, with Santa going one direction and Robo-Santa going the other.
## Solution

This time:

- Two deliverers: Santa and Robo-Santa.
- They both start at (0, 0) → so the starting house gets 2 presents, but we still count it once (we only care about "at least one").
- They take turns using the same instruction string:
- Santa takes the 1st, 3rd, 5th, ... (odd-indexed) moves.
- Robo-Santa takes the 2nd, 4th, 6th, ... (even-indexed) moves.


- Start with one shared set of visited houses.
- Add the starting position (0, 0) to it.
- Keep two positions:
- (sx, sy) for Santa
- (rx, ry) for Robo-Santa
- Loop through each character in the input:
- If index is even → update Santa’s position
- If index is odd → update Robo-Santa’s position
- After each move (by either), add the new position to the shared set.
- At the end, the size of the set = answer.
- Again, duplicates don’t matter - the set (or list) automatically handles uniqueness.


Instructions: `['^', '>', 'v', '<']`
Indices: `0 1 2 3`

- Start: Santa=(0,0), Robo=(0,0) → visited = {(0,0)}
- Index 0 (`^`) → Santa moves → (0,1) → visited = {(0,0), (0,1)}
- Index 1 (`>`) → Robo moves → (1,0) → visited = {(0,0), (0,1), (1,0)}
- Index 2 (`v`) → Santa moves → (0,0) → already visited
- Index 3 (`<`) → Robo moves → (0,0) → already visited
- Total unique houses = 3

---
