#ifndef DNO_HH
#define DNO_HH

#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"
#include "Dron.hh"

/*!
 * \brief implementacja klasy Dno dziedziczacej z Plaszczyzny
 */
class Dno: public Plaszczyzna, public Przeszkoda{

public:
    bool kolizja(const Dron & D) const override{
        double porownanie = (D.zwroc_srodek())[2];
        if(porownanie<poziom+D.zwroc_promien()) {
        return true;
        } else {
            return false;
            }
    }
    /*!
     * \brief Rysuje i tworzy dno
     * \param api  api sceny
     * \param z punkt na osi z
     */
    void rysuj(shared_ptr<drawNS::Draw3DAPI> api, const double & z) override;
};

#endif