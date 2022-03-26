#ifndef _CADENA_
#define _CADENA_

#include <iostream>
#include <iterator>
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

    //Iteradores
    typedef char* iterator ;
    typedef const char* const_iterator;
    typedef std::reverse_iterator<iterator> reverse_iterator;
    typedef std::reverse_iterator<const_iterator> const_reverse_iterator;
    iterator begin();
    const_iterator begin() const;
    iterator end();
    const_iterator end() const;
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    const_reverse_iterator rbegin() const;
    reverse_iterator rend();
    const_reverse_iterator rend() const;
    const_reverse_iterator crbegin() const;
    const_reverse_iterator crend() const;
    
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