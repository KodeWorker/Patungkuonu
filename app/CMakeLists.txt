PROJECT(Demo LANGUAGES CXX)

FILE(GLOB SRC 
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h)

SOURCE_GROUP(src FILES ${SRC})

INCLUDE_DIRECTORIES(${ROOT_PROJECT_DIR}/include)

ADD_EXECUTABLE(${PROJECT_NAME} ${SRC} ${HEADER})

TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${ROOT_PROJECT_NAME})

INSTALL(TARGETS ${PROJECT_NAME} 
        RUNTIME DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
        LIBRARY DESTINATION ${CMAKE_LIBRARY_OUTPUT_DIRECTORY}
        ARCHIVE DESTINATION ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY})