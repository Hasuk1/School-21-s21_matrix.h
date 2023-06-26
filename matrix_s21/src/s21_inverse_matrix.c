#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int exit_status = OK;
  if (!(A->rows > 0 && A->columns > 0)) {
    exit_status = INCORRECT;
  } else {
    if (A != NULL && result != NULL && A->rows == A->columns) {
      double det = 0;
      exit_status = s21_determinant(A, &det);
      if (det != 0 && exit_status == OK) {
        matrix_t buffer = {0};
        exit_status = s21_create_matrix(A->rows, A->rows, &buffer);
        if (exit_status == OK) {
          exit_status = s21_calc_complements(A, result);
          if (exit_status == OK) {
            exit_status = s21_transpose(result, &buffer);
            if (exit_status == OK) {
              s21_mult_number(&buffer, (1 / det), result);
            }
          }
          s21_remove_matrix(&buffer);
        }
      } else
        exit_status = CALC_ERROR;
    } else
      exit_status = CALC_ERROR;
  }
  return exit_status;
}