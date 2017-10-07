class Dissimilarity{
    private:
        vector<vector<double> > matrix;
        double weight;
    public:
        Dissimilarity(View view, double weight = 1){
            this->weight = weight;
            for(int i = 0; i < view.size(); i++){
                vector<double> dists;
                for(int j = i; j < view.size(); j++){
                    dists.push_back(view[i].dist(view[j]));
                }
                this->matrix.push_back(dists);
            }
        }
        double get(int i, int j){
            if(j < i) swap(i, j);
            return weight * matrix[i][j];
        }
};