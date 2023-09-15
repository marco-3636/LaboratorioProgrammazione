project(test)
add_subdirectory(./googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})
add_executable(test RunAllTest.cpp NotebookTest.cpp NoteTest.cpp ../Note.h ../Notebook.h ../SetCollezioni.h ../SetCollezioni.cpp ../Notebook.cpp ../Note.cpp ../Subject.cpp ../Subject.h
../Observer.cpp ../Observer.h  )
target_link_libraries(test gtest gtest_main)