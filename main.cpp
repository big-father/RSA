#include <iostream>
#include <string>
using namespace std;

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
