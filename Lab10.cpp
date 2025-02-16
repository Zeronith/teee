#include <iostream>
#include <string.h>
#include <math.h>
#define PI 3.14159265359
using namespace std;
class Shape
{
private:
protected:
    char *name;

public:
    void set_name(char *name);
    char *get_name() { return name; }
    void setter();
    Shape(char a[]);
    Shape();
    ~Shape();
};
Shape ::Shape()
{
    name = new char[strlen("Undefined") + 1];
    strcpy(name, "Undefined");
}
Shape ::Shape(char a[])
{
    name = new char[strlen(a) + 1];
    strcpy(name, a);
}
Shape ::~Shape()
{
    delete[] name;
}
void Shape ::setter()
{
    char str[100];
    cin >> str;
    set_name(str);
}
void Shape ::set_name(char *name)
{
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}
class TwoDShape : public Shape
{
protected:
public:
    int *x;
    int *y;
    float area;
    float perimeter;
    TwoDShape();
    TwoDShape(char a[], int pe, int ar);
    void calculate_a();
    void calculate_p();
    void setter();
    void copy(TwoDShape *obj);
};
TwoDShape ::TwoDShape()
{
    char a[10] = "Undefined";
    set_name(a);
    area = 0;
    perimeter = 0;
}
TwoDShape ::TwoDShape(char a[], int pe, int ar) : Shape(a)
{
    perimeter = pe;
    area = ar;
}
class Circle : public TwoDShape
{
protected:
    int radius;

public:
    Circle()
    {
        area = 0;
        perimeter = 0;
        char a[10] = "Undefined";
        set_name(a);
        x = new int[1];
        y = new int[1];
        radius = 0;
    }
    Circle(char name[], int pe, int ar, int xcord, int ycord, int rad) : TwoDShape(name, pe, ar)
    {
        x = new int[1];
        y = new int[1];
        this->x[0] = xcord;
        this->y[0] = ycord;
        radius = rad;
    }
    void setter();
    void calculate_a()
    {
        area = PI * (radius * radius);
    }
    void calculate_p()
    {
        perimeter = PI * radius * 2;
    }
};
void Circle ::setter()
{
    cout << "Toirgiin hemjeeg oruulna uu " << endl;
    cout << "Please enter xcord" << endl;
    cin >> x[0];
    cout << "Please enter ycord" << endl;
    cin >> y[0];
    cout << "Please enter radius" << endl;
    cin >> radius;
    cout << "Please enter the shape of name" << endl;
    char str[100];
    cin >> str;
    set_name(str);
    calculate_a();
    calculate_p();
}
class Square : public TwoDShape
{
protected:
    int s_len;

public:
    Square()
    {
        char a[10] = "Undefined";
        set_name(a);
        area = 0;
        perimeter = 0;
        x = new int[4];
        y = new int[4];
        x[0] = 0;
        y[0] = 0;
        s_len = 0;
    }
    Square(char name[], int ar, int pe, int zdx, int zdy, int slen) : TwoDShape(name, ar, pe)
    {
        x = new int[4];
        y = new int[4];
        this->x[0] = zdx;
        this->y[0] = zdy;
        this->s_len = slen;
    }
    void setter();
    void s_calculate(int &side);
    void calculate_a()
    {
        area = s_len * s_len;
    }
    void calculate_p()
    {
        perimeter = 4 * s_len;
    }
};
void Square ::setter()
{
    cout << "Kvadratiin hemjeeg oruulna uu " << endl;
    cout << "Zuun deed x-iin coordinatiig oruulna uu" << endl;
    cin >> x[0];
    cout << "Zuun deed y-iin coordinatiig oruulna uu" << endl;
    cin >> y[0];
    cout << "Taliin urtiig oruulna uu " << endl;
    cin >> s_len;
    cout << "Dursiin neriig oruulna uu" << endl;
    char str[100];
    cin >> str;
    set_name(str);
    s_calculate(s_len);
    calculate_a();
    calculate_p();
}
void Square ::s_calculate(int &side)
{
    x[1] = x[0] + side;
    y[1] = y[0];
    x[2] = x[0];
    y[2] = y[0] - side;
    x[3] = x[1];
    y[3] = y[1] - side;
    cout << "Baruun deed x ba y coordinate" << endl;
    cout << x[0] << " " << y[0] << endl;
    cout << "Zuun deed x ba y coordinate" << endl;
    cout << x[1] << " " << y[1] << endl;
    cout << "Baruun dood x ba y coordinate" << endl;
    cout << x[2] << " " << y[2] << endl;
    cout << "Zuun dood x ba y coordinate" << endl;
    cout << x[3] << " " << y[3] << endl;
}

class Triangle : public TwoDShape
{
protected:
    int s_len, d_oroi_x, d_oroi_y;
    int z_oroi_x, z_oroi_y, b_oroi_x, b_oroi_y;

public:
    Triangle();
    Triangle(char name[], int ar, int per, int s_len, int d_oroi_x, int d_oroi_y);
    void setter();
    void s_calculate();
    float h_calculate();
    void calculate_a()
    {
        area = h_calculate() * s_len / 2;
    }
    void calculate_p()
    {
        perimeter = s_len * 3;
    }
};
Triangle ::Triangle()
{
    char a[10] = "Undefined";
    set_name(a);
    area = 0;
    perimeter = 0;
    s_len = 0;
    x = new int[3];
    y = new int[3];
    x[0] = 0;
    y[0] = 0;
}
Triangle::Triangle(char name[], int ar, int pe, int s_len, int d_oroi_x, int d_oroi_y) : TwoDShape(name, ar, pe)
{
    this->set_name(name);
    x = new int[3];
    y = new int[3];
    this->s_len = s_len;
    this->area = ar;
    this->perimeter = pe;
    this->x[0] = 0;
    this->y[0] = 0;
}
void Triangle ::setter()
{
    cout << "Gurvaljingiin hemjeeg oruulna uu" << endl;
    cout << "Taliin urtiig oruul" << endl;
    cin >> s_len;
    cout << "Deed oroin x-iig oruul" << endl;
    cin >> x[0];
    cout << "Deed oroin y-iig oruul" << endl;
    cin >> y[0];
    cout << "Dursiin neree oruulna uu" << endl;
    char str[100];
    cin >> str;
    set_name(str);
    s_calculate();
    calculate_a();
    calculate_p();
}
float Triangle ::h_calculate()
{
    return (sqrt(3) / 2) * s_len;
}
void Triangle ::s_calculate()
{
    float height = h_calculate();
    x[1] = x[0] - s_len / 2;
    y[1] = y[0] - height;
    x[2] = x[0] + s_len / 2;
    y[2] = y[0] - height;
    cout << "zuun dood oroi x ba y coordination" << endl;
    cout << x[1] << " " << y[1] << endl;
    cout << "baruun dood oroi x ba y coordination" << endl;
    cout << x[2] << " " << y[2] << endl;
}
void TwoDShape ::copy(TwoDShape *obj)
{
    delete[] this->name;
    name = new char[strlen(obj->name) + 1];
    strcpy(this->name, obj->name);
    this->area = obj->area;
    this->perimeter = obj->perimeter;
}
template <class T>
class Linked_List
{
private:
    T val;
    Linked_List *next;
public:
    void add(T temp)
    (

        while()
    )
};

int main()
{
    system("cls");
    Linked_List <TwoDShape *> shape;x
    
}