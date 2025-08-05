#ifndef WORD_HPP
#define WORD_HPP

#include<string>
#include<vector>
#include<set>
#include "Chip.hpp"

struct Word
{
    std::string word;
    std::vector<Chip> alphabets;

    Word(std::string word);
    void displayWord(std::set<char> guessedLetters);
};

#endif