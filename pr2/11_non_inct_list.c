#include <stdio.h>
int main()
{
	double n1, n2;
	int i, N;
	(void)scanf("%d", &N);
	if (N <= 0)
		return 1;
	(void)scanf("%lf", &n1);
	for (i = 1; i < N; i++)
	{
		(void)scanf("%lf", &n2);
		if (n1 < n2)
		{
			printf("0");
			return 1;
		}
		n1 = n2;
	}
	printf("1");
	return 1;
}