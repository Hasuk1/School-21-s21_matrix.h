#include "s21_matrix.h"

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int exit_status = OK;
  if (A != NULL && B != NULL && result != NULL) {
    if (A->rows == B->rows && A->columns == B->columns) {
      exit_status = s21_create_matrix(A->rows, A->columns, result);
      if (exit_status == OK) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] - B->matrix[i][j];
          }
        }
      }
    } else
      exit_status = CALC_ERROR;
  } else
    exit_status = INCORRECT;
  return exit_status;
}