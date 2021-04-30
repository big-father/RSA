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

    string input_text;
    string output_text;
    string user;

    int get_sample_number();
    int fun_e();
    int get_fi();
    bool is_semple_number(int x);
    bool nod_is_one(int x, int y);

public:

    RSA(string user);
    void set_mod(int n = 0);
    int get_mod();
    void set_exp();
    void get_exp();
    void set_d();
    void input_massege(string text);
    string get_enctypt_massege();
    void encrypting_message();
    void diencrypting_message();

};

#endif // !_RSA_H_