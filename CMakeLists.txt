cmake_minimum_required(VERSION 3.26)
project(LaboratorioProgrammazione_SianiMarco)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(test)
set(SOURCE_FILES main.cpp
        Note.h
        Note.cpp
        Notebook.h
        Notebook.cpp
        Observer.h
        Subject.h
        SetCollezioni.h
        SetCollezioni.cpp
        Displayer.h
        Displayer.cpp
)

add_executable(LaboratorioProgrammazione_SianiMarco main.cpp
        Note.h
        Note.cpp
        Notebook.h
        Notebook.cpp
        Observer.h
        Subject.h
        SetCollezioni.h
        SetCollezioni.cpp
        Displayer.h
        Displayer.cpp
        #test/RunAllTest.cpp
        #test/NotebookTest.cpp
        #test/NoteTest.cpp
)

