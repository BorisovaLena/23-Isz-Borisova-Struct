
#include <iostream>
#include <malloc.h>
#include <time.h>
#pragma warning(disable : 4996)


struct Dot {
    float x;
    float y;
};

int definition_of_quarter_A(struct Dot dot) //определение четверти (функция принимает структуру)
{
    int number = 0;
    if (dot.x > 0 && dot.y > 0)
    {
        number = 1;
    }
    else if (dot.x > 0 && dot.y < 0)
    {
        number = 4;
    }
    else if (dot.x > 0 && dot.y == 0)
    {
        number = 14;
    }
    else if (dot.x < 0 && dot.y < 0)
    {
        number = 3;
    }
    else if (dot.x < 0 && dot.y>0)
    {
        number = 2;
    }
    else if (dot.x < 0 && dot.y == 0)
    {
        number = 23;
    }
    else if (dot.x == 0 && dot.y > 0)
    {
        number = 12;
    }
    else if (dot.x == 0 && dot.y < 0)
    {
        number = 34;
    }
    else if (dot.x == 0 && dot.y == 0)
    {
        number = 0;
    }

    return number;
}

int definition_of_quarter_B(struct Dot* p_dot) //определение четверти (функция принимает указатель на структуру)
{
    int number = 0;
    if (p_dot->x > 0 && p_dot->y > 0)
    {
        number = 1;
    }
    else if (p_dot->x > 0 && p_dot->y < 0)
    {
        number = 4;
    }
    else if (p_dot->x > 0 && p_dot->y == 0)
    {
        number = 14;
    }
    else if (p_dot->x < 0 && p_dot->y < 0)
    {
        number = 3;
    }
    else if (p_dot->x < 0 && p_dot->y>0)
    {
        number = 2;
    }
    else if (p_dot->x < 0 && p_dot->y == 0)
    {
        number = 23;
    }
    else if (p_dot->x == 0 && p_dot->y > 0)
    {
        number = 12;
    }
    else if (p_dot->x == 0 && p_dot->y < 0)
    {
        number = 34;
    }
    else if (p_dot->x == 0 && p_dot->y == 0)
    {
        number = 0;
    }

    return number;
}

struct student {
    char fam[20];
    int ball[4];
    float srball;
};

void excellent_students(struct student* students, int n) //определение отличников
{
    for (int i = 0; i < n; i++)
    {
        if (students[i].srball == 5)
        {
            printf("%s\n", students[i].fam);
        }
    }
}

void poor_student(struct student* students, int n) //определение двоечников
{
    for (int i = 0; i < n; i++)
    {
        if (students[i].srball == 2)
        {
            printf("%s\n", students[i].fam);
        }
    }
}

float srball_group(struct student* students, int n) //подсчет среднего балла группы
{
    float srb = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += students[i].srball;
    }
    return srb = sum / n;
}

struct trapezoid {
    float a;
    float b;
    float h;
};

float square_Trapeziod(struct trapezoid* tr) //определение площади трапеции
{
    float sq = (tr->a + tr->b) * tr->h / 2;
    return sq;
}

struct Time {
    int hour;
    int min;
};

struct Date {
    int day;
    int month;
    int year;
};

struct Visitor {
    char surname[30];
    char name[30];
    char patronymic[30];
};

struct Record {
    struct Time ttime;
    struct Date ddate;
    struct Visitor visitor;
};

Record* add_record(Date date_visit, Time time_visit, Visitor visitor_visit, int* size, Record* records) //создание новой записи
{
    *size = *size + 1;
    records = (struct Record*)realloc(records, (*size) * sizeof(struct Record));
    records[*size - 1].ddate = date_visit;
    records[*size - 1].ttime = time_visit;
    records[*size - 1].visitor = visitor_visit;
    return records;
}

void print_records(Record record) //вывод журнала
{
    printf("Дата: %02d.%02d.%d\n", record.ddate.day, record.ddate.month, record.ddate.year);
    printf("Время: %d:%02d\n", record.ttime.hour, record.ttime.min);
    printf("Посетитель: %s %s %s\n", record.visitor.surname, record.visitor.name, record.visitor.patronymic);
    printf("\n");
}


