/*
 *   CSC(Compressed Sparse Column) format for sparse matrix.
 *
 */

// N: columns of sparse matrix
// nz_vals: non-zero elements of sparse matrix
// x: source vector, it has N x 1 float elements
// y: destination vector, it has M x 1 doule elements
void csc(const int &N, float *nz_vals, int *row_index, int *column_start,
         float *x, float *y) {
  int i, j;
#ifdef CSC_OMP
#endif // CSC_OMP
  // loop over the columns of sparse matrix
  for (i = 0; i < N; ++i) {
    for (j = column_start[i]; j < column_start[i + 1]; ++j) {
      y[row_index[j]] += nz_vals[j] * x[i];
    }
  }
}
