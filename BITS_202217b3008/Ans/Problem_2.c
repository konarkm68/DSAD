#include <stdio.h>

// Global Declarations
#define MAX_DEGREE 10 // Each Polynomial is allowed to have a maximum of MAX_DEGREE terms
char var = 'x'; //  var - Variable
struct plynml_term { // plynml_Term - Polynomial Term
    int coeff; // coeff - Coefficient
    int expon; // expon - Exponent
}; // res_plynml = plynml_1 + plynml_2
struct plynml_term plynml_1[MAX_DEGREE], plynml_2[MAX_DEGREE], res_plynml[MAX_DEGREE];

// Function Prototypes
void get_plynml(struct plynml_term[], int);
void display_plynml(struct plynml_term[], int);
int add_plynml(struct plynml_term[], int, struct plynml_term[], int, struct plynml_term[]);

int main()
{
    int p1_nt, p2_nt; // p - plynml_ & nt - number_of_terms
    printf("Polynomial Addition\n\n");

    // Get the 1st Polynomial and display it.
    printf("Enter the number of terms for the 1st polynomial: "); scanf("%d", &p1_nt);
    get_plynml(plynml_1, p1_nt);
    printf("1st polynomial: "); display_plynml(plynml_1, p1_nt);
    // Get the 2nd Polynomial and display it.
    printf("\nEnter the number of terms for the 2nd polynomial: "); scanf("%d", &p2_nt);
    get_plynml(plynml_2, p2_nt);
    printf("2nd polynomial: "); display_plynml(plynml_2, p2_nt);

    // Add both the Polynomials_1&2, and display the resultant polynomial.
    int p3_nt = add_plynml(plynml_1, 3, plynml_2, 3, res_plynml);
    printf("\nResultant 3rd polynomial (Polynomial Addition of Polynomials_1&2): "); display_plynml(res_plynml, p3_nt);

    return 0;
}

void get_plynml(struct plynml_term p_t[], int num_terms)
{
    printf("Enter BOTH coefficient-value and exponent-value in the DESCENDING-ORDER-OF-EXPONENT-VALUES!!\n");
    for (int i = 0; i < num_terms; i++)
    {
        printf("Enter the coefficient for the term - %d: ", i+1); scanf("%d", &p_t[i].coeff);
        printf("Enter the    exponent for the term - %d: ", i+1); scanf("%d", &p_t[i].expon);
    }
    printf("\n");
}

void display_plynml(struct plynml_term p_t[], int num_terms)
{
    for (int i = 0; i < num_terms; i++)
    {
        printf("(%d).(%c^%d)", p_t[i].coeff, var, p_t[i].expon);
        if (i < num_terms - 1)
            printf(" + ");
    }
    printf("\n");
}

int add_plynml(struct plynml_term p1[], int p1_nt, struct plynml_term p2[], int p2_nt, struct plynml_term p3[])
{
    int i = 0, j = 0, p3_nt = 0;
    while (i < p1_nt && j < p2_nt)
    {
        if (p1[i].expon == p2[j].expon)
        {
            p3[p3_nt].coeff = p1[i].coeff + p2[j].coeff;
            p3[p3_nt].expon = p1[i].expon;
            i++; j++; p3_nt++;
        }
        else if (p1[i].expon > p2[j].expon)
        {
            p3[p3_nt].coeff = p1[i].coeff;
            p3[p3_nt].expon = p1[i].expon;
            i++; p3_nt++;
        }
        else
        {
            p3[p3_nt].coeff = p2[j].coeff;
            p3[p3_nt].expon = p2[j].expon;
            j++; p3_nt++;
        }
    }
    // Inserting any left-over values from p1 into p3
    while (i < p1_nt)
    {
        p3[p3_nt].coeff = p1[i].coeff;
        p3[p3_nt].expon = p1[i].expon;
        i++; p3_nt++;
    }
    // Inserting any left-over values from p2 into p3
    while (j < p2_nt)
    {
        p3[p3_nt].coeff = p2[j].coeff;
        p3[p3_nt].expon = p2[j].expon;
        j++; p3_nt++;
    }

    return p3_nt;
}
