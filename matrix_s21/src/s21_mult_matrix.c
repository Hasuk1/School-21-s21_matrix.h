#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int exit_status = OK;
  if (A != NULL && B != NULL) {
    if (A->rows == B->columns && A->columns == B->rows) {
      exit_status = s21_create_matrix(A->rows, B->columns, result);
      if (exit_status == OK) {
        for (int i = 0; i < result->rows; i++) {
          for (int j = 0; j < result->columns; j++) {
            result->matrix[i][j] = 0;
            for (int q = 0; q < A->columns; q++) {
              result->matrix[i][j] += A->matrix[i][q] * B->matrix[q][j];
            }
          }
        }
      }
    } else
      exit_status = CALC_ERROR;
  } else
    exit_status = INCORRECT;
  return exit_status;
}