class View{
    private:
        vector<Point> data;
    public:
        View(Dataset data, int from, int to){
            for(int i = 0; i < data.size(); i++){
                Point p;
                for(int j = from; j <= to; j++){
                    p.push(atof(data[i][j].c_str()));
                }
                this->data.push_back(p);
            }
        }
        Point operator[](int i) const{
            return data[i];
        }
        int size(){
            return data.size();
        }
};