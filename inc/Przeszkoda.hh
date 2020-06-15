#ifndef PRZESZKODA_HH
#define PRZESZKODA_HH

class Dron;

class Przeszkoda{

public:

virtual bool kolizja(const Dron & D) const =0;

};

#endif