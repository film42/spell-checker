//
//  SpellingCorrector.h
//  SpellChecker
//
//  Created by Garrett Thornburg on 4/27/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#ifndef __SpellChecker__SpellingCorrector__
#define __SpellChecker__SpellingCorrector__

#include <iostream>

class ISpelling {
public:
    virtual void useDictionary(const std::string fileName) {
    
    }
    
    virtual std::string suggestSimilarWord(const std::string inputWord) {
        return NULL;
    }
    
};

#endif /* defined(__SpellChecker__SpellingCorrector__) */
