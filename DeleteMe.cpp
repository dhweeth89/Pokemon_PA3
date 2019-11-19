#include <iostream>
#include "stdlib.h"
#include "time.h"
#include "math.h"

using namespace std;

int main()
{
    srand(time(NULL));

    for (int i = 0; i < 5; i++)
    {
        cout <<  ((double) round( (  ( (double)rand() / RAND_MAX) * (2 - 0) * 100)) / 100) << endl;
    }

    return 0;
}