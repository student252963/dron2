#ifndef TAFLA_HH
#define TAFLA_HH

#include "Plaszczyzna.hh"
#include "Przeszkoda.hh"
#include "Dron.hh"
/*!
 * \brief implementacja klasy Tafla dziedziczacej z Plaszczyzny
 */
class Tafla: public Plaszczyzna, public Przeszkoda{

public:
    bool kolizja(const Dron & D) const override {
        double porownanie = (D.zwroc_srodek())[2];
        if(porownanie>poziom) {
        return true;
        } else {
            return false;
            }
    }
    /*!
     * \brief Rysuje i tworzy tafle
     * \param api  api sceny
     * \param z punkt na osi z
     */
    void rysuj(shared_ptr<drawNS::Draw3DAPI> api, const double & z) override;
};

#endif