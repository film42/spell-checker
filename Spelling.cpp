//
//  Spelling.cpp
//  SpellChecker
//
//  Created by Garrett Thornburg on 4/27/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#include "Spelling.h"

Spelling::Spelling() {
    dictionary = new Trie();
}

Spelling::~Spelling() {
    delete dictionary;
}

void Spelling::useDictionary(const std::string fileName) {
    std::string line = "";
    std::ifstream fin(fileName);
    while (std::getline(fin, line)) {
        
        // Strip white space
        unsigned long last = line.find(' ');
        line = line.substr(0,last);
        
        // Add if valid
        if(line.length() >= 2) {
            // Ensure lower case
            std::transform(line.begin(), line.end(), line.begin(), ::tolower);
            // Save it in Trie
            dictionary->add(line);
        }
    }
    fin.close();
}

std::string Spelling::suggestSimilarWord(const std::string inputWord) {
    
    if(dictionary->find(inputWord) != NULL)
        return inputWord;
    
    std::set<std::string> similarWords;

    // First Pass
    deletionDistance(similarWords, inputWord);
    transpositionDistance(similarWords, inputWord);
    alterationDistance(similarWords, inputWord);
    insertionDistance(similarWords, inputWord);
    
    // Copy
    std::set<std::string> similarWordsCopy;
    std::copy(similarWords.begin(), similarWords.end(), std::inserter(similarWordsCopy, similarWordsCopy.end()));
    
    // Check First Pass
    std::string res = filter(similarWords);
    if(!res.empty()) return res;
    
    // Second Pass
    deletionDistance(similarWordsCopy, similarWords);

    
    transpositionDistance(similarWordsCopy, similarWords);
    alterationDistance(similarWordsCopy, similarWords);
    insertionDistance(similarWordsCopy, similarWords);
    
    res = filter(similarWords);
    
    if(res.empty()) return inputWord;
    return res;
}

std::string Spelling::toString() const {
    std::string out;
    out = "Nodes: ";
    out += std::to_string(dictionary->getNodeCount());
    out += "  Words: ";
    out += std::to_string(dictionary->getWordCount());
    
    return out;
}

//
// Private
//
std::string Spelling::filter(std::set<std::string> &suggestions) {
    if(suggestions.size() == 0) return NULL;
    
    Trie::Node *topNode = NULL;
    std::string topString;

    std::set<std::string>::iterator it;
    for(it = suggestions.begin(); it != suggestions.end(); it++) {
        std::string word = *it;
        
        Trie::Node* seek = dictionary->find(word);
        
        if(seek == NULL) continue;
        
        if(topNode == NULL) {
            topNode = seek;
            topString = word;
            continue;
        }
        
        if(seek->getFrequency() > topNode->getFrequency()) {
            topNode = seek;
            topString = word;
        }
    }
    
    return topString;
}

void Spelling::deletionDistance(std::set<std::string> &acc, const std::string word) {
    for(int i = 1; i <= word.length(); i++) {
        std::string base = word.substr(0,i-1);
        std::string tail = word.substr(i);
        std::string cutlet = base + tail;
        
        if(!cutlet.empty())
            acc.insert(cutlet);
    }
}

void Spelling::deletionDistance(std::set<std::string> &copy, std::set<std::string> &words) {
    std::set<std::string>::iterator it;
    for(it = copy.begin(); it != copy.end(); it++) {
        // Alter
        deletionDistance(words, *it);
    }
}

void Spelling::transpositionDistance(std::set<std::string> &acc, const std::string word) {
    for(int i = 0; i <= (word.length() - 2); i++) {
        std::string letterOne = word.substr(i, i+1);
        std::string letterTwo = word.substr(i+1, i+2);
        std::string firstHalf = word.substr(0, i);
        std::string lastHalf = word.substr(i+2);
        std::string cutlet = firstHalf + letterTwo + letterOne + lastHalf;

        if(!cutlet.empty())
            acc.insert(cutlet);
    }
}

void Spelling::transpositionDistance(std::set<std::string> &copy, std::set<std::string> &words) {
    std::set<std::string>::iterator it;
    for(it = copy.begin(); it != copy.end(); it++) {
        // Alter
        transpositionDistance(words, *it);
    }
}

void Spelling::alterationDistance(std::set<std::string> &acc, const std::string word) {
    for(int i = 0; i <= (word.length() - 1); i++) {
        std::string firstHalf = word.substr(0, i);
        std::string lastHalf = word.substr(i+1);
        
        for(int y = 0; y < 26; y++) {
            char letter = (char)'a' + y;
            std::string cutlet = firstHalf + letter + lastHalf;

            if(!cutlet.empty())
                acc.insert(cutlet);
        }
    }
}

void Spelling::alterationDistance(std::set<std::string> &copy, std::set<std::string> &words) {
    std::set<std::string>::iterator it;
    for(it = copy.begin(); it != copy.end(); it++) {
        // Alter
        alterationDistance(words, *it);
    }
}

void Spelling::insertionDistance(std::set<std::string> &acc, const std::string word) {
    for(int i = 0; i <= word.length(); i++) {
        std::string firstHalf = word.substr(0, i);
        std::string lastHalf = word.substr(i);
        
        for(int y = 0; y < 26; y++) {
            char letter = (char)'a' + y;
            std::string cutlet = firstHalf + letter + lastHalf;

            if(!cutlet.empty())
                acc.insert(cutlet);
        }
    }
}

void Spelling::insertionDistance(std::set<std::string> &copy, std::set<std::string> &words) {
    std::set<std::string>::iterator it;
    for(it = copy.begin(); it != copy.end(); it++) {
        // Alter
        insertionDistance(words, *it);
    }
}
