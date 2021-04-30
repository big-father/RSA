#include "RSA.h"

int RSA::get_prime()
{
    return 0;
}

int RSA::eulers(int p, int q)
{
    return 0;
}

bool RSA::is_prime(int x)
{
    return false;
}

bool RSA::is_double_prime(int x, int y)
{
    return false;
}

void RSA::set_d()
{
    // use fi
    d = 0;
}

void RSA::make_fi()
{
    fi = eulers(p, q);
}








RSA::RSA(string user)
{
    this->user = user;

    if (user == CREATOR)
    {
        set_mod();
        set_exp();
        set_d();
    }
}

int RSA::get_mod()
{
    return mod;
}

void RSA::set_mod(int n = 0)
{
    if (n != 0)
    {
        exp = n;
    }
    else
    {
        // calculate mod
        p = get_prime();
        q = get_prime();
        mod = q * p;
    }
}

void RSA::get_exp()
{
    return exp;
}

void RSA::set_exp(int n = 0)
{
    if (n != 0)
    {
        exp = n;
    }
    else
    {
        // calculate exp and use fi
        make_fi();
    }
}

string RSA::get_massege()
{
    return msg;
}

void RSA::set_massege(string msg)
{
    this->msg = msg;
}

void RSA::encrypting()
{
    this->msg = "";
}

void RSA::dencrypting()
{
    this->msg = "";
}