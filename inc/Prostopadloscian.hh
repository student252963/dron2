#ifndef PROSTOPADLOSCIAN_HH
#define PROSTOPADLOSCIAN_HH

#include "Bryla.hh"
/*!
 * \brief Implementacja klasy Prostopadloscian  dziedziczacej z bryly
 */
class Prostopadloscian: public Bryla {

protected:
/*!
 * \brief wierzcholki prostopadloscianu
 */
Wektor3D w[8];

public:   
    /*!
     * \brief rysuje prostopadloscian
     * \param polozenie srodek prost na osi
     * \param api api sceny
     * \param kolor kolor drona
     */
    void rysuj(const Wektor3D & polozenie , shared_ptr<drawNS::Draw3DAPI> api) override;
    /*!
     * \brief ustawia wierzcholki prostopadloscianu
     */
    void ustaw(string kolor) override;
};

#endif