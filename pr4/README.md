### Министерство науки и высшего образования Российской Федерации

### ТОМСКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ СИСТЕМ УПРАВЛЕНИЯ И РАДИОЭЛЕКТРОНИКИ (ТУСУР)

### Кафедра комплексной информационной безопасности электронно-вычислительных систем (КИБЭВС)

### Отчёт по практической работе №3 "ДВУСВЯЗНЫЕ СПИСКИ" по дисциплине "Технологии и методы программирования"

Выполнил студент группы 728-1

________Солопов Никита

_____04.2020

Принял

Преподаватель кафедры КИБЭВС

________Перминов П.В.

_____04.2020

Томск 2019

### Введение

Цель работы: целью работы является освоение навыков работы с системой контроля версий gitlab на более высоком уровне. Разработка алгоритма и написание программы, реализующих полноценную работу с двусвязным линейным списком: его создание/очищение, добавление/удаление элементов на разных узлах, а также поиск элементов.

Описание порядка работы программы:

1. Cчитывает количество элементов n, 0 < n <= 2147483647;
2. Cоздает пустой список, считывает n элементов a, |a| <= 2147483647 и заносит их в список;
3. Выводит содержимое списка, используя функцию print;
4. Считывает k1, k2, k3 (|k| <= 2147483647) и выводит "1", если в списке существует элемент с таким значением и "0" если нет (выводить через пробел, например "1 0 1");
5. Считывает m, |m| <= 2147483647 и вставляет его в конец списка;
6. Выводит содержимое списка, используя функцию print_invers;
7. Считывает t, |t| <= 2147483647 и вставляет его в начало списка;
8. Выводит содержимое списка, используя функцию print;
9. Cчитывает j и x (0 < j <= 2147483647, |x| <= 2147483647) и вставляет значение x после j-ого элемента списка;
10. Выводит содержимое списка, используя функцию print_invers;
11. Считывает u и y (0 < u <= 2147483647, |y| <= 2147483647) и вставляет значение y перед u-ым элементом списка;
12. Выводит содержимое списка, используя функцию print;
13. Считывает z, |z| <= 2147483647 и удаляет первый элемент (при его наличии), хранящий значение z из списка;
14. Выводит содержимое списка, используя функцию print_invers;
15. Считывает r, |r| <= 2147483647 и удаляет последний элемент (при его наличии), хранящий значение r из списка;
16. Выводит содержимое списка, используя функцию print;
17. Очищает список.

### 1 Теоретическая часть

Список — это линейная динамическая структура данных, у каждого элемента может быть только один предок и только один потомок. По сути своей это очень похоже на обыкновенный массив, с той лишь разницей, что размер его не имеет ограничений. Списки также подразделяются на несколько типов. Разберём детально двусвязный список и сравним с односвязным. В отличие от односвязного, каждый узел двунаправленного(двусвязного) линейного списка содержит два поля указателей — на следующий и на предыдущий узлы. Указатель на предыдущий узел корня списка содержит нулевое значение. Указатель на следующий узел последнего узла также содержит нулевое значение. Наличие двух ссылок вместо одной предоставляет несколько преимуществ. Вероятно, наиболее важное из них состоит в том, что перемещение по списку возможно в обоих направлениях. Это упрощает работу со списком, в частности, вставку и удаление. Помимо этого, пользователь может просматривать список в любом направлении. Еще одно преимущество имеет значение только при некоторых сбоях. Поскольку весь список можно пройти не только по прямым, но и по обратным ссылкам, то в случае, если какая-то из ссылок станет неверной, целостность списка можно восстановить по другой ссылке. Построение двусвязного списка выполняется аналогично построению односвязного за исключением того, что необходимо установить две ссылки. Поэтому в структуре данных должны быть описаны два указателя связи. То есть, двусвязный список можно создать из односвязного, добавив/изменив несколько строчек кода и добавив в структуру указатель на структуру того же типа. Сложность операций односвязного и двусвязного списка отличается. Ниже предоставлены таблицы со сложностями некоторых операций.

