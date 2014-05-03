//
//  Trie.h
//  SpellChecker
//
//  Created by Garrett Thornburg on 4/27/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#ifndef __SpellChecker__Trie__
#define __SpellChecker__Trie__

#include <iostream>

class Trie {
public:
    class Node {
        int frequency;
        int childCount;
        Node **children;
    public:
        Node();
        ~Node();
        int getFrequency() const;
        int getChildCount() const;
        int getIndexOf(const char letter) const;
        void incFrequency();
        Node **getChildren() const;
        
        Node *getChild(const char letter) const;
        void setChild(const char letter, Node *node);
    };
    
    Trie();
    ~Trie();
    void add(const std::string word);
    Node *find(const std::string word) const;
    
    int getWordCount() const;
    int getNodeCount() const;
    
private:
    Node *head;
    int nodeCount;
    int wordCount;
    void clear(Node *node);
};

#endif /* defined(__SpellChecker__Trie__) */