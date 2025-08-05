#include "Utils.hpp"
#include "Constants.hpp"
#include<iostream>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<cstdio>
#include "raylib.h"

using namespace std;

void loadCategoryWords(const char* categoryName,vector<string>& words,const string& filePath)
{
    ifstream file(filePath);
    if(!file.is_open())
    {
        cout<<"Failed to open!"<<endl;
        return;
    }

    string line;
    getline(file,line);

    while(getline(file,line))
    {
        stringstream ss(line);
        string category,word;

        getline(ss,category,',');
        getline(ss,word,',');

        if(category==categoryName)
        {
            words.push_back(word);
        }
    }

    file.close();
}

bool isSubset(const set<char>& superset,const set<char>& subset)
{
    return includes(superset.begin(),superset.end(),subset.begin(),subset.end());
}

void displayStats(const char*&category,const int&wins,const int&losses)
{
    char categoryHeading[32];
    int categoryHeadingSize=45;
    sprintf(categoryHeading,"CATEGORY: %s",category);
    DrawText(categoryHeading,(SCREEN_WIDTH-MeasureText(categoryHeading,categoryHeadingSize))/2,15,categoryHeadingSize,APRICOT);
            
    int scoresHeadingSize=35;
    char winsDisplay[10];
    sprintf(winsDisplay,"WINS: %d",wins);
    DrawText(winsDisplay,20,70,scoresHeadingSize,WHITE);

    char lossesDisplay[10];
    sprintf(lossesDisplay,"LOSSES: %d",losses);
    DrawText(lossesDisplay,SCREEN_WIDTH-MeasureText(lossesDisplay,scoresHeadingSize)-20,70,scoresHeadingSize,WHITE);
}