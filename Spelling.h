//
//  Spelling.h
//  Playground1
//
//  Created by Garrett Thornburg on 4/27/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#ifndef __Playground1__Spelling__
#define __Playground1__Spelling__

#include <iostream>
#include <fstream>
#include "ISpelling.h"
#include "Trie.h"
#include <set>
#include <functional>

class Spelling: public ISpelling {
    Trie *dictionary;
    
    std::string filter(std::set<std::string> &suggestions);
    
    void deletionDistance(std::set<std::string> &acc, std::string word);
    void deletionDistance(std::set<std::string> &words);
    
    void transpositionDistance(std::set<std::string> &acc, std::string word);
    void transpositionDistance(std::set<std::string> &words);
    
    void alterationDistance(std::set<std::string> &acc, std::string word);
    void alterationDistance(std::set<std::string> &words);
    
    void insertionDistance(std::set<std::string> &acc, std::string word);
    void insertionDistance(std::set<std::string> &words);
    
public:
    Spelling();
    ~Spelling();
    
    void useDictionary(std::string fileName);
    
    std::string suggestSimilarWord(std::string inputWord);
    
    std::string toString();
};

#endif /* defined(__Playground1__Spelling__) */