cd Projetos/ShadersComCpp && rmdir /S /Q build && cmake -S . -B build -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=C:/Users/davil/vcpkg/scripts/buildsystems/vcpkg.cmake && cmake --build build --config Release && build\Release\ShadersComCpp.exe 


cmake --build build --config Release && build\Release\ShadersComCpp.exe