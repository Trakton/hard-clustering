class HardClustering{
    private:
        int n;
        int k;
        int t;
        vector<Dissimilarity> dissimilarities;
        vector<Cluster> clusters;
    public:
        HardClustering(int n, int k, int q, vector<Dissimilarity> dissimilarities){
            this->n = n;
            this->k = k;
            this->t = 0;
            this->dissimilarities = dissimilarities;
            this->clusters.assign(k, Cluster(n, q));
        }
        void run(){

        }
};