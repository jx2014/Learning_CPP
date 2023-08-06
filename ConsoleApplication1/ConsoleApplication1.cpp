// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

/*

class Vector {
private:
    double* elem;
    size_t sz;
public:
    Vector(size_t s) : elem{ new double[s] }, sz(s)
    {
        for (int i = 0; i != s; ++i) elem[i] = 0;
    }
    Vector(initializer_list<double> lst)
        :elem{ new double[lst.size()] }, sz{lst.size()}
    {
        copy(lst.begin(), lst.end(), elem);
    }

    ~Vector() { delete elem; }

    double& operator[](int i);
    int size() const;
};

double& Vector::operator[](int i)
{
    return elem[i];
}

int Vector::size() const
{
    return sz;
}

class Container {
public:
    virtual double& operator[](int) = 0;
    virtual int size() const = 0;
    virtual ~Container() {}
};

class Vector_container : public Container { // Vector_container implements Container
    Vector v;
public:
    Vector_container(int s) : v(s) { } // Vector of s elements
    Vector_container(initializer_list<double> lst) : v(lst) {}
    ~Vector_container() {}
    double& operator[](int i) { return v[i]; }
    int size() const { return v.size(); }
};

void use(Container& c)
{
    const int sz = c.size();
    for (int i = 0; i != sz; ++i)
        cout << c[i] << '\n';
};


void g()
{
    Vector_container vc { 10,9,8,7 };
    use(vc);
}

class Shape {
public:
    virtual Point center() const = 0;
    virtual void move(Point to) = 0;
    virtual void draw() const = 0;
    virtual void rotate(int angle) = 0;

    virtual ~Shape() {}
};

void rotate_all(vector<Shape*>& v, int angle)
{
    for (auto p : v)
        p->rotate(angle);
}

class Circle : public Shape {
public:
    Circle(Point p, int rr);
    Point center() const { return x; }
    void move(Point to) { x = to; }

    void draw() const;
    void rotate(int) {}

private:
    Point x;
    int r;
};

class Smiley : public Circle {
public:
    Smiley(Point p, int r) : Circle{ p, r }, mouth{ nullptr } {}
    ~Smiley()
    {
        delete mouth;
        for (auto p : eyes) delete p;
    }
    void move(Point to);
    void draw() const;
    void rotate(int);

    void add_eye(Shape* s) { eye.push_back(s); }
    void set_mouth(Shape* s);
    virtual void wink(int i);
private:
    vector<Shape*> eyes;
    Shape* mouth;
};

void Smiley::draw()
{
    Circle::draw();
    for (auto p : eyes)
        p->draw();
    mouth->draw();
}

enum class Kind {circle, triangle, smiley};

Shape* read_shape(istream& is)
{

    // ... read shape header from is and find its Kind k...
    switch (k) {
        case Kind::circle:
            // read circle data {Point, int} into p and r
            return new Circle{ p, r };

        case Kind::triangle:
            // read triangle data {Point,Point,Point} into p1, p2, and p3
            return new Triangle{ p1,p2,p3 };

        case Kind::smiley:
            // read smiley data {Point, int, Shape, Shape, Shape} into p, r, e1, e2, and m
            Smiley* ps = new Smiley{ p,r };
            ps->add_eye(e1);
            ps->add_eye(e2);
            ps->set_mouth(m);
            return ps;
    }
}

void user()
{
    std::vector<Shape*> v;
    while (cin)
        v.push_back(read_shape(cin));
    draw_all(v);
    rotate_all(v, 45);
    for (auto p : v) delete p;

}
*/

/* One solution to both problems is to return a standard-library unique_ptr (§5.2.1) rather than a
‘‘naked pointer’’ and store unique_ptrs in the container:
*/

/*
unique_ptr<Shape> read_shape(istream& is) // read shape descriptions from input stream is
{
    // read shape header from is and find its Kind k
    switch (k) {
    case Kind::circle:
        // read circle data {Point,int} into p and r
        return unique_ptr<Shape>{new Circle{ p,r }}; // §5.2.1
        // ...
    }
    void user()
    {
        vector<unique_ptr<Shape>> v;
        while (cin)
            v.push_back(read_shape(cin));
        draw_all(v); // call draw() for each element
        rotate_all(v, 45); //
    }

//§ 3.3 Copy and Move

    // memberwise copy is the right semantics for simply concrete types, but not for sophisticated concrete types and never is for abstract types.
    void test(complex z1) {
        complex z2(z1); // copy initialization
        complex z3;
        z3 = z2;        // copy assignment
    }

    void bad_copy(Vector v1)
    {
        Vector v2 = v1; // copy v1’s representation into v2
        v1[0] = 2; // v2[0] is now also 2!
        v2[1] = 3; // v1[1] is now also 3!
    }

    class Vector {
    private:
        double* elem;
        int sz;
    public:
        Vector(int s);
        ~Vector() { delete[] elem; }

        Vector(const Vector& a);
        Vector& operator=(const Vector& a);

        double& operator[](int i);
        const double& operator[](int i) const;

        int size() const;
    };

    Vector::Vector(const Vector& a) // copy constr uctor
        :elem{ new double[sz] }, // allocate space for elements
        sz{ a.sz }
    {
        for (int i = 0; i != sz; ++i) // copy elements
            elem[i] = a.elem[i];
    }

    Vector& Vector::operator=(const Vector& a) // copy assignment
    {
        double∗ p = new double[a.sz];
        for (int i = 0; i != a.sz; ++i)
            p[i] = a.elem[i];
        delete[] elem; // delete old elements
        elem = p;
        sz = a.sz;
        return ∗this;
    }

//§3.3.2 move instead of copy
    class Vector {
        // ...
        Vector(const Vector& a); // copy constr uctor
        Vector& operator=(const Vector& a); // copy assignment
        Vector(Vector&& a); // move constr uctor
        Vector& operator=(Vector&& a);  // move assignment
    };

    // && means rvalue reference.

    Vector::Vector(Vector&& a)
        :elem{ a.elem }, // "grab the elements" from a
        sz{ a.sz }
    {
        a.elem = nullptr; // now a has no elements
        a.sz = 0;
    }
*/


int main()
{
    std::cout << "Hello World!\n";
    //g();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
