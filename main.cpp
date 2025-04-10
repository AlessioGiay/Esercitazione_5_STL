#include "Utils.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;

int main()
{
	PolygonalMesh mesh;
	string path = "/home/appuser/Data/Esercitazione_5_STL/PolygonalMesh";
	string C0DPath = "/home/appuser/Data/Esercitazione_5_STL/Miei/Cell0Ds.txt";

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
	
	if(!ExpPoints(mesh, C0DPath))
	{
		return 1;	
	}

	return 0;
}