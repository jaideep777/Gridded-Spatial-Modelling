#include <iostream>
#include <netcdfcpp.h>
#include <vector>
#include <algorithm>
#include "../include/gsm.h"
using namespace std;

// g++ -O3 -I/usr/local/netcdf-c/include -I/usr/local/netcdf-cxx-legacy/include -I/home/jaideep/codes/libgsm_v3/include -L/home/jaideep/codes/libgsm_v3/lib -L/usr/local/netcdf-cxx-legacy/lib -o 1 fill_test.cpp -l:libgsm.so.3 -lnetcdf_c++ 


int main(){
	
	// ~~~~~~ Some NetCDF Essentials ~~~~~~~~
	// set NETCDF error behavior to non-fatal
	NcError err(NcError::silent_nonfatal);
	
	// specify log file for gsm
//	ofstream gsml("gsm_log.txt");
//	gsm_log = &gsml;

	// create a grid limits vector for convenience
	float glimits[] = {-180, 180, -90, 90};
	vector <float> glim(glimits, glimits+4);
	// ~~~~~~~~~~~~~~~~~~~~~~~~~~

	// create the coordinates for our georeferenced variable
	int nlons, nlats, nlevs, ntimes;
	vector <float> lats = createCoord(-90+0.25,90-0.25,0.5,nlats);
	vector <float> lons = createCoord(-180+0.25,180-0.25,0.5,nlons);
	vector <float> levs = createCoord(1,1,1,nlevs);
	vector <double> times(1); 
	times[0]=0;

	gVar hires;
	hires.createOneShot("/media/jaideep/Totoro/Data/precip_imd/rf_imd.1901.nc", glim);
	hires.fill(0);
	hires.printGrid();
//	hires.printValues();


	return 0;

}


