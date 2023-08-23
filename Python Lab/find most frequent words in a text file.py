from collections import Counter
import re

def get_most_frequent_words(file_path, num_words):
    with open(file_path, 'r') as file:
        text = file.read()

    # Remove non-alphanumeric characters and convert to lowercase
    cleaned_text = re.sub(r'[^a-zA-Z\s]', '', text).lower()

    words = cleaned_text.split()
    word_count = Counter(words)

    most_common_words = word_count.most_common(num_words)
    return most_common_words

def main():
    file_path = input("Enter the path to the text file: ")
    num_words = int(input("Enter the number of most frequent words to find: "))

    frequent_words = get_most_frequent_words(file_path, num_words)

    print(f"\nMost frequent {num_words} words:")
    for word, count in frequent_words:
        print(f"{word}: {count}")

if __name__ == "__main__":
    main()
