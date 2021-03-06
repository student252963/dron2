CPPFLAGS= -c -g -Wall -pedantic -std=c++17

__start__:  dron
	  ./dron

dron:	obj/Dr3D_gnuplot_api.o obj/main.o obj/MacObrot.o  obj/Prostopadloscian.o obj/Dron.o obj/Bryla.o obj/Graniastoslup.o obj/Tafla.o obj/Dno.o
	g++ -o dron obj/Dr3D_gnuplot_api.o obj/main.o obj/MacObrot.o  obj/Prostopadloscian.o obj/Dron.o obj/Bryla.o obj/Graniastoslup.o obj/Tafla.o obj/Dno.o -lpthread

obj/main.o:	src/main.cpp inc/Dron.hh inc/Tafla.hh inc/Dno.hh
	g++ ${CPPFLAGS} -o obj/main.o src/main.cpp

obj/Dr3D_gnuplot_api.o:	src/Dr3D_gnuplot_api.cpp inc/Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o obj/Dr3D_gnuplot_api.o src/Dr3D_gnuplot_api.cpp

obj/Bryla.o:	src/Bryla.cpp inc/Bryla.hh
	g++ ${CPPFLAGS} -o obj/Bryla.o src/Bryla.cpp

obj/Dron.o:	src/Dron.cpp inc/Dron.hh
	g++ ${CPPFLAGS} -o obj/Dron.o src/Dron.cpp

obj/Graniastoslup.o:	src/Graniastoslup.cpp inc/Graniastoslup.hh
	g++ ${CPPFLAGS} -o obj/Graniastoslup.o src/Graniastoslup.cpp

obj/MacObrot.o:	src/MacObrot.cpp inc/MacObrot.hh
	g++ ${CPPFLAGS} -o obj/MacObrot.o src/MacObrot.cpp


obj/Prostopadloscian.o:	src/Prostopadloscian.cpp inc/Prostopadloscian.hh
	g++ ${CPPFLAGS} -o obj/Prostopadloscian.o src/Prostopadloscian.cpp

obj/Tafla.o:	src/Tafla.cpp inc/Tafla.hh
	g++ ${CPPFLAGS} -o obj/Tafla.o src/Tafla.cpp

obj/Dno.o:	src/Dno.cpp inc/Dno.hh
	g++ ${CPPFLAGS} -o obj/Dno.o src/Dno.cpp


cler:
	rm -f obj/*.o dron
