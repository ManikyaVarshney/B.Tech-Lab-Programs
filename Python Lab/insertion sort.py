def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

def main():
    numbers = input("Enter a list of numbers separated by spaces: ").split()
    numbers = [int(num) for num in numbers]

    insertion_sort(numbers)

    print("Sorted list using Insertion Sort:", numbers)

if __name__ == "__main__":
    main()
