#include "Utils.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <cerrno>
#include <cstring> // per std::strerror

using namespace std;

namespace PolygonalLibrary
{
bool ImportMesh(const string& path, PolygonalMesh& mesh)
{
	if(!ImportCell0Ds(path, mesh)) //prova ad importare il file Cell0d.csv
    {
        cerr << "File Cell0Ds.csv not found" << endl;
        return false;
    }

    if(!ImportCell1Ds(path, mesh)) //prova ad importare il file Cell1d.csv
    {
        cerr << "File Cell1Ds.csv not found" << endl;
        return false;
    }

    if(!ImportCell2Ds(path, mesh)) //prova ad importare il file Cell2d.csv
    {
        cerr << "File Cell2Ds.csv not found" << endl;
        return false;
    }

    return true;

}
// ***************************************************************************
bool ImportCell0Ds(const string& path, PolygonalMesh& mesh)
{
	string filePath = path + "/Cell0Ds.csv";
	ifstream file0(filePath);

    if (!file0)
    {
        return false;
    }
    
	list<string> lines;
    string line;
    while(getline(file0,line))
    {
        lines.push_back(line);
    }

    lines.pop_front();
    mesh.NumCell0Ds = lines.size();
    mesh.Cell0DsCoordinates.reserve(mesh.NumCell0Ds);
    mesh.Cell0DsID.reserve(mesh.NumCell0Ds);
    
    cout<<"Coo: "<<mesh.Cell0DsCoordinates.capacity()<<", ID: "<<mesh.Cell0DsID.capacity()<<endl;
	
    return true;
}
// ***************************************************************************
bool ImportCell1Ds(const string& path, PolygonalMesh& mesh)
{
	string filePath = path + "/Cell1Ds.csv";
	ifstream file1(filePath);

    if (!file1) //controlla se si apre il file
    {
        return false;
    }
    
    list<string> lines;
    string line;
    while(getline(file1,line))
    {
        lines.push_back(line);
    }

    lines.pop_front();
    mesh.NumCell1Ds = lines.size();
    mesh.Cell1DsVertices.reserve(mesh.NumCell1Ds);
    mesh.Cell1DsID.reserve(mesh.NumCell1Ds);
    
    cout<<"Ver: "<<mesh.Cell1DsVertices.capacity()<<", ID: "<<mesh.Cell1DsID.capacity()<<endl;

    return true;
}
// ***************************************************************************
bool ImportCell2Ds(const string& path, PolygonalMesh& mesh)
{
	string filePath = path + "/Cell2Ds.csv";
	ifstream file2(filePath);

    if (!file2) //controlla se si apre il file
    {
        return false;
    }
    
    list<string> lines;
    string line;
    while(getline(file2,line))
    {
        lines.push_back(line);
    }

    lines.pop_front();
    mesh.NumCell2Ds = lines.size();
    mesh.Cell2DsVertices.reserve(mesh.NumCell2Ds);
    mesh.Cell2DsEdges.reserve(mesh.NumCell2Ds);
    mesh.Cell2DsID.reserve(mesh.NumCell2Ds);
    
    cout<<"Coo: "<<mesh.Cell2DsVertices.capacity()<<",Edg: "<<mesh.Cell2DsEdges.capacity()<<", ID: "<<mesh.Cell2DsID.capacity()<<endl;
    	
    return true;
}

}