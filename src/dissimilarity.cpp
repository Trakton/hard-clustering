class Dissimilarity{
    private:
        vector<vector<double> > matrix;
    public:
        Dissimilarity(View view){
            for(int i = 0; i < view.size(); i++){
                vector<double> dists;
                for(int j = i; j < view.size(); j++){
                    double dist = 0;
                    for(int k = 0; k < view[i].size(); k++){
                        dist += (view[i][k] - view[j][k]) * (view[i][k] - view[j][k]); 
                    }
                    dists.push_back(sqrt(dist));
                }
                matrix.push_back(dists);
            }
        }
        double get(int i, int j){
            if(j < i) swap(i, j);
            return matrix[i][j];
        }
};