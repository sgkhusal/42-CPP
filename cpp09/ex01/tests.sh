./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
# result = 42
./RPN "7 7 * 7 -"
# result = 42
./RPN "1 2 * 2 / 2 * 2 4 - +"
# 0
./RPN "5 1 2 + 4 * + 3 -"
# result = 14

# depends on implementation
./RPN 42+
# result = 6
./RPN 4

# Errors
./RPN "(1 + 1)"
./RPN
./RPN 4+
./RPN 4+2
./RPN 42
./RPN "5 1 2 + 4 * 3 -"
