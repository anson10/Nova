cmake_minimum_required(VERSION 3.10)
project(TextEditor)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(TextEditor 
    main.cpp 
    TextEditor.cpp 
    TextEditor.h
    SyntaxHighlighter.cpp 
    SyntaxHighlighter.h
)
target_link_libraries(TextEditor Qt6::Widgets)