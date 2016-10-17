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
    char *head = polynomial;
    for(char *i = polynomial; i == polynomial || *(i - 1) != '\0'; i++){
	if(*i == '+' || *i == '-' || *i == '\0'){
	    //printf("Saving one terms...\n");
	    // parse the polynomials term by term
	    int exp = 0;
	    if(i != polynomial && *(i - 1) != '^'){
		for(char *j = head; j <= i; j++){
		    if(*j == 'x' || *j == '\0'){
			if(j != head){
			    if(j - head != 1){
		                char tmp[100];
				int n = (j - head) / sizeof(char) + 1;
			        strncpy(tmp, head, n);
				tmp[n] = '\0';
			        p->terms[p->length].coef = atoi(tmp);
			    }else{
				if(*head == '+') p->terms[p->length].coef = 1;
				else if(*head == '-') p->terms[p->length].coef = -1;
				else p->terms[p->length].coef = *head - '0';
			    }

			}
			else p->terms[p->length].coef = 1;
			head = j + 1;
			exp = *j == '\0' ? 0 : 1;
			break;
		    }
		}
		if(*head == '^'){
		    char tmp[100];
		    int n = (i - head) / sizeof(char);
		    head++;
		    strncpy(tmp, head, n);
		    tmp[n] = '\0';
		    p->terms[p->length].exp = atoi(tmp);
		}else p->terms[p->length].exp = exp;
		p->length++;
		//printf("%d: %dx^%d\n", p->length, p->terms[p->length - 1].coef, p->terms[p->length - 1].exp);
	    }
	    head = i;
	}
	
    }
}
/* do differential of input polynomials */
void polynomials_differential(polynomials *p)
{
    struct polynomial *curr;
    for(int i = 0; i < p->length; i++){
        curr = &(p->terms[i]);
	curr->coef = curr->coef * curr->exp;
	curr->exp--;
    }
}

/* output polynomials                   */
void output_polynomials(polynomials *p)
{
    struct polynomial *curr;
    for(int i = 0; i < p->length; i++){
        curr = &(p->terms[i]);
	if(curr->coef == 0) continue;
	if(curr->coef > 0 && i != 0) printf("+");
	if(curr->exp != 0){
	    if(curr->coef > 1 || curr->coef < -1) printf("%d", curr->coef);
	    else if(curr->coef == -1) printf("-");
	    printf("x");
	    if(curr->exp > 1) printf("^%d", curr->exp);
	}else{
	    printf("%d", curr->coef);
	}
    }
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
