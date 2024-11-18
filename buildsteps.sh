mkdir build
cd build
cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_PREFIX_PATH=C:/Qt/6.7.2/msvc2019_64 ..
cmake --build . --config Release