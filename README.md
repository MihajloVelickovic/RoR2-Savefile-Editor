# Risk of Rain 2 Lunar coin modifier 

---

Prerequisites:
* vcpkg
* CMake

When compiling pass
```shell
-DCMAKE_TOOLCHAIN_FILE=${PATH_TO_VCPKG}/scripts/buildsystems/vcpkg.cmake 
```
to CMake

---

Depending on your operating system you're going to need to install a different triplet of wxWidgets:
```c++
std::string os = [["your_operating_system"]];
switch(os){
    case Windows MSVC: os = "x64-windows-static"; break;
    case Windows MinGW: os = "x64-mingw-static"; break;
    case Linux: os = "x64-linux"; break;
    case OSX: os = "x64-osx"; break;
    default: break;
}
```
To download the correct triplet use
```shell
vcpkg install --triplet=your_operating_system
```