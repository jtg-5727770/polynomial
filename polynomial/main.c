#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b)(((a)>(b))?(a):(b))
#define MAX_DEGREE 101
typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} polynomial;
polynomial poly_add(polynomial A, polynomial B)
{
	polynomial C;
	int Apos = 0, Bpos = 0, Cpos = 0;
	int degree_a = A.degree;
	int degree_b = B.degree;
	C.degree = MAX(A.degree, B.degree);
	while (Apos <= A.degree && Bpos <= B.degree) {
		if (degree_a > degree_b) {
			C.coef[Cpos++] = A.coef[Apos++];
			degree_a--;

		}
		else if (degree_a == degree_b) {
			C.coef[Cpos++] = A.coef[Apos++] + B.coef[Bpos++];
			degree_a--; degree_b--;
		}
		else {
			C.coef[Cpos++] = B.coef[Bpos++];
			degree_b--;
		}
	}
	return C;
}
void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	printf("%3.1f \n", p.coef[p.degree]);
}

int main(void)
{
	polynomial a1 = { 3,{ 4, 3, 2, 1} };
	polynomial b1 = { 2,{ 3, 2, 8} };
	polynomial c1;
	print_poly(a1);
	print_poly(b1);
	c1 = poly_add(a1, b1);
	printf("----------------------------------------------------------------------------\n");
	print_poly(c1);
	printf("\n\n");

	polynomial a2 = { 6,{ 7, 0, 0, 5, 9, 0, 1} };
	polynomial b2 = { 3,{ 5, 2, 1, 10} };
	polynomial c2;
	print_poly(a2);
	print_poly(b2);
	c2 = poly_add(a2, b2);
	printf("----------------------------------------------------------------------------\n");
	print_poly(c2);

	system("pause");
	return 0;
}