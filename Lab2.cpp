// Lab2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <conio.h>

//Создание квадрата
class Rect {
protected:
    //Аттрибуты
    int x, y, dx, dy;
public:
    //Конструктор Rect()
    Rect() : x(0), y(0), dx(5), dy(5) {
        printf("Rect()\n");
    }
    //Конструктор Rect(int x, int y)
    Rect(int x, int y) : x(x), y(x), dx(5), dy(5) {
        printf("Rect(int x, int y)\n");
    }
    //Конструктор Rect(Const Rect &r)
    Rect(const Rect &r) : x(r.x), y(r.y), dx(5), dy(5) {
        printf("Rect(Const Rect &r)\n");
    }
    //Деструктор
    ~Rect() {
        printf("%d,%d,%d,%d\n",x,y,x+dx,y+dy);
        printf("~Rect()\n");
    }
    //Метод удваивающий длины сторон прямоугольника
    void dbl() {
        dx = dx * 2;
        dy = dy * 2;
    }
    //Метод возвращающий изначальные значения длин сторон
    void reset();
};


void Rect::reset() {
    dx = 5;
    dy = 5;
}

//Создание квадрата и дальнейшая его вырисовка
class DrawRect: public Rect {
protected:
    //Аттрибуты
    int x, y, dx, dy;
public:
    //Конструктор Rect()
    DrawRect() : x(0), y(0), dx(5), dy(5) {
        printf("DrawRect()\n");
    }
    //Конструктор Rect(int x, int y)
    DrawRect(int x, int y) : x(x), y(x), dx(5), dy(5) {
        printf("DrawRect(int x, int y)\n");
    }
    //Конструктор Rect(Const Rect &r)
    DrawRect(const DrawRect& r) : x(r.x), y(r.y), dx(5), dy(5) {
        printf("Rect(Const Rect &r)\n");
    }
    //Деструктор
    ~DrawRect() {
        printf("%d,%d,%d,%d\n", x, y, x + dx, y + dy);
        printf("~DrawRect()\n");
    }
    //Метод Выполняющий вырисовку куба с помощью символа "0"
    void draw() {
        printf("\n");
        for (int i = 0; i <= dx; i += 1) {
            printf("0");
        }
        printf("\n");
        for (int i = 0; i <= dy-2; i += 1) {
            printf("0");
            for (int i = 0; i <= dx-2; i += 1) {
                printf(" ");
            }
            printf("0\n");
        }
        for (int i = 0; i <= dx; i += 1) {
            printf("0");
        }
        printf("\n\n");
    }
};

class Dot {
public:
    int x, y;
    Dot() : x(0), y(0) {
        printf("Dot()\n");
    }
    Dot(int x, int y) : x(x), y(y) {
        printf("Dot(int x, int y)\n");
    }
    Dot(const Dot& d) : x(d.x), y(d.y) {
        printf("Dot(const Dot &d)\n");
    }
    ~Dot() {
        printf("%d,%d\n", x, y);
        printf("~Dot()\n");
    }
};

class Line {
public:
    Dot* d1;
    Dot* d2;
    Line() {
        printf("Line()\n");
        d1 = new Dot;
        d2 = new Dot;
    }
    Line(int x1, int y1, int x2, int y2) {
        printf("Line(int x1, int y1, int x2, int y2)\n");
        d1 = new Dot(x1, y1);
        d2 = new Dot(x2, y2);
    }
    Line(const Line& l) {
        printf("Line(const Line &l)\n");
        d1 = new Dot(*(l.d1));
        d2 = new Dot(*(l.d2));
    }
    ~Line() {
        //printf("%d,%d\n", x, y);
        delete d1;
        delete d2;
        printf("~Line()\n");
    }
};

int main()
{
    //Создание статических объектов
    {
        Rect r;
        Rect r2(20, 30);
        Rect r3(r2);
    }
    //Создание динамического объекта
    printf("\n"); //Пробел для лучшей читаемости консоли
    Rect* r = new Rect(20, 30);

    delete r;
    printf("\n"); //Пробел для лучшей читаемости консоли

    Rect* r1 = new Rect();

    //Использование метода
    r1->dbl();

    delete r1;

    printf("\n"); //Пробел для лучшей читаемости консоли

    Rect* r2 = new Rect(5, 5);

    //Использование метода
    r2->dbl();
    r2->reset();

    delete r2;

    //Использование метода-наследника
    DrawRect* dr = new DrawRect(10, 10);

    dr->draw();
    dr->dbl();
    dr->draw();

    delete dr;

    printf("\n"); //Пробел для лучшей читаемости консоли

    //Создание объекта, обращаясь к объекту-наследнику
    Rect* r4 = new DrawRect(5,5);
    delete r4;

    printf("\n"); //Пробел для лучшей читаемости консоли

    Line* l1 = new Line(1, 1, 5, 5);

    delete l1;

    _getch();
    return 0;
}