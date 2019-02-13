#ifndef BLOCKCHAIN_H
#define BLOCKCHAIN_H

#include <string>
#include <vector>
#include <time.h>
#include <iostream>

using namespace std;

#include "block.hpp"

class Blockchain {
public:
    void AddBlock(Block);
    void CreateBlock(string);
    Blockchain(int);
private:
    vector<Block> chain;
    int nDifficult;
    string compD;
};

Blockchain::Blockchain(int _num) {
    this->nDifficult = _num;
    char cstr[this->nDifficult + 1];
    for (int i = 0; i < this->nDifficult ; i++) {
        cstr[i] = '0';
    }
    cstr[this->nDifficult] = '\0';

    this->compD = cstr;
}

void Blockchain::AddBlock(Block newBlock) {
    if (newBlock.getCurrentHash().substr(0, this->nDifficult) != this->compD) {
        cout << "fault hash" << endl;
        return;
    }
    chain.push_back(newBlock);
}

void Blockchain::CreateBlock(string _data) {
    time_t ctime = time(NULL);
    Block prevBlock = this->chain[this->chain.size() - 1];
    uint32_t nonce = -1;

    stringstream ss;

    string currentHash;

    do {
        nonce++;
        ss << ctime << _data << prevBlock.getCurrentHash() << nonce;
        currentHash = sha256(ss.str());
    } while (currentHash.substr(0, this->nDifficult) != this->compD);

    Block newBlock(_data, prevBlock.getCurrentHash(), nonce, ctime);

    this->AddBlock(newBlock);
}


#endif