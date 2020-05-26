#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>//для bool, очевидно
struct List
{
	struct List *NextBlock;
	double Data;
};
struct node
{
	struct node *NextBlock;
	double Data;
};
void init(struct List **l)//получаем значение, взятое по адресу адреса
{
	*l = (struct List *)malloc(sizeof(struct List));
	(*l)->NextBlock = NULL;
	(*l)->Data = 2147483648;//на 1 больше, чем допустимо
}
void clean(struct List *l)
{
	struct List *Temp = l;
	do
	{
		Temp = Temp->NextBlock;
		free(l);
		l = Temp;
	} while (l != NULL);
}
bool is_empty(struct List *l)//проверка на пустоту
{
	if (l == NULL)
		return 0;//0--список пуст
	else
		return 1;//1--в списке есть штуки
}
struct node *find(struct List *l, int value)//найти элемент со значением
{
	struct List *Temp = l;
	while (1)
	{
		if (Temp == NULL)
			return NULL;
		else
		{
			if ((Temp->Data) == value)
				return ((struct node *)l);
		}
		Temp = Temp->NextBlock;
	}
}
int push_back(struct List *l, int value)//вставить в конец(0 при успехе)
{//а как может быть 1?
	if (l->Data == 2147483648)
	{
		l->Data = value;
		return 0;
	}
	struct List *Temp = (struct List *)malloc(sizeof(struct List));
	Temp = l;
	while (Temp->NextBlock != NULL)
		Temp = Temp->NextBlock;
	Temp->NextBlock = (struct List *)malloc(sizeof(struct List));
	Temp = Temp->NextBlock;
	Temp->Data = value;
	Temp->NextBlock = NULL;
	return 0;
}
int push_front(struct List **l, int value)//вставить в начало(0 при успехе)
{//а как может быть 1?
	struct List *Temp = (struct List *)malloc(sizeof(struct List));//при этом здесь **l--это значение
	Temp->Data = value;//l--конкретно двойной адрес, *l--адрес блока, **l--блок
	Temp->NextBlock = (*l);//то есть, в следующем элементе записан адрес начального эл-та списка
	(*l) = Temp;//вот у нас есть список, засунутый в Temp(адрес), мы берём присваиваем адресу l адрес Temp
	return 0;
}
int insert_after(struct node *l, int value)//вставка на нужное место(0--успех)
{
	struct List *Temp = (struct List *)malloc(sizeof(struct List)), *Temp2;
	Temp2=(struct List *)l->NextBlock;
	l->NextBlock =(struct node *)Temp;
	Temp->Data = value;
	Temp->NextBlock = Temp2;
	return 0;
}
int remove_node(struct List *l, int value)//удаление(надо сделать удаление 1-го)
{
	struct List *Temp = l;
	if (l != NULL)
	{
		while (1)
		{
			if ((Temp->NextBlock) == NULL)
				return 1;
			if ((Temp->NextBlock->Data) == value)
			{
				struct List *Temp2 = (struct List *)malloc(sizeof(struct List));
				Temp2 = Temp->NextBlock->NextBlock;
				free(Temp->NextBlock);
				Temp->NextBlock = Temp2;
				return 0;
			}
			Temp = Temp->NextBlock;
		}
	}
	else
		return 1;
}
void print(struct List *l)//вывести всё, что есть
{
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->NextBlock;
	}
	printf("\n");
}
int main()
{
	struct List *l, *Temp;//здесь l--адрес
	int N, i;
	double a, b;
	scanf("%d", &N);//1 пункт
	init(&l);//2 пункт, передаём адрес адреса
	for (i = 0; i < N; i++)
	{
		scanf("%lf", &a);
		push_back(l, a);
	}
	print(l);//3 пункт
	for (i = 0; i < 3; i++)//4 пункт
	{
		scanf("%lf", &a);
		if (find(l, a) == NULL)
			printf("0");
		else
			printf("1");
		if (i!=2)
			printf(" ");
		else
			printf("\n");
	}
	scanf("%lf", &a);//5 пункт
	push_back(l, a);
	print(l);//6 пункт
	scanf("%lf", &a);//7 пункт
	push_front(&l, a);
	print(l);//8 пункт
	scanf("%lf", &a);//9 пункт, здесь a--это j, номер в списке(или значение?)
	scanf("%lf", &b);//b--это x, само значение
	struct node *el=(struct node *)l;
	while (a != 1)
	{
		el = el->NextBlock;
		a--;
	}
	insert_after(el, b);
	print(l);//10 пункт
	scanf("%lf", &a);//11 пункт
	if (l->Data==a)
	{
		Temp=l->NextBlock;
		free(l);
		l=Temp;
	}
	else
		remove_node(l, a);
	print(l);//12 пункт
	clean(l);//13 пункт
	return 1;
}
