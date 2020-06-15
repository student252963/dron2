#ifndef PLASZCZYZNA_HH
#define PLASZCZYZNA_HH

#include "ObiektRysowalny.hh"



class Plaszczyzna: public ObiektRysowalny{

protected:

double poziom;

public:
    
    virtual void rysuj(shared_ptr<drawNS::Draw3DAPI> api , const double & z)=0;

};

#endif