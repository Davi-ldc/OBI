cd Projetos/ShadersComCpp && rmdir /S /Q build && cmake -S . -B build -G "Visual Studio 17 2022" -DCMAKE_TOOLCHAIN_FILE=C:/Users/davil/vcpkg/scripts/buildsystems/vcpkg.cmake && cmake --build build --config Release && build\Release\ShadersComCpp.exe 

comando pra rodar:
cd Projetos/ShadersComCpp && cmake --build build --config Release && build\Release\ShadersComCpp.exe

É bem legal e artistico mecher com shaders (no caso só o fragment) a ideia aqui era montar algo no estilo do xor (https://x.com/XorDev/). Ai eu fiz uma window com SDL e openGL (depois fiz umas optmizações com chat XD) e fui mechendo aleatóriamente no julia set. É massa o processo de pensar matematicamente para chegar a um efeito, mudar intervalos, trigonometria... por mais que provavelmente não tenha aplicação nenhuma montar shaders artisticos (efeitos super especificios) melhora seu raciocinio lógico e matematico além de tornar trigonometria divertido :)