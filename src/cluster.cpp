class Cluster{
    private:
        list<int> elements;       
    public:
        Prototype prototype;        
        Cluster(int n, int q){
            prototype = Prototype(q);
            prototype.randomize(n);
        }
        void insert(int i){
            elements.push_back(i);
        }
        double dist(int j, const vector<Dissimilarity>& dissimilarities){
            double d = 0;
            for(list<int>::iterator it = elements.begin(); it != elements.end(); ++it){
                for(int k = 0; k < dissimilarities.size(); ++k){
                    d += dissimilarities[k].get(*it, j);
                }
            }
            return d;
        }
};