class Prototype{
    private:
        int q;
        vector<int> prototypes;
    public:
        Prototype(){}
        Prototype(int q){
            this->q = q;
        }
        int getQ(){
            return q;
        }
        void randomize(int n){
            prototypes.clear();
            for(int i = 0; i < q; i++){
                prototypes.push_back(rand()%n);
            }
        }
        void set(vector<int> prototypes){
            this->prototypes = prototypes;
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
        double dist(int j, const Dissimilarity &dissimilarity){
            double d = 0;
            for(int i = 0; i < q; i++){
                d += dissimilarity.get(prototypes[i], j);
            }
            return d;
        }
        double distUnweight(int j, const Dissimilarity &dissimilarity){
            double d = 0;
            for(int i = 0; i < q; i++){
                d += dissimilarity.getUnweight(prototypes[i], j);
            }
            return d;
        }
        void print(){
            for(int i = 0; i < prototypes.size(); i++){
                printf("%d,", prototypes[i]);
            }
        }
};