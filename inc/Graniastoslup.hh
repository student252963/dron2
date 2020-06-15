#ifndef GRANIASTOSLUP_HH
#define GRANIASTOSLUP_HH

#include "Bryla.hh"
/*!
 * \brief Implementacja klasy Graniastoslup  dziedziczacej z bryly
 */
class Graniastoslup: public Bryla {

protected:
/*!
 * \brief wierzcholki graniastoslupa
 */
Wektor3D w[12];

public:
/*!
 * \brief ustawia wierzcholki granistoslupa
 */
void ustaw(string kolor) override;
/*!
 * \brief rysuje graniastoslup
 * \param polozenie srodek grania na osi
 * \param api api sceny
 * \param kolor kolor graniastoslupa
 */
void rysuj(const Wektor3D & polozenie , shared_ptr<drawNS::Draw3DAPI> api) override;
  
  //void wiru_wiru(const Wektor3D & sr, const double kat);
  
};

#endif
