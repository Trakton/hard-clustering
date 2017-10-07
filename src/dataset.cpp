class Dataset{
    private:
        vector<vector<string> > data;
    public:
        Dataset(vector<vector<string> > data){
            this->data = data;
        }
        vector<string> operator[](int i) const{
            return data[i];
        }
        int size() const{
            return data.size();
        }
};