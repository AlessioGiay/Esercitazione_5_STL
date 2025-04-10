#include <iostream>
#include "PolygonalMesh.hpp"
#include "Utils.hpp"
#include "UCDUtilities.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;

int main()
{
    PolygonalMesh mesh;
    string path = "/home/appuser/Data/Esercitazione_5_STL/PolygonalMesh";

    if(!ImportMesh(path, mesh))
    {
        return 1;
    }
    
    if(!CheckLength(mesh))
    {
	    return 1;
	}

    //Gedim::UCDUtilities utilities;
    //utilities.ExportPonits("./Cell0Ds.inp", mesh.Cell0DsVertices

    return 0;
}