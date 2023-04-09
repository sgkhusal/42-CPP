# Concepts

## New and Delete

- `malloc` and `free` works well for types like `int`, `char` and `float`. But for classes they don't work well because they don't call the constructor and destructor of the class. 
- The `new` and `delete` operators handle the memory allocation in a clean way for classes

```c++
Student* jim = new Student();
delete jim;

Student* students = newStudent[42];
delete [] students;
```

## References
- don't replace pointers
- reference is a pointer that is constant and that is always referenced (it is never void).
- Once created, it can't points to another variable.
- You can't create one without attribute it's value. So, if you use a reference, you have the guarantee that it is not void, and so you will not have the null pointer problems
- The values of the variable can be changed, the reference that can't point to another variable
- To access a reference value, you only needs to use its name (unlike the pointer). A reference is like a de-referenced pointer

```c++
int  numberOfBalls = 42;
int* ballsPtr = &numberOfBalls; // a pointer to an int
int& ballsRef = numberOfBalls; // a reference to an int

std::cout << ballsRef << std::endl; // prints 42
ballsRef = 84;
std::cout << numberOfBalls << std::endl; // prints 84

std::cout << &ballsRef << std::endl; // prints the memory address stored in ballsRef (the memory address of numberOfBalls; equivalent to &numberOfBalls)
```

<b>Important:</b> References have advantages over pointers but don't replace them. We still need pointers when we don't know the value in the beginning or when the memory address varies:
- if at some point it will not exist or if it should change: use a pointer
- if it will always exists and never changes it value: use a reference

## Filestreams

references:
- [Input-Output base classes](https://cplusplus.com/reference/ios/)
- [File I/O](https://www.cs.uic.edu/~jbell/CourseNotes/CPlus/FileIO.html)

### The Stream Class Hierarchy

A C++ stream is a flow of data into or out of a program, such as the data written to `cout` or read from `cin`

<img width="1024" alt="image" src="https://user-images.githubusercontent.com/75377067/230795460-834cf81c-b0d2-477f-a803-e9157b36061e.png">


### \<fstream> library
Streams to interact with files:
- `std::fstream`: input/output file stream class
- `std::ifstream`: input file stream class
- `std::ofstream`: output file stream class

Because `ifstream`/`ofstream` is an `istream`/`ostream`, anything you can do to an `istream`/`ostream` you can also do the same way to an `ifstream`/`ofstream`

```c++
std::ifstream ifs("filename");

// or:
std::ifstream ifs;
ifs.open("filename");
if (ifs.fail()) {
    // ...
}
ifs >> str; // reads only one word per time
ifs.eof(); // indicates if it reachs the EOF
ifs.readbuf // gets all the file content
ifs.close(); // to prevent possible corruption
```

### \<sstream> string streams
- `std::ostringstream`: output stream class to operate on strings
```c++
std::ifstream ifs("filename");
std::ostringstream oss;

oss << ifs.readbuf // reads all the file content and put it into a ostringstream
```
