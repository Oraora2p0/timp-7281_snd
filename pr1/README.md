### Министерство науки и высшего образования Российской Федерации

### ТОМСКИЙ ГОСУДАРСТВЕННЫЙ УНИВЕРСИТЕТ СИСТЕМ УПРАВЛЕНИЯ И РАДИОЭЛЕКТРОНИКИ (ТУСУР)

### Кафедра комплексной информационной безопасности электронно-вычислительных систем (КИБЭВС)

### Отчёт по практической работе №1 по дисциплине "Технологии и методы программирования"

Выполнил студент группы 728-1

________Солопов Никита

_____04.2020

Принял

Преподаватель кафедры КИБЭВС

________Перминов П.В.

_____04.2020

Томск 2019

### Введение

Цель работы: целью работы является освоение навыков работы с системой контроля версий gitlab, операционной  системой Ubuntu, а также получение новых знаний по splint и рефакторингу. Также необходимым является написание следующих программ:

* Написать программу, печатающую в stdout фразу "Hello, World!" на отдельной строке.
* Написать программу, принимающую на вход два числа, разделённые пробелом, и суммирующую их.
* Написать программу, принимающую на вход числа x и y, разделённые пробелом, и вычисляющую x в степени y.

### 1 Теоретическая часть

В ОС Ubuntu файловая структура связана в логическое дерево. Путь каждого файла или каталога начинается с корня, который обозначается обратным слэшем «/» (/ – корневой каталог).

Непосредственно работу с системой можно проводить с помощью терминала. Для этого можно либо найти его в меню приложений, либо нажав Ctrl+Alt+T. 

В терминале можно использовать различные команды. Так, в ходе лабораторной использовались команды `cd` для перемещения между каталогами, `mv` для перемещения файлов программ, `rm` для их удаления. Кроме того были использованы более узкоспециализированные команды, например, `clone` для клонирования репозитория, `splint ` для рефакторинга и `gcc` для компиляции кода на языке С.

Система контроля версий--система, позволяющая пользователю упростить работу с проектом. Суть в том, что она включает возможность оставлять предыдущие версии и в случае критичных ошибок переходить к ним. В git, например и подобных системах хранятся только изменения между отдельными решениями. Существует несколько типов СКВ: локальные, централизованные и распределённые(git).

Рассмотрим все три типа в приведённой ниже таблице:

Таблица 2.1--Сравнение систем контроля версий

| Название         | Плюсы                              | Минусы                           |
| ---------------- | ---------------------------------- | -------------------------------- |
| Локальные        | Простота, распространённость       | Большая вероятность ошибок       |
| Централизованные | Проще администрировать, понятность | Единая точка отказа              |
| Распределённые   | Удалённая работа, иерархия моделей | Отсутствуют                      |

В частности git имеет достаточно широкие возможности:

* Управление репозиториями
* База данных
* Возможность отслеживания ошибок
* Возможность разграничения доступа

В рамках практической работы был использован splint--Secure Programming List. Встроенный компилятор Си далеко не идеален, поэтому желательно использовать данный инструмент при проверке кода на наличие ошибок. Это поможет написать более безопасный и правильный код. Но нужно добавить, что даже при успешной компиляции нет никакой гарантии, что программа выполнится корректно.

### 2 Ход работы

В процессе работы были проделаны следующие действия:

Установлена с помощью виртуальной машины операционная система Ubuntu. Были попытки установить систему в качестве второй(оптимальный вариант), но были выявлены ошибки, не позволяющие этого сделать.

![](/pr1/images/1.png "1")

Рисунок 2.1--Рабочий стол Ubuntu

После этого было обновлено и установлено новое ПО. Также использовалась команда `sudo apt-get install git splint build-essential -y`.

![](/pr1/images/2.png "2")

Рисунок 2.2--Терминал и установка ПО

Была выполнена проверка корректности установленных программ.

![](/pr1/images/3.png "3")

Рисунок 2.3--Проведение проверок

Очевидно, что для дальнейшей работы потребуется  форкнуть и клонировать репозиторий к себе на компьютер. Форк--процесс, состоящий из двух шагов. Первое, нужно нажать кнопку Fork в домашнем каталоге.  Второе--щёлкнуть пространство имён, чтобы разветвить его. 

![](/pr1/images/4.png "4")

Рисунок 2.4--Форк уже существующего репозитория

Для клонирования в свою очередь необходимо использовать команду `git clone <adress>`, где на месте `<adress>` указывается адрес уже существующего репозитория.

Далее были написаны необходимые по условию программы и отрефакторены по splint. Ниже показано их прохождение--отсутствие ошибок и предупреждений, а также непосредственно работа программ.

![](/pr1/images/5.png "5")

Рисунок 2.5--Рефакторинг по splint

![](/pr1/images/6.png "6")

Рисунок 2.6--Работа программы(1)

![](/pr1/images/7.png "7")

Рисунок 2.7--Работа программы(2)

![](/pr1/images/8.png "8")

Рисунок 2.8--Работа программы(3)

Ниже, в приложении А предоставлены коды программ.

В приложении Б можно увидеть ссылки на материалы по git, использовавшиеся в рамках работы.

### 4 Заключение

В результате работы были освоены навыков использования системы контроля версий gitlab, операционной  системы Ubuntu, а также получены новые знания по splint и рефакторингу. Были написаны программы из задания и составлен отчёт с использованием разметки Markdown.

### Приложение А(коды программ)

##### Первая программа

```с
#include 
<stdio.h>
int main()
{
    printf("Hello, World!\n"); 
    return 1;
}
```

##### Вторая программа

```с
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
```

##### Третья программа

```с
#include <stdio.h>
#include <math.h>
int main()
{
	char a[40];
	int i = -1, j, numb = 1, pnt = 0, pw;
	double num1 = 0, num2 = 0, dec;
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
			num2 = num2 + numb * ((double)(a[i] - '0') / (double)dec);
			pnt++;
		}
	}
	dec=pow(num1, num2);
	printf("%.8f", (double)dec);
	return 1;
}
```

### Приложение Б(ссылки на источники)

* [Информация по первой практической работе](https://gitlab.com/tusur_fb_timp/practices/-/wikis/1-практическая-работа)
* [Что такое Markdown и как им пользоваться?](https://lifehacker.ru/chto-takoe-markdown/)
* [Шпаргалка по синтаксису Markdown](http://ilfire.ru/kompyutery/shpargalka-po-sintaksisu-markdown-markdaun-so-vsemi-samymi-populyarnymi-tegami/#link14)
* [Команды Git](https://git-scm.com/book/ru/v2/Appendix-C%3A-Команды-Git-Клонирование-и-создание-репозиториев)
* [Основные команды Linux](https://pontin.ru/technical/linux/sudo-ubuntu)
* [О системе контроля версий](https://git-scm.com/book/ru/v2/Введение-О-системе-контроля-версий)