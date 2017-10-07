#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
#include <cmath>

using namespace std;

#include "csv.cpp"
#include "dataset.cpp"
#include "view.cpp"
#include "dissimilarity.cpp"

int main(){
    CSV csv;
    Dataset dataset(csv.read("data/segmentation.test.csv"));
    Dissimilarity dissimilarity[2] = {Dissimilarity(View(dataset, 1, 10)),
                                      Dissimilarity(View(dataset, 11, 19))};
    return 0;
}