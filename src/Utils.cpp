#include "Utils.hpp"
#include <fstream>
#include <sstream>
#include <cmath>
#include <limits>
//#include <cerrno>
//#include <cstring>

using namespace std;

double EdgeLength(const double& x1, const double& y1, const double& x2, const double& y2)
{
	return sqrt(pow(x2 - x1 , 2) + pow(y2 - y1 , 2));	
}

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
    mesh.Cell0DsMarker.reserve(mesh.NumCell0Ds);
    
    Vector2d Coordinates;
    char tmp;
    unsigned int Id;
    unsigned int Marker;
	
	for(const auto& l : lines)
	{
		stringstream ss(l);
		ss >> Id >> tmp >> Marker >> tmp >> Coordinates(0) >> tmp >> Coordinates(1);
		
		mesh.Cell0DsID.push_back(Id);
		mesh.Cell0DsMarker.push_back(Marker);
		mesh.Cell0DsCoordinates.push_back(Coordinates);
	}
	
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
    mesh.Cell1DsMarker.reserve(mesh.NumCell1Ds);
    
    Vector2i Vertices;
    char tmp;
    unsigned int Id;
    unsigned int Marker;
	
	for(const auto& l : lines)
	{
		stringstream ss(l);
		ss >> Id >> tmp >> Marker >> tmp >> Vertices(0) >> tmp >> Vertices(1);
		
		mesh.Cell1DsID.push_back(Id);
		mesh.Cell1DsMarker.push_back(Marker);
		mesh.Cell1DsVertices.push_back(Vertices);
	}
	
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
    mesh.Cell1DsMarker.reserve(mesh.NumCell1Ds);
    
    char tmp;
    unsigned int Id;
    unsigned int Marker;
    unsigned int NumVertices;
    unsigned int NumEdges;
    
	for(const auto& l : lines)
	{
		stringstream ss(l);
		ss >> Id >> tmp >> Marker >> tmp >> NumVertices >> tmp;

		vector<unsigned int> Vertices(NumVertices);
		for(unsigned int i = 0; i < NumVertices; i++)
		{
		    ss >> Vertices[i] >> tmp;
		}
		
		ss >> NumEdges >> tmp;
		
		vector<unsigned int> Edges(NumEdges);
		for(unsigned int i = 0; i < NumEdges; i++)
		{
			ss >> Edges[i] >> tmp;
		}
		
		mesh.Cell2DsVertices.push_back(Vertices);
		mesh.Cell2DsEdges.push_back(Edges);
		mesh.Cell2DsID.push_back(Id);
		mesh.Cell2DsMarker.push_back(Marker);
	}
		
	return true;
}
// ***************************************************************************
bool CheckLength(PolygonalMesh& mesh)
{
	const double epsilon = std::numeric_limits<double>::epsilon();
	
	for(size_t i = 0; i < mesh.Cell1DsID.size(); i++)
	{
		double length = EdgeLength(
		mesh.Cell0DsCoordinates[mesh.Cell1DsVertices[i][0]](0), // Prendo la x del primo vertice
		mesh.Cell0DsCoordinates[mesh.Cell1DsVertices[i][0]](1), // Prendo la y del primo vertice
		mesh.Cell0DsCoordinates[mesh.Cell1DsVertices[i][1]](0), // Prendo la x del secondo vertice
		mesh.Cell0DsCoordinates[mesh.Cell1DsVertices[i][1]](1)); // Prendo la y del secondo vertice
		
		if (length < sqrt((4*epsilon)/sqrt(3)))
		// L'area del poligono più piccolo è un triangolo equilatero di lato L, ε < A = L^2*sqrt(3)/4, => L > sqrt((4*epsilon)/sqrt(3))
		{
			cout << "La lato: " << i << " ha lunghezza non valida\n";
			return false;
		}
	}
	
	return true;
}
// ***************************************************************************
bool CheckAreas(PolygonalMesh& mesh)
{
	
	
	return true;
}
// ***************************************************************************
bool ExpPoints(PolygonalMesh& mesh, const string& C0Path)
{
	mesh.Points.resize(3, mesh.NumCell0Ds);
	for(size_t i = 0; i < mesh.NumCell0Ds; i++)
	{
		mesh.Points(0,i) = mesh.Cell0DsCoordinates[i][0];
		mesh.Points(1,i) = mesh.Cell0DsCoordinates[i][1];
		mesh.Points(2,i) = 0.0;
	}
	
	Gedim::UCDUtilities utilities;
	utilities.ExportPoints(C0Path, mesh.Points);
	
	return true;
}
}