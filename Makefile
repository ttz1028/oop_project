main:main.o Book.o Library.o Student.o Staff.o User.o Menu.o
	g++ main.o Book.o Library.o Student.o Staff.o User.o Menu.o
	./a.out

main.o:main.cpp
	g++ -c main.cpp
Menu,o:Menu.cpp
	g++ -c Menu.cpp
Book.o:Book.cpp 
	g++ -c Book.cpp
Library.o:Library.cpp 
	g++ -c library.cpp
Student.o:Student.cpp 
	g++ -c student.cpp
Staff.o:Staff.cpp 
	g++ -c staff.cpp
User.o:User.cpp 
	g++ -c user.cpp
clean:
	rm *.o a.out