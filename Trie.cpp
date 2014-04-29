//
//  Trie.cpp
//  Playground1
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
        if(node->children[i] != NULL)
            clear(node->children[i]);
    }
    delete[] node->children;
    node->children = NULL;
    delete node;
    node = NULL;
}

void Trie::add(std::string word) {
    
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

Node *Trie::find(std::string word) {
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
int Trie::getNodeCount() {
    return nodeCount;
}

int Trie::getWordCount() {
    return wordCount;
}


//
// ;; Node Class
//
Node::Node() {
    children = new Node*[26];
}
Node::~Node() {
}

int Node::getFrequency() {
    return frequency;
}

int Node::getChildCount() {
    return childCount;
}

int Node::getIndexOf(char letter) {
    return letter - 'a';
}

void Node::incFrequency() {
    frequency++;
}

Node * Node::getChild(char letter) {
    int index = getIndexOf(letter);
    return children[index];
}

void Node::setChild(char letter, Node *node) {
    int index = getIndexOf(letter);
    children[index] = node;
    childCount++;
}



