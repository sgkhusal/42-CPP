ls -la
ls -la ex0*

cd ex02
make
make
./PmergeMe `shuf -i 1-10000 -n 10000 | tr "\n" " "`
valgrind ./PmergeMe `shuf -i 1-10000 -n 3000 | tr "\n" " "`
valgrind ./PmergeMe `shuf -i 1-1000 -n 100 | tr "\n" " "`
valgrind ./PmergeMe 3 5 9 7 4
valgrind ./PmergeMe 7 8 27 100 11 46 2 53 0 9 42 15 21
valgrind ./PmergeMe 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
make fclean

cd ../ex00
make
make
valgrind ./btc input.txt
make fclean

cd ../ex01
make
make
./tests.sh
make fclean
