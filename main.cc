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
    mpz_class N;
    Collatz(string NUM)
    {
        this->N = NUM;
    }

    mpz_class computing()
    {
        list.push_back(this->N);
        if (this->N <= 1)
        {
            this->oddNums++;
            return 0;
        }
        if (this->N % 2 == 0)
        {
            this->evenNums++;
            return computing((this->N / 2));
        }
        this->oddNums++;
        return computing((3 * this->N + 1));
    }

    mpz_class computing(mpz_class N)
    {
        list.push_back(N);
        if (N <= 1)
        {
            this->oddNums++;
            return 0;
        }
        if (N % 2 == 0)
        {
            this->evenNums++;
            return computing((N / 2));
        }
        this->oddNums++;
        return computing((3 * N + 1));
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

    Collatz a(argv[1]);
    cout << "Computing start...\n";
    a.computing();
    cout << "Computing end.\n";

    cout << "-------- Result --------\n\n";

    for (auto i = 0; i < argc; i++)
        if (strcmp(argv[i], "-p") == 0 || strcmp(argv[i], "--print") == 0)
        {
            for (auto i : a.list)
                cout << i << endl;
            break;
        }

    cout
        << "\nEvens: " << a.evenNums << endl;
    cout << "Odds: " << a.oddNums << endl;
    cout << "All: " << a.oddNums + a.evenNums << endl;
}