Таблица 2.1--Сложности односвязного списка

| init() | clean() | push_back() | push_front() | insert_after() | remove_first() | remove_last() |
| ------ | ------- | ----------- | ------------ | -------------- | -------------- | ------------- |
| O(1)   | O(n)    | O(n)        | O(n)         | O(n)           | O(n)           | O(n)          |

Таблица 2.2--Сложности двусвязного списка

| init() | clean() | push_back() | push_front() | insert_after() | remove_first() | remove_last() |
| ------ | ------- | ----------- | ------------ | -------------- | -------------- | ------------- |
| O(1)   | O(n)    | O(n)        | O(n)         | O(n)           | O(n)           | O(1)          |

### 2 Ход работы

В процессе работы были проделаны следующие действия:

Написаны с помощью программы Visual Studio 2017 программа на основе алгоритма работы с двусвязным списком. Отдельно были прописаны алгоритмы работы, такие как вывод всего списка в указанном порядке или вставка значения в конец/начало списка. Позже функции были написаны и протестированы в вышеупомянутой среде Visual Studio 2017. Ниже продемонстрирована работа двух наиболее простых блоков--приёма чисел и проверки на существование в списке трёх введённых за этим чисел. Также можно увидеть наглядную визуализацию структуры списка.

![](/pr4/images/1.png "1")

Рисунок 2.1--Работа первых блоков программы

![](/pr4/images/2.png "2")

Рисунок 2.2--Структура списка

Необходимо также сказать о структуре двусвязного списка, так как это особенность его работы. Как видно из рисунка ниже, структура состоит из трёх элементов--переменной типа double, в которой хранятся важные данные и двух переменных типа структуры, которые потенциально могут предоставлять доступ к последующим элементам списка, либо не указывать никуда, для этого применяется значение NULL.

![](/pr4/images/3.png "3")

Рисунок 2.3--Структура списка(код)

Уже на основе этого была написана работа программы целиком, в которой и использовались блоки-функции.

![](/pr4/images/4.png "4")

Рисунок 2.4--Работа программы

Коды писались на основе материалов по работе с односвязанными списками, данными для прошлой работы в качестве методички. Отсюда возможно некоторое сходство принципов работы и функционирования. Для сравнения ниже представлены функции вставки элемента в начало для одно- и двусвязного списков.

![](/pr4/images/5.png "5")

Рисунок 2.5--Добавление в начало, двусвязный список

![](/pr4/images/6.png "6")

Рисунок 2.6--Добавление в начало, односвязный список

В рамках эксперимента был произведён рефакторинг программы по splint, результаты приведены ниже--splint не был успешно пройден из-за множества недочётов, каждый из которых теоретически можно устранить, но тогда это заняло бы значительный объём времени. Стоит отметить, что прохождение по splint необязательно в рамках данной лабораторной работы и поэтому не было выполнено.

![](/pr4/images/7.png "7")

Рисунок 2.7--Рефакторинг по splint

Ниже, в приложении А предоставлен код программы.

В приложении Б можно увидеть ссылки на материалы по CI/CD, GitLab и системе типов Си, использовавшиеся в рамках работы.

### 4 Заключение

В результате работы были закреплены навыки работы с системой контроля версий gitlab на более высоком уровне. Разработан алгоритм, а также написана программа, реализующая полноценную работу с двусвязным линейным списком: его создание/очищение, добавление/удаление элементов на разных узлах, а также поиск элементов.

### Приложение А(код программы)

