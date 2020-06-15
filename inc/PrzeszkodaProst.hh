#ifndef PRZESZKODAPROST_HH
#define PRZESZKODAPROST_HH

#include "Prostopadloscian.hh"
#include "Przeszkoda.hh"
#include "Dron.hh"

class PrzeszkodaProst: public Prostopadloscian, public Przeszkoda {

public:

bool kolizja(const Dron & D) const override {return false;};

void ustaw(string kolor) override {
    color=kolor;
    Wektor3D W[8] = { Wektor3D(-5,-1,-5) , Wektor3D(5,-1,-5) , Wektor3D(5,-1,5) , Wektor3D(-5,-1,5) ,
                        Wektor3D(-5,1,-5) , Wektor3D(5,1,-5) , Wektor3D(5,1,5) , Wektor3D(-5,1,5) };
    w[0]=W[0];
    w[1]=W[1];
    w[2]=W[2];
    w[3]=W[3];
    w[4]=W[4];
    w[5]=W[5];
    w[6]=W[6];
    w[7]=W[7];
    }

};

#endif