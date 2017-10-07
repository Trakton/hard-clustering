#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <cstdlib>
#include <cmath>

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
    CSV csv;
    Dataset dataset(csv.read("data/segmentation.data.csv"));
    Dissimilarity dissimilarity[2] = {Dissimilarity(View(dataset, 1, 9)),
                                      Dissimilarity(View(dataset, 10, 19))};
    
    return 0;
}