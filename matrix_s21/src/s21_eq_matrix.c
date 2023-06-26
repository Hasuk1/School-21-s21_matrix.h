#include "s21_matrix.h"

const double EPSILON = 1e-06;

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int exit_status = SUCCESS;
  if (A->rows == B->rows && A->columns == B->columns) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (fabs(A->matrix[i][j] - B->matrix[i][j]) > EPSILON) {
          exit_status = FAILURE;
          break;
        }
      }
      if (exit_status == FAILURE) break;
    }
  } else
    exit_status = FAILURE;
  return exit_status;
}