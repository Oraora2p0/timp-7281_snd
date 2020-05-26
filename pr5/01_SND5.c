#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>//для bool, очевидно
struct Tree
{
	struct Tree *Right;
	struct Tree *Left;
	double Data;
};
void init(struct Tree **t)//получаем значение, взятое по адресу адреса
{
	*t = (struct Tree *)malloc(sizeof(struct Tree));
	(*t)->Right = NULL;
	(*t)->Left = NULL;
	(*t)->Data = 2147483648;//на 1 больше, чем допустимо
}
void clean(struct Tree *t)
{
	if (t != NULL)//проверка на пустоту списка
	{
		if (t->Right != NULL)
			clean(t->Right);
		if (t->Left != NULL)
			clean(t->Left);
		free(t);
	}
}
struct Tree* find(struct Tree *t, int value)
{
	if (t->Data==value)
		return t;
	else
	{
		if (value < t->Data)
		{
			if (t->Left != NULL)
				return(find(t->Left, value));
			else
				return NULL;
		}
		else
		{
			if (t->Right != NULL)
				return(find(t->Right, value));
			else
				return NULL;
		}
	}
}
int find_with_output(struct Tree *t, int value)
{
	if (t->Data == value)
	{
		printf("_ ");//предка нет
		if (t->Left != NULL)
			printf("%d ", (int)t->Left->Data);
		else
			printf("_ ");
		if (t->Right != NULL)
			printf("%d", (int)t->Right->Data);
		else
			printf("_");
	}
	else
	{
		if (value < t->Data)
		{
			if (t->Left != NULL)
			{
				if (t->Left->Data == value)
				{
					printf("%d ", (int)t->Data);
					if ((t->Left->Left) != NULL)
						printf("%d ", (int)t->Left->Left->Data);
					else
						printf("_ ");
					if ((t->Left->Right) != NULL)
						printf("%d", (int)t->Left->Right->Data);
					else
						printf("_");
				}
				else
					return(find_with_output(t->Left, value));
			}
			else
				return 1;
		}
		else
		{
			if (t->Right != NULL)
			{
				if (t->Right->Data == value)
				{
					printf("%d ", (int)t->Data);
					if ((t->Right->Left) != NULL)
						printf("%d ", (int)t->Right->Left->Data);
					else
						printf("_ ");
					if ((t->Right->Right) != NULL)
						printf("%d", (int)t->Right->Right->Data);
					else
						printf("_");
				}
				else
					return(find_with_output(t->Right, value));
			}
			else
				return 1;
		}
	}
	return 0;
}
int insert(struct Tree *t, int value)
{
	if (t->Data == 2147483648)//если корневой корень--мать всех корней
	{
		t->Data = value;
		return 0;
	}
	if (t->Data == value)//если уже есть такой
		return 1;
	if (value > (t->Data))//вставка направо
	{
		if ((t->Right)!=NULL)//если дальше есть вообще узел, решаем это рекурсивно
			return(insert(t->Right, value));
		else//ну а если нет, то вот
		{
			t->Right=(struct Tree *)malloc(sizeof(struct Tree));
			t->Right->Right = NULL;
			t->Right->Left = NULL;
			t->Right->Data = value;
			return 0;
		}
	}
	else//налево
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
int deep(struct Tree *t)
{
	int r=0, l=0;
	if ((t->Right) != NULL)
		r=deep(t->Right);
	if ((t->Left) != NULL)
		l = deep(t->Left);
	if (r > l)//если правая ветка глубже, то возвращаем её значение
		return (r+1);
	return (l+1);
}
int remove_node(struct Tree **t, int value)
{
	if ((*t)->Data == value)//нашли
	{//берём либо самый левый правого, либо самый правый левого, я выбрал левый правого
		if ((*t)->Right != NULL)//если справа что-то есть
		{
			struct Tree *Temp = (*t)->Right, *Temp2;//создаём доп. переменную для перемещения
			if (Temp->Left != NULL)//если левый правого вообще есть
			{
				while (Temp->Left->Left != NULL)//и через цикл доходим до самого левого
					Temp = Temp->Left;
				(*t)->Data = Temp->Left->Data;//дошли, поменяли, тогда нужно этот последний либо очистить, либо
				Temp2=Temp->Left;//ну и уберём поставленный элемент
				Temp->Left=Temp2->Right;//спасаем правых потомков самого левого
				free(Temp2);//а левого убиваем
			}
			else//если левого правого нет, то самый левый правого и есть правый
			{
				struct Tree *Temp;
				(*t)->Data = (*t)->Right->Data;//главным становится правый потомок
				Temp = (*t)->Right;//запоминаем, чтобы убрать
				(*t)->Right = (*t)->Right->Right;//новый праввый правого
				free(Temp);
			}
		}
		else//если справа пусто, то просто убиваем корень
		{
			struct Tree *Temp;
			Temp = (*t);
			(*t) = (*t)->Left;//теперь главный--левый потомок
			free(Temp);//убиваем корень
			Temp = NULL;
		}
		return 0;
	}
	else//не нашли
	{
		if (value < ((*t)->Data))
		{
			if ((*t)->Left != NULL)
				return(remove_node(&((*t)->Left), value));
			else
				return 1;
		}
		else
		{
			if (((*t)->Right) != NULL)
				return(remove_node(&((*t)->Right), value));
			else
				return 1;
		}
	}
}
int remove_min(struct Tree *t)
{
	struct Tree *Temp = t, *Temp2;//создаём доп. переменную для перемещения
	if (Temp->Left != NULL)//если левый вообще есть
	{
		while (Temp->Left->Left != NULL)//и через цикл доходим до самого левого
			Temp = Temp->Left;
		Temp2 = Temp->Left;//ну и уберём минимальный элемент
		Temp->Left = Temp2->Right;//спасаем правых потомков самого левого
		free(Temp2);//а левого убиваем
	}
	else//если левого нет, то самый левый и есть текущий
	{
		Temp = t->Right;
		free(t);
		t = Temp;
	}
	return 0;
}
int rotate_right(struct Tree **t)//вращение направо
{
	if (*t == NULL)
		return 1;
	struct Tree *A, *B, *C=(*t)->Right, *x=(*t)->Left, *y=(*t), *Temp = (struct Tree *)malloc(sizeof(struct Tree));
	if (x != NULL)
	{
		A = x->Left;
		B = x->Right;
	}
	else
		return 1;//нам нечего закидывать в корень
	Temp->Right = y;//не может быть NULL, это бывший корень
	Temp->Left = A;
	Temp->Right->Right = C;
	Temp->Right->Left = B;
	Temp->Data = x->Data;
	free(x);
	(*t) = Temp;
	return 0;
}
int rotate_left(struct Tree **t)//вращение направо
{
	if (*t == NULL)
		return 1;
	struct Tree *A = (*t)->Left, *B, *C, *x = (*t), *y = (*t)->Right, *Temp=(struct Tree *)malloc(sizeof(struct Tree));
	if (y != NULL)
	{
		B = y->Left;
		C = y->Right;
	}
	else
		return 1;//нам нечего закидывать в корень
	Temp->Right = C;
	Temp->Left = x;
	Temp->Left->Right = B;
	Temp->Left->Left = A;
	Temp->Data = y->Data;
	free(y);
	(*t) = Temp;
	return 0;
}
int print_tree(struct Tree *t)//смысл делать две одинаковые функции?
{
	if (t == NULL)
	{
		printf("-\n");
		return 1;
	}
	struct Tree *Temp=t;
	int Rang=0, i, j, k, sk;//k--для индекса массива при переборе, i--номер уровня, j--количество выводов
	int *comb;
	Rang = deep(t);
	comb = (int*)malloc(sizeof(int));//динамический создаём
	for (i = 0; i < Rang; i++)//проходим по уровням
	{
		if (i != 0)
		{
			comb = (int*)realloc(comb, i* sizeof(int));//выделяем количество ячеек соответственно уровню
			for (j = 0; j < i; j++)
				comb[j] = 0;//зануляем всё
		}
		//это будет количество выводов
		j = 1;
		sk = i;
		while (sk != 0)
		{
			j = j * 2;
			sk--;
		}
		//
		while (j != 0)
		{
			k = 0;
			Temp = t;
			for (k = 0; k < i; k++)//здесь просто доходим до нужной точки
			{
				if (comb[k] == 0)
				{
					if ((Temp->Left) != NULL)
						Temp = Temp->Left;
					else
					{
						k = -1;//для отслеживания что элемента нет
						break;
					}
				}
				else
				{
					if ((Temp->Right) != NULL)
						Temp = Temp->Right;
					else
					{
						k = -1;//для отслеживания что элемента нет
						break;
					}
				}
			}
			if (i != 0)
			{
				sk=i-1;
				comb[sk]++;//изменяем массив
				while (1)
				{
					if (comb[sk] == 2)
					{
						comb[sk] = 0;
						sk--;
						if (sk < 0)
							break;//всё перебрали, закончили с выводом
						else
							comb[sk]++;
					}
					else
						break;//то есть, если просто прибавили, то выходим
				}
			}
			if (k==-1)//непосредственно вывод
				printf("_");
			else
				printf("%d", (int)Temp->Data);
			j--;
			if (j != 0)
				printf(" ");
		}
		printf("\n");
	}
	return 1;
}
int all(struct Tree *t)
{
	if (t == NULL)
		return 0;
	int r, l;
	l = all(t->Left);
	r = all(t->Right);
	return (l + r+1);
}
int main()
{
	struct Tree *t;
	int i;
	double a;
	init(&t);//1 пункт, передаём адрес адреса
	for (i = 0; i < 4; i++)
	{
		scanf("%lf", &a);
		insert(t, a);
	}
	print_tree(t);//2 пункт, вывод
	printf("\n");
	for (i = 0; i < 3; i++)//3 пункт
	{
		scanf("%lf", &a);
		insert(t, a);
	}
	print_tree(t);//4 пункт, вывод
	printf("\n");
	for (i = 0; i < 2; i++)
	{
		scanf("%lf", &a);//5 и 6 пункт
		a = find_with_output(t, a);
		if (a == 1)
			printf("-");
		printf("\n\n");
	}
	scanf("%lf", &a);//пункт 7
	remove_node(&t, a);
	print_tree(t);//8 пункт
	printf("\n");
	while (1)//9 пункт
	{
		a=rotate_left(&t);
		if (a == 1)
			break;
	}
	print_tree(t);//10 пункт
	printf("\n");
	while (1)//11 пункт
	{
		a = rotate_right(&t);
		if (a == 1)
			break;
	}
	print_tree(t);//12 пункт
	printf("\n");
	printf("%d\n\n", all(t));//13 пункт
	clean(t);//14 пункт
	t = NULL;
	print_tree(t);//15 пункт
	return 0;
}
