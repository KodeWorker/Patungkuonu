// Copyright 2025 KodeWorker(fxp61005@gmail.com)
#ifndef INCLUDE_LIB_EXPORT_OPTIONS_HPP_
#define INCLUDE_LIB_EXPORT_OPTIONS_HPP_

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

#endif  // INCLUDE_LIB_EXPORT_OPTIONS_HPP_
