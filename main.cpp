#include <iostream>
#include <fstream>
#include "kc_sha256.h"

int main() {
    std::cout << std::endl << "================================================================================";
    std::cout << std::endl << "k-Concise::SHA256 Test Suite";
    std::cout << std::endl << "================================================================================";

    int fail_ct = 0;
    int pass_ct = 0;

    {
        kc::sha256 sha256;
        std::cout << std::endl << "Hashing";
        std::cout << std::endl << "    std::string (Initial Pass) ........................................ ";
        if (sha256.hash("apples") == "f5903f51e341a783e69ffc2d9b335048716f5f040a782a2764cd4e728b0f74d9") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
    }
    {
        kc::sha256 sha256;
        std::cout << std::endl << "    std::ifstream (Initial Pass) ...................................... ";
        std::ofstream outfile;
        outfile.open("kc_sha256_temp_1.dat");
        outfile << "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor\n"
                "incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis\n"
                "nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.\n"
                "\n"
                "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu\n"
                "fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in\n"
                "culpa qui officia deserunt mollit anim id est laborum.";
        outfile.close();
        std::ifstream infile;
        infile.open("kc_sha256_temp_1.dat");
        if (sha256.hash(infile) == "92306303c5c43eca1fc1f37ae4830962fe7cc9777a2bff89685c6f781f1a8806") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
        infile.close();
    }
    {
        kc::sha256 sha256;
        std::cout << std::endl << "    std::string (Second Pass) ......................................... ";
        sha256.hash("apples");
        if (sha256.hash("oranges") == "0c7aae56ebe5d422f7f0f5b97da9856b135de81ac462c9c1a85ee53850fec479") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
    }
    {
        kc::sha256 sha256;
        std::cout << std::endl << "    std::ifstream (Second Pass) ....................................... ";
        std::ofstream outfile;
        outfile.open("kc_sha256_temp_2.dat");
        outfile << "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu\n"
                "fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in\n"
                "culpa qui officia deserunt mollit anim id est laborum.\n"
                "\n"
                "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor\n"
                "incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis\n"
                "nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
        outfile.close();
        std::ifstream infile2;
        infile2.open("kc_sha256_temp_1.dat");
        infile2.close();
        infile2.open("kc_sha256_temp_2.dat");
        if (sha256.hash(infile2) == "10b6cea48b9db2acf78c5f964bc946f805988fa8a42671ea73e8fce5943432b4") {
            std::cout << "Pass";
            ++pass_ct;
        } else {
            std::cout << "FAIL";
            ++fail_ct;
        }
        infile2.close();
    }


    std::remove("kc_sha256_temp_1.dat");
    std::remove("kc_sha256_temp_2.dat");

    std::cout << std::endl << std::endl << "================================================================================";
    std::cout << std::endl << "k-Concise::MD5 Summary";
    std::cout << std::endl << "================================================================================";
    std::cout << std::endl << "Status: " << ((fail_ct) ? "FAIL" : "Pass");
    std::cout << std::endl << "    Success Count: " << pass_ct;
    std::cout << std::endl << "    Failure Count: " << fail_ct;

    return 0;
}





/*

{
std::cout << std::endl << "    Update w/ File; MD5 Check .................. ";
std::ifstream infile;
infile.open("kc_md5_temp_1.dat");
kc::md5 mymd5_2_3(infile);
infile.close();
std::ofstream outfile;
outfile.open("kc_md5_temp_2.dat");
outfile << "Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu\n"
"fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in\n"
"culpa qui officia deserunt mollit anim id est laborum.\n"
"\n"
"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor\n"
"incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis\n"
"nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
outfile.close();
infile.open("kc_md5_temp_2.dat");
mymd5_2_3.update(infile);
if (mymd5_2_3.hash() == "738b52562b33e27f762f485b0e4d9e72") {
std::cout << "Pass";
++pass_ct;
} else {
std::cout << "FAIL";
++fail_ct;
}
}*/