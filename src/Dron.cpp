#include "../inc/Dron.hh"

    void Dron::ustaw_dron(string kolor) {
        ustaw(kolor);
        Wirnik_L.ustaw(kolor);
        Wirnik_P.ustaw(kolor);
    }

    void Dron::rysuj_drona(const Wektor3D & S , std::shared_ptr<drawNS::Draw3DAPI> api){
        scena=api;
        srodek = S;
        Lew=srodek+(orientacja*Wektor3D(-1.5,-4.5,0));
        Pra=srodek+(orientacja*Wektor3D(1.5,-4.5,0));
        rysuj(srodek , scena);
        Wirnik_L.rysuj(Lew , scena);
        Wirnik_P.rysuj(Pra , scena);
        rysuj(srodek , scena);
        scena->redraw();
    }

    void Dron::animacja_ruch(const double droga , std::shared_ptr<drawNS::Draw3DAPI> api){
        scena=api;
        // for(int i=0 ; i < 100 ; i++){
            ruch(droga);
	        Wirnik_L.obrot('Y',10);
	        Wirnik_P.obrot('Y',-10);
            //Wirnik_L.wiru_wiru(Lew,10);
	        //Wirnik_P.wiru_wiru(Pra,-10);
            //erase_scena();
            rysuj_drona(srodek,scena);
            scena->redraw();
                }
        //}
    

    void Dron::animacja_obrot(char os, const double kat , std::shared_ptr<drawNS::Draw3DAPI> api) {
        scena=api;
        for(int i=0 ; i<100 ; i++) {
            obrot(os , kat/100);
            Wirnik_L.obrot(os , kat/100);
            Wirnik_P.obrot(os , kat/100);
	        //Wirnik_L.obrot('Y',10);
	        //Wirnik_P.obrot('Y',-10);
            //Wirnik_L.wiru_wiru(Lew,10);
            //Wirnik_P.wiru_wiru(Pra,-10);
            erase_scena();
            rysuj_drona(srodek,scena);
            scena->redraw();
        }
    }

    void Dron::animacja_plyn(const double kat, const double droga , std::shared_ptr<drawNS::Draw3DAPI> api) {
        char x = 'X';
        animacja_obrot(x , kat , api);
        animacja_ruch(droga , api);
        animacja_obrot(x , -kat , api);
    }

    bool Dron::kolizja(const Dron & D)const{
        if( srodek == D.zwroc_srodek()) {
            return false;
        } else {
            if((srodek - D.zwroc_srodek()).dlugosc() < promien + D.zwroc_promien()) {
            return true;
            } 
            return false;            
        }
    }
