#pragma once

#include <iostream>
#include "Eigen/Eigen"

using namespace std;
using namespace Eigen;


namespace PolygonalLibrary {

struct PolygonalMesh
{
	unsigned int NumCell0Ds = 0;
	vector<unsigned int> Cell0DsID = {};
	vector<unsigned int> Cell0DsMarker = {};
	vector<Vector2d> Cell0DsCoordinates = {}; // Uso Vector2d perchè le coordinate sono sempre 2
		
	unsigned int NumCell1Ds = 0;
	vector<unsigned int> Cell1DsID {};
	vector<unsigned int> Cell1DsMarker = {};
	vector<Vector2i> Cell1DsVertices = {}; // Uso Vector2d perchè i vertici sono sempre 2
	
	unsigned int NumCell2Ds = 0;
	vector<unsigned int> Cell2DsID = {};
	vector<unsigned int> Cell2DsMarker = {};
	vector<vector<unsigned int>> Cell2DsVertices = {}; // Uso vector perchè non conosco la dimensione dei poligoni
	vector<vector<unsigned int>> Cell2DsEdges = {}; // Uguale
	
	MatrixXd Points;
};

}