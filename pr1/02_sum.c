#include <stdio.h>
int main()
{
	char a[40];
	int i = -1, j, numb=1, pnt=0, pw, dec;
	double num1=0, num2 = 0;
	j=(int)fgets(a, (int)sizeof(a), stdin);
	while (a[++i] != ' ')
	{
		if (a[i] == '\n')
		{
			printf("Error 1--found only one number!");
			return 1;
		}
		else
			if ((a[i] < '0') || (a[i] > '9'))
			{
				if ((a[i]=='-') && (i==0))
				{
					numb = -1;
					i++;
				}
				else
					if ((a[i] == '.') && (i != 0))
					{
						pnt = 1;
						i++;
					}
					else
					{
						printf("Error 2.1--found unacceptable symbols!");
						return 1;
					}
			}
		if (pnt == 0)
			num1 = (num1 * 10) + numb * (int)(a[i] - '0');
		else
		{
			dec=1;
			for(pw=0; pw<pnt; pw++)
				dec*=10;	
			num1 = num1 + numb * ((double)(a[i] - '0') / (double)dec);
			pnt++;
		}
	}
	j = i;
	pnt = 0;
	numb = 1;
	while (a[++i] != '\n')
	{
		if ((a[i] < '0') || (a[i] > '9'))
		{
			if ((a[i] == '-') && (i == j + 1))
			{
				numb = -1;
				i++;
			}
			else
				if ((a[i] == '.') && (i != 0))
				{
					pnt = 1;
					i++;
				}
				else
				{
					printf("Error 2.2--found unacceptable symbols!");
					return 1;
				}
		}
		if (pnt == 0)
			num2 = (num2 * 10) + numb * (int)(a[i] - '0');
		else
		{
			dec=1;
			for(pw=0; pw<pnt; pw++)
				dec*=10;	
			num1 = num1 + numb * ((double)(a[i] - '0') / (double)dec);
			pnt++;
		}
	}
	printf("%.8f", ((double)num1 + (double)num2));
	return 1;
}
