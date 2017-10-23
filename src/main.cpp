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
    int seed = 1508782516;
    srand(seed);
    CSV csv;
    Dataset dataset(csv.read("data/segmentation.test.csv"));
    HardClustering clustering(7, 3, dataset, false);
    for(int i = 0; i < 100; i++){
        if(clustering.run()){
          printf("REACHED A LOCAL MINIMUM\n");
          break;
        }
        printf("%d/100 iterations done.\n", i);
    }
    clustering.printLog();
    ClassClustering knownCluster(dataset, 0);
    knownCluster.printLog();
    RandIndex rand(dataset.size(), clustering.getClusters(), knownCluster.getClusters());
    rand.printContingency();
    printf("\n -- AJUSTED RAND INDEX -- \n\n %.4lf\n", rand.getAjusted());
    printf("\n -- RANDOM SEED: %d\n", seed);
    return 0;
}
