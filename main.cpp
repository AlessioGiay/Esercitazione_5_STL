#include "Utils.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;

int main()
{
	PolygonalMesh mesh;
	string path = "/home/appuser/Data/Esercitazione_5_STL/PolygonalMesh";
	string FilePath = "/home/appuser/Data/Esercitazione_5_STL/Miei/Cells.csv";

	if(!ImportMesh(path, mesh))
	{
		return 1;
	}
	
	if(!CheckLength(mesh))
	{
		return 1;
	}
	
	if(!CheckAreas(mesh))
	{
		return 1;
	}
	
	if(!CheckMarker0Ds(mesh))
	{
		return 1;
	}
	
	if(!CheckMarker1Ds(mesh))
	{
		return 1;
	}
	
	if(!ExpPoints(mesh, FilePath))
	{
		return 1;
	}
	
	if(!ExpSegments(mesh, FilePath))
	{
		return 1;
	}
	
	if(!ExpPolygons(mesh, FilePath))
	{
		return 1;
	}

	return 0;
}