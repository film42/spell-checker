//
//  main.cpp
//  Playground1
//
//  Created by Garrett Thornburg on 4/27/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#include <iostream>
#include "Spelling.h"
#include "Trie.h"

int main(int argc, const char * argv[]) {
    // Check flags
    if(argc < 2) {
        std::cout << "Error: Please provide valid arguments." << std::endl;
        std::cout << "Usage: spelling path/to/dictionary.txt word" << std::endl;
        return -1;
    }
    
    // Setup Spelling
    Spelling spelling;
    spelling.useDictionary(argv[1]);
    
    // Debug Info
    // std::cout << spelling.toString() << std::endl;

    // Run
    std::cout << spelling.suggestSimilarWord(argv[2]);
    return 0;
}

