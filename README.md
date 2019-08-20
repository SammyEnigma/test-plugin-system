#About

Small but smart SteamAPI-like C++ plugin system.

Main target is backward compability and ability to use plugins that relies on different versions of same API 
(for example, ver 0 and ver 5) alongside.  


# Toolchain

0. Windows - any modern, I believe.
1. CMake - 3.14+
2. MinGW-w64 - i686-w64-mingw32


#Building

* Configure as common CMake project. Make sure using "MinGW Makefiles" as build generator. Keep in mind, 
CMake may require some settings to set this GCC/G++ from Toolchain section. Mine are working fine, so...
```
mkdir build
cd build
CMake -G "MinGW MakeFiles" ..
```
* Build as common CMake project.
```
CMake --build .``
```


#Running

1. Launch PS or CMD instance.
2. Navigate to **build/bin**.
3. Launch "application.exe".
4. Look at output. 
