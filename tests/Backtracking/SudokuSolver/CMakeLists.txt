add_executable(SudokuSolver_test testSudokusolver.cpp)

target_link_libraries(SudokuSolver_test PRIVATE SudokuSolver gtest gtest_main)

add_test(NAME SudokuSolver_test COMMAND SudokuSolver_test)
