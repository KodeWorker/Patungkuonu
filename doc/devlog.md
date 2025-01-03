# Hundred-Peak Project

## Devlog

- 2024/12/18 employ SDL as submodule

    SDL release-2.30.10
    SDL_image release-2.8.3 (run script in external/)
    SDL_ttf release-2.22.0 (run script in external/)

    https://www.studyplan.dev/sdl2-minesweeper/sdl2-cmake

- 2024/12/19 employ cpplint and googltest

    pip install cpplint==2.0.0
    ```
    cpplint --linelength=120 --exclude .\3rdparty\ --exclude .\bin\ --exclude .\build\ --exclude .\data\ --recursive .\
    ```
    CMAKE_CXX_CPPLINT only works in Makefile and Ninja generators

    https://github.com/cpplint/cpplint
    https://gitlab.kitware.com/cmake/cmake/-/issues/18808

    googletest v1.15.2

    copy built googletest dlls to destination of project
    https://stackoverflow.com/questions/69978314/cmake-with-gtest-on-windows-build-starts-test-but-shared-libs-cannot-be-found

- 2024/12/21 Debian support

    DO NOT BUILD IN ANACONDA ENVIRONMENT! IT CAUSES LINKING ISSUES!

    can not find freetype while adding SDL_ttf
    https://discourse.libsdl.org/t/build-sdl2-ttf-for-android/46897/8

    Getting started with SDL
    https://lazyfoo.net/tutorials/SDL/

- 2024/12/27

    implement settings
    implement serializer/deserializer

    implement loglevel
    https://www.reddit.com/r/cpp/comments/zw59lh/enums_with_methods/

- 2024/12/28

    start implementing sprite object

    asset for demo:
    https://kenmi-art.itch.io/cute-fantasy-rpg

    understand link property:
    https://stackoverflow.com/questions/69783203/examples-of-when-public-private-interface-should-be-used-in-cmake
    
- 2024/12/31

    check for MSVC support
    TARGET_LINK_LIBRARIES PUBLIC/PRIVATE

    https://stackoverflow.com/questions/69783203/examples-of-when-public-private-interface-should-be-used-in-cmake

    warning C4251:
    https://www.cnblogs.com/zhangyz/articles/6238841.html

- 2025/1/1

    Multiple key press in SDL:

    https://stackoverflow.com/questions/1252976/how-to-handle-multiple-keypresses-at-once-with-sdl

- 2025/1/3

    High CPU Usage -> require frame rate control

    https://discourse.libsdl.org/t/high-cpu-usage/14676/12