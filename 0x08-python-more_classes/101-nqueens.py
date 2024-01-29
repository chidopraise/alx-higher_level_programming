#!/usr/bin/python3
"""
N Queens puzzle solution
"""

import sys


def print_solution(solution):
    """Print the N Queens solution."""
    print([[i, j] for i, j in enumerate(solution)])


def is_safe(board, row, col):
    """Check if it's safe to place a queen at board[row][col]."""
    for prev_row in range(row):
        if board[prev_row] == col or \
                board[prev_row] - prev_row == col - row or \
                board[prev_row] + prev_row == col + row:
            return False
    return True


def solve_queens(board, row, n):
    """Solve N Queens using backtracking."""
    if row == n:
        print_solution(board)
        return

    for col in range(n):
        if is_safe(board, row, col):
            board[row] = col
            solve_queens(board, row + 1, n)


def nqueens(n):
    """Solve the N Queens problem."""
    if not isinstance(n, int):
        print("N must be a number")
        sys.exit(1)

    if n < 4:
        print("N must be at least 4")
        sys.exit(1)

    board = [-1] * n
    solve_queens(board, 0, n)


if __name__ == "__main__":
    if len(sys.argv) != 2:
        print("Usage: nqueens N")
        sys.exit(1)

    try:
        N = int(sys.argv[1])
        nqueens(N)
    except ValueError:
        print("N must be a number")
        sys.exit(1)
