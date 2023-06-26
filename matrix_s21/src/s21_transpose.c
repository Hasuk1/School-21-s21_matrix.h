#include "s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int exit_status = OK;
  if (A != NULL) {
    exit_status = s21_create_matrix(A->columns, A->rows, result);
    if (exit_status == OK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[j][i];
        }
      }
    }
  } else
    exit_status = INCORRECT;
  return exit_status;
}