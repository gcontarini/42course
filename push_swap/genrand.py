import sys
import random

nbr = int(sys.argv[1])
_min = -2147483648
#_min = -500
_max = 2147483647
#_max = 500

sample = random.sample(range(_min, _max), nbr)

for i in sample:
    print(f"{i} ", end="")
