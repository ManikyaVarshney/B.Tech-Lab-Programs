def main():
    numbers = input("Enter a list of numbers separated by spaces: ").split()
    numbers = [float(num) for num in numbers]

    if not numbers:
        print("List is empty.")
    else:
        max_number = max(numbers)
        print(f"The maximum number in the list is: {max_number}")

if __name__ == "__main__":
    main()
