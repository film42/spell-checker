//
//  Trie.cpp
//  SpellChecker
//
//  Created by Garrett Thornburg on 4/27/14.
//  Copyright (c) 2014 Garrett Thornburg. All rights reserved.
//

#include "Trie.h"

Trie::Trie() {
    head = new Node();
    nodeCount = 1;
    wordCount = 0;
}

Trie::~Trie() {
    clear(head);
}

void Trie::clear(Node *node) {
    
    for(int i = 0; i < 26; i++) {
        if(node->getChildren()[i] != NULL)
            clear(node->getChildren()[i]);
    }
    delete[] node->getChildren();
    delete node;
}

void Trie::add(const std::string word) {
    
    Node *state = head;
    
    for(int i = 0; i < word.length(); i++) {
        char letter = word[i];
        
        Node *cursor = state->getChild(letter);
        
        if(cursor == NULL) {
            cursor = new Node();
            state->setChild(letter, cursor);
            
            nodeCount++;
        }
        
        if(i == (word.length() - 1))
            cursor->incFrequency();
        
        state = cursor;
    }

    wordCount++;
}

Trie::Node *Trie::find(const std::string word) const {
    Node *state = head;
    
    for(int i = 0; i < word.length(); i++) {
        state = state->getChild(word[i]);
        
        if(state == NULL) break;
    }
    
    if(state == NULL || state->getFrequency() == 0)
        return NULL;
    else
        return state;
}

//
// Getters
//
int Trie::getNodeCount() const {
    return nodeCount;
}

int Trie::getWordCount() const {
    return wordCount;
}


//
// ;; Node Class
//
Trie::Node::Node() {
    children = new Node*[26];
}
Trie::Node::~Node() {
}

Trie::Node **Trie::Node::getChildren() const {
    return children;
}

int Trie::Node::getFrequency() const {
    return frequency;
}

int Trie::Node::getChildCount() const {
    return childCount;
}

int Trie::Node::getIndexOf(char letter) const {
    return letter - 'a';
}

void Trie::Node::incFrequency() {
    frequency++;
}

Trie::Node * Trie::Node::getChild(const char letter) const {
    int index = getIndexOf(letter);
    return children[index];
}

void Trie::Node::setChild(const char letter, Node *node) {
    int index = getIndexOf(letter);
    children[index] = node;
    childCount++;
}



