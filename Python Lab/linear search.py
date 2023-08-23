def linear_search(arr, target):
    for i, num in enumerate(arr):
        if num == target:
            return i
    return -1

def main():
    numbers = input("Enter a list of numbers separated by spaces: ").split()
    numbers = [int(num) for num in numbers]

    target = int(input("Enter the number to search for: "))

    result = linear_search(numbers, target)
    if result != -1:
        print(f"The target {target} was found at index {result}.")
    else:
        print("The target was not found in the list.")

if __name__ == "__main__":
    main()
