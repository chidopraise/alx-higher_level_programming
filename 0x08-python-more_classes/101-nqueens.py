#!/usr/bin/python3

import sys


def n_queens(n):

    queens = [-1] * n  # Initialize queens list with -1 (no queen placed)
    solve_n_queens(queens, 0)


def solve_n_queens(queens, row):

    n = len(queens)

    if row == n:  # All queens are placed, print the solution
        print_solution(queens)
        return

    for col in range(n):
        if is_safe(queens, row, col):
            queens[row] = col
            solve_n_queens(queens, row + 1)
            queens[row] = -1  # Backtrack


def is_safe(queens, row, col):

    for prev_row in range(row):
        # Check if there is a queen in the same column or diagonal
        if (
            queens[prev_row] == col or
            queens[prev_row] - prev_row == col - row or
            queens[prev_row] + prev_row == col + row
        ):
            return False
    return True


def print_solution(queens):

    for col in queens:
        print("." * col + "Q" + "." * (len(queens) - col - 1))
    print()


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        exit(1)

    try:
        n = int(sys.argv[1])
    except (ValueError, TypeError):
        print("N must be a number")
        exit(1)

    if n < 4:
        print("N must be at least 4")
        exit(1)

    n_queens(n)
