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
	vector<Vector2d> Cell0DsCoordinates = {};
		
	unsigned int NumCell1Ds = 0;
	vector<unsigned int> Cell1DsID {};
	vector<unsigned int> Cell1DsMarker = {};
	vector<Vector2i> Cell1DsVertices = {};
	
	unsigned int NumCell2Ds = 0;
	vector<unsigned int> Cell2DsID = {};
	vector<unsigned int> Cell2DsMarker = {};
	vector<vector<unsigned int>> Cell2DsVertices = {};
	vector<vector<unsigned int>> Cell2DsEdges = {};
	
	MatrixXd Points;
	MatrixXi Segments;
	
	// const double epsilon = numeric_limits<double>::epsilon();
	
	const double epsilon = 1.0e-6;
};

}