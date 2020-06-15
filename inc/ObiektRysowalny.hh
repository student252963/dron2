#ifndef OBIEKTRYSOWALNY_HH
#define OBIEKTRYSOWALNY_HH

#include "Dr3D_gnuplot_api.hh"
#include "Wektor3D.hh"
#include "MacObrot.hh"

using namespace std;
using drawNS::Point3D;
using drawNS::APIGnuPlot3D;


/*!
 * \brief implementacja klasy ObiektRysowalny
 */
class ObiektRysowalny {

protected:
/*!
 * \brief ilosc istniejacych bryl
 */
inline static int istniejace;
/*!
 * \brief ilosc stworzonych bryl
 */
inline static int stworzone;
/*!
 * indeks sceny
 */
int index;
/*!
 * wskaznik sceny
 */
shared_ptr<drawNS::Draw3DAPI> scena;

public:
/*!
 * \brief Konstuktor bezparametryczny obiektu rysowalnego
 */
ObiektRysowalny() {++istniejace; ++stworzone;};
 /*!
  * \brief zmazuje obiekt
  */
~ObiektRysowalny() {--istniejace;}
static int zwroc_istniejace() {return istniejace;}
static int zwroc_stworzone() { return stworzone;}
void erase_scena() {
    scena->erase_shape(index);
}

};

#endif