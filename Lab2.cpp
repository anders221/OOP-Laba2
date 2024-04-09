#include <iostream>
#include <conio.h>

class Rect {
protected:
    int x, y, dx, dy;
public:
    Rect() : x(0), y(0), dx(5), dy(5) {
        printf("Rect()\n");
    }

    Rect(int x, int y) : x(x), y(x), dx(5), dy(5) {
        printf("Rect(int x, int y)\n");
    }

    Rect(const Rect &r) : x(r.x), y(r.y), dx(5), dy(5) {
        printf("Rect(Const Rect &r)\n");
    }

    ~Rect() {
        printf("%d,%d,%d,%d\n",x,y,x+dx,y+dy);
        printf("~Rect()\n");
    }

    void dbl() {
        dx = dx * 2;
        dy = dy * 2;
    }

    void reset();
};


void Rect::reset() {
    dx = 5;
    dy = 5;
}

class DrawRect: public Rect {
protected:
    int x, y, dx, dy;
public:
    DrawRect() : x(0), y(0), dx(5), dy(5) {
        printf("DrawRect()\n");
    }

    DrawRect(int x, int y) : x(x), y(x), dx(5), dy(5) {
        printf("DrawRect(int x, int y)\n");
    }

    DrawRect(const DrawRect& r) : x(r.x), y(r.y), dx(5), dy(5) {
        printf("Rect(Const Rect &r)\n");
    }
    
    ~DrawRect() {
        printf("%d,%d,%d,%d\n", x, y, x + dx, y + dy);
        printf("~DrawRect()\n");
    }

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
        delete d1;
        delete d2;
        printf("~Line()\n");
    }
};

int main()
{
    {
        Rect r;
        Rect r2(20, 30);
        Rect r3(r2);
    }
    \
    printf("\n");
    Rect* r = new Rect(20, 30);

    delete r;
    printf("\n"); 

    Rect* r1 = new Rect();

    r1->dbl();

    delete r1;

    printf("\n"); 

    Rect* r2 = new Rect(5, 5);

    r2->dbl();
    r2->reset();

    delete r2;

    DrawRect* dr = new DrawRect(10, 10);

    dr->draw();

    delete dr;

    printf("\n"); 

    Rect* r4 = new DrawRect(5,5);
    delete r4;

    printf("\n");

    Line* l1 = new Line(1, 1, 5, 5);

    delete l1;

    _getch();
    return 0;
}
