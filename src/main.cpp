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

using namespace std;

#include "csv.cpp"
#include "dataset.cpp"
#include "point.cpp"
#include "view.cpp"
#include "dissimilarity.cpp"
#include "prototype.cpp"
#include "cluster.cpp"
#include "hardClustering.cpp"

int main(){
    srand(time(NULL));
    CSV csv;
    Dataset dataset(csv.read("data/segmentation.data.csv"));
    HardClustering clustering(7, 3, dataset, false);
    for(int i = 0; i < 100; i++){
        clustering.run();
    }
    clustering.printLog();
    return 0;
}