```с
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>//для bool, очевидно
struct Line
{
	struct Line *Front;
	struct Line *Back;
	double Data;
};
struct Node
{
	struct Node *Front;
	struct Node *Back;
	double Data;
};
void init(struct Line **l)//получаем значение, взятое по адресу адреса
{
	*l = (struct Line *)malloc(sizeof(struct Line));
	(*l)->Front = NULL;
	(*l)->Back = NULL;
	(*l)->Data = 2147483648;//на 1 больше, чем допустимо
}
void clean(struct Line *l)
{
	struct Line *Temp = l;
	free(Temp->Back);
	do
	{
		Temp = Temp->Front;
		free(l);
		l = Temp;
	} while (l != NULL);
}
bool is_empty(struct Line *l)//проверка на пустоту
{
	if (l == NULL)
		return 0;//0--список пуст
	else
		return 1;//1--в списке есть штуки
}
struct Node *find(struct Line *l, int value)//найти элемент со значением
{
	struct Line *Temp = l;
	while (1)
	{
		if (Temp == NULL)
			return NULL;
		else
		{
			if ((Temp->Data) == value)
				return ((struct Node *)l);
		}
		Temp = Temp->Front;
	}
}
int push_back(struct Line *l, int value)//вставить в конец(0 при успехе)
{//а как может быть 1?
	if (l->Data == 2147483648)
	{
		l->Data = value;
		return 0;
	}
	struct Line *Temp = (struct Line *)malloc(sizeof(struct Line));
	Temp = l;
	while (Temp->Front != NULL)
		Temp = Temp->Front;
	Temp->Front = (struct Line *)malloc(sizeof(struct Line));
	Temp->Front->Back = Temp;//отличие с прошлым кодом
	Temp = Temp->Front;
	Temp->Data = value;
	Temp->Front = NULL;
	return 0;
}
int push_front(struct Line **l, int value)//вставить в начало(0 при успехе)
{//а как может быть 1?
	struct Line *Temp = (struct Line *)malloc(sizeof(struct Line));//при этом здесь **l--это значение
	Temp->Data = value;//l--конкретно двойной адрес, *l--адрес блока, **l--блок
	Temp->Front = (*l);//то есть, в следующем элементе записан адрес начального эл-та списка
	Temp->Back = NULL;
	Temp->Front->Back = Temp;//указатель от прошлого первого элемента
	(*l) = Temp;//вот у нас есть список, засунутый в Temp(адрес), мы берём присваиваем адресу l адрес Temp
	return 0;
}
int insert_after(struct Node *l, int value)//вставка на нужное место(0--успех)
{
	if (l->Front != NULL)
	{
		struct Node *Temp = (struct Node *)malloc(sizeof(struct Node)), *Temp2;
		Temp->Front = l->Front;//делаем привязки от элемента к соседним тут
		Temp->Back = l;//и тут
		Temp->Data = value;
		l->Front->Back = Temp;//меняем указатель с последующего элемента на вставляемый
		l->Front = Temp;
	}
	else
	{
		l->Front = (struct Node *)malloc(sizeof(struct Node));
		l->Front->Front = NULL;
		l->Front->Data = value;
		l->Front->Back = l;
	}
	return 0;
}
int insert_before(struct Node *l, int value)//вставка на нужное место(0--успех)
{
	if (l->Back != NULL)
	{
		struct Node *Temp = (struct Node *)malloc(sizeof(struct Node)), *Temp2;
		Temp->Back = l->Back;//делаем привязки от элемента к соседним тут
		Temp->Front = l;//и тут
		Temp->Data = value;
		l->Back->Front = Temp;//меняем указатель с последующего элемента на вставляемый
		l->Back = Temp;
	}
	else
	{
		l->Back = (struct Node *)malloc(sizeof(struct Node));
		l->Back->Back = NULL;
		l->Back->Data = value;
		l->Back->Front = l;
	}
	return 0;
}
int remove_first(struct Line *l, int value)//удаление(надо сделать удаление 1-го)
{
	struct Line *Temp = l;
	if (l != NULL)
	{
		while (1)
		{
			if ((Temp->Front) == NULL)
				return 1;//не найдено
			if ((Temp->Front->Data) == value)
			{
				Temp = Temp->Front;
				if (Temp->Front != NULL)
				{
					Temp->Back->Front = Temp->Front;
					Temp->Front->Back = Temp->Back;
					free(Temp);
				}
				else
				{
					Temp->Back->Front = NULL;
					free(Temp);
				}
				return 0;
			}
			Temp = Temp->Front;
		}
	}
	else
		return 1;
}
int remove_last(struct Line *l, int value)//удаление(надо сделать удаление 1-го)
{
	struct Line *Temp = l, *TempSaving = NULL;
	if (l != NULL)
	{
		while (Temp->Front != NULL)
		{
			if ((Temp->Front->Data) == value)
				TempSaving = Temp->Front;
			Temp = Temp->Front;
		}
		if (TempSaving != NULL)
		{
			if (TempSaving->Front != NULL)
			{
				TempSaving->Back->Front = TempSaving->Front;
				TempSaving->Front->Back = TempSaving->Back;
				free(TempSaving);
			}
			else
			{
				TempSaving->Back->Front = NULL;
				free(TempSaving);
			}
			return 1;//не найдено
		}
		return 0;
	}
	else
		return -1;
}
void print(struct Line *l)//вывести всё, что есть
{
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->Front;
	}
	printf("\n");
}
void print_inverse(struct Line *l)//вывести всё, что есть
{
	while (l->Front != NULL)
		l = l->Front;
	while (l != NULL)
	{
		printf("%.0lf ", l->Data);
		l = l->Back;
	}
	printf("\n");
}
int main()
{
	struct Line *l, *Temp;
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
		if (i != 2)
			printf(" ");
		else
			printf("\n");
	}
	scanf("%lf", &a);//5 пункт
	push_back(l, a);
	print_inverse(l);//6 пункт
	scanf("%lf", &a);//7 пункт
	push_front(&l, a);
	print(l);//8 пункт
	scanf("%lf", &a);//9 пункт, здесь a--это j, номер в списке
	scanf("%lf", &b);//b--это x, само значение
	struct Node *el = (struct Node *)l;
	while (a != 1)
	{
		el = el->Front;
		a--;
	}
	insert_after(el, b);
	print_inverse(l);//10 пункт
	scanf("%lf", &a);//11, a=u
   	scanf("%lf", &b);//b=y
    	if (a == 1)
    	{
		el= (struct Node *)malloc(sizeof(struct Node));
    		el->Data = b;
   		el->Back = NULL;
    		el->Front = (struct Node *)l;
    		l->Back = (struct Line *)el;
		l=l->Back;
    	}
    	else
    	{
    		el = (struct Node *)l;
    		while (a != 1)
    		{
    			el = el->Front;
    			a--;
    		}
    		insert_before(el, b);
    	}
	print(l);//12 пункт
	scanf("%lf", &a);//13 пункт
	if (l->Data == a)
	{
		Temp = l->Front;
		free(l);
		l = Temp;
		l->Back = NULL;
	}
	else
		remove_first(l, a);
	print_inverse(l);//14 пункт
	scanf("%lf", &a);//15 пункт
	if ((remove_last(l, a) == 0) && (l->Data == a))
	{
		Temp = l->Front;
		free(l);
		l = Temp;
	}
	print(l);//16 пункт
	clean(l);//17 пункт
	return 1;
}
```

### Приложение Б(ссылки на источники)

* [4 практическая работа. Двусвязные списки](https://gitlab.com/tusur_fb_timp/practices/-/wikis/4-практическая-работа.-Двусвязные-списки)
* [Двусвязный линейный список](https://prog-cpp.ru/data-dls/)
* [Реализация двусвязного списка на Си](https://learnc.info/adt/double_linked_list.html)
* [Связный список](http://kvodo.ru/linked-lists.html)
* [Двунаправленные(двусвязные) списки](https://studopedia.su/5_3465_dvunapravlennie-dvusvyaznie-spiski.html)