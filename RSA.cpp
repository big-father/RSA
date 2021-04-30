#include "RSA.h"

int RSA::get_sample_number()
{
    cout << "semple number is getting" << endl;
    return 0;
}

int RSA::fun_e()
{
    cout << "fi is getting" << endl;
    return 0;
}

int RSA::get_fi()
{
    cout << "starting set_fi" << endl;
    return 0;
}

bool RSA::is_semple_number(int x)
{
    return false;
}

bool RSA::nod_is_one(int x, int y)
{
    return false;
}






RSA::RSA(string user)
{
    this->user = user;

    cout << "constructor seted" << endl;
}

void RSA::set_mod(int n = 0)
{
    cout << "seted mod (q * p)" << endl;
}

int RSA::get_mod()
{
    cout << "geted mod (q * p)" << endl;
}

void RSA::set_exp()
{
    cout << "key is setting" << endl;
}

void RSA::get_exp()
{
    cout << "key is getting" << endl;
}

void RSA::set_d()
{
    cout << "d is setting" << endl;
}

void RSA::input_massege(string text)
{
    cout << "input message" << endl;
    input_text = text;
}

string RSA::get_enctypt_massege()
{
    cout << "get encrypt message" << endl;
    return output_text;
}

void RSA::encrypting_message()
{
    cout << "encrypted_message is making" << endl;
}

void RSA::diencrypting_message()
{
    cout << "diencrypting message" << endl;
}