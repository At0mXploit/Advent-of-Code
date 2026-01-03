# Day 6: Probably a Fire Hazard
Because your neighbors keep defeating you in the holiday house decorating contest year after year, you've decided to deploy one million lights in a 1000x1000 grid.

Furthermore, because you've been especially nice this year, Santa has mailed you instructions on how to display the ideal lighting configuration.

Lights in your grid are numbered from 0 to 999 in each direction; the lights at each corner are at 0,0, 0,999, 999,999, and 999,0. The instructions include whether to turn on, turn off, or toggle various inclusive ranges given as coordinate pairs. Each coordinate pair represents opposite corners of a rectangle, inclusive; a coordinate pair like 0,0 through 2,2 therefore refers to 9 lights in a 3x3 square. The lights all start turned off.

To defeat your neighbors this year, all you have to do is set up your lights by doing the instructions Santa sent you in order.

For example:

turn on 0,0 through 999,999 would turn on (or leave on) every light.
toggle 0,0 through 999,0 would toggle the first line of 1000 lights, turning off the ones that were on, and turning on the ones that were off.
turn off 499,499 through 500,500 would turn off (or leave off) the middle four lights.
After following the instructions, how many lights are lit?
## Solution

Think of it like a standard Cartesian graph (like in math class), but with only positive coordinates:

- The horizontal axis (→) is x
- The vertical axis (↑) is y
- Each light is a point (x, y) on this grid.

So the instruction:
- 119,662 through 760,838

Means:

- One corner of the rectangle is at (x=119, y=662)
- The opposite corner is at (x=760, y=838)
- To get all points in the rectangle, you take:

- x from 119 to 760 (left to right)
- y from 662 to 838 (bottom to top)
- Every combination of those x and y values is a light you affect.

So:

- x values: 119, 120, 121, ..., 760
- y values: 662, 663, 664, ..., 838

It’s just a solid rectangle of points on a graph.
## Part Two 
You just finish implementing your winning light pattern when you realize you mistranslated Santa's message from Ancient Nordic Elvish.

The light grid you bought actually has individual brightness controls; each light can have a brightness of zero or more. The lights all start at zero.

The phrase turn on actually means that you should increase the brightness of those lights by 1.

The phrase turn off actually means that you should decrease the brightness of those lights by 1, to a minimum of zero.

The phrase toggle actually means that you should increase the brightness of those lights by 2.

What is the total brightness of all lights combined after following Santa's instructions?

For example:

turn on 0,0 through 0,0 would increase the total brightness by 1.
toggle 0,0 through 999,999 would increase the total brightness by 2000000.
## Solution

Think of the grid the same way as Part 1:

Each light is a point (x, y) on a 1000×1000 grid (x and y from 0 to 999).
A command like 119,662 through 760,838 affects every light where:
- x = 119 to 760
- y = 662 to 838

But now, instead of just turning lights on/off, each instruction changes brightness:

- turn on → add +1 to brightness of every light in the rectangle
- turn off → subtract 1 (but never go below 0)
- toggle → add +2

All lights start at brightness 0.
After all instructions, total brightness = sum of all light values.

---