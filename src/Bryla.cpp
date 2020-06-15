#include "../inc/Bryla.hh"

void Bryla::ruch(const double droga){
        Wektor3D przesuniecie(0,1,0);
        srodek = srodek + (orientacja * (przesuniecie * droga));
    }

void Bryla::obrot(char os , const double kat) {
        MacObrot Mac;
        switch (os)
        {
        case 'X':
            Mac = Mac.M_obrot_X(kat);
            orientacja = orientacja * Mac;
            break;
        case 'Y':
            Mac = Mac.M_obrot_Y(kat);
            orientacja = orientacja * Mac;
            break;
        case 'Z':
            Mac = Mac.M_obrot_Z(kat);
            orientacja = orientacja * Mac;
            break;
        }
    }