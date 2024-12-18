# Hundred-Peak Project

- TODO
[-] SDL
[-] cpplint
[-] googletest

- 2024/12/18 employ SDL as submodule

    SDL release-2.30.10
    SDL_image release-2.8.3
    SDL_ttf release-2.22.0 (need update submodules)

    https://www.studyplan.dev/sdl2-minesweeper/sdl2-cmake

- 2024/12/19 employ cpplint and googltest

    pip install cpplint==2.0.0
    ```
    cpplint --filter "-build/include_subdir,-build/include_what_you_use" --linelength=120 --exclude .\3rdparty\ --exclude .\bin\ --exclude .\build\ --exclude .\data\ --recursive .\
    ```
    CMAKE_CXX_CPPLINT only works in Makefile and Ninja generators

    https://github.com/cpplint/cpplint
    https://gitlab.kitware.com/cmake/cmake/-/issues/18808

    googletest v1.15.2

    copy built googletest dlls to destination of project
    https://stackoverflow.com/questions/69978314/cmake-with-gtest-on-windows-build-starts-test-but-shared-libs-cannot-be-found