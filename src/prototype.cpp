class Prototype{
    private:
        int q;
        vector<int> prototypes;
    public:
        Prototype(){}
        Prototype(int q){
            this->q = q;
        }
        void randomize(int n){
            prototypes.clear();
            for(int i = 0; i < q; i++){
                prototypes.push_back(rand()%n);
            }
        }
        int operator[](int i) const {
            return prototypes[i];
        }
        double dist(int j, const vector<Dissimilarity> &dissimilarities){
            double d = 0;
            for(int i = 0; i < q; i++){
                for(int k = 0; k < dissimilarities.size(); k++){
                    d += dissimilarities[k].get(prototypes[i], j);
                }
            }
            return d;
        }
};