class Cluster{
    public:
        set<int> elements;               
        Prototype prototype;        
        Cluster(int n, int q){
            prototype = Prototype(q);
            prototype.randomize(n);
        }
        void insert(int i){
            elements.insert(i);
        }
        void remove(int i){
            elements.erase(i);
        }
        double dist(int j, const vector<Dissimilarity>& dissimilarities){
            double d = 0;
            for(set<int>::iterator it = elements.begin(); it != elements.end(); ++it){
                for(int k = 0; k < dissimilarities.size(); ++k){
                    d += dissimilarities[k].get(*it, j);
                }
            }
            return d;
        }
        double distToPrototypeUnweight(const Dissimilarity& dissimilarity){
            double d = 0;
            for(set<int>::iterator it = elements.begin(); it != elements.end(); ++it){
                d += prototype.distUnweight(*it, dissimilarity);
            }
            return d;
        }
        void print(){
            for(set<int>::iterator it = elements.begin(); it != elements.end(); ++it){
                printf("%d,", *it);
            }                
        }
};