@echo off
mkdir build_msvc19
cd build_msvc19
cmake -G"Visual Studio 16 2019" ..
pause