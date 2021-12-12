vector<vector<int> > Solution::solve(vector<vector<int> > &A) {

    int row = A.size();
    int col = A[0].size();

    vector<vector<int>> V;

    for(int i=0; i<col; i++)
    {
        vector<int> B;
        for(int j=0; j<row; j++)
        {
            B.push_back(A[j][i]);
        }

        V.push_back(B);
    }
   return V;
}
