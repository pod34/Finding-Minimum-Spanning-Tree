#include "Communicator.h"

Communicator::Communicator(const string fileName){
    inputFile.open(fileName,ifstream::in);
    if(!inputFile.is_open()){
        //TODO throw exception;
    }
}

Communicator::~Communicator() {
    if(inputFile.is_open()){
        inputFile.close();
    }
}

vector<int> Communicator::ReadGraphDetailsFromFile() {//TODO  validate that all edges data is valid int and not float  etc.
    int tmpEdgeData;
     inputFile >> tmpEdgeData;
    edgesData.push_back(tmpEdgeData);
    inputFile >> numOfEdges;
    edgesData.push_back(tmpEdgeData);
    vector<int> edgesData;

     for(int i = 0; i < numOfEdges*3 + 2; i++){
         if(inputFile.peek() != EOF){
             inputFile >> tmpEdgeData;
             edgesData.push_back(tmpEdgeData);
         }
         else{
             //TODO we need to validate that there is enough edges and weights in file as given number of edges and throw an error
         }
     }
     if(inputFile.peek() != EOF){
         //TODO to much data in file we need to throw exception.
     }
     return edgesData;
}



