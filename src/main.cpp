#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#include "csv.cpp"
#include "dataset.cpp"
#include "view.cpp"

int main(){
    CSV csv;
    Dataset dataset(csv.read("data/segmentation.test.csv"));
    View v(dataset, 1, 10);
    v.print();
    return 0;
}