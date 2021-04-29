#include <iostream>
#include <ctime>
#include <string>
using namespace std;

class RSA
{
    unsigned int exp = 0;
    unsigned int d = 0;
    unsigned int mod = 0;

    string input_text;
    string output_text;
    string user;

    unsigned int get_sample_number()
    {
        cout << "semple number is getting" << endl;
        return 0;
    }

    unsigned int fun_e()
    {
        cout << "fi is getting" << endl;
        return 0;
    }

    int get_fi()
    {
        cout << "starting set_fi" << endl;
        return 0;
    }

    bool is_semple_number(unsigned int x)
    {
        return false;
    }

    bool nod_is_one(unsigned int x, unsigned int y)
    {
        return false;
    }

public:
    RSA(string user)
    {
        this->user = user;

        cout << "constructor seted" << endl;
    }

    void set_mod(int n = 0)
    {
        cout << "seted mod (q * p)" << endl;
    }

    int get_mod()
    {
        cout << "geted mod (q * p)" << endl;
    }

    void set_exp()
    {
        cout << "key is setting" << endl;
    }

    void get_exp()
    {
        cout << "key is getting" << endl;
    }

    void set_d()
    {
        cout << "d is setting" << endl;
    }

    void input_massege(string text)
    {
        cout << "input message" << endl;
        input_text = text;
    }

    string get_enctypt_massege()
    {
        cout << "get encrypt message" << endl;
        return output_text;
    }

    void encrypting_message()
    {
        cout << "encrypted_message is making" << endl;
    }

    void diencrypting_message()
    {
        cout << "diencrypting message" << endl;
    }
};

int main(int argc, char* argv[])
{

    RSA adam("adam");
    RSA eva("eva");

    // set n
    adam.set_mod(); eva.set_mod(adam.get_mod());

    // set exp
    adam.set_exp(); eva.set_exp();

    // set d
    adam.set_d();

    string msg;

    eva.input_massege(msg);
    eva.encrypting_message();

    adam.input_massege(eva.get_enctypt_massege());
    adam.diencrypting_message();

    return 0;
}
