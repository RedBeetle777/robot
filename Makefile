#
#  To sa opcje dla kompilacji
#
CXXFLAGS=-c -g -Iinc -Wall -pedantic -std=c++11

TRGDIR=/tmp/robot_scena

__start__: ./robot_scena
	./robot_scena

./robot_scena: obj obj/main.o obj/Robot.o obj/Macierz.o obj/Scena.o obj/Wektor.o obj/lacze_do_gnuplota.o
	g++ -Wall -pedantic -std=c++11 -o ./robot_scena obj/Wektor.o obj/Macierz.o obj/main.o obj/Robot.o obj/Scena.o obj/lacze_do_gnuplota.o
		
obj:
	mkdir -p obj						
                       

obj/main.o: src/main.cpp inc/Macierz.hh inc/Wektor.hh inc/Robot.hh\
			inc/Scena.hh
	g++ -c ${CXXFLAGS} -o obj/main.o src/main.cpp

obj/Robot.o: src/Robot.cpp inc/Robot.hh		
	g++ ${CPPFLAGS} -Iinc -c -o obj/Robot.o src/Robot.cpp

obj/Macierz.o: src/Macierz.cpp inc/Macierz.hh
	g++ ${CPPFLAGS} -Iinc -c -o obj/Macierz.o src/Macierz.cpp

obj/Scena.o: src/Scena.cpp inc/Scena.hh
	g++ ${CPPFLAGS} -Iinc -c -o obj/Scena.o src/Scena.cpp

obj/Wektor.o: src/Wektor.cpp inc/Wektor.hh
	g++ ${CPPFLAGS} -Iinc -c -o obj/Wektor.o src/Wektor.cpp

obj/lacze_do_gnuplota.o: inc/lacze_do_gnuplota.hh src/lacze_do_gnuplota.cpp
	g++ -c ${CXXFLAGS} -o obj/lacze_do_gnuplota.o src/lacze_do_gnuplota.cpp


clean:
	rm -f obj/*.o ./robot_scena
