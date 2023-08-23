def get_matrix(rows, cols, name):
    matrix = []
    print(f"Enter elements for {name} matrix:")
    for i in range(rows):
        row = []
        for j in range(cols):
            element = float(input(f"Enter element at position ({i+1},{j+1}): "))
            row.append(element)
        matrix.append(row)
    return matrix

def matrix_multiplication(matrix1, matrix2):
    result = []
    for i in range(len(matrix1)):
        row = []
        for j in range(len(matrix2[0])):
            element = 0
            for k in range(len(matrix2)):
                element += matrix1[i][k] * matrix2[k][j]
            row.append(element)
        result.append(row)
    return result

def main():
    rows1 = int(input("Enter the number of rows for the first matrix: "))
    cols1 = int(input("Enter the number of columns for the first matrix: "))
    matrix1 = get_matrix(rows1, cols1, "first")

    rows2 = int(input("Enter the number of rows for the second matrix: "))
    cols2 = int(input("Enter the number of columns for the second matrix: "))
    matrix2 = get_matrix(rows2, cols2, "second")

    if cols1 != rows2:
        print("Matrix multiplication not possible.")
    else:
        result_matrix = matrix_multiplication(matrix1, matrix2)
        print("Result of matrix multiplication:")
        for row in result_matrix:
            print(row)

if __name__ == "__main__":
    main()
