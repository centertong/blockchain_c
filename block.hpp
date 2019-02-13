#ifndef BLOCK_H
#define BLOCK_H

#include <string>
#include <time.h>
#include <sstream>
using namespace std;

#include "hash.hpp"

class Block {
public:
    Block(string, string, uint32_t, time_t);
    string getCurrentHash();
    string getPrevHash();
private:   
    string prevHash;
    string currentHash;
    uint32_t nonce;
    string data;
    time_t ctime;
};


Block::Block(string _data, string _prevHash, uint32_t _nonce, time_t _ctime) {
    this->data = _data;
    this->prevHash = _prevHash;
    this->ctime = _ctime;
    this->nonce = _nonce;
}

string Block::getCurrentHash() {
    return this->currentHash;
}

string Block::getPrevHash() {
    return this->prevHash;
}

#endif