#pragma once 
#ifndef _RSA_H_
#define _RSA_H_

#include <string>
#include "prime.h"

using namespace std;
using boost::multiprecision::cpp_int;

class RSA
{
public:
    struct s_open_key
    {
        cpp_int n;
        cpp_int exp;
        cpp_int init_vec= 0;
    };

    struct s_key
    {
        cpp_int key = 0;
        s_open_key open;
    };
    enum users
    {
        USER = "user",
        CREATOR = "creator"
    };

    RSA(string user);
    int get_mod();
    void set_mod(int n = 0);

    void key_gen();

    vector<cpp_int> encrypt(const std::string& mes);
    std::string dencrypt(const vector<cpp_int>& crp_blocks);
private:
    cpp_int encrypt_block(const cpp_int& mes, cpp_int open_key, cpp_int open_e, cpp_int noise = 0);
    cpp_int decrypt_block(const cpp_int& crp, cpp_int open_key, cpp_int key, cpp_int noise = 0);
    cpp_int findE(const cpp_int& n);
    inline cpp_int findD(const cpp_int& e, const cpp_int& N);
private:
    s_key  key;
    string user;            // creator (decryptor) or user (encryptor)


};

ostream& operator<<(ostream& os, const RSA::s_open_key& ok);
ostream& operator<<(ostream& os, const RSA::s_key& k);
istream& operator>>(istream& is, RSA::s_open_key& ok);
istream& operator>>(istream& is, RSA::s_key& key);

#endif // !_RSA_H_
