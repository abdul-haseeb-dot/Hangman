#ifndef UTILS_HPP
#define UTILS_HPP

#include<vector>
#include<string>
#include<set>

void loadCategoryWords(const char* categoryName,std::vector<std::string>& words,const std::string& filePath="assets/data/word_bank.txt");
bool isSubset(const std::set<char>& superset,const std::set<char>& subset);
void displayStats(const char*&category,const int&wins,const int&losses);

#endif