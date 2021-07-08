import random
n = 500
lst = random.sample(range(0, n), n)
print(" ".join(str(x) for x in lst))