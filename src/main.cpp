#include <iostream>
#include "../inc/Dron.hh"
#include "../inc/Tafla.hh"
#include "../inc/Dno.hh"
#include "../inc/PrzeszkodaProst.hh"

void wait4key() {
  do {
    std::cout << "\n Press a key to continue..." << std::endl;
  } while(std::cin.get() != '\n');
}

int main() {

  std::shared_ptr<drawNS::Draw3DAPI> api(new APIGnuPlot3D(-50,50,-50,50,-35,35,-1)); 

  Wektor3D S1(20,0,0), S2(-20,20,0), S3(0,-20,-20), //Drony
           S4(10,0,0), S5(0,-10,-20), S6(-20,10,-10); //Przeszkody

  vector<shared_ptr<Dron>> drony;
  vector<shared_ptr<Przeszkoda>> przeszkody;
  
  shared_ptr<Tafla> T;
  T=make_shared<Tafla>();
  T -> rysuj(api,30);
  T -> rysuj(api,30); //zeby sie narysowal bo zmazuje pierwsze
  przeszkody.push_back(T);

  shared_ptr<Dno> D;
  D=make_shared<Dno>();
  D->rysuj(api,-30);
  przeszkody.push_back(D);

  shared_ptr<PrzeszkodaProst> P1;
  P1=make_shared<PrzeszkodaProst>();
  P1 -> ustaw("black");
  P1 -> obrot('Z',90);
  P1 -> rysuj(S4,api);
  przeszkody.push_back(P1);

  shared_ptr<PrzeszkodaProst> P2;
  P2=make_shared<PrzeszkodaProst>();
  P2 -> ustaw("black");
  P2 -> rysuj(S5,api);
  przeszkody.push_back(P2);

  shared_ptr<PrzeszkodaProst> P3;
  P3=make_shared<PrzeszkodaProst>();
  P3 -> ustaw("black");
  P3 -> rysuj(S6,api);
  przeszkody.push_back(P3);

  shared_ptr<Dron> Witold; //red
  Witold=make_shared<Dron>();
  Witold -> ustaw_dron("red"); 
  Witold -> rysuj_drona(S1,api);
  drony.push_back(Witold);
  przeszkody.push_back(Witold);

  shared_ptr<Dron> Andrzej; //green
  Andrzej=make_shared<Dron>();
  Andrzej -> ustaw_dron("green");
  Andrzej -> rysuj_drona(S2,api);
  drony.push_back(Andrzej);
  przeszkody.push_back(Andrzej);

  shared_ptr<Dron> Stanislaw; //purple
  Stanislaw=make_shared<Dron>();
  Stanislaw -> ustaw_dron("purple");
  Stanislaw -> rysuj_drona(S3,api);
  drony.push_back(Stanislaw);
  przeszkody.push_back(Stanislaw);

  char klawisz;
  double kat, droga;
  int ktory=3;

  cout<< "Istniejace wektory: " << Wektor3D::zwroc_istniejace() << endl;
  cout<< "Stworzone wektory: " << Wektor3D::zwroc_stworzone()<<endl;
  cout << "Istniejace obiekty: " << ObiektRysowalny::zwroc_istniejace() << endl;
  cout << "Stworzone obiekty: " << ObiektRysowalny::zwroc_stworzone()<<endl;
  cout << "\nPanel sterowania dronem" << endl << endl;

  while(ktory!=0 && ktory!=1 && ktory!=2) {
      cout<<"Którym dronem chcesz sterować?"<<endl;
      cout<<"0 - czerwony"<<endl;
      cout<<"1 - zielony"<<endl;
      cout<<"2 - fioletowy"<<endl;
      cout<<">";
      cin>>ktory;
      cout<<endl;
  } 

  while(klawisz != 'q') {
    cout << "Wybierz opcję sterowania:" <<endl << endl;
    cout << "d - Zmień drona" <<endl;
    cout << "p - Płyń naprzód" <<endl;
    cout << "w - Płyń pod kątem" <<endl;
    cout << "o - Obróć" <<endl;
    cout << "f - Zrób fikołka!" << endl<<endl;
    cout << "q - Zakończ program"<<endl<<endl;
    cout << ">";
    cin >> klawisz; 
    cout<<endl;

    switch (klawisz)
    {
    case 'd':
      
      cout<<"Którym dronem chcesz sterować?"<<endl;
      cout<<"0 - czerwony"<<endl;
      cout<<"1 - zielony"<<endl;
      cout<<"2 - fioletowy"<<endl;
      cout<<">";
      cin>>ktory;
      cout<<endl;
      if(ktory!=0 && ktory!=1 && ktory!=2) {
        while(ktory!=0 && ktory!=1 && ktory!=2) {
      cout<<"Którym dronem chcesz sterować?"<<endl;
      cout<<"0 - czerwony"<<endl;
      cout<<"1 - zielony"<<endl;
      cout<<"2 - fioletowy"<<endl;
      cout<<">";
      cin>>ktory;
      cout<<endl;
  } 
      }
      break;

    case 'p':
      cout << "Jaką drogę ma przepłynąć?" << endl;
      cout << ">";
      cin >> droga;
      cout<<endl;
      drony[ktory] -> animacja_ruch(droga,api);
      /*
      for(int i=0; i<100;i++){
      drony[ktory] -> animacja_ruch(droga/100,api);
        for(int j=0; j<8; j++) {
          if(przeszkody[j]->kolizja(*drony[ktory])==true){
            i=420;
            cout<<"KOLIZJA"<<endl;
            drony[ktory] -> animacja_ruch(-droga/100,api);
          }
        }
      } */
  cout<< "Istniejace wektory: " << Wektor3D::zwroc_istniejace() << endl;
  cout<< "Stworzone wektory: " << Wektor3D::zwroc_stworzone()<<endl;
  cout << "Istniejace obiekty: " << ObiektRysowalny::zwroc_istniejace() << endl;
  cout << "Stworzone obiekty: " << ObiektRysowalny::zwroc_stworzone()<<endl;
      break;
    
    case 'w': // do poprawy
      cout << "Pod jakim kątem ma płynąć?" << endl;
      cout << ">";
      cin >> kat;
      cout << "Jaką drogę ma przepłynąć?" << endl;
      cout << ">";
      cin >> droga;
      cout<<endl;
      drony[ktory]->animacja_plyn(kat,droga,api);
      
      cout<< "Istniejace wektory: " << Wektor3D::zwroc_istniejace() << endl;
  cout<< "Stworzone wektory: " << Wektor3D::zwroc_stworzone()<<endl;
  cout << "Istniejace obiekty: " << ObiektRysowalny::zwroc_istniejace() << endl;
  cout << "Stworzone obiekty: " << ObiektRysowalny::zwroc_stworzone()<<endl;
      break;

    case 'o':
      cout << "Pod jakim kątem ma się obrócić?" << endl;
      cout << ">";
      cin >> kat;
      cout<<endl;
      drony[ktory] -> animacja_obrot('Z',kat,api);
      cout<< "Istniejace wektory: " << Wektor3D::zwroc_istniejace() << endl;
  cout<< "Stworzone wektory: " << Wektor3D::zwroc_stworzone()<<endl;
  cout << "Istniejace obiekty: " << ObiektRysowalny::zwroc_istniejace() << endl;
  cout << "Stworzone obiekty: " << ObiektRysowalny::zwroc_stworzone()<<endl;
      break;

    case 'f':
      cout<<"I myk!" <<endl;
      drony[ktory] -> animacja_obrot('X',360,api);
      cout<< "Istniejace wektory: " << Wektor3D::zwroc_istniejace() << endl;
  cout<< "Stworzone wektory: " << Wektor3D::zwroc_stworzone()<<endl;
  cout << "Istniejace obiekty: " << ObiektRysowalny::zwroc_istniejace() << endl;
  cout << "Stworzone obiekty: " << ObiektRysowalny::zwroc_stworzone()<<endl;
      break;

    case 'q':
      cout << "Miłego dnia!" <<endl;
      break;
    
    default:
      cerr<<"Złe wprowadzenie opcji"<<endl;
      break;
    }
  }


 
  


  wait4key();


  /*
  Dron Witold, Andrzej, Stanislaw;
  Tafla T;
  Dno D;
  Przeszkoda P1, P2, P3;
  

  Wektor3D S1(20,0,0), S2(-20,20,0), S3(0,-20,-20), //Drony
           S4(10,0,0), S5(0,-10,-20), S6(-20,10,-10);

  T.rysuj(api,30);
  T.rysuj(api,30);
  D.rysuj(api,-30);
  P1.ustaw("black");
  P1.obrot('Z',90);
  P1.rysuj(S4,api);
  P2.ustaw("black");
  P2.rysuj(S5,api);
  P3.ustaw("black");
  P3.rysuj(S6,api);
  Witold.ustaw_dron("red"); 
  Witold.rysuj_drona(S1,api);
  Andrzej.ustaw_dron("green");
  Andrzej.rysuj_drona(S2,api);
  Stanislaw.ustaw_dron("purple");
  Stanislaw.rysuj_drona(S3,api);

  char klawisz;
  double kat, droga;
  cout<< "jest:" << Wektor3D::zwroc_istniejace() << endl;
  cout<< "stworzono:" << Wektor3D::zwroc_stworzone()<<endl;
  cout << "obiekty jest:" << ObiektRysowalny::zwroc_istniejace() << endl;
  cout << "w sumie stworzono:" << ObiektRysowalny::zwroc_stworzone()<<endl;
  cout << "Panel sterowania dronem" << endl << endl;
  while(klawisz != 'q') {
    cout << "Wybierz opcję sterowania:" <<endl << endl;
    cout << "p - Płyń naprzód" <<endl;
    cout << "w - Płyń pod kątem" <<endl;
    cout << "o - Obróć" <<endl;
    cout << "f - Zrób fikołka!" << endl<<endl;
    cout << "q - Zakończ program"<<endl<<endl;
    cout << ">";
    cin >> klawisz; 
    cout<<endl;
    switch (klawisz)
    {
    case 'p':
      cout << "Jaką drogę ma przepłynąć?" << endl;
      cout << ">";
      cin >> droga;
      cout<<endl;
      Witold.animacja_ruch(droga,api);
      cout<< "jest:" << Wektor3D::zwroc_istniejace() << endl;
      cout<< "stworzono:" << Wektor3D::zwroc_stworzone()<<endl;
      cout << "obiekty jest:" << ObiektRysowalny::zwroc_istniejace() << endl;
      cout << "w sumie stworzono:" << ObiektRysowalny::zwroc_stworzone()<<endl;
      break;
    
    case 'w':
      cout << "Pod jakim kątem ma płynąć?" << endl;
      cout << ">";
      cin >> kat;
      cout << "Jaką drogę ma przepłynąć?" << endl;
      cout << ">";
      cin >> droga;
      cout<<endl;
      Witold.animacja_plyn(kat,droga,api);
      cout<< "jest:" << Wektor3D::zwroc_istniejace() << endl;
      cout<< "stworzono:" << Wektor3D::zwroc_stworzone()<<endl;
      cout << "obiekty jest:" << ObiektRysowalny::zwroc_istniejace() << endl;
      cout << "w sumie stworzono:" << ObiektRysowalny::zwroc_stworzone()<<endl;
      break;

    case 'o':
      cout << "Pod jakim kątem ma się obrócić?" << endl;
      cout << ">";
      cin >> kat;
      cout<<endl;
      Witold.animacja_obrot('Z',kat,api);
      cout<< "jest:" << Wektor3D::zwroc_istniejace() << endl;
      cout<< "stworzono:" << Wektor3D::zwroc_stworzone()<<endl;
      cout << "obiekty jest:" << ObiektRysowalny::zwroc_istniejace() << endl;
      cout << "w sumie stworzono:" << ObiektRysowalny::zwroc_stworzone()<<endl;
      break;

    case 'f':
      cout<<"I myk!" <<endl;
      Witold.animacja_obrot('X',360,api);
      cout<< "jest:" << Wektor3D::zwroc_istniejace() << endl;
      cout<< "stworzono:" << Wektor3D::zwroc_stworzone()<<endl;
      cout << "obiekty jest:" << ObiektRysowalny::zwroc_istniejace() << endl;
      cout << "w sumie stworzono:" << ObiektRysowalny::zwroc_stworzone()<<endl;
      break;

    case 'q':
      cout << "Miłego dnia!" <<endl;
      break;
    
    default:
      cerr<<"Złe wprowadzenie opcji"<<endl;
      break;
    }

  } */
}
  
  
