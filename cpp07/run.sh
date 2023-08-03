ls -la
ls -la ex0*

cd ex00
make
valgrind ./whatever
make fclean

cd ../ex01
make
valgrind ./iter
make fclean

cd ../ex02
make
valgrind ./array
make fclean

