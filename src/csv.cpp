class CSV{
    private:
        vector<string> nextLine(istream& str){
            vector<string> result;

            string line;
            getline(str, line);

            stringstream lineStream(line);
            string cell;
        
            while(getline(lineStream, cell, ',')){
                result.push_back(cell);
            }

            return result;
        }
    public: 
        vector<vector<string> > read(string path){
            ifstream file(path.c_str());
            vector<vector<string> > result;
            do{
                vector<string> line(nextLine(file));
                if(line.size() == 0){
                    break;
                }
                result.push_back(line);
            } while(1);
            return result;
        }
};

