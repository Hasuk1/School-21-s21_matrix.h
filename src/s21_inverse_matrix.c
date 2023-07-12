#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int exit_status = OK;
  if ((A->rows > 0 && A->columns > 0)) {
    double det = 0;
    if (A != NULL && result != NULL && A->rows == A->columns &&
        s21_determinant(A, &det) == OK && det != 0) {
      matrix_t buffer1;
      exit_status = s21_calc_complements(A, &buffer1);
      if (exit_status == OK) {
        matrix_t buffer2;
        exit_status = s21_transpose(&buffer1, &buffer2);
        s21_remove_matrix(&buffer1);
        if (exit_status == OK) {
          s21_mult_number(&buffer2, (1 / det), result);
          s21_remove_matrix(&buffer2);
        }
      }

    } else
      exit_status = CALC_ERROR;
  } else
    exit_status = INCORRECT;

  return exit_status;
}