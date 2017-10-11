class RandIndex{
    private:
        vector<vector<int> > contingency;
        vector<int> cSum;
        vector<int> rSum;
        int n;
        double adjusted;

        int intersection(const Cluster& a, const Cluster& b){
            int sum = 0;
            for(set<int>::iterator it = a.elements.begin(); it != a.elements.end(); it++){
                if(b.elements.count(*it)){
                    sum++;
                }
            }
            return sum;
        }
        int comb(int n){
            if(n < 2) return 0;
            return (n*(n-1))/2;
        }
        double calculateAdjustedIndex(){
            double index = 0;
            for(int i = 0; i < contingency.size(); i++){
                for(int j = 0; j < contingency[i].size(); j++){
                    index += comb(contingency[i][j]);
                }
            }
            double expectedIndex = 0;
            double maxIndex = 0;
            double left = 0, right = 0;
            for(int i = 0; i < rSum.size(); i++){
                left += comb(rSum[i]);
                maxIndex += comb(rSum[i]);
            }
            for(int j = 0; j < cSum.size(); j++){
                right += comb(cSum[j]);
                maxIndex += comb(cSum[j]);
            }
            expectedIndex = ((double)(left*right))/((double)comb(n));
            maxIndex /= 2;
            this->adjusted = (index-expectedIndex)/(maxIndex-expectedIndex);
        }
    public:
        RandIndex(int n, const vector<Cluster>& a, const vector<Cluster>& b){
            this->adjusted = 0;
            this->n = n;
            this->rSum.assign(a.size(), 0);
            this->cSum.assign(b.size(), 0);

            contingency.assign(a.size(), vector<int>(b.size(), 0));
            for(int i = 0; i < a.size(); i++){
                for(int j = 0; j < b.size(); j++){
                    contingency[i][j] = intersection(a[i], b[j]);
                    rSum[i] += contingency[i][j];
                    cSum[j] += contingency[i][j];
                }
            }

            calculateAdjustedIndex();
        }

       double getAjusted(){
           return this->adjusted;
       }


        void printContingency(){
            printf("\n -- CONTINGENCY TABLE -- \n\n");
            for(int i = 0; i < contingency.size(); i++){
                for(int j = 0; j < contingency[i].size(); j++){
                    printf("%3d ", contingency[i][j]);
                }
                printf("| %d\n", rSum[i]);
            }
            for(int j = 0; j < contingency[0].size(); j++){
                printf("___ ");
            }
            printf("\n");
            for(int j = 0; j < contingency[0].size(); j++){
                printf("%3d ", cSum[j]);
            }
            printf("\n");
        }
};