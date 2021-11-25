#include <iostream>
#include <string>
#include <gmpxx.h>
#include <vector>
using namespace std;

class Collatz
{
public:
    vector<mpz_class> list;
    mpz_class evenNums = 0;
    mpz_class oddNums = 0;
    Collatz() {}

    mpz_class computing(mpz_class n)
    {
        list.push_back(n);
        if (n <= 1)
        {
            this->oddNums++;
            return 0;
        }
        if (n % 2 == 0)
        {
            this->evenNums++;
            return computing(n / 2);
        }
        this->oddNums++;
        return computing(3 * n + 1);
    }
    ~Collatz() {}
};

int main(int argc, char **argv)
{
    if (argc > 3)
    {
        cerr << "A lot of arguments passed." << endl;
        return -1;
    }
    else if (argc < 2)
    {
        cout << "Usage: CC [NUMBER] [...OPTIONS]" << endl;
        return -1;
    }

    if (strcmp(argv[1], "--help") == 0 || strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "?") == 0)
    {
        cout << R""(
            CC [NUMBER] [...OPTIONS]

            OPTIONS :
                -p, --print  : print list of numbers after computing.
        )"" << endl;

        return 0;
    }

    Collatz a;
    mpz_class START(argv[1]);
    cout << "Computing start...\n";
    a.computing(START);
    cout << "Computing end.\n";

    for (auto i = 0; i < argc; i++)
        if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--print") == 0)
        {
            for (auto i : a.list)
                cout << i << endl;
            break;
        }
    cout << "-------- Result --------\n";

    cout
        << "Evens: " << a.evenNums << endl;
    cout << "Odds: " << a.oddNums << endl;
    cout << "All: " << a.oddNums + a.evenNums << endl;
}
