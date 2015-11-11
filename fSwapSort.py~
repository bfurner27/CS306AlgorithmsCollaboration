import sys;
import time;
items = []

def selection_sort(lst):
    for i, e in enumerate(lst):
        mn = min(range(i,len(lst)), key=lst.__getitem__)
        lst[i], lst[mn] = lst[mn], e
    return lst

with open(sys.argv[1], 'r') as f:
    for value in enumerate(f.read().split()):
        items.append(int(value[1]))
t0 = time.clock()
selection_sort(items)
print time.clock() - t0, "seconds process time"
#print items
