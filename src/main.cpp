#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <set>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <limits>
#include <utility>
#include <functional>
#include <queue>
#include <map>

using namespace std;

#include "csv.cpp"
#include "dataset.cpp"
#include "point.cpp"
#include "view.cpp"
#include "dissimilarity.cpp"
#include "prototype.cpp"
#include "cluster.cpp"
#include "hardClustering.cpp"
#include "classClustering.cpp"
#include "randIndex.cpp"

int main(){
    vector<double> rands;
    int seed = 1508782516;
    srand(seed);
    CSV csv;
    Dataset dataset(csv.read("data/segmentation.test.csv"));
    ClassClustering knownCluster(dataset, 0);    
    RandIndex bestRand;
    HardClustering bestCluster;
    for(int i = 0; i < 100; i++){
        printf("\n[%d] -- NEW CLUSTERING --\n", i);
        HardClustering clustering(7, 3, dataset, false);
        while(clustering.run());
        clustering.printLog();
        RandIndex rand(dataset.size(), clustering.getClusters(), knownCluster.getClusters());
        printf("\n -- AJUSTED RAND INDEX -- \n\n %.4lf\n", rand.getAjusted());
        if(rand.getAjusted() > bestRand.getAjusted()){
            bestRand = rand;
            bestCluster = clustering;
        }        
        rands.push_back(rand.getAjusted());
    }
    knownCluster.printLog();
    bestCluster.printLog();
    bestRand.printContingency();
    printf("\n -- AJUSTED RAND INDEX -- \n\n %.4lf\n", bestRand.getAjusted());
    printf("\n Rand Indexes for the 100 independent runs: \n");
    for(int i = 0; i < rands.size(); i++){
        printf("%.3lf, ", rands[i]);
    }
    printf("\n");
    return 0;
}
