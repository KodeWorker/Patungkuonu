#ifndef LIB_EXPORTS_OPTIONS_HPP
#define LIB_EXPORTS_OPTIONS_HPP

#if defined(_WIN32) || defined(_WIN64)
    #ifdef BUILDING_DLL
        #define LIB_EXPORT __declspec(dllexport)
    #else
        #define LIB_EXPORT __declspec(dllimport)
    #endif
#elif defined(__GNUC__)
    #ifdef BUILDING_DLL
        #define LIB_EXPORT __attribute__((visibility("default")))
    #else
        #define LIB_EXPORT
    #endif
#else
    #define LIB_EXPORT
#endif

#endif // LIB_EXPORTS_OPTIONS_HPP