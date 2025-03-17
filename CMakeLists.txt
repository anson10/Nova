cmake_minimum_required(VERSION 3.10)
project(TextEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Widgets TextToSpeech)  # Changed to Qt5

add_executable(TextEditor 
    main.cpp 
    TextEditor.cpp 
    TextEditor.h
    SyntaxHighlighter.cpp 
    SyntaxHighlighter.h
)

target_link_libraries(TextEditor Qt5::Widgets Qt5::TextToSpeech)  # Changed to Qt5
