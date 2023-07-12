#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int exit_status = OK;
  if (A != NULL) {
    exit_status = s21_create_matrix(A->rows, A->columns, result);
    if (exit_status == OK) {
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          result->matrix[i][j] = A->matrix[i][j] * number;
        }
      }
    }
  } else
    exit_status = INCORRECT;
  return exit_status;
}