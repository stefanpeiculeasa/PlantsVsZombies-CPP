#ifndef STAT_H
#define STAT_H

template<typename T>
class Stat {
    T stat;
public:
    Stat() = default;

    Stat(const T x) : stat(x) {}

    T get() const {return stat;}

    void set(const T x) {stat = x;}

    void modify(const T delta) {stat += delta;}
};

#endif