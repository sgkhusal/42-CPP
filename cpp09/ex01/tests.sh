valgrind ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
# result = 42
valgrind ./RPN "7 7 * 7 -"
# result = 42
valgrind ./RPN "1 2 * 2 / 2 * 2 4 - +"
# 0
valgrind ./RPN "5 1 2 + 4 * + 3 -"
# result = 14

# depends on implementation
valgrind ./RPN 42+
# result = 6
valgrind ./RPN 4

# Errors
valgrind ./RPN "(1 + 1)"
valgrind ./RPN
valgrind ./RPN 4+
valgrind ./RPN 4+2
valgrind ./RPN 42
valgrind ./RPN "5 1 2 + 4 * 3 -"
