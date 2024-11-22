cmake CMakeLists.txt
cmake --install .
cmake --build .
copy src\\studentai_1000.txt build\\Debug\\studentai_1000.txt
cd Debug\
obj_projektas.exe
pause