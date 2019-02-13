#include <iostream>

using namespace std;

#include "blockchain.hpp"

int main() {
    Blockchain myChain(4);

    string genesis_data = "blockchain is starting";

    myChain.CreateBlock(genesis_data);

    return 0;
}