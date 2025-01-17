cmake_minimum_required(VERSION 3.16)
project(Snake LANGUAGES CXX)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

set(SOURCES
    src/AssetMan.cpp
    src/Game.cpp
    src/GameOver.cpp
    src/GamePlay.cpp
    src/main.cpp
    src/MainMenu.cpp
    src/Snake.cpp
    src/StateMan.cpp
    src/PauseGame.cpp
)

if(WIN32)
    set(RESOURCES ${PROJECT_SOURCE_DIR}/src/resources.rc)
endif()

add_executable(main ${SOURCES} ${RESOURCES})
target_link_libraries(main PRIVATE sfml-graphics)
target_compile_features(main PRIVATE cxx_std_17)
target_include_directories(main PRIVATE ${PROJECT_SOURCE_DIR}/include)

if(WIN32)
    add_custom_command(
        TARGET main
        COMMENT "Copy OpenAL DLL"
        PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:main>
        VERBATIM)
endif()
