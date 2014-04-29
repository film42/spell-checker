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

class Trie {
public:
    class Node {
        int frequency;
        int childCount;
        Node **children;
    public:
        Node();
        ~Node();
        int getFrequency();
        int getChildCount();
        int getIndexOf(char letter);
        void incFrequency();
        Node **getChildren();
        
        Node *getChild(char letter);
        void setChild(char letter, Node *node);
    };
    
    Trie();
    ~Trie();
    void add(std::string word);
    Node *find(std::string word);
    
    int getWordCount();
    int getNodeCount();
    
private:
    Node *head;
    int nodeCount;
    int wordCount;
    void clear(Node *node);
};

#endif /* defined(__Playground1__Trie__) */