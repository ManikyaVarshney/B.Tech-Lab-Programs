def selection_sort(arr):
    for i in range(len(arr)):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]

def main():
    numbers = input("Enter a list of numbers separated by spaces: ").split()
    numbers = [int(num) for num in numbers]

    selection_sort(numbers)

    print("Sorted list using Selection Sort:", numbers)

if __name__ == "__main__":
    main()
