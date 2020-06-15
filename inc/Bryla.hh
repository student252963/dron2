#ifndef BRYLA_HH
#define BRYLA_HH

#include "ObiektRysowalny.hh"
/*!
 * \brief implementacja klasy Bryla dziedziczacej z obiektu rysowalnego
 */
class Bryla: public ObiektRysowalny {
    
protected:
/*!
 * \brief srodek bryly jako wektor3d
 */
Wektor3D srodek;
/*!
 * \brief orientacja bryly
 */
MacObrot orientacja;
/*!
 * \brief kolor bryly
 */
string color;


public:
    /*!
     * \brief rysuje bryle
     * \param polozenie umiejscowienie swodka bryly na osi
     * \param api  api sceny
     * \param kolor kolor bryly
     */
    virtual void rysuj(const Wektor3D & polozenie , shared_ptr<drawNS::Draw3DAPI> api)=0;
    /*!
     * \brief ustawia wierzcholki bryly
     */
    virtual void ustaw(string kolor)=0;
    /*!
     * \brief bryla wykonuje ruch
     * \param droga odleglosc jaka przebedzie bryla
     */
    void ruch(const double droga);
    /*!
     * \brief obrot bryly
     * \param os os wokol ktorej bedzie sie obracac
     * \param kat kat obrotu
     */
    void obrot(char os , const double kat);

};

#endif