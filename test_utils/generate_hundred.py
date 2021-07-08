import random
n = 100
lst = random.sample(range(0, n), n)
print(" ".join(str(x) for x in lst))