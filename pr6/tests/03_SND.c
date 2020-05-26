#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
struct Tree
{
	struct Tree *Right;
	struct Tree *Left;
	double Data;
};
int insert(struct Tree *t, int value)
{
	if (t->Data == value)
		return 1;
	if (value > (t->Data))
	{
		if ((t->Right) != NULL)
			return(insert(t->Right, value));
		else
		{
			t->Right = (struct Tree *)malloc(sizeof(struct Tree));
			t->Right->Right = NULL;
			t->Right->Left = NULL;
			t->Right->Data = value;
			return 0;
		}
	}
	else
	{
		if ((t->Left) != NULL)
			return(insert(t->Left, value));
		else
		{
			t->Left = (struct Tree *)malloc(sizeof(struct Tree));
			t->Left->Right = NULL;
			t->Left->Left = NULL;
			t->Left->Data = value;
			return 0;
		}
	}
}
void init(struct Tree **t, int value)
{
	*t = (struct Tree *)malloc(sizeof(struct Tree));
	(*t)->Right = NULL;
	(*t)->Left = NULL;
	(*t)->Data = value;
}
int print_reverse(struct Tree *t)//пробелы
{
	struct Tree *Temp[7];
	int i = 0;
	Temp[0] = t;
	while (1)
	{
		while (1)//запись до конца
		{
			while ((Temp[i]->Left) != NULL)
			{
				Temp[i + 1] = Temp[i]->Left;
				i++;
			}
			if ((Temp[i]->Right) != NULL)
			{
				Temp[i + 1] = Temp[i]->Right;
				i++;
			}
			else
				break;
		}
		while ((i != 0) && ((Temp[i - 1]->Right) == Temp[i]))//нужно сдвигаться вверх?
		{
			printf("%d ", (int)Temp[i]->Data);
			i--;
		}
		if (i == 0)
			break;
		while (i != 0)
		{
			if (((Temp[i - 1]->Right) != NULL) && ((Temp[i - 1]->Right) != Temp[i]))//нужно сдвигаться вправо?
			{
				printf("%d ", (int)Temp[i]->Data);
				Temp[i] = Temp[i - 1]->Right;
				break;
			}
			else
			{
				i--;
				printf("%d ", (int)Temp[i + 1]->Data);//выводим покинутый узел
				if (i == 0)
				{
					printf("%d", (int)Temp[i]->Data);
					return 0;
				}
			}
		}
	}
	printf("%d", (int)Temp[i]->Data);
	return 0;
}
int main()
{
	struct Tree *t;
	double val;
	int i;
	scanf("%lf", &val);
	init(&t, val);
	for (i = 0; i < 6; i++)
	{
		scanf("%lf", &val);
		insert(t, val);
	}
	print_reverse(t);
	return 1;
}
