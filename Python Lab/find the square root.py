import math

def main():
    num = float(input("Enter a number: "))

    if num < 0:
        print("Cannot calculate square root of a negative number.")
    else:
        square_root = math.sqrt(num)
        print(f"The square root of {num} is {square_root:.3f}")

if __name__ == "__main__":
    main()
