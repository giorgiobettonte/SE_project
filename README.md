## DevOps project part 1 - Software For High Performance Computing Engineering

### Overview

The purpose of this project is to gain hands-on experience with automated testing using Google Test and integrating these tests within a CI/CD pipeline using GitHub Actions.
In particular, tests are focused on the behaviour of the function multiplyMatrices, which it is used to perform matrix-matrix multiplication. The implementation of the function is deliberately uncorrect and leads to warnings regarding errors which are not properly real errors (for example, matrix B can't contain the number 3).

We implemented a serie of tests functions, which are able to check the conditons to satisfy and assert if everything is correct.
For the test activity we used Google test, and we automated the testing process exploting GitHubActions.

This repository includes sample code and tests to demonstrate the workflow.


### Content

The repository contains the following components:

- CI/CD Pipeline (.github/workflows/): Automated processes that trigger on file pushes to the repository, executing build and test procedures.
- src/: Source code for the matrix multiplication parallel software.
- test/: Testing with googletest for the application
- README.md: Project documentation.

### Getting Started

##### Prerequisites:

- GitHub Account: Required for accessing the repository and triggering GitHub Actions.

### CI Workflow with Github Actions

1. Clone the repo

     ```
     git clone https://github.com/giorgiobettonte/SE_project.git
     cd SE_project

     ```

2. Compile the project
    ```
    mkdir build
    cd build
    cmake ..
    make
    ```
3. Run the code

    To run all the tests:
     ```
    ./test_multiplication
     ```
    To run a specific suite of tests:
    ```
    ./test_multiplication --gtest_filter=ErrorsMatrixB.*
     ```
4. Run the GitHubAction.

   After local modifications, a contributer can push his work on the remote repository. This will activate the GitHubAction, which         controls that everything is correct.
   ```
   git add .
   git commit -m "/*comments*/"
   git push
   ```
5. Control process
   
   This is defined in the file "SE/.github/workflows/testing.yml. Every time someone push something or does a pull request, a remote
   virtual machine, offered by GitHub is allocated to compile, execute and test the code. The result is visible on the Github
   repository:
   ![image_git](image/image_git.png)

   In the image, all the tests performed have failed; we expected this behaviour since we designed test cases in order
   to verify the reliability of our tests.
  



