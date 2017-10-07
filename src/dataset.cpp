class Dataset{
    private:
        vector<vector<string> > data;
    public:
        Dataset(vector<vector<string> > data){
            this->data = data;
        }
        void print(){
            for(int i = 0; i < data.size(); i++){
                for(int j = 0; j < data[i].size(); j++){
                    printf("%s,", data[i][j].c_str());
                }
                printf("\n");
            }
        }
        vector<string> operator[](int i) const{
            return data[i];
        }
        int size(){
            return data.size();
        }
};