def binary_search(arr, target):
    left, right = 0, len(arr) - 1

    while left <= right:
        mid = (left + right) // 2
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            left = mid + 1
        else:
            right = mid - 1

    return -1

def main():
    numbers = input("Enter a sorted list of numbers separated by spaces: ").split()
    numbers = [int(num) for num in numbers]

    target = int(input("Enter the number to search for: "))

    result = binary_search(numbers, target)
    if result != -1:
        print(f"The target {target} was found at index {result}.")
    else:
        print("The target was not found in the list.")

if __name__ == "__main__":
    main()
