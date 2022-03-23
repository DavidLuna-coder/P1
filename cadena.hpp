#ifndef _CADENA_
#define _CADENA_

#include <iostream>
class Cadena
{
private:
    char* s_;
    unsigned tam_;
public:
    explicit Cadena(unsigned t = 0, char c = '\0');
    Cadena(const Cadena& S);
    Cadena(const char* S);
    Cadena(Cadena&& S);
    Cadena substr(int i, unsigned t) const;

    char at (int n) const;
    char& at (int n);
    Cadena& operator = (const Cadena& S);
    Cadena& operator = (const char * S);
    Cadena& operator = (Cadena&& S);

    char operator[](int) const;
    char& operator[](int n);

    Cadena& operator+=(Cadena& C);   
    friend Cadena operator+ (Cadena& S, Cadena& C);
    const char* c_str() const;

    unsigned length() const;
    ~Cadena()
    {
        delete[] s_;
    }
};

Cadena operator+ (Cadena& S, Cadena& C);
bool operator== (const Cadena& S,const Cadena& C);
bool operator < (const Cadena& S, const Cadena & C);
bool operator > (const Cadena& S, const Cadena& C);
bool operator <= (const Cadena& S, const Cadena& C);
bool operator >= (const Cadena& S, const Cadena& C);

std::ostream& operator <<(std::ostream& os, const Cadena& C);
std::istream& operator >>(std::istream& is, Cadena& C);
#endif