int main()
{
    system("chcp 1251>null");

    printf("Задание 1 (a): Написать функцию, которая по координатам точки, определяет номер координатной четверти, в которой находится данная точка. Для хранения данных точки (координат x,y) использовать структуру. Функция должна принимать структуру и возвращать номер четверти.\n");
    struct Dot dot;
    printf("Введите координату x: ");
    scanf_s("%f", &dot.x);
    printf("Введите координату y: ");
    scanf_s("%f", &dot.y);
    int n = definition_of_quarter_A(dot);
    if (n / 10 > 0)
    {
        printf("Точка %-3.1f,%-3.1f находится между %d и %d четвертями\n", dot.x, dot.y, n / 10, n % 10);
    }
    else if (n == 0)
    {
        printf("Точка %-3.1f,%-3.1f находится в начале координат\n", dot.x, dot.y);
    }
    else
    {
        printf("Точка %-3.1f,%-3.1f находится в четверти №%d\n", dot.x, dot.y, n);
    }

    printf("\n");

    printf("Задание 1 (б): Функция должна принимать указатель на структуру и возвращать номер строки.\n");
    struct Dot dot_b;
    printf("Введите координату x: ");
    scanf_s("%f", &dot_b.x);
    printf("Введите координату y: ");
    scanf_s("%f", &dot_b.y);
    struct Dot* p_dot_b = &dot_b;
    int number = definition_of_quarter_B(p_dot_b);
    if (number / 10 > 0)
    {
        printf("Точка %-3.1f,%-3.1f находится между %d и %d четвертями\n", dot_b.x, dot_b.y, number / 10, number % 10);
    }
    else if (number == 0)
    {
        printf("Точка %-3.1f,%-3.1f находится в начале координат\n", dot_b.x, dot_b.y);
    }
    else
    {
        printf("Точка %-3.1f,%-3.1f находится в четверти №%d\n", dot_b.x, dot_b.y, number);
    }

    printf("\n");

    printf("Задание 2: Есть  описание структуры student. Создать массив структур. Написать функции определения фамилий двоечников, отличников. Определить средний балл группы.\n");
    struct student students[] = { {"Ильин",{4,4,4,4}, 4.0}, {"Сергеев", {5,5,5,5}, 5.0}, {"Андреев", {2,2,2,2}, 2.0} };
    int count = sizeof(students) / sizeof(students[0]);
    printf("Отличники:\n");
    excellent_students(students, count);
    printf("Двоечники:\n");
    poor_student(students, count);
    float srb = srball_group(students, count);
    printf("Средний балл группы = %-3.2f\n", srb);

    printf("\n");

    printf("Задание 3: Написать структуру Трапеция, которая должна содержать данные о трапеции (два основания и высоту). Написать функцию, которая будет рассчитывать площадь трапеции.\n");
    struct trapezoid tr;
    printf("Введите длину первого основания трапеции: ");
    scanf_s("%f", &tr.a);
    printf("Введите длину второго основания трапеции: ");
    scanf_s("%f", &tr.b);
    printf("Введите длину высоты трапеции: ");
    scanf_s("%f", &tr.h);
    float square = square_Trapeziod(&tr);
    printf("Площадь трапеции = %-3.3f\n", square);

    printf("\n");

    printf("Задание 4: Описать структуру Date (для хранение даты), структуру Time (для хранения времени), Visitor (фамилия, имя, отчество посетителя). Написать функцию, которая будет добавлять в журнал информацию о посетителях – дата, время и ФИО посетителя.\n");

    Record* records = NULL;
    int size = 0;
    time_t mytime = time(NULL);
    struct tm* now = localtime(&mytime);
    Date date_visit = { now->tm_mday, now->tm_mon + 1, now->tm_year + 1900 };
    Time time_visit = { now->tm_hour, now->tm_min};
    Visitor visitor_visit = { "Чудаков", "Иван", "Иванович" };
    records = add_record(date_visit, time_visit, visitor_visit, &size, records);

    Date date_visit2 = { now->tm_mday, now->tm_mon + 1, now->tm_year + 1900 };
    Time time_visit2 = { now->tm_hour, now->tm_min};
    Visitor visitor_visit2 = { "Боров", "Андрей", "Андреевич" };
    records = add_record(date_visit2, time_visit2, visitor_visit2, &size, records);

    for (int i = 0; i < size; i++) 
    {
        print_records(records[i]);
    }
    free(records);

    return 0;
}


