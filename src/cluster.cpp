class Cluster{
    private:
        list<int> elements;        
    public:
        Prototype prototype;        
        Cluster(int n, int q){
            prototype = Prototype(q);
            prototype.randomize(n);
        }
        void insert(int i){
            elements.push_back(i);
        }
        void print(){
            for(list<int>::iterator it = elements.begin(); it != elements.end(); ++it){
                printf("%d,", *it);
            }
            printf("\n");
        }
};