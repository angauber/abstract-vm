# Abstract Vm
RPN calculator virtual machine built in C++ 17

## Dependancies
* A C++ 17 compiller
* Cmake
* Catch2

# Building
Run `./build.sh` build artifacts and executables will be place inside the created `build` dirrectory


# Testing
`cd build`  
`ctest . -v`  

## Sample file
```txt
; ------------
; sample.avm -
; ------------
push int32(42)
push int32(33)
add
push float(44.55)
mul
push double(42.42)
push int32(42)
dump
pop
assert double(42.42)
exit
```
`./build/avm tests/files/sample.avm`
```txt
42
42.42
3341.25
```
