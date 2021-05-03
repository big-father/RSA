#include "RSA.h"
#include "converter.h"
#include <boost/integer/mod_inverse.hpp>
#include <boost/math/special_functions/prime.hpp>

using namespace boost::math;
using namespace boost::multiprecision;

cpp_int RSA::encrypt_block(const cpp_int& mes, cpp_int open_key, cpp_int open_e, cpp_int noise)
{
    auto m(mes);
    m ^= noise;

    return powm(m, open_e, open_key);
}

cpp_int RSA::decrypt_block(const cpp_int& crp, cpp_int open_key, cpp_int key, cpp_int noise)
{
    cpp_int c = powm(crp, key, open_key);
    c ^= noise;

    return c;
}

cpp_int RSA::findE(const cpp_int& n)
{
    cpp_int e;
        for ( unsigned i = 1; i < max_prime; i++ )
        {
            e = prime(i);
            if (gcd(e, n) == 1 )
            {
                return e;
            }
        }

        return cpp_int(-1);
}

inline cpp_int RSA::findD(const cpp_int& e, const cpp_int& N)
{
    return boost::integer::mod_inverse(e, N);
}

vector<cpp_int> RSA::encrypt(const std::string& mes)
{
    if (key.open.n == 0)
        return vector<cpp_int>();

    vector<cpp_int> crp_blocks;
    auto open_blocks = converter::string_to_blocks(mes);
    auto crp_block = key.open.init_vec;
    for (const auto& ob : open_blocks)
    {
        crp_block = encrypt_block(ob, key.open.n, key.open.exp , crp_block);
        crp_blocks.push_back(crp_block);
    }

    return crp_blocks;
}

std::string RSA::dencrypt(const vector<cpp_int>& crp_blocks)
{
    if (key.key == 0)
        return "";

    string mes;
    auto crp_block = key.open.init_vec;
    for (const auto& cb : crp_blocks)
    {
        auto open_block = decrypt_block(cb, key.open.n, key.key, crp_block);
        auto str = converter::block_to_string(open_block);
        crp_block = cb;

        mes += str;
    }

    return mes;
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

ostream& operator<<(ostream& os, const RSA::s_open_key& ok)
{
    os << ok.exp << SPLITER
       << converter::cpp_int_to_str64(ok.n) << SPLITER
       << converter::cpp_int_to_str64(ok.init_vec) << SPLITER;

    return os;
}

ostream& operator<<(ostream& os, const RSA::s_key& k)
{
    os << k.open
       << converter::cpp_int_to_str64(k.key) << SPLITER;

    return os;
}

istream& operator>>(istream& is, RSA::s_open_key& ok)
{
    string  str64_n, str64_init_vec;
    is >> ok.exp >> str64_n >> str64_init_vec;

    ok.exp = converter::str64_to_cpp_int(str64_n);
    ok.exp = converter::str64_to_cpp_int(str64_init_vec);

    return is;
}

istream& operator>>(istream& is, RSA::s_key& key)
{
    string str64_key;
    is >> key.open >> str64_key;

    key.key = converter::str64_to_cpp_int(str64_key);

    return is;
}
