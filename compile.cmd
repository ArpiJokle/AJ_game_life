@ECHO OFF
cd ./objects
g++ -c ../source/*.cpp -I ..\SFML-2.5.1\include\
g++ -o ../main.exe ./*.o -L ..\SFML-2.5.1\lib\ -lsfml-graphics -lsfml-window -lsfml-system -mwindows