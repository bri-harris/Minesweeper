#pragma once
#include <random>

//∃!1 of a static 'thing' shared among all instanciations of the class
    //static variables/functions exist for the lifetime of a program
class Random {
    static std::mt19937 random;
public:
    static int Int(int min, int max);
    static float Float(float min, float max);

};



