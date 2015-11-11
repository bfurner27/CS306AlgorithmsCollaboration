import sys;
import time;
items = []

def insertion_sort(l):
    for i in xrange(1, len(l)):
        j = i-1 
        key = l[i]
        while (l[j] > key) and (j >= 0):
           l[j+1] = l[j]
           j -= 1
        l[j+1] = key

with open(sys.argv[1], 'r') as f:
    for value in enumerate(f.read().split()):
        items.append(value[1])
t0 = time.clock()
insertion_sort(items)
print time.clock() - t0, "seconds process time"
#print items
