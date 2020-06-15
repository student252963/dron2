#ifndef WEKTOR3D_HH
#define WEKTOR3D_HH 

#include "Dr3D_gnuplot_api.hh"
#include "Wektor.hh"
#include <iostream>

/*!
 * \brief implementacja klasy Wektor3D dziedziczacej z szablonu Wektor<double,3>
 */
class Wektor3D: public Wektor<double,3> {
/*!
 * \brief istniejace wektory 
 */
inline static int istniejace;
/*!
 * \brief stworzone wektory 
 */
inline static int stworzone;
public:
    /*!
     * \brief konstruktor bezparametryczny z wektora<double,3>
     * zwieksza wartosc istniejacych i stworzonych wektorow
     */
    Wektor3D(): Wektor<double,3>() {++istniejace; ++stworzone;};
    /*!
     * \brief konstruktor parametryczny wektora3d z 3 liczb typu double
     * zwieksza wartosc istniejacych i stworzonych wektorow
     * \param X wspolzedna na osi x
     * \param Y na osi y
     * \param Z na osi z
     */
    Wektor3D(double X, double Y, double Z) {
        tab[0]=X;
        tab[1]=Y;
        tab[2]=Z;
        ++istniejace;
        ++stworzone;
    }
    /*!
    * \brief destruktor bezparametryczny wektora3d , zmniejsza wartosc istniejacych wektorow
    */
    ~Wektor3D() {--istniejace;}
    /*!
     * \brief operator przypisania wektora3d do wektora3d
     * \param W2 wektor3d
     * \return wektor3d po przerpisaniu z innego wketora3d
     */
    Wektor3D & operator = (Wektor3D W2) {
        for(int i = 0 ; i < 3 ; i++){ 
            tab[i]=W2[i];
        }
        return *this;
    }
    /*!
     * \brief operator przypisania wektora<double,3> do wektora3d
     * \param W2 wektor<double,3>
     * \return wektor3d po przerpisaniu z wektora<double,3>
     */
    Wektor3D & operator = (Wektor<double,3> W2) { 
        for(int i = 0 ; i < 3 ; ++i){ 
            tab[i]=W2[i];
        }
        return *this;
    }
    /*!
     * \brief Konwertuje Wektor3D na Point3D
     * \return Point3D z danymi z Wektor3D
     */
    drawNS::Point3D Wek2Pt() {
        return drawNS::Point3D(tab[0] , tab[1] , tab[2]);
    }
    /*!
     * \brief Funkcja zwracajaca informacje o istniejacych wektorach3d
     * \return int istniejacych wektorow
     */
    static int zwroc_istniejace() {return istniejace;};
    /*!
     * \brief Funkcja zwracajaca informacje o stworzonych wektorach3d
     * \return int stworzonych wektorow
     */
    static int zwroc_stworzone() {return stworzone;};
    /*!
     * \brief 
     */
    /*
    double  dlugosc() {

    } */




};

#endif