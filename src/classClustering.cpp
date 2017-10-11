class ClassClustering{
    private:
        vector<Cluster> clusters;
        map<string, int> classMap;
        int c;
    public:
        ClassClustering(const Dataset& data, int classIndex){
            this->c = 0;
            for(int i = 0; i < data.size(); i++){
                string label = data[i][classIndex];
                if(classMap.count(label) == 0){
                    classMap[label] = c++;
                    clusters.push_back(Cluster(data.size(),0));
                }
                clusters[classMap[label]].insert(i);
            }
        }
        vector<Cluster> getClusters(){
            return clusters;
        }
        void printLog(){
            printf("\n -- KNOWN CLUSTERING EXTRACTED FROM CLASS --\n\n");
            for(map<string, int>::iterator it = classMap.begin(); it != classMap.end(); ++it){
                printf("%s:\n", it->first.c_str());
                clusters[it->second].print();
                printf("\n");
            }
        }
};