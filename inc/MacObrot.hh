#ifndef MACOBROT_HH
#define MACOBROT_HH

#include "Macierz.hh"
#include <iostream>
#include <cmath>

#define PI 3.14159265

using namespace std;
/*!
 * \brief implementacja klasy macierzy obrotowej dziedziczacej z szablony macierzy kwadratowej<double,3>
 */
class MacObrot: public MacierzKw<double,3> {
  
protected:
  /*!
   * \brief kat obrotu
   */
  double angle;

public:
  /*!
   * \brief konstruktor bezparametryczny
   */
  MacObrot();
  /*!
   * \brief konstruktor kopiujacy z mackw<double,3> na Macbrot
   * \param M1 macierzkw<double,3>
   */
  MacObrot(const MacierzKw <double,3> & M1): MacierzKw <double,3>(M1) {
    if(abs(M1.wyznacznik() - 1)>=0.0001) {
        cerr << "Nie jest to macierz obrotu!"<<endl;
        exit(1);
    } 
  }
  /*!
   * \brief wykonuje obrot macierzy wokol osi x
   * \param angle kat obrotu
   * \return zwraca obrocona macierz obrotu
   */
  MacObrot M_obrot_X(double angle);
  /*!
   * \brief wykonuje obrot macierzy wokol osi y
   * \param angle kat obrotu
   * \return zwraca obrocona macierz obrotu
   */
  MacObrot M_obrot_Y(double angle);
  /*!
   * \brief wykonuje obrot macierzy wokol osi z
   * \param angle kat obrotu
   * \return zwraca obrocona macierz obrotu
   */
  MacObrot M_obrot_Z(double angle);


};

#endif

  
