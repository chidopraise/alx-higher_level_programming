#!/usr/bin/python3
print("".join("{}" .format(chr(char)) for char in range(ord('a'), ord('z') + 1)), end="")
