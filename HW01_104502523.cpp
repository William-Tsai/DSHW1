#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

typedef struct polynomial {
    /*define struct polynomial*/
    int coef;
    int exp;
};
typedef struct polynomials {
    /*define struct polynomials*/
    int length=0;
    polynomial terms[100];
};
/* save the input polynomials           */
void save_polynomials(char *polynomial,polynomials *p)
{

}
/* do differential of input polynomials */
void polynomials_differential(polynomials *p)
{

}

/* output polynomials                   */
void output_polynomials(polynomials *p)
{

}

int main()
{
    char input_polynomials[50];
    polynomials *p=(polynomials *)malloc(sizeof(polynomials));
    p->length=0;
    cout << "Type your polynomials here : ";
    cin >> input_polynomials;
    cout << "Your Input polynomials : ";
    save_polynomials(input_polynomials,p);
    output_polynomials(p);
    cout << endl;
    cout << "Your First differential polynomials : ";
    polynomials_differential(p);
    output_polynomials(p);
    cout << endl;
    cout << "Your Second differential polynomials : ";
    polynomials_differential(p);
    output_polynomials(p);
    cout << endl;
    free(p);
}
/*
2x^3-7x^2-x+9
-x^2-x-1
*/
