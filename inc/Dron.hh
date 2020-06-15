#ifndef DRON_HH
#define DRON_HH

#include "Prostopadloscian.hh"
#include "Graniastoslup.hh"
#include "Przeszkoda.hh"

/*!
 * \brief Implementacja klasy Droon  dziedziczacej z prostopadl.
 */
class Dron: public Prostopadloscian, public Przeszkoda{

protected:
/*!
 * \brief pozycja lewego wirnika
 */
Wektor3D Lew;
/*!
 * \brief pozycja prawego wirnika
 */
Wektor3D Pra;
/*!
 * \brief Lewy wirnik
 */
Graniastoslup Wirnik_L;
/*!
 * \brief Prawy wirnik
 */
Graniastoslup Wirnik_P;
/*!
 * \brief promien drona
 * dron jest kulą przy sprawdzaniu kolizji dronow
 */
double promien=5.6; 

public:
    /*!
     * \brief ustawia wierzcholki drona
     */
    void ustaw_dron(string kolor);
    /*!
     * \brief rysuje drona
     * \param S srodek prostopadloscianu drona
     * \param api api sceny
     */
    void rysuj_drona(const Wektor3D & S , std::shared_ptr<drawNS::Draw3DAPI> api);
    /*!
     * \brief animuje ruch drona
     * \param droga droga 
     * \param api api sceny
     */
    void animacja_ruch(const double droga , std::shared_ptr<drawNS::Draw3DAPI> api);
    /*!
     * \brief animuje obrot
     * \param os  os obrotu
     * \param kat kat obrotu
     * \param api api sceny
     */
    void animacja_obrot(char os, const double kat , std::shared_ptr<drawNS::Draw3DAPI> api);
    /*!
     * \brief animuje plywanie ze wznoszeniem/opadaniem
     * \param kat kat obrotu
     * \param droga droga jak przeplynie
     */
    void animacja_plyn(const double kat, const double droga , std::shared_ptr<drawNS::Draw3DAPI> api);
    /*!
     * \brief funkcja pobierajaca promien drona
     * \return double promien drona
     */ 
    double zwroc_promien() const {return promien;}
    /*!
     * \brief funkcja pobierajaca srodek drona
     * \return Wektor3D srodek drona
     */
    Wektor3D zwroc_srodek() const {return srodek;}
    
    bool kolizja(const Dron & D) const;

    
};

#endif