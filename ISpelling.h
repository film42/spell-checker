//
//  SpellingCorrector.h
//  Playground1
//
//  Created by Garrett Thornburg on 4/27/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#ifndef __Playground1__SpellingCorrector__
#define __Playground1__SpellingCorrector__

#include <iostream>

class ISpelling {
public:
    virtual void useDictionary(std::string fileName) {
    
    }
    
    virtual std::string suggestSimilarWord(std::string inputWord) {
        return NULL;
    }
    
};

#endif /* defined(__Playground1__SpellingCorrector__) */
