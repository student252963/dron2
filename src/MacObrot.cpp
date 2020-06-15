#include "../inc/MacObrot.hh"
#include "../inc/Wektor3D.hh"

MacObrot::MacObrot() {
    angle = 0;
    for(int i=0 ; i < 3 ; i++) {
        for(int j=0 ; j<3 ; j++){
            if(i==j){ 
                tab[i][j] = 1;
            }
            else {
            tab[i][j] = 0;
            }
        }
    }
}

MacObrot MacObrot::M_obrot_X(double angle) {
    double rad;
    rad = angle * PI / 180;

    tab[0][0]=1;    tab[0][1]=0;           tab[0][2]=0;
    tab[1][0]=0;    tab[1][1]=cos(rad);    tab[1][2]=-sin(rad);
    tab[2][0]=0;    tab[2][1]=sin(rad);    tab[2][2]=cos(rad);

    return *this;
}

MacObrot MacObrot::M_obrot_Y(double angle) {
    double rad;
    rad = angle * PI / 180;

    tab[0][0]=cos(rad);     tab[0][1]=0;    tab[0][2]=sin(rad);
    tab[1][0]=0;            tab[1][1]=1;    tab[1][2]=0;
    tab[2][0]=-sin(rad);    tab[2][1]=0;    tab[2][2]=cos(rad);

    return *this;
}

MacObrot MacObrot::M_obrot_Z(double angle){
    double rad;
    rad = angle * PI / 180;

    tab[0][0]=cos(rad);    tab[0][1]=-sin(rad);    tab[0][2]=0;
    tab[1][0]=sin(rad);    tab[1][1]=cos(rad);     tab[1][2]=0;
    tab[2][0]=0;           tab[2][1]=0;            tab[2][2]=1;

    return *this;
}