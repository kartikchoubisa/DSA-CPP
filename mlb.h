int mlb_print2darr (int rows, int cols, int *A){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%d ", A[i][j])
        }
        printf("\n")
    }
}