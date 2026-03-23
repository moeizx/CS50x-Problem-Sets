def count_letters(text):
    length = 0
    for char in text:
        if char.isalpha():
            length += 1
    return length

def count_words(text):
    length = 1
    for char in text:
        if char.isspace():
            length += 1
    return length

def count_sentences(text):
    length = 0
    for char in text:
        if char in ['.', '!', '?']:
            length += 1
    return length

def avg_l(l_length, w_length):
    return (l_length / w_length) * 100

def avg_s(s_length, w_length):
    return (s_length / w_length) * 100

def colman(avg_l_val, avg_s_val):
    x = (0.0588 * avg_l_val) - (0.2968 * avg_s_val) - 15.8
    return round(x)


text = input("Enter: ")

letters = count_letters(text)
words = count_words(text)
sentences = count_sentences(text)

avg_letter = avg_l(letters, words)
avg_sentence = avg_s(sentences, words)

grade = colman(avg_letter, avg_sentence)

if grade < 1:
    print("Before Grade 1")
elif grade > 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}")
