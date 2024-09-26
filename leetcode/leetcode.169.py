import math
import random

def majority(array):
    l = len(array)
    d = {}

    maj = math.floor(l/2) + 1

    for n in array:
        if n in d:
            d[n] = d[n] + 1
            if d[n] >= maj:
                return n
            continue
        d[n] = 1


def test():

    for x in range(50):
        rand_length = random.randint(1, 99)
        rand_major = random.randint(1, 99)
        arr = [rand_major] * (rand_length + 1)
        for x in range(rand_length):
            arr.append(random.randint(1,99))

        random.shuffle(arr)
        print("For array:", arr, "\nMajority is:", rand_major)

        if majority(arr) == rand_major:
            print("Test passed!")
        else:
            print("Test failled!")

test()
