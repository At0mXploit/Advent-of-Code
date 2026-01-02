def is_nice(string: str) -> bool:
    """
    1. Contains at least 3 vowels (aeiou)
    2. Contains atleast one letter that appears twice in a row
    3. Does NOT contain strings: ab, cd, pq, ry
    """
    vowels = "aeiou"
    vowel_count = 0
    for char in string:
        if char in vowels:
            vowel_count += 1

    has_double = False
    for i in range(len(string) - 1):
        if string[i] == string[i + 1]:
            has_double = True
            break

    bad_strings = ["ab", "cd", "pq", "xy"]
    has_bad_string = False
    for bad in bad_strings:
        if bad in string:
            has_bad_string = True
            break

    return vowel_count >= 3 and has_double and not has_bad_string 

def is_nice_part2(string):
    """
    Check if string is nice according to part 2 rules:
    1. Contains a pair of any two letters that appears at least twice without overlapping
    2. Contains at least one letter which repeats with exactly one letter between them
    """
    
    # 1. CHECK FOR PAIR THAT APPEARS TWICE WITHOUT OVERLAPPING
    has_pair = False
    for i in range(len(string) - 2):  # We need to check up to second-to-last for pairs
        # Get a pair of letters (like "ab" or "xy")
        pair = string[i:i+2]
        
        # Check if this same pair appears later in the string
        # Start looking after the current pair (at i+2) to avoid overlap
        for j in range(i + 2, len(string) - 1):
            next_pair = string[j:j+2]
            if pair == next_pair:
                has_pair = True
                break  
        
        if has_pair:
            break  
    
    # 2. CHECK FOR LETTER REPEATING WITH ONE LETTER BETWEEN
    has_repeat = False
    for i in range(len(string) - 2):
        if string[i] == string[i + 2]:
            has_repeat = True
            break 

    return has_pair and has_repeat

file = open('input.txt', 'r')
strings = []
for line in file:
    clean_line = line.strip() # Remove \n at end
    strings.append(clean_line)
file.close()

nice_count = 0
for s in strings:
    if is_nice(s):
        nice_count += 1

print(f"Number of nice strings: {nice_count}")

nice_count = 0
for s in strings:
    if is_nice_part2(s):
        nice_count += 1

print(f"Number of nice strings (Part 2): {nice_count}")
