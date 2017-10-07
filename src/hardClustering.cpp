class HardClustering{
    private:
        int n;
        int k;
        int t;
        vector<Dissimilarity> dissimilarities;
        vector<Cluster> clusters;
    public:
        HardClustering(int k, int q, const Dataset& data){
            this->n = data.size();
            this->k = k;
            this->t = 0;

            for(int i = 0; i < k; i++){
                clusters.push_back(Cluster(n, q));
            }

            dissimilarities.push_back(Dissimilarity(View(data, 1, 9)));
            dissimilarities.push_back(Dissimilarity(View(data, 10, 19)));

            for(int point = 0; point < n; point++){
                int cluster;
                double closestDist = numeric_limits<double>::max();
                for(int c = 0; c < k; c++){
                    double curDist = clusters[c].prototype.dist(point, dissimilarities);
                    if(curDist < closestDist){
                        closestDist = curDist;
                        cluster = c;
                    }
                }
                clusters[cluster].insert(point);
            }
        }

        void run(){

        }
};