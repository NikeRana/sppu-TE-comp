# -*- coding: utf-8 -*-
"""AI-8(n-queens).ipynb

Automatically generated by Colaboratory.

Original file is located at
    https://colab.research.google.com/drive/19Dso-X1eO_ZAJjQ5oHWrPQiRD5MZ1jl9
"""

def solve_n_queens(n):
    board = [[0] * n for _ in range(n)]  # Create an empty chessboard
    queens = []  # List to store the column position of queens

    def is_safe(row, col):
        # Check if placing a queen at the given position is safe
        # Check column
        for i in range(row):
            if board[i][col] == 1:
                return False
        # Check upper diagonal
        i, j = row, col
        while i >= 0 and j >= 0:
            if board[i][j] == 1:
                return False
            i -= 1
            j -= 1
        # Check lower diagonal
        i, j = row, col
        while i >= 0 and j < n:
            if board[i][j] == 1:
                return False
            i -= 1
            j += 1
        return True

    def backtrack(row):
        if row == n:
            # All queens have been placed, print the solution
            print_solution()
            return True
        for col in range(n):
            if is_safe(row, col):
                # Place a queen at the current position
                board[row][col] = 1
                queens.append(col)

                # Recursively backtrack to place the remaining queens
                if backtrack(row + 1):
                    return True

                # If the current configuration doesn't lead to a solution, backtrack
                board[row][col] = 0
                queens.pop()

        return False

    def print_solution():
        # Print the board configuration
        for row in range(n):
            for col in range(n):
                if queens[row] == col:
                    print("Q", end=" ")
                else:
                    print(".", end=" ")
            print()

    # Start with the first row (row index 0)
    backtrack(0)

# Prompt the user to enter the number of queens
n = int(input("Enter the number of queens: "))
solve_n_queens(n)