BOLD="\e[1m"
YELLOW="\033[0;33m"
GREY="\033[38;5;244m"
PURPLE="\033[0;35m"
BLUE="\033[0;36m"
RED="\e[0;31m"
END="\033[0m"

test_file="conversion_tests/special_cases"
# test_file="conversion_tests/char" # manual: space and enter
# test_file="conversion_tests/int"
# test_file="conversion_tests/float"
test_file="conversion_tests/double"
# test_file="conversion_tests/errors"
exec="./convert"
i=1

make

printf $RED
	echo "\nCPP06 ex00 tests\n"

while read test; do
    printf $BLUE
	echo "$i.     $test"
    printf $GREY
    $exec $test
    echo
	((i++))
done < $test_file
printf "\n$END"
