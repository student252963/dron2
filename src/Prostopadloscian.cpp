#include "../inc/Prostopadloscian.hh"

void Prostopadloscian::rysuj(const Wektor3D & polozenie , shared_ptr<drawNS::Draw3DAPI> api){
        srodek=polozenie;
        scena=api;
        Wektor3D W[8];
        for(int i=0 ; i<8 ; i++){
            W[i]=srodek+(orientacja*w[i]);
        }
        erase_scena();
        index=scena->draw_polyhedron(vector<vector<Point3D>> {
            {W[0].Wek2Pt() , W[1].Wek2Pt() , W[2].Wek2Pt() , W[3].Wek2Pt()}
            ,
	        {W[4].Wek2Pt() , W[5].Wek2Pt() , W[6].Wek2Pt() , W[7].Wek2Pt()}
        },color);
        scena->redraw();
    }

void Prostopadloscian::ustaw(string kolor){
    color=kolor;
    Wektor3D W[8] = { Wektor3D(-2.5,-4,-1) , Wektor3D(2.5,-4,-1) , Wektor3D(2.5,-4,1) , Wektor3D(-2.5,-4,1) ,
                        Wektor3D(-2.5,4,-1) , Wektor3D(2.5,4,-1) , Wektor3D(2.5,4,1) , Wektor3D(-2.5,4,1) };
    w[0]=W[0];
    w[1]=W[1];
    w[2]=W[2];
    w[3]=W[3];
    w[4]=W[4];
    w[5]=W[5];
    w[6]=W[6];
    w[7]=W[7];
    }