#include <iostream>
#include <string>

using namespace std;

/// BEGIN  <STUDENT ANSWER>
class Matrix
{
  private:
    int** mat;
    int rows;
    int cols;
  public:
    Matrix(int rows, int cols);
    ~Matrix();
    void printMatrix(); 
    void setElement(int rows, int cols, int value); 
    void setMatrix(int rows, int cols, int**);
    void addMatrix(int rows, int cols, int**); 
    void addMatrix(const Matrix&); 
};

// TODO


/// END  <STUDENT ANSWER>