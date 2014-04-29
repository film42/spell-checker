//
//  Trie.h
//  Playground1
//
//  Created by Garrett Thornburg on 4/27/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#ifndef __Playground1__Trie__
#define __Playground1__Trie__

#include <iostream>

class Node {
    int frequency;
    int childCount;
public:
    Node();
    ~Node();
    int getFrequency();
    int getChildCount();
    int getIndexOf(char letter);
    void incFrequency();
    Node **children;
    
    Node *getChild(char letter);
    void setChild(char letter, Node *node);
};

class Trie {
    Node *head;
    int nodeCount;
    int wordCount;
    void clear(Node *node);
public:
    Trie();
    ~Trie();
    void add(std::string word);
    Node *find(std::string word);
    
    int getWordCount();
    int getNodeCount();
    
};

#endif /* defined(__Playground1__Trie__) */