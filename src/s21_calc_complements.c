#include "s21_matrix.h"

void s21_get_matrix_algebraic_compl(matrix_t *A, matrix_t *minor,
                                    matrix_t *result, int n, int *exit_status) {
  for (int j = 0; j < n; j++) {
    for (int i = 0; i < n; i++) {
      int row = 0;
      for (int k = 0; k < n; k++) {
        if (k == i) {
          continue;
        }
        int col = 0;
        for (int l = 0; l < n; l++) {
          if (l == j) continue;
          minor->matrix[row][col] = A->matrix[k][l];
          col++;
        }
        row++;
      }
      double det = 0.0;
      *exit_status = s21_determinant(minor, &det);
      if (*exit_status == OK) {
        double sign = pow(-1, i + j);
        result->matrix[i][j] = sign * det;
      }
    }
    if (*exit_status != OK) break;
  }
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int exit_status = OK;
  if (A != NULL && result != NULL && A->rows == A->columns) {
    int n = A->rows;
    exit_status = s21_create_matrix(n, n, result);
    if (exit_status == OK) {
      if (n > 1) {
        matrix_t minor = {0};
        exit_status = s21_create_matrix(n - 1, n - 1, &minor);
        if (exit_status == OK) {
          s21_get_matrix_algebraic_compl(A, &minor, result, n, &exit_status);
          s21_remove_matrix(&minor);
        }
      } else if (n == 1)
        result->matrix[0][0] = 1;
    }
  } else {
    exit_status = CALC_ERROR;
    if (A == NULL || result == NULL) exit_status = INCORRECT;
  }
  return exit_status;
}