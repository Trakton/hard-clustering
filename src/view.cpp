class View{
    private:
        vector<vector<double> > data;
    public:
        View(Dataset data, int from, int to){
            for(int i = 0; i < data.size(); i++){
                vector<double> line;
                for(int j = from; j <= to; j++){
                    line.push_back(atof(data[i][j].c_str()));
                }
                this->data.push_back(line);
            }
        }
        vector<double> operator[](int i) const{
            return data[i];
        }
        void print(){
            for(int i = 0; i < data.size(); i++){
                for(int j = 0; j < data[i].size(); j++){
                    printf("%.2lf,", data[i][j]);
                }
                printf("\n");
            }
        }
        int size(){
            return data.size();
        }
};