def square_matrix_simple(matrix):
    # Create a new matrix with the same size as the input matrix
    new_matrix = [[0] * len(matrix[0]) for _ in range(len(matrix))]

    # Iterate through the elements of the matrix and compute the square
    for i in range(len(matrix)):
        for j in range(len(matrix[i])):
            new_matrix[i][j] = matrix[i][j] ** 2

    return new_matrix
