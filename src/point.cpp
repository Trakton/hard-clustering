class Point{
    private:
        vector<double> coordinates;
    public:
        Point(){}
        double operator[](int i) const{
            return coordinates[i];
        }
        void push(double x){
            coordinates.push_back(x);
        }
        int size() const{
            return coordinates.size();
        }
        double dist(const Point& b) const{
            int n = min(size(), b.size());
            double d = 0;
            for(int i = 0; i < n; i++){
                d += (coordinates[i] - b[i]) * (coordinates[i] - b[i]);
            }
            return sqrt(d);
        }
};