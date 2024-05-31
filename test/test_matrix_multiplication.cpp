#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult



//Here we generate random matrix in order to find which errors are defined
//Since errors to spot are not necessarily errors in real matrix-matrix multiplication 
//it is not possible to conduct test relying on real algebraic rules: for this reason random tests.
TEST(MatrixMultiplicationTest, TestMultiplyMatrices) {
    std::vector<std::vector<int>> A = {
        {1, 2, 3},
        {4, 5, 6}
    };
    std::vector<std::vector<int>> B = {
        {7, 8},
        {9, 10},
        {11, 12}
    };
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));

    multiplyMatrices(A, B, C, 2, 3, 2);

    std::vector<std::vector<int>> expected = {
        {58, 64},
        {139, 154}
    };

    ASSERT_EQ(C, expected) << "Matrix multiplication test failed! :(((()";
}


//To run only this test, on the terminal: ./test_multiplication --gtest_filter=NotAllowedNumbers.*
//Error 6: Result matrix contains a number bigger than 100!
TEST(NotAllowedNumbers, Error6) {
    //it spots specifically the error6: Result matrix contains a number bigger than 100
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{7, 8},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    for (int i = 0; i < C.size(); ++i)
        for (int j = 0; j < C[i].size(); ++j) 
            ASSERT_LT(C[i][j], 101) << "Error 6: Result matrix contains a number bigger than 100!";
}


//To run only this test, on the terminal: ./test_multiplication --gtest_filter=NotAllowedSameRowsColumns.*
//Error 12: The number of rows in A is equal to the number of columns in B!
TEST(NotAllowedSameRowsColumns, Error12 ){
    //it spots error14: Number of columns in matrix A is odd!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{7, 8},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool rows_columns = A.size() != B[0].size()? true : false;
    ASSERT_TRUE(rows_columns) << "Error 12: The number of rows in A is equal to the number of columns in B"; 
}


//To run only this test, on the terminal: ./test_multiplication --gtest_filter=NotAlloweEvenRows.*
//Error 14: The result matrix C has an even number of rows!
TEST(NotAllowedEvenRows, Error14 ){
    //it spots error14: Number of columns in matrix A is odd!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{7, 8},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool rowsC = C.size() % 2 == 0 ? true: false;
    ASSERT_TRUE(rowsC) << "Error 14: The result matrix C has an even number of rows!"; 
}

//To run only this test, on the terminal: ./test_multiplication --gtest_filter=NotAllowedOddColumns.*
//Error 20: Number of columns in matrix A is odd!
TEST(NotAllowedOddColumns, Error20) {
    //it spots error20: Number of columns in matrix A is odd!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{7, 8},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool colsA = A[0].size() % 2 == 0 ? true: false;
    ASSERT_TRUE(colsA) << "Error20: Number of columns in matrix A is odd"; 

}     



int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
