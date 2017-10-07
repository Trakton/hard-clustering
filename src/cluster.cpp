class Cluster{
    private:
        Prototype prototype;
    public:
        list<int> elements;
        Cluster(int n, int q){
            prototype = Prototype(q);
            prototype.randomize(n);
        }
};