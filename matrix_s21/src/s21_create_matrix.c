#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int i = 0;
  if (rows <= 0 || columns <= 0 || result == NULL) {
    return INCORRECT;
  } else {
    result->rows = rows;
    result->columns = columns;
    result->matrix = calloc(rows, sizeof(double *));
    if (result->matrix) {
      while (i < rows) {
        result->matrix[i] = calloc(columns, sizeof(double));
        if (result->matrix[i] == NULL) {
          s21_remove_matrix(result);
          break;
        }
        i++;
      }
    }
  }
  return result->matrix && result->matrix[i - 1] ? OK : CALC_ERROR;
}