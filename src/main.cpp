#include<set>
#include<vector>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cctype>
#include<cstdio>
#include "raylib.h"
#include "Constants.hpp"
#include "Utils.hpp"
#include "Button.hpp"
#include "Keyboard.hpp"
#include "Word.hpp"
#include "Artwork.hpp"

using namespace std;

int main()
{
    InitWindow(SCREEN_WIDTH,SCREEN_HEIGHT,"Hangman");
    SetTargetFPS(60);
    srand(time(0));
    
    vector<string> word_bank;
    set<int> wordsPlayed;
    set<char> guessedLetters;
    set<char> correctLetters;
    Keyboard keyboard;
    Artwork art;

    int wins=0;
    int losses=0;
    int wrongAttempts=6;

    bool roundInProgress=false;
    bool roundOver=false;
    bool endGame=false;
    Word currentWord("");

    vector<Button> categoryButtons;
    const char* categoryNames[]={"MARVEL","MOVIES","PALINDROMES","BOOKS","COUNTRIES"};
    float buttonWidth=250,buttonHeight=60;
    float startX=(SCREEN_WIDTH-buttonWidth)/2,startY=230,padding=20;

    for(int i=0;i<5;i++)
    {
        Button button;
        button.rectangle={startX,startY+i*(buttonHeight+padding),buttonWidth,buttonHeight};
        button.label=categoryNames[i];
        categoryButtons.push_back(button);
    }

    bool categorySelected=false;
    const char* category=nullptr;

    while(!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(DARKBLUE);

        if(!categorySelected)
        {
            DrawText("HANGMAN",(SCREEN_WIDTH-MeasureText("HANGMAN",95))/2,40,95,RICH_GOLD);
            DrawText("CHOOSE A CATEGORY:",(SCREEN_WIDTH-MeasureText("CHOOSE A CATEGORY:",40))/2,150,40,WHITE);
            for(auto& button:categoryButtons)
            {
                button.drawButton(PEACH);
                if(button.isButtonClicked())
                {
                    categorySelected=true;
                    category=button.label;
                    loadCategoryWords(category,word_bank);
                    break;
                }
            }
        }
        else
        {
            if(!roundInProgress)
            {
                if(wordsPlayed.size()==word_bank.size()||endGame)
                {
                    Color background;
                    if(wins==losses)
                        background=SLATE_GRAY;
                    else
                        background=wins>losses?DARKGREEN:MAROON;
                    ClearBackground(background);
                    char over[]="GAME OVER";
                    char status[10];
                    if(wins==losses)
                        sprintf(status,"DRAW");
                    else
                        sprintf(status,"YOU %s",wins>losses?"WON":"LOST");
                    DrawText(over,(SCREEN_WIDTH-MeasureText(over,70))/2,200,70,WHITE);
                    Color textColor;
                    if(wins==losses)
                        textColor={152,255,152,255};
                    else if(wins>losses)
                        textColor={255,255,120,255};
                    else
                        textColor={255,200,200,255};
                    DrawText(status,(SCREEN_WIDTH-MeasureText(status,50))/2,300,50,textColor);
                    
                    char finalScore[50];
                    sprintf(finalScore,"FINAL SCORE: %d WINS - %d LOSSES",wins,losses);
                    DrawText(finalScore,(SCREEN_WIDTH-MeasureText(finalScore,30))/2,400,30,WHITE);
                    
                    DrawText("PRESS ANY KEY TO EXIT",(SCREEN_WIDTH-MeasureText("PRESS ANY KEY TO EXIT",30))/2,500,30,WHITE);
                    if(GetKeyPressed()!=0||IsMouseButtonPressed(MOUSE_LEFT_BUTTON))
                    {
                        break;
                    }
                }
                else
                {
                    int choose=rand()%word_bank.size();
                    while(wordsPlayed.find(choose)!=wordsPlayed.end())
                        choose=rand()%word_bank.size();
                    wordsPlayed.insert(choose);
                    guessedLetters.clear();
                    correctLetters.clear();
                    currentWord=Word(word_bank[choose]);
                    for(char c:currentWord.word)
                    {
                        if(isalpha(c))
                            correctLetters.insert(c);
                    }
                    wrongAttempts=6;
                    roundInProgress=true;
                }
            }
            
            if(roundInProgress)
            {
                displayStats(category,wins,losses);

                art.displayArt(wrongAttempts);

                currentWord.displayWord(guessedLetters);
                keyboard.drawKeyboard(guessedLetters);
                char input='\0';
                if(wrongAttempts>0&&!isSubset(guessedLetters,correctLetters))
                {
                    input=keyboard.getCharacterInput();
                    if(correctLetters.find(input)==correctLetters.end()&&guessedLetters.find(input)==guessedLetters.end()&&isalpha(input))
                    {
                        wrongAttempts--;
                    }
                    if(isalpha(input))
                        guessedLetters.insert(input);
                }

                bool playerWon=isSubset(guessedLetters,correctLetters);
                bool playerLost=wrongAttempts==0;
                
                if(playerWon||playerLost)
                {
                    int font=25;
                    char result[15];
                    sprintf(result,"YOU %s!",playerWon?"WON":"LOST");
                    char prompt[]="PRESS ENTER TO END GAME OR ANY OTHER KEY TO MOVE TO NEXT ROUND";
                    Color textColor=playerWon?YELLOW:PALE_PINK;
                    DrawText(result,(SCREEN_WIDTH-MeasureText(result,font))/2,360,font,textColor);
                    DrawText(prompt,(SCREEN_WIDTH-MeasureText(prompt,font-4))/2,395,font-4,textColor);
                    if(playerLost)
                        currentWord.displayWord(correctLetters);
                    if(!roundOver)
                    {
                        if(playerWon)
                            wins++;
                        else
                            losses++;
                        roundOver=true;
                    }
                    if(IsKeyPressed(KEY_ENTER))
                    {
                        endGame=true;
                        roundInProgress=false;
                    }
                    else if(GetKeyPressed()!=0)
                    {
                        roundInProgress=false;
                        roundOver=false;
                    }
                }
            }
        }

        EndDrawing();
    }

    CloseWindow();
    return 0;
}