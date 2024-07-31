import random

def for_word():
    fruits=["apple","banana","mango","orange","grape","kiwi","grapefruit","peach","date","blueberry","apricot","blackberry","pineapple","lychee","pear"]
    element=random.choice(fruits)
    return element #extracting a random element from the list
 
attempts = 6

word=for_word() #we get the word to be guessed

word_letters=set(word) #the letters in the word
guessed_letters=set() #the letters guessed by players

while attempts>0 and word_letters:
    display=[letter if letter in guessed_letters else "___" for letter in word_letters]
    print("Current Word: ", " ".join(display))

    guess=input("Guess a Letter: ").lower()
