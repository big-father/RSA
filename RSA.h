#pragma once 
#ifndef _RSA_H_
#define _RSA_H_

#include <string>
using namespace std;

class RSA
{
private:

    int exp = 0;
    int d = 0;
    int mod = 0;
    int p = 0;
    int q = 0;
    int fi = 0;

    string msg;
    string user;            // creator (decryptor) or user (encryptor)

    int get_prime();
    int eulers(int p, int q);
    bool is_prime(int x);
    bool is_double_prime(int x, int y);
    void set_d();
    void make_fi();

public:

    enum users
    {
        USER = "user",
        CREATOR = "creator"
    };

    RSA(string user);
    int get_mod();
    void set_mod(int n = 0);
    void get_exp();
    void set_exp(int n = 0);
    
    string get_massege();
    void set_massege(string msg);
    void encrypting();
    void dencrypting();

};

#endif // !_RSA_H_