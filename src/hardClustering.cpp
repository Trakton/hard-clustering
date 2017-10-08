class HardClustering{
    private:
        int n;
        vector<Dissimilarity> dissimilarities;
        vector<Cluster> clusters;

        void findBestPrototypes(){
            for(int k = 0; k < clusters.size(); k++){
                printf("%d:\n", k);
                clusters[k].prototype.print();
            }
            printf("\n");
            for(int k = 0; k < clusters.size(); k++){
                priority_queue<pair<double, int>, vector<pair<double, int> >, greater<pair<double, int> > > closest;
                for(int i = 0; i < n; i++){
                    double d = clusters[k].dist(i, dissimilarities);
                    closest.push(pair<double, int>(d, i));
                }
                vector<int> prototypes;
                for(int i = 0; i < clusters[k].prototype.getQ(); i++){
                    prototypes.push_back(closest.top().second);
                    closest.pop();
                }
                clusters[k].prototype.set(prototypes);
                printf("%d:\n", k);
                clusters[k].prototype.print();
            }
            printf("\n");
        }

        void findBestWeights(){
            int P = dissimilarities.size();
            int K = clusters.size();
            vector<double> denominators;
            double numerator = 1;
            for(int h = 0; h < P; ++h){
                double sum = 0;
                for(int k = 0; k < K; ++k){
                    sum += clusters[k].distToPrototypeUnweight(dissimilarities[h]);
                }
                numerator *= sum;
                denominators.push_back(sum);
            }
            numerator = pow(numerator, 1.0/P);
            for(int j = 0; j < P; ++j){
                dissimilarities[j].weight = numerator/denominators[j];
                printf("[%.2lf],", dissimilarities[j].weight);
            }
            printf("\n");
        }
    public:
        HardClustering(int k, int q, const Dataset& data){
            this->n = data.size();

            for(int i = 0; i < k; i++){
                clusters.push_back(Cluster(n, q));
            }

            dissimilarities.push_back(Dissimilarity(View(data, 1, 9)));
            dissimilarities.push_back(Dissimilarity(View(data, 10, 19)));

            for(int point = 0; point < n; point++){
                int cluster;
                double closestDist = numeric_limits<double>::max();
                for(int c = 0; c < clusters.size(); c++){
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
            findBestPrototypes();
            findBestWeights();
        }
};