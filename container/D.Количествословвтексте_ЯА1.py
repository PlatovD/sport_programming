import sys

text = sys.stdin.read()
words = text.split()
unique_words_count = len(set(words))
print(unique_words_count)
