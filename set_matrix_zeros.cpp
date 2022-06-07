
void setZeros(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    vector<int>v1(row,-1);
    vector<int>v2(col,-1);
  for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(matrix[i][j] == 0){
                v1[i] = 0;
                v2[j] = 0;
            }
        }
    }
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            if(v1[i] == 0 || v2[j] == 0){
                matrix[i][j] = 0;
            }    
        }
    }
    
}