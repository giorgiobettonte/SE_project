#include "matrix_multiplication.h"
#include <iostream>
#include <vector>
#include <gtest/gtest.h>

// ######################### Source code of multiplyMatrices in src/matrix_mult


TEST(ErrorsMatrixA, Error1){
    //it spots Error 1: Element-wise multiplication of ones detected!
    std::vector<std::vector<int>> A = {{1, 2 ,3},{4, 5, 6}}; 
    std::vector<std::vector<int>> B = {{1, 2}, {0, 4}, {5, 0}, {7, 0}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    //Search for element-wise multiplication of ones
    bool no_element_wise = true; //At the beginning we assume that the correct condition is satisfied
    
    //Loop over A
    for (int i = 0; i < A.size(); ++i){
        if(no_element_wise == false) break; //if the condition is already unsatisfied, no need to continue the loop
        for (int j = 0; j < A[i].size(); ++j){
            if (A[i][j] != 1){
                no_element_wise = false; //we set the condition to false
                break; //if we have already find the error, no need to continue the nested loop
            }
        }
    }
    
    ASSERT_TRUE(no_element_wise); //Check the condition
}

TEST(ErrorsMatrixA, Error2){
    //it spots Error 2: Matrix A contains the number 7!
    std::vector<std::vector<int>> A = {{7, 5, 6},{7, 8, 9}};
    std::vector<std::vector<int>> B = {{0, 8},{0, 10},{0, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_number_7 = true; //At the beginning we assume that the correct condition is satisfied
    
    //Loop over A
    for (int i = 0; i < A.size(); ++i){
        if(no_number_7 == false) break; //if the condition is already unsatisfied, no need to continue the loop
        for (int j = 0; j < A[i].size(); ++j){
            if (A[i][j] == 7){
                no_number_7 = false; //if we find a 7, we sent the condition to false
                break; //if we have already find a 7, no need to continue the nested loop
            }
        }
    }
    
    ASSERT_TRUE(no_number_7); //check the condtion; test fails if no_number_7 == false
}

TEST(ErrorsMatrixA, Error3){
    //it spots Error 3: Matrix A contains a negative number!
    std::vector<std::vector<int>> A = {{-1, 5, 6},{7, 8, 9}};
    std::vector<std::vector<int>> B = {{0, 8},{0, 10},{0, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_negative = true; //At the beginning we assume that the correct condition is satisfied

    //Loop over A
    for (int i = 0; i < A.size(); ++i){
        if(no_negative == false) break; //if the condition is already unsatisfied, no need to continue the loop
        for (int j = 0; j < A[i].size(); ++j){
            if (A[i][j] < 0){
                no_negative = false; //if we find a negative, we sent the condition to false
                break; //if we have already find a negative number, no need to continue the nested loop
            } 
        }
    }
    
    ASSERT_TRUE(no_negative); //check the condition; test fails if no_negative == false
}

TEST(ErrorsMatrixB, Error4){
    //Error 4: Matrix B contains the number 3!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{7, 3},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_number_3 = true; //At the beginning we assume that the correct condition is satisfied
    
    //Loop over B
    for (int i = 0; i < B.size(); ++i){
        if(no_number_3 == false) break;
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] == 3){
                no_number_3 = false; //if we find a 3, we sent the condition to false
                break; //if we have already find a 3, no need to continue the nested loop
            }
        }
    }

    ASSERT_TRUE(no_number_3); //check the condition; test fails if no_number_3 == false
}

TEST(ErrorsMatrixB, Error5){
    //Error 5: Matrix B contains a negative number!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{-7, 4},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_negative_number = true; //At the beginning we assume that the correct condition is satisfied
    
    //Loop over B
    for (int i = 0; i < B.size(); ++i){
        if(no_negative_number == false) break; //if the condition is already unsatisfied, no need to continue the loop
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] < 0){
                no_negative_number = false;  //if we find a negative, we sent the condition to false
                break; //if we have already find a negative number, no need to continue the nested loop
            }
        }
    }
    
    ASSERT_TRUE(no_negative_number); //check the condition; test fails if no_negative_number == false;
}

