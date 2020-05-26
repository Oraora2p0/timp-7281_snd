#include <stdio.h>
int main()
{
	double el, min;
	int i, N;
	(void)scanf("%d", &N);
	if (N <= 0)
		return 1;
	(void)scanf("%lf", &el);
	min = el;
	for (i = 1; i < (int)N; i++)
	{
		(void)scanf("%lf", &el);
		if (el < min)
			min = el;
	}
	printf("%lf", min);
	return 1;
}