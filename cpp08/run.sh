ls -la
ls -la ex0*

cd ex00
make
valgrind ./easyfind
make fclean

cd ../ex01
make
valgrind ./span
make fclean

cd ../ex02
make
valgrind ./mutant_stack
make fclean

