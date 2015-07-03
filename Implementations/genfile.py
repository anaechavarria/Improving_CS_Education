import sys
import random

# Generate n random numbers between 0 and m-1.
def main(argv):
    m, n = map(int, argv[1:])

    for _ in range(n):
        print random.randrange(0, m)


if __name__ == '__main__':
    main(sys.argv)
