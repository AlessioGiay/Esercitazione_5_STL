#pragma once

#include "PolygonalMesh.hpp"
#include "UCDUtilities.hpp"

using namespace std;

namespace PolygonalLibrary
{
bool ImportMesh(const string& path, PolygonalMesh& mesh);

bool ImportCell0Ds(const string& path, PolygonalMesh& mesh);

bool ImportCell1Ds(const string& path, PolygonalMesh& mesh);

bool ImportCell2Ds(const string& path, PolygonalMesh& mesh);

bool CheckLength(PolygonalMesh& mesh);

bool CheckAreas(PolygonalMesh& mesh);

bool ExpPoints(PolygonalMesh& mesh, const string& C0Path);
}