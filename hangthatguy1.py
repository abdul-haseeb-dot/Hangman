# Important Features Of Hangman:
#1) Word Bank (Selects a random word)
#2) Guess One Letter At A Time (While Loop probably)
#3) Letter checker. If present in the word, put in the exact position (a[i] probably)
#4) A guessed letter cannot be guessed again (While loop probably)
#5) Make an ASCII noose thing
#6) Update the noose thing with every mistake (3 total mistakes)
#7) Make a hint system (If I get the time)
import random
def guess(word,input1,blank,mistake):
    if input1 in word:
        position = word.find(input1)
        blank[position]= input1
        print("".join(blank))
        if word.count(input1)>1:
            position=[]
            for i in range(len(word)):
                if input1 == word[i]:
                    position.append(i)
            for j in position:
                blank[j]= input1
    else:
        print("Incorrect guess.")
        mistake+=1
    return blank,mistake
mistake = 0
game_won=None
words=["blade","queen","maple","smile","earth","dream","light","magic","happy","exile","issue","carry","parry","order","asia","merry","arrow","words","swell","dwell","mimic","wrist","wheel"]
word = random.choice(words)
in_word=[]
blank= ["__" , "__" , "__" , "__" , "__"]

while game_won==None:
    input1= str(input("Enter your guess: ")).lower()
    while len(input1)>1 or not input1.isalpha():
        print("Invalid entry!")
        input1= str(input("Enter your first guess: "))
    while input1 in in_word:
        print("Already Guessed!")
        input1=input("Enter your guess: ")
    blank,mistake = guess(word, input1, blank,mistake)
    in_word.append(input1)
    if mistake==3:
        game_won = False
    if "".join(blank)==word:
        game_won = True
    

