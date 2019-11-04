#ifndef POLINOME_H
#define POLINOME_H

struct Monome
{
    int power;
    double coef;
    Monome(int power, int coef): power(power), coef(coef) { }
    double calculateAt(double x) const
    {
        double result = coef;
        for (int i = 0; i < power; i++) {
            result *= x;
        }
        return result;
    }
    Monome mult(const Monome& other) const
    {
        return Monome(this->power + other.power, this->coef * other.coef);
    }
};

struct PolinomeElement
{
    Monome m;
    PolinomeElement* next;
};

class Polinome
{
    public:
        Polinome();
        Polinome(const Monome& m);
        Polinome(const Polinome& other);
        Polinome& operator=(const Polinome& other);
        virtual ~Polinome();
        void add(const Monome& m);
        double calculateAt(double x) const;
        Polinome add(const Polinome& other) const;
        Polinome mult(const Monome& other) const;
        Polinome mult(const Polinome& other) const;

    protected:

    private:
        PolinomeElement* first;
};

#endif // POLINOME_H
