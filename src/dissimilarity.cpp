class Dissimilarity{
    private:
        vector<vector<double> > matrix;
    public:
        double weight;        
        Dissimilarity(View view, double weight = 1){
            this->weight = weight;
            this->matrix.assign(view.size(), vector<double>(view.size(), 0));
            for(int i = 0; i < view.size(); i++){
                for(int j = i; j < view.size(); j++){
                    this->matrix[i][j] = view[i].dist(view[j]);
                }
            }
        }
        double get(int i, int j) const{
            if(j < i) swap(i, j);
            return weight * matrix[i][j];
        }
        double getUnweight(int i, int j) const{
            if(j < i) swap(i, j);
            return matrix[i][j];
        }
};