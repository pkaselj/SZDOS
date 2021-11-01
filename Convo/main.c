#include <stdio.h>
#include <string.h>

#define ELEMENT_COUNT(X) (unsigned long)(sizeof(X) / sizeof(X[0]))

#define F_LEN 4
#define G_LEN 6
#define N_ELEM F_LEN + G_LEN - 1

void print(
    const double* const array,
    const unsigned long length,
    const char* const szName
);

void convo(
    const double f[],
    const unsigned long f_len,
    const double g[],
    const unsigned long g_len,
    double result[]
);

int main() {
    const double g[] = { -1, 2, 3.25, -3.05, 2, 4 };
    const double f[] = { 1, 2, -1.05, 2 };

    print(f, F_LEN, "f");
    print(g, G_LEN, "g");

    double result[N_ELEM] = {0};

    convo(
        f, F_LEN,
        g, G_LEN,
        result
    );

    print(result, N_ELEM, "result");

}

void print(
    const double* const array,
    const unsigned long length,
    const char* const szName
)
{
    printf("%s = [ ", szName);
    int i;
    for (i = 0; i < length; i++)
    {
        printf("%0.2lf ", array[i]);
    }
    printf("]\n");
};

// CONVOLUTION FUNCTION =================================

void convo(
    const double f[],
    const unsigned long f_len,
    const double g[],
    const unsigned long g_len,
    double result[]
)
{
    const unsigned long N = f_len + g_len - 1;

    int n;
    for (n = 0; n < N; n++) {

        unsigned long kmin = (n > f_len - 1) ? n - (f_len - 1) : 0;
        unsigned long kmax = (n < g_len - 1) ? n : g_len - 1;

        for (int k = kmin; k <= kmax; k++) {
            result[n] += g[k] * f[n - k];
        }
    }
}

// =======================================================