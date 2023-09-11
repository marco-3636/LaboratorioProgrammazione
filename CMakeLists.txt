cmake_minimum_required(VERSION 3.26)
project(LaboratorioProgrammazione_SianiMarco)

set(CMAKE_CXX_STANDARD 11)

add_executable(LaboratorioProgrammazione_SianiMarco main.cpp
        Note.h
        Note.cpp
        Notebook.h
        Notebook.cpp
        Observer.h
        Observer.cpp
        Subject.h
        Subject.cpp
        SetCollezioni.h
        SetCollezioni.cpp
        Displayer.h
        Displayer.cpp
        Test/NoteTest.cpp
        Test/NotebookTest.cpp
        Test/AllTest.cpp)