TEST(ErrorsMatrixC, Error6){
    //it spots Error 6: Result matrix contains a number bigger than 100!
    std::vector<std::vector<int>> A = {{1, 100, 3},{4, 5, 6},{7, 8, 9}};
    std::vector<std::vector<int>> B = {{7, 100, 0},{9, 10, 0},{11, 12, 0}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    
    multiplyMatrices(A, B, C, 3, 3, 3);

   //Search for number bigger than 100 in matrix C
    bool no_gt_hund = true; //At the beginning we assume that the correct condition is satisfied
    
    //Loop over C
    for (int i = 0; i < C.size(); ++i){
        if(no_gt_hund == false) break; //if the condition is already unsatisfied, no need to continue the loop
        for (int j = 0; j < C[i].size(); ++j){
            if (C[i][j] > 100){
                no_gt_hund = false; //if we find a number greater than 100, we sent the condition to false
                break; //if we have already find a number greater than 100, no need to continue the nested loop
            }
        }
    }
        
    ASSERT_TRUE(no_gt_hund); //check the condition; test fails if no_gt_hund == false;
}

TEST(ErrorsMatrixC, Error7){
    //it spots Error 7: Result matrix contains a number between 11 and 20!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    std::vector<std::vector<int>> B = {{7, 100, 0},{9, 10, 0},{11, 12, 0}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    
    multiplyMatrices(A, B, C, 3, 3, 3);

   //Search for number  between 11 and 20!
    bool correct_range = true; //At the beginning we assume that the correct condition is satisfied
    
    //Loop over C
    for (int i = 0; i < C.size(); ++i){
        if(correct_range == false) break; 
        for (int j = 0; j < C[i].size(); ++j){
            if (C[i][j] < 11 && C[i][j] < 20){
                correct_range = false; //if we find a number in the not-correct interval, we sent the condition to false
                break;  //if we have already find a number in the not-correct interval, no need to continue the nested loop
            }
        }
    }
    
    ASSERT_TRUE(correct_range); //check the condition; test fails if correct_range == false;
}

TEST(ErrorsMatrixC, Error8){
    //it spots Error 8: Result matrix contains zero!
    std::vector<std::vector<int>> A = {{0,0,0}};
    std::vector<std::vector<int>> B = {{0}, {0}, {0}};
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    bool no_zero = true; //At the beginning we assume that the correct condition is satisfied
    
    //Loop over C
    for (int i = 0; i < C.size(); ++i){
        if(no_zero == false) break; //if the condition is already unsatisfied, no need to continue the loop
        for (int j = 0; j < C[i].size(); ++j){
            if (C[i][j] == 0 ){
                no_zero = false; //if we find a zero, we set the condition to false 
                break; //if we have already found a zero in C, no need to continue the nested loop
            }
        }
    }
    
    ASSERT_TRUE(no_zero);
    
}


TEST(ErrorsMatrixA, Error10){
    //it spots Error 10: A row in matrix A contains more than one '1'!
    std::vector<std::vector<int>> A = {{1, 1, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{7, 8},{9, 10},{11, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_more_than_one = true; //At the beginning we assume that the correct condition is satisfied
    
    //Loop over A
    for (int i = 0; i < A.size(); ++i){
        int ones = 0;
        for (int j = 0; j < A[i].size(); ++j)
            if (A[i][j] == 1) ones++;
        if (ones > 1) no_more_than_one = false;
    }

    ASSERT_TRUE(no_more_than_one); //check the condition: test fails if no_more_than_one == false
}

TEST(ErrorsMatrixB, Error11){
    //it spots error 11: Every row in matrix B contains at least one 0!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{0, 4},{0, 10},{0, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    int counter_zeros = 0; //Ath the beggining we set the counter of zeros to zero
    
    //Loop over B
    for (int i = 0; i < B.size(); ++i){
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] == 0){
                counter_zeros++; //If we find a zero, we increase the counter
                continue; //If we have already found a zero in this row, no need no continue the nested loop
            }
        }
    }
    ASSERT_NE(counter_zeros, B.size()); //check the condition; test fails if: counter_zeros == B.size()
}

TEST(ErrorsMatrixB, Error12){
    //it spots error 12: The number of rows in A is equal to the number of columns in B!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 5}, {7, 8, 9}};
    std::vector<std::vector<int>> B = {{1, 4, 5},{1, 10, 5},{0, 12, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    std::vector<std::vector<int>> expected = {{58, 64},{139, 154}};
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool rows_columns = A.size() != B[0].size()? true : false; //if the number of rows in A is equal to the number of columns in B, we set rows_columns to false
    ASSERT_TRUE(rows_columns); //check the condition; test fails if rows_colums is equal to false
}


TEST(ErrorsMatrixC, Error14){
    //it spots error 14: The result matrix has an even number of rows!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 5}};
    std::vector<std::vector<int>> B = {{1, 4, 5},{1, 6, 5},{0, 12, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_even_rows = C.size() % 2 == 0 ? false : true; //if the number of colums of C is even, we set no_even_rows to false

    ASSERT_TRUE(no_even_rows); //check the condition; test fails if: no_even_row == false

}

TEST(ErrorsMatrixB, Error16){
    //it spots error 16: Matrix b contains the number 6!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 5}, {7, 8, 9}};
    std::vector<std::vector<int>> B = {{1, 4, 5},{1, 6, 5},{0, 12, 5}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_number_6 = true; //At the beginning we assume that the correct condition is satisfied
    
    //Loop over B
    for (int i = 0; i < B.size(); ++i){
        if(no_number_6 == false) break;  //If the condition is already unsatisfied, no need no continue the loop
        for (int j = 0; j < B[i].size(); ++j){
            if(B[i][j] == 6){
                no_number_6 = false; //If we find a 6, we set the condition to false
                break; //If we have already found a 6, no need no continue the nested loop
            }
        }
    }
    ASSERT_TRUE(no_number_6); //check the condition; test fails if: no_number_6 == false
}


TEST(ErrorsMatrixC, Error17){
    //it spots error 17: result matrix C contains the number 17!
    std::vector<std::vector<int>> A = {{17, 0, 0},{4, 5, 6}};
    std::vector<std::vector<int>> B = {{1, 8},{9, 10},{0, 12}};
    std::vector<std::vector<int>> C(2, std::vector<int>(2, 0));
    multiplyMatrices(A, B, C, 2, 3, 2);

    bool no_number_17 = true; //At the beginning we assume that the correct condition is satisfied
    
    //Loop over C
    for (int i = 0; i < C.size(); ++i){
        if(no_number_17) break; //If we have already found a 17, no need no continue the loop
        for (int j = 0; j < C[i].size(); ++j){
            if(C[i][j] == 6){
                no_number_17 = false; //If we find a 17, we set the condtion to false
                break; //If we have already found a 17, no need no continue the nested loop
            }
        }
    }
    ASSERT_TRUE(no_number_17); //check the condition; test fails if: no_number_17 == false
}



TEST(ErrorsMatrixA, Error18){
    //it spots Error 18: Matrix A is a square matrix!
    std::vector<std::vector<int>> A = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    std::vector<std::vector<int>> B = {{7, 8, 0},{9, 10, 0},{11, 12, 0}};
    std::vector<std::vector<int>> C(3, std::vector<int>(3, 0));
    
    multiplyMatrices(A, B, C, 3, 3, 3);
    
    ASSERT_NE(A.size(), A[0].size()); //check the condition; test fails if: A.size() and A[0].size() return the same number
}

TEST(ErrorsMatrixA, Error20){
    //it spots Error 20: Number of columns in matrix A is odd!
    std::vector<std::vector<int>> A = {{0,0,0}};
    std::vector<std::vector<int>> B = {{1}, {2}, {3}};
    std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));

    multiplyMatrices(A, B, C, 1, 3, 1);

    bool colsA = A[0].size() % 2 == 0 ? true : false; //if the number of columns is odd, we set colsA to false

    ASSERT_TRUE(colsA); //check the condition; test fails if: colsA == false
}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
