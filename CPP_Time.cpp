#include <time.h>
#include <string.h>
#include <malloc.h>
#include <math.h>
#include <windows.h>
#include <iostream>

using namespace std;

char* getLocalTime(struct tm* u)
{
	char s[40];
	char* tmp;
	for (int i = 0; i < 40; i++) s[i] = 0;
	int length = strftime(s, 40, "%d.%m.%Y %H:%M:%S ", u);
	switch (u->tm_wday)
	{
	case 0: strcpy_s(s + length, _countof(s) + length, " воскресенье"); break;
	case 1: strcpy_s(s + length, _countof(s) + length, " понедельник"); break;
	case 2: strcpy_s(s + length, _countof(s) + length, " вторник"); break;
	case 3: strcpy_s(s + length, _countof(s) + length, " среда"); break;
	case 4: strcpy_s(s + length, _countof(s) + length, " четверг"); break;
	case 5: strcpy_s(s + length, _countof(s) + length, " пятница"); break;
	case 6: strcpy_s(s + length, _countof(s) + length, " суббота"); break;
	}
	tmp = (char*)malloc(sizeof(s));
	strcpy_s(tmp, strlen(tmp) + length, s);
	return tmp;
}


void delay(int ms) // аргумент - требуемое время задержки в миллисекундах
{
	int c = clock() + ms;
	while (clock() < c);
	//Sleep(1);
}

int primes(int number) // функция поиска простых чисел
{
	int quantity = number - 1;
	for (int i = 2; i <= number; ++i)
	{
		for (int j = sqrt((float)i); j > 1; --j)
		{
			if (i % j == 0)
			{
				--quantity;
				break;
			}
		}
	}
	return quantity;
}

void example1()
{
	const time_t curMoment = time(NULL);
	struct tm* curTime = NULL;
	char* timeStringValue = NULL;

	localtime_s(curTime, &curMoment);
	timeStringValue = getLocalTime(curTime);

	cout << curMoment << " соответствует " << timeStringValue;
}

void example2()
{
	printf("clock = %d\n", clock());
	delay(1000);
	printf("clock = %d\n", clock());
	Sleep(1000);
	printf("clock = %d\n", clock());
}

void example3()
{
	cout << "Вычисление начато ..." << endl;
	int primesNumber = primes(2000000); // ищем количество простых чисел в интервале от 2 до 2 000 000
	int t = clock(); // получаем количество тиков времени
	cout << "Количество простых чисел меньших 2 000 000 = " << primesNumber << endl;
	cout << "Для вычисления понадобилось " << t << " тиков времени или " << ((float)t) / CLOCKS_PER_SEC << " секунд\n";
}

void example4()
{
	time_t start, end;
	char name[80];
	time(&start); // начальное время
	cout << "Пожалуйста, введите своё имя: ";
	cin.getline(name, 80); // считать имя в name
	time(&end); // конечное время
	cout << "Здравствуйте, " << name << endl;
	cout << "Вам понадобилось " << difftime(end, start) << " секунд для ввода своего имени\n";
}

int main()
{
	example1();
	//example2();
	//example3();
	//example4();

	return 0;
}