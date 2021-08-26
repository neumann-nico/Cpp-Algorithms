add_library(SudokuSolver
        include/SudokuSolver/SudokuSolver.h
        src/SudokuSolver.cpp)

target_include_directories(SudokuSolver PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(SudokuSolver PUBLIC CppAlgorithms)

add_executable(SudokuSolver_run src/main.cpp)
target_link_libraries(SudokuSolver_run SudokuSolver)