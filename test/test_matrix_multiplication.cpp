#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


TEST(ErrorsMatrixB, Error4){
    //Error 4: Matrix B contains the number 3!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{7, 3},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_number_3 = true;
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] == 3){
                no_number_3 = false;
                break;
            } 
        }
    }
    ASSERT_TRUE(no_number_3);
}

TEST(ErrorsMatrixB, Error5){
    //Error 5: Matrix B contains a negative number!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{-7, 4},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool not_negative_number = true;
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] < 0){
                not_negative_number = false;
                break;
            }
        }
    }
    
    ASSERT_TRUE(not_negative_number);
}

TEST(ErrorsMatrixB, Error11){
    //Error 11: Every row in matrix B contains at least one 0!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{0, 4},{0, 10},{0, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    int counter_zeros = 0;
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] == 0){
                counter_zeros++;
                continue;
            }
        }
    }
    ASSERT_GT(B.size(), counter_zeros);
}

TEST(ErrorsMatrixB, Error12){
    //Error 12: The number of rows in A is equal to the number of columns in B!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 5}, {7, 8, 9}};
    std::vector<std::vector<int>> B = {{1, 4, 5},{1, 10, 5},{0, 12, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool rows_columns = A.size() != B[0].size()? true : false;
    ASSERT_TRUE(rows_columns); 
}

TEST(ErrorsMatrixB, Error16){
    //Error 16: Matrix b contains the number 6!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 5}, {7, 8, 9}};
    std::vector<std::vector<int>> B = {{1, 4, 5},{1, 6, 5},{0, 12, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_number_6 = true;
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] == 6){
                no_number_6 = false;
                break;
            }
        }
    }
    ASSERT_TRUE(no_number_6);
}

TEST(ErrorsMatrixC, Error14){
    //Error 14: The result matrix has an even number of rows!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 5}};
    std::vector<std::vector<int>> B = {{1, 4, 5},{1, 6, 5},{0, 12, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_even_rows = C.size() % 2 == 0 ? false : true;
    ASSERT_TRUE(no_even_rows);
}

TEST(ErrorsMatrixC, Error17){
    //Error 17: result matrix C contains the number 17!
    std::vector<std::vector<int>> A = {{17, 0, 0},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{1, 8},{9, 10},{0, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_number_17 = true;
    for (int i = 0; i < C.size(); ++i){
        for (int j = 0; j < C[i].size(); ++j){
            if(C[i][j] == 6){
                no_number_17 = false;
                break;
            }
        }
    }
    ASSERT_TRUE(no_number_17);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
