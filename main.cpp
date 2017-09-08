#include <iostream>
#include "kc_sha256.h"

int main(int argc, char *argv[])
{
    std::string input = "grape";
    std::string output1 = kc::sha256(input);

    std::cout << "sha256('"<< input << "'):" << output1 << std::endl;
    return 0;
}