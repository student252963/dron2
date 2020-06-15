#include "../inc/Graniastoslup.hh"

void Graniastoslup::ustaw(string kolor) {
  color=kolor;
  Wektor3D W[12] = {Wektor3D(-1,-0.5,0), Wektor3D(-0.5,-0.5,-0.5), Wektor3D(0.5,-0.5,-0.5), Wektor3D(1,-0.5,0), Wektor3D(0.5,-0.5,0.5), Wektor3D(-0.5,-0.5,0.5),
                    Wektor3D(-1,0.5,0), Wektor3D(-0.5,0.5,-0.5), Wektor3D(0.5,0.5,-0.5), Wektor3D(1,0.5,0), Wektor3D(0.5,0.5,0.5), Wektor3D(-0.5,0.5,0.5)};
  for(int i=0 ; i < 12 ; i++) {
  w[i]=W[i];
  }
}

void Graniastoslup::rysuj(const Wektor3D & polozenie , shared_ptr<drawNS::Draw3DAPI> api) {
    scena=api;
    Wektor3D W[12];
    for (int i = 0; i < 12; i++)
    {
      W[i]=polozenie+(orientacja*w[i]);
    }
    erase_scena();
    index=scena->draw_polyhedron(vector<vector<Point3D>>{
      {W[0].Wek2Pt(), W[1].Wek2Pt(), W[2].Wek2Pt(), W[3].Wek2Pt(), W[4].Wek2Pt(), W[5].Wek2Pt()}
      ,
      {W[6].Wek2Pt(), W[7].Wek2Pt(), W[8].Wek2Pt(), W[9].Wek2Pt(), W[10].Wek2Pt(), W[11].Wek2Pt()}
    },color);
    scena->redraw();  
}
/*
void Graniastoslup::wiru_wiru(const Wektor3D & sr, const double kat){
  srodek=sr;
  obrot('Y' , kat);
  //erase_scena();
  rysuj(srodek, scena);
  scena->redraw();
}
*/
