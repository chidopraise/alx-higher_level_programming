#!/usr/bin/python3
print("".join(f"{chr(char)}" for char in range(ord('a'), ord('z') + 1) if chr(char) not in 'qe'), end="")
