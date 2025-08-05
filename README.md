# Hangman Game

A modern desktop Hangman game built with C++ and Raylib, featuring multiple categories and a clean graphical interface.

## Features

- **Multiple Categories**: Choose from 5 different word categories:
  - Marvel Characters
  - Movies
  - Books
  - Palindromes
  - Countries

- **Visual Hangman Art**: Progressive hangman drawings that update with each wrong guess
- **Interactive Keyboard**: Click on letters or use your physical keyboard to make guesses
- **Score Tracking**: Keep track of wins and losses throughout your gaming session
- **Smooth Gameplay**: 60 FPS performance with responsive controls
- **Game Statistics**: View your performance at the end of each game

## Game interface Preview

<img width="898" height="650" alt="image" src="https://github.com/user-attachments/assets/cd9c8994-2761-4690-8f6b-dc517d85f1ed" />
<img width="898" height="650" alt="image" src="https://github.com/user-attachments/assets/5216949f-d49a-4f42-9f88-0133c369261f" />
<img width="898" height="650" alt="image" src="https://github.com/user-attachments/assets/17b4c9de-e174-4cd2-a023-da8c80c377d0" />


The game features a colorful interface with:
- Category selection screen
- Interactive word display with letter chips
- On-screen keyboard with visual feedback
- Progressive hangman artwork
- Win/loss statistics

## Installation & Setup

### Prerequisites

1. Install a C++ compiler (e.g., GCC or MinGW for Windows).
2. Install [Raylib](https://www.raylib.com/) (a simple and easy-to-use library for game development).
3. Ensure you have a terminal or command prompt to run commands.

### Building the Game

1. Clone or download the project
2. Navigate to project directory
3. Run the following command to compile the game:
```bash
make all
```
4. Or use this command to compile and run the game in one step:
```bash
make run
```

### Cleaning Build Files

To remove compiled files and clean the project, run:
```bash
make clean
```

## How to Play

1. **Start the Game**: Launch the executable to see the main menu
2. **Choose Category**: Select one of the five available categories
3. **Guess Letters**: 
   - Click letters on the on-screen keyboard, or
   - Use your physical keyboard to type letters
4. **Win Condition**: Guess all letters in the word before the hangman is complete
5. **Game Over**: You have 6 wrong guesses before losing the round
6. **Continue Playing**: After each round, choose to continue or end the game

## Game Controls

- **Mouse**: Click on keyboard letters or buttons
- **Physical Keyboard**: Type letters A-Z to make guesses
- **Enter**: End the current game session
- **Any Key**: Continue to next round after winning/losing

## Project Structure

```
hangman-game/
├── src/                     # Source code files
│   ├── main.cpp             # Main game loop and logic
│   ├── Artwork.cpp          # Hangman drawing management
│   ├── Button.cpp           # Button interaction system
│   ├── Chip.cpp             # Letter display chips
│   ├── Key.cpp              # Individual keyboard keys
│   ├── Keyboard.cpp         # Virtual keyboard system
│   ├── Utils.cpp            # Utility functions
│   └── Word.cpp             # Word display and management
├── include/                 # Header files
├── assets/
│   ├── data/
│   │   └── word_bank.txt    # Word database with categories
│   └── images/              # Hangman artwork (art0.png - art6.png)
├── bin/                     # Compiled executable and assets
├── obj/                     # Object files
├── Makefile                 # Build configuration
└── .gitignore               # Git ignore rules
```

## Word Database

The game includes over 200 words across 5 categories:

- **Marvel**: 60+ superhero names and terms
- **Movies**: 40+ popular movie titles
- **Books**: 30+ famous book titles
- **Palindromes**: 40+ words that read the same forwards and backwards
- **Countries**: 45+ country names from around the world

## Technical Details

- **Language**: C++17
- **Graphics**: Raylib
- **Build System**: GNU Make
- **Platform**: Windows (with potential for cross-platform compilation)
- **Resolution**: 900x650 pixels
- **Frame Rate**: 60 FPS

## Customization

### Adding New Words

Edit `assets/data/word_bank.txt` to add new words:
```
Category,Word
MOVIES,YOUR NEW MOVIE
BOOKS,YOUR NEW BOOK
```

### Adding New Categories

1. Add words with a new category name in `word_bank.txt`
2. Update the `categoryNames` array in `main.cpp`
3. Adjust the category button creation loop

### Modifying Colors

Colors are defined in `include/Constants.hpp`:
- `PEACH`: Main UI color
- `APRICOT`: Accent color
- `RICH_GOLD`: Title color
- And more...
