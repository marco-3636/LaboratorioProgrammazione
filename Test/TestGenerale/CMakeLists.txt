include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests AllTest.cpp NotebookTest.cpp NoteTest.cpp
        ../Note.h
        ../Notebook.h
        ../SetCollezioni.h
        ../Subject.h
        ../Observer.h)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(runBasicTests Test)