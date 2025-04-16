#include "Utils.hpp"

using namespace std;
using namespace Eigen;
using namespace PolygonalLibrary;

int main()
{
	PolygonalMesh mesh;
	string path = "/home/appuser/Data/Esercitazione_5_STL/PolygonalMesh";
	string File_1_Path = "/home/appuser/Data/Esercitazione_5_STL/MioExport/Cell0Ds.inp";
	string File_2_Path = "/home/appuser/Data/Esercitazione_5_STL/MioExport/Cell1Ds.inp";
	string File_8_Path = "/home/appuser/Data/Esercitazione_5_STL/MioExport/Cell0Ds.txt";
	string File_9_Path = "/home/appuser/Data/Esercitazione_5_STL/MioExport/Cell1Ds.txt";

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
	
	if(!ExpPoints(mesh, File_1_Path))
	{
		return 1;
	}
	
	if(!ExpSegments(mesh, File_2_Path))
	{
		return 1;
	}
	
	if(!ExpPoints(mesh, File_8_Path))
	{
		return 1;
	}
	
	if(!ExpSegments(mesh, File_9_Path))
	{
		return 1;
	}
	return 0;
}