import sys;
import time;
items = []

from heapq import merge
 
def merge_sort(m):
    if len(m) <= 1:
        return m
 
    middle = len(m) // 2
    left = m[:middle]
    right = m[middle:]
 
    left = merge_sort(left)
    right = merge_sort(right)
    return list(merge(left, right))

with open(sys.argv[1], 'r') as f:
    for value in enumerate(f.read().split()):
        items.append(float(value[1]))
t0 = time.clock()
merge_sort(items)
print time.clock() - t0, "seconds process time"
#print items
