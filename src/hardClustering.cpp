class HardClustering{
    private:
        int n;
        int t;
        bool log;
        vector<Dissimilarity> dissimilarities;
        vector<Cluster> clusters;
        vector<int> belongsTo;

        int closestCluster(int point){
            int cluster;
            double closestDist = numeric_limits<double>::max();
            for(int c = 0; c < clusters.size(); c++){
                double curDist = clusters[c].prototype.dist(point, dissimilarities);
                if(curDist < closestDist){
                    closestDist = curDist;
                    cluster = c;
                }
            }
            return cluster;
        }

        void findBestPrototypes(){
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
            }
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
            }
        }

        bool defineBestPartition(){
            bool stuck = true;
            for(int point = 0; point < n; point++){
                int shouldBelong = closestCluster(point);
                int belongs = belongsTo[point];
                if(shouldBelong != belongs){
                    stuck = false;
                    belongsTo[point] = shouldBelong;
                    clusters[belongs].remove(point);
                    clusters[shouldBelong].insert(point);
                }
            }
            return stuck;
        }
    public:
        HardClustering(){}
        HardClustering(int k, int q, const Dataset& data, bool generateLogs){
            this->n = data.size();
            this->log = generateLogs;
            this->t = 0;

            for(int i = 0; i < k; i++){
                clusters.push_back(Cluster(n, q));
            }

            dissimilarities.push_back(Dissimilarity(View(data, 1, 9)));
            dissimilarities.push_back(Dissimilarity(View(data, 10, 19)));

            for(int point = 0; point < n; point++){
                int cluster = closestCluster(point);
                belongsTo.push_back(cluster);
                clusters[cluster].insert(point);
            }

            if(log) printLog();
            
        }

        vector<Cluster> getClusters(){
            return clusters;
        }

        void printLog(){
            printf("\n\n[Hard-Clustering] NEW ITERATION:\n");
            printf("T: %d, K: %lu, P: %lu, Q: %d\n", t, clusters.size(), dissimilarities.size(), clusters[0].prototype.getQ());
            printf("\n -- CLUSTER STATE --\n");
            for(int i = 0; i < clusters.size(); i++){
                printf("[%d]:\n", i);
                clusters[i].print();
                printf("\n");
            }
            printf("\n -- PROTOTYPE STATE --\n");
            for(int i = 0; i < clusters.size(); i++){
                printf("[%d]: ", i);
                clusters[i].prototype.print();
                printf("\n");
            }
            printf("\n -- WEIGHT STATE --\n");
            for(int i = 0; i < dissimilarities.size(); i++){
                printf("[%d]: %.2lf\n", i, dissimilarities[i].weight);
            }
        }

        bool run(){
            t++;
            findBestPrototypes();
            findBestWeights();
            bool stuck = defineBestPartition();
            if(log) printLog();
            return stuck;
        }
};
