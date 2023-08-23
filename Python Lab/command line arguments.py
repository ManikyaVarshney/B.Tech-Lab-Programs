import sys

def main():
    # Get command line arguments
    command_line_args = sys.argv[1:]  # Exclude the script name

    # Get user input
    user_input = input("Enter additional input: ")

    # Combine command line arguments and user input
    all_arguments = command_line_args + [user_input]

    num_args = len(all_arguments)

    print(f"Total arguments: {num_args}")
    print("Arguments:", ", ".join(all_arguments))

if __name__ == "__main__":
    main()
