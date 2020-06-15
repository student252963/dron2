#include "../inc/Dno.hh"

void  Dno::rysuj(shared_ptr<drawNS::Draw3DAPI> api, const double & z) {
        scena=api;
        poziom=z;
        index=scena->draw_surface(vector<vector<Point3D>>{
        {drawNS::Point3D(-50,-50,poziom), drawNS::Point3D(-50,-40,poziom), drawNS::Point3D(-50,-30,poziom), drawNS::Point3D(-50,-20,poziom), drawNS::Point3D(-50,-10, poziom), drawNS::Point3D(-50,0, poziom), drawNS::Point3D(-50,10, poziom), drawNS::Point3D(-50,20, poziom), drawNS::Point3D(-50,30, poziom), drawNS::Point3D(-50,40, poziom), drawNS::Point3D(-50,50, poziom)}
        ,
        {drawNS::Point3D(-30,-50,poziom), drawNS::Point3D(-30,-40,poziom), drawNS::Point3D(-30,-30,poziom), drawNS::Point3D(-30,-20,poziom), drawNS::Point3D(-30,-10, poziom), drawNS::Point3D(-30,0, poziom), drawNS::Point3D(-30,10, poziom), drawNS::Point3D(-30,20, poziom), drawNS::Point3D(-30,30, poziom), drawNS::Point3D(-30,40, poziom), drawNS::Point3D(-30,50, poziom)}
        ,
        {drawNS::Point3D(-40,-50,poziom), drawNS::Point3D(-40,-40,poziom), drawNS::Point3D(-40,-30,poziom), drawNS::Point3D(-40,-20,poziom), drawNS::Point3D(-40,-10, poziom), drawNS::Point3D(-40,0, poziom), drawNS::Point3D(-40,10, poziom), drawNS::Point3D(-40,20, poziom), drawNS::Point3D(-40,30, poziom), drawNS::Point3D(-40,40, poziom), drawNS::Point3D(-40,50, poziom)}
        ,
        {drawNS::Point3D(-20,-50,poziom), drawNS::Point3D(-20,-40,poziom), drawNS::Point3D(-20,-30,poziom), drawNS::Point3D(-20,-20,poziom), drawNS::Point3D(-20,-10, poziom), drawNS::Point3D(-20,0, poziom), drawNS::Point3D(-20,10, poziom), drawNS::Point3D(-20,20, poziom), drawNS::Point3D(-20,30, poziom), drawNS::Point3D(-20,40, poziom), drawNS::Point3D(-20,50, poziom)}
        ,
        {drawNS::Point3D(-10,-50,poziom), drawNS::Point3D(-10,-40,poziom), drawNS::Point3D(-10,-30,poziom), drawNS::Point3D(-10,-20,poziom), drawNS::Point3D(-10,-10, poziom), drawNS::Point3D(-10,0, poziom), drawNS::Point3D(-10,10, poziom), drawNS::Point3D(-10,20, poziom), drawNS::Point3D(-10,30, poziom), drawNS::Point3D(-10,40, poziom), drawNS::Point3D(-10,50, poziom)}
        ,
        {drawNS::Point3D(0,-50,poziom), drawNS::Point3D(0,-40,poziom), drawNS::Point3D(0,-30,poziom), drawNS::Point3D(0,-20,poziom), drawNS::Point3D(0,-10, poziom), drawNS::Point3D(0,0, poziom), drawNS::Point3D(0,10, poziom), drawNS::Point3D(0,20, poziom), drawNS::Point3D(0,30, poziom), drawNS::Point3D(0,40, poziom), drawNS::Point3D(0,50, poziom)}
        ,
        {drawNS::Point3D(10,-50,poziom), drawNS::Point3D(10,-40,poziom), drawNS::Point3D(10,-30,poziom), drawNS::Point3D(10,-20,poziom), drawNS::Point3D(10,-10, poziom), drawNS::Point3D(10,0, poziom), drawNS::Point3D(10,10, poziom), drawNS::Point3D(10,20, poziom), drawNS::Point3D(10,30, poziom), drawNS::Point3D(10,40, poziom), drawNS::Point3D(10,50, poziom)}
        ,
        {drawNS::Point3D(20,-50,poziom), drawNS::Point3D(20,-40,poziom), drawNS::Point3D(20,-30,poziom), drawNS::Point3D(20,-20,poziom), drawNS::Point3D(20,-10, poziom), drawNS::Point3D(20,0, poziom), drawNS::Point3D(20,10, poziom), drawNS::Point3D(20,20, poziom), drawNS::Point3D(20,30, poziom), drawNS::Point3D(20,40, poziom), drawNS::Point3D(20,50, poziom)}
        ,
        {drawNS::Point3D(30,-50,poziom), drawNS::Point3D(30,-40,poziom), drawNS::Point3D(30,-30,poziom), drawNS::Point3D(30,-20,poziom), drawNS::Point3D(30,-10, poziom), drawNS::Point3D(30,0, poziom), drawNS::Point3D(30,10, poziom), drawNS::Point3D(30,20, poziom), drawNS::Point3D(30,30, poziom), drawNS::Point3D(30,40, poziom), drawNS::Point3D(30,50, poziom)}
        ,
        {drawNS::Point3D(40,-50,poziom), drawNS::Point3D(40,-40,poziom), drawNS::Point3D(40,-30,poziom), drawNS::Point3D(40,-20,poziom), drawNS::Point3D(40,-10, poziom), drawNS::Point3D(40,0, poziom), drawNS::Point3D(40,10, poziom), drawNS::Point3D(40,20, poziom), drawNS::Point3D(40,30, poziom), drawNS::Point3D(40,40, poziom), drawNS::Point3D(40,50, poziom)}
        ,
        {drawNS::Point3D(50,-50,poziom), drawNS::Point3D(50,-40,poziom), drawNS::Point3D(50,-30,poziom), drawNS::Point3D(50,-20,poziom), drawNS::Point3D(50,-10, poziom), drawNS::Point3D(50,0, poziom), drawNS::Point3D(50,10, poziom), drawNS::Point3D(50,20, poziom), drawNS::Point3D(50,30, poziom), drawNS::Point3D(50,40, poziom), drawNS::Point3D(50,50, poziom)}
        },"yellow");
        scena->redraw();
    }