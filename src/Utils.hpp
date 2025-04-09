#pragma once

#include <iostream>
#include "PolygonalMesh.hpp"

using namespace std;

namespace PolygonalLibrary
{
bool ImportMesh(const string& path, PolygonalMesh& mesh);

bool ImportCell0Ds(const string& path, PolygonalMesh& mesh);

bool ImportCell1Ds(const string& path, PolygonalMesh& mesh);

bool ImportCell2Ds(const string& path, PolygonalMesh& mesh);

}