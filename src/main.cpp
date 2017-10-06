#include "csv.cpp"
#include "dataset.cpp"

using namespace std;

int main(){
    CSV csv;
    Dataset dataset(csv.read("data/segmentation.test.csv"));
    
    
    return 0;
}