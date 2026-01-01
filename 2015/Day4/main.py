# Lowest well yeah it means first so we find first rather than lowest

import hashlib

def find_advent_coin(secret_key, zeros=5):
    n = 1
    target = '0' * zeros
    while True:
        data = f"{secret_key}{n}".encode()
        hash_result = hashlib.md5(data).hexdigest()
        if hash_result.startswith(target):
            return n
        n += 1

print(find_advent_coin("ckczppom", 5